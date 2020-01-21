#include <d3d9.h>
#include <d3dx9.h>

 /**========================================================================
  * 전역 변수
  *=========================================================================*/
LPDIRECT3D9	g_pD3D = NULL; //IDeirectX3D9 interface의 typedef된 포인터형
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL; //그래픽 카드의 추상화라고 한다.

//육면체(1)
LPDIRECT3DVERTEXBUFFER9 g_FirstVB = NULL; //정점을 보관할 버퍼
LPDIRECT3DINDEXBUFFER9 g_FirstIB = NULL; // 인덱스를 저장할 인덱스 버퍼
//사각뿔
LPDIRECT3DVERTEXBUFFER9 g_SecondVB = NULL; //정점을 보관할 버퍼
LPDIRECT3DINDEXBUFFER9 g_SecondIB = NULL; // 인덱스를 저장할 인덱스 버퍼
//육면체(2)
LPDIRECT3DVERTEXBUFFER9 g_ThirdVB = NULL; //정점을 보관할 버퍼
LPDIRECT3DINDEXBUFFER9 g_ThirdIB = NULL; // 인덱스를 저장할 인덱스 버퍼

struct CUSTOMVERTEX
{
	FLOAT x, y, z;
	DWORD color;
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)

//인덱스의 인자가 3개!!!!
struct MYINDEX
{
	WORD _0, _1, _2;	// 일반적으로 인덱스는 16비트의 크기를 갖는다.
};

/**========================================================================
 * Direct3D 초기화
 *=========================================================================*/
HRESULT InitD3D(HWND hWnd)
{
	// 디바이스를 생성하기 위한 D3D 객체 생성
	if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS	d3dpp; //디바이스 생성을 위한 구조체
	ZeroMemory(&d3dpp, sizeof(d3dpp)); //반드시 구조체를 비운다.

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; //가장 효율적인 swap효과
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	d3dpp.EnableAutoDepthStencil = TRUE; // 깊이가 있는 z버퍼가 필요하므로 설정한다.
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	// 디바이스를 설정해서 생성
	// 디폴트 비디오카드를 사용하고, HAL 디바이스를 생성한다.
	// 정점 처리는 모든 카드에서 지원하는 SW처리로 생성한다.
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
	{
		return E_FAIL;
	}

	//컬링기능을 끈다. 삼각형의 앞면, 뒷면을 모두 랜더링한다. 컬링: 카메라가 보고 있는 방향만 렌더링 하는것
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	//Z(깊이) 버퍼 기능을 켠다.
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	//정점에 색깔이 있으므로 광원 기능을 끈다.
	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	return S_OK;
}

/**========================================================================
 * 정점 초기화 : 정점 버퍼를 생성하고 정점값을 채워 넣는다.
 *=========================================================================*/
HRESULT InitVB()
{
	// 상자(cube)를 랜더링하기 위해 8개의 정점 선언
	CUSTOMVERTEX vertices[] =
	{
		{-1, 1, 1, 0xffff0000},	//v0
		{ 1, 1, 1, 0xff00ff00}, //v1
		{ 1, 1,-1, 0xff0000ff}, //v2
		{-1, 1,-1, 0xffffff00}, //v3

		{-1,-1, 1, 0xffff0000}, //v4
		{ 1,-1, 1, 0xff00ff00}, //v5
		{ 1,-1,-1, 0xff0000ff}, //v6
		{-1,-1,-1, 0xffffff00}, //v7
	};

	// 정점 버퍼를 생성한다.
	// 정점 구조체 3개를 저장할 메모리를 할당한다.
	// FVF를 지정하여 보관할 데이터의 형식을 지정한다.
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(8 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_FirstVB, NULL)))
	{
		return E_FAIL;
	}

	//정점의 버퍼를 값으로 채운다.
	//정점 버퍼의 Lock() 함수를 호출하여 포인터를 얻어온다.
	void* pVertices;

	if (FAILED(g_FirstVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	//메모리 카피
	memcpy(pVertices, vertices, sizeof(vertices));
	//UnLock해줘야 Render사용가능
	g_FirstVB->Unlock();
}

/**========================================================================
 * 인덱스 버퍼 설정
 *=========================================================================*/
HRESULT InitIB()
{
	MYINDEX indices[] =
	{
		{0, 1, 2}, {0, 2, 3}, // 윗면
		{4, 5, 6}, {4, 7, 6}, // 아랫면
		{0, 3, 7}, {0, 7, 4}, // 왼면
		{1, 5, 6}, {1, 6, 2}, // 오른면
		{3, 2, 6}, {3, 6, 7}, // 앞면
		{0, 4, 5}, {0, 5, 1}, // 뒷면
	};

	//인덱스 버퍼 생성
	//D3DFMT_INDEX16은 인덱스의 단위가 16비트라는 것.
	//MYINDEX 구조체에서 WORD형으로 선언으므로 D3DFMT_INDEX16을 사용한다.
	if (FAILED(g_pd3dDevice->CreateIndexBuffer(12 * sizeof(MYINDEX), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &g_FirstIB, NULL)))
	{
		return E_FAIL;
	}

	//인덱스 버퍼를 값으로 채운다.
	void* pIndices;

	//인덱스 버퍼의 Lock() 함수를 호출하여 포인터를 얻어와서 정보를 채운다.
	if (FAILED(g_FirstIB->Lock(0, sizeof(indices), (void**)&pIndices, 0)))
	{
		return E_FAIL;
	}

	//메모리 카피
	memcpy(pIndices, indices, sizeof(indices));

	//UnLock해줘야 Render사용가능
	g_FirstIB->Unlock();

	return S_OK;
}


/**========================================================================
 * 정점 초기화 : 정점 버퍼를 생성하고 정점값을 채워 넣는다.
 *=========================================================================*/
HRESULT InitVB_Second()
{
	// 상자(cube)를 랜더링하기 위해 8개의 정점 선언
	CUSTOMVERTEX vertices[] =
	{
		{0, 1, 0, 0xffff0d00},	//v0
		{ -1, 0, 1, 0xff00ffd0}, //v1
		{ 1, 0, 1, 0xff000dff}, //v2
		{-1, 0,-1, 0xfffff000}, //v3
		{1, 0, -1, 0xfff00000}, //v4
	};

	// 정점 버퍼를 생성한다.
	// 정점 구조체 3개를 저장할 메모리를 할당한다.
	// FVF를 지정하여 보관할 데이터의 형식을 지정한다.
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(5 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_SecondVB, NULL)))
	{
		return E_FAIL;
	}

	//정점의 버퍼를 값으로 채운다.
	//정점 버퍼의 Lock() 함수를 호출하여 포인터를 얻어온다.
	void* pVertices;

	if (FAILED(g_SecondVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	//메모리 카피
	memcpy(pVertices, vertices, sizeof(vertices));
	//UnLock해줘야 Render사용가능
	g_SecondVB->Unlock();

	return S_OK;
}

/**========================================================================
 * 인덱스 버퍼 설정
 *=========================================================================*/
HRESULT InitIB_Second()
{
	MYINDEX indices[] =
	{
		{1, 0, 3}, // 왼면
		{0, 2, 4}, // 오른면
		{1, 0, 2}, // 앞면
		{3, 0, 4}, // 뒷면
		{2, 1, 3}, {3, 4, 2}, // 아랫면
	};

	//인덱스 버퍼 생성
	//D3DFMT_INDEX16은 인덱스의 단위가 16비트라는 것.
	//MYINDEX 구조체에서 WORD형으로 선언으므로 D3DFMT_INDEX16을 사용한다.
	if (FAILED(g_pd3dDevice->CreateIndexBuffer(6 * sizeof(MYINDEX), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &g_SecondIB, NULL)))
	{
		return E_FAIL;
	}

	//인덱스 버퍼를 값으로 채운다.
	void* pIndices;

	//인덱스 버퍼의 Lock() 함수를 호출하여 포인터를 얻어와서 정보를 채운다.
	if (FAILED(g_SecondIB->Lock(0, sizeof(indices), (void**)&pIndices, 0)))
	{
		return E_FAIL;
	}
	//메모리 카피
	memcpy(pIndices, indices, sizeof(indices));
	//UnLock해줘야 Render사용가능
	g_SecondIB->Unlock();

	return S_OK;
}

/**========================================================================
 * 정점 초기화 : 정점 버퍼를 생성하고 정점값을 채워 넣는다.
 *=========================================================================*/
HRESULT InitVB_Third()
{
	// 상자(cube)를 랜더링하기 위해 8개의 정점 선언
	CUSTOMVERTEX vertices[] =
	{
		{-1, 1, 1, 0xffff0000},	//v0
		{ 1, 1, 1, 0xff00ff00}, //v1
		{ 1, 1,-1, 0xff0000ff}, //v2
		{-1, 1,-1, 0xffffff00}, //v3

		{-1,-1, 1, 0xffff0000}, //v4
		{ 1,-1, 1, 0xff00ff00}, //v5
		{ 1,-1,-1, 0xff0000ff}, //v6
		{-1,-1,-1, 0xffffff00}, //v7
	};

	// 정점 버퍼를 생성한다.
	// 정점 구조체 3개를 저장할 메모리를 할당한다.
	// FVF를 지정하여 보관할 데이터의 형식을 지정한다.
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(8 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_ThirdVB, NULL)))
	{
		return E_FAIL;
	}

	//정점의 버퍼를 값으로 채운다.
	//정점 버퍼의 Lock() 함수를 호출하여 포인터를 얻어온다.
	void* pVertices;

	if (FAILED(g_ThirdVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	//메모리 카피
	memcpy(pVertices, vertices, sizeof(vertices));
	//UnLock해줘야 Render사용가능
	g_ThirdVB->Unlock();

	return S_OK;
}

/**========================================================================
 * 인덱스 버퍼 설정
 *=========================================================================*/
HRESULT InitIB_Third()
{
	MYINDEX indices[] =
	{
		{0, 1, 2}, {0, 2, 3}, // 윗면
		{5, 4, 6}, {4, 7, 6}, // 아랫면
		{0, 3, 7}, {0, 7, 4}, // 왼면
		{1, 5, 6}, {1, 6, 2}, // 오른면
		{3, 2, 6}, {3, 6, 7}, // 앞면
		{0, 4, 5}, {0, 5, 1}, // 뒷면
	};

	//인덱스 버퍼 생성
	//D3DFMT_INDEX16은 인덱스의 단위가 16비트라는 것.
	//MYINDEX 구조체에서 WORD형으로 선언으므로 D3DFMT_INDEX16을 사용한다.
	if (FAILED(g_pd3dDevice->CreateIndexBuffer(12 * sizeof(MYINDEX), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &g_ThirdIB, NULL)))
	{
		return E_FAIL;
	}

	//인덱스 버퍼를 값으로 채운다.
	void* pIndices;

	//인덱스 버퍼의 Lock() 함수를 호출하여 포인터를 얻어와서 정보를 채운다.
	if (FAILED(g_ThirdIB->Lock(0, sizeof(indices), (void**)&pIndices, 0)))
	{
		return E_FAIL;
	}
	//메모리 카피
	memcpy(pIndices, indices, sizeof(indices));
	//UnLock해줘야 Render사용가능
	g_ThirdIB->Unlock();

	return S_OK;
}


/**========================================================================
 * 기하 정보 초기화
 * 도형 갯수만큼 정점 버퍼와 인덱스 버퍼를 설정한다.
 * 코드에선 사각형1, 삼각형 1
 *=========================================================================*/
HRESULT InitGeometry()
{
	//첫번째 VerTexBuffer
	if (FAILED(InitVB()))
	{
		return E_FAIL;
	}
	//첫번째 IndexBuffer
	if (FAILED(InitIB()))
	{
		return E_FAIL;
	}
	//두번째 VerTexBuffer
	if (FAILED(InitVB_Second()))
	{
		return E_FAIL;
	}
	//두번째 IndexBuffer
	if (FAILED(InitIB_Second()))
	{
		return E_FAIL;
	}
	//세번째 VerTexBuffer
	if (FAILED(InitVB_Third()))
	{
		return E_FAIL;
	}
	//세번째 IndexBuffer
	if (FAILED(InitIB_Third()))
	{
		return E_FAIL;
	}
		
	return S_OK;
}

/**========================================================================
 * 카메라 행렬 설정
 *=========================================================================*/
void SetupCamera()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld); //월드 스페이스를 생성
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld); //월드 스페이스를 디바이스에 적용한다.

	//뷰 행렬(카메라)을 정의하기 위해서는 3가지 값이 필요하다.
	D3DXVECTOR3 vEyePt(0.0f, 10.0f, -20.0f);						//눈의 위치(0.0f, 10.0f, -20.0f)
	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);						// 눈이 바라보는 위치(0.0f, 0.0f, 0.0f)
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);							// 윗 방향을 나타내는 상방 벡터(0.0f, 1.0f, 0.0f)

	D3DXMATRIXA16 matView;
	// 3가지 Point를 이용해 뷰 행렬을 생성한다.
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);		//결과 행렬에 카메라에 대한 위치, 지점, 벡터를 적용한다.
	g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);				// 생성한 뷰 행렬을 디바이스에 설정한다.

	// 프로젝션 행렬을 정의하기 위해서는 시야각(FOV = Field Of View)과 종횡비(aspect ratio), 클리핑 평면의 값이 필요하다.
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);			//생성한 프로젝션 행렬을 디바이스에 설정.
}

/**========================================================================
 * 메시 그리기
 *=========================================================================*/
void DrawMesh(D3DXMATRIXA16* pMat, LPDIRECT3DVERTEXBUFFER9 _vertexBuffer, LPDIRECT3DINDEXBUFFER9 _IndexBuffer, int _count)
{
		/*
		매트릭스 구조체의 포인터, 회전 각도, 회전 각도 이므로, 나누기가 작을수록 빨라진다. TickCount가 1000일때, TickCount/100 = 10(각도), TickCount/500 = 2(각도)
		D3DXMatrixRotationX -> x축
		D3DXMatrixRotationY -> y축
		D3DXMatrixRotationZ -> z축
		*/
		// 기하 정보를 출력하기 위한 DrawIndexPrimitive() 함수를 호출한다.
		// 첫 번째 : 그리고자 하는 기본 타입형
		// 두 번째 : 여러 오브젝트를 하나로 묶을때 더해질 넘버.
		// 세 번째 : 참조할 최소 인덱스 값
		// 네 번째 : 이번 호출에 참조될 버텍스의 수
		// 다섯 번째 : 인덱스 버퍼 내에서 읽기를 시작할 요소로의 인덱스
		// 여섯 번째 : 그리고자 하는 기본형의 수
		//g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
	//D3DXMatrixRotationY(pMat, GetTickCount() / 500.0f);
	g_pd3dDevice->SetTransform(D3DTS_WORLD, pMat); //생성한 회전 행렬을 월드 행렬로 디바이스에 설정한다.
	g_pd3dDevice->SetStreamSource(0, _vertexBuffer, 0, sizeof(CUSTOMVERTEX)); //다른 형태나 크기의 그림을 그리기 위해선 반드시 선언해줘야한다.
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	g_pd3dDevice->SetIndices(_IndexBuffer); //인덱스 버퍼를 불러온다.
	g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, _count);
}

/**========================================================================
 * 초기화 객체들 Release
 *=========================================================================*/
void Cleanup()
{
	//해제 순서가 중요 인터페이스 생성의 역순으로 해제하자.
	//해체는 조립의 역순....
	if (g_ThirdIB != NULL)
		g_ThirdIB->Release();

	if (g_ThirdVB != NULL)
		g_ThirdVB->Release();

	if (g_SecondIB != NULL)
		g_SecondIB->Release();

	if (g_SecondVB != NULL)
		g_SecondVB->Release();

	if (g_FirstIB != NULL)
		g_FirstIB->Release();

	if (g_FirstVB != NULL)
		g_FirstVB->Release();

	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	if (g_pD3D != NULL)
		g_pD3D->Release();
}

/**========================================================================
 * 화면 그리기
 *=========================================================================*/
void Render()
{
	if (NULL == g_pd3dDevice)
	{
		return;
	}

	D3DXMATRIXA16 matWorld;
	//위치
	D3DXMATRIXA16 g_Squre; //사각형1
	D3DXMATRIXA16 g_Squre_pyramid; //사각뿔
	D3DXMATRIXA16 g_Squre_Second; //사각형2

	//회전
	D3DXMATRIXA16 rSqure; //사각형1
	D3DXMATRIXA16 rSqure_pyramid; //사각뿔
	D3DXMATRIXA16 rSqure_Second; //사각형2

	// 후면 버퍼를 파란색(0, 0, 255)으로 지우고 Z버퍼를 사용하기 위해 초기화 한다.
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	D3DXMatrixIdentity(&g_Squre);//원점(0,0,0)에 첫번째 사각형을 위치한다.

	D3DXMatrixRotationY(&rSqure, GetTickCount() / 500.0f);			//사각형 회전
	D3DXMatrixRotationZ(&rSqure_pyramid, GetTickCount() / 500.0f);	//사각뿔 회전
	D3DXMatrixRotationX(&rSqure_Second, GetTickCount() / 500.0f);	//사각뿔 회전

	D3DXMatrixTranslation(&g_Squre_pyramid, 3, 3, 3); //두번째 사각형을 0,0,0에서 각 점에서 3만큼 떨어진 곳에 두번째 사각형을 위치
	D3DXMatrixTranslation(&g_Squre_Second, -3, -3, -6); //세번째 사각형을 0,0,0에서 각 점에서 3만큼 떨어진 곳에 세번째 사각형을 위치
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	
	// 랜더링 시작
	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		//크기->자전->이동->공전 순서에 주의한다!
		matWorld = rSqure * g_Squre;
		DrawMesh(&matWorld, g_FirstVB, g_FirstIB, 12);

		matWorld = rSqure_pyramid * g_Squre_pyramid;
		DrawMesh(&matWorld, g_SecondVB, g_SecondIB, 6);

		matWorld = rSqure_Second * g_Squre_Second;
		DrawMesh(&matWorld, g_ThirdVB, g_ThirdIB, 12);

		//렌더링 종료
		g_pd3dDevice->EndScene();
	}

	// 후면 버퍼를 보이는 화면으로 전환.
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

/**========================================================================
 * WinProc
 *=========================================================================*/
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		Cleanup();
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

/**========================================================================
 * Window 생성
 *=========================================================================*/
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
	//윈도우 클래스 등록
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "D3D IndexBuffer", NULL };

	//winclass 레지스터에 등록
	RegisterClassEx(&wc);

	HWND hWnd = CreateWindow("D3D IndexBuffer", "D3D IndexBuffer", WS_OVERLAPPEDWINDOW, 100, 100, 1024, 768, GetDesktopWindow(), NULL, NULL, wc.hInstance, NULL);

	if (SUCCEEDED(InitD3D(hWnd)))
	{
		if (SUCCEEDED(InitGeometry()))
		{
			SetupCamera();
			ShowWindow(hWnd, SW_SHOWDEFAULT);
			UpdateWindow(hWnd);

			MSG msg;
			ZeroMemory(&msg, sizeof(msg));

			while (msg.message != WM_QUIT)
			{
				if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else
					Render();
			}
		}
	}

	//등록된 레지스트 winclass 릴리즈.
	UnregisterClass("D3D IndexBuffer", wc.hInstance);
	return 0;
}



