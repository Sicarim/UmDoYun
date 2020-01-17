/**========================================================================
 * 디바이스 생성
 * D3D 디바이스를 생성하고, 이를 사용해서 화면을 지우는 방법에 대해서 공부하게 된다.
 *=========================================================================*/

 // Direct3D9을 사용하기 위한 헤더
#include <d3d9.h>
#include <d3dx9.h>

/**========================================================================
 * 전역 변수
 *=========================================================================*/

LPDIRECT3D9			g_pD3D = NULL;			// D3D 디바이스를 생성할 D3D 객체 변수
LPDIRECT3DDEVICE9	g_pd3dDevice = NULL;	// 랜더링에 사용될 D3D 디바이스

LPDIRECT3DVERTEXBUFFER9 g_FirstVB = NULL; //사각형 정점 보관
LPDIRECT3DVERTEXBUFFER9 g_SecondVB = NULL; //삼각형 정점 보관
LPDIRECT3DVERTEXBUFFER9 g_ThirdVB = NULL; //평행사변형 정점 보관

struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw; //(rhw 값이 있으면 변환이 완료된 정점이다.)
	DWORD color;
};

// 사용자 정점 구조체에 관한 정보를 나타내는 FVF값
// 구조체는 x, y, z, RHW 값과 Diffuse 색깔 값으로 이루어져 있음을 알 수 있다.
// D3DFVF_DIFFUSE 옵션으로 꼭지점이 정해져 있다는걸 알려준다.
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

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

	D3DPRESENT_PARAMETERS	d3dpp;				// 디바이스 생성을 위한 구조체
	ZeroMemory(&d3dpp, sizeof(d3dpp));			// 반드시 ZeroMemory() 함수로 미리 구조체를 깨끗이 지워야 한다.

	d3dpp.Windowed = TRUE;						// 창 모드로 생성
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// 가장 효율적인 SWAP 효과
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;	// 현재 바탕화면 모드에 맞춰서 후면 버퍼를 생성.

	// 디바이스를 설정해서 생성
	// 디폴트 비디오카드를 사용하고, HAL 디바이스를 생성한다.
	// 정점 처리는 모든 카드에서 지원하는 SW처리로 생성한다.
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
	{
		return E_FAIL;
	}
	// 디바이스 상태 정보를 처리할 경우 여기에서 한다.

	return S_OK;
}

//사각형 Init
HRESULT InitFirstVB()
{
	//->그리는 순서(점찍는 순서에 주의)
	CUSTOMVERTEX vertices[] =
	{
		// x, y, z, rhw, color
		{ 125.0f, 150.0f, 0.5f, 1.0f, 0xff00ffff, }, //LeftTop 0
		{ 350.0f, 150.0f, 0.5f, 1.0f, 0xffff0000, }, //RightTop 1
		{ 125.0f, 350.0f, 0.5f, 1.0f, 0xff00ffff, }, //LeftBottom 2
		{ 350.0f, 350.0f, 0.5f, 1.0f, 0xff00fff0, } //RightBottom 3

		/*
			0------------------------------------1
		   │                                   │
		   │                                   │
		   │                                   │
			2------------------------------------3
		*/
	};

	// 정점 버퍼를 생성한다.
	// 정점 구조체 4개를 저장할 메모리를 할당한다.
	// FVF를 지정하여 보관할 데이터의 형식을 지정한다.
	//->n * sizeof(CUSTOMVETEX) 갯수 주의!!!
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(4 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_FirstVB, NULL)))
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

	memcpy(pVertices, vertices, sizeof(vertices));
	//UnLock해줘야 Render사용가능
	g_FirstVB->Unlock();

	return S_OK;
}

//삼각형 Init
HRESULT InitSecondVB()
{
	//->그리는 순서(점찍는 순서에 주의)
	CUSTOMVERTEX vertices[] =
	{
		// x, y, z, rhw, color
		{ 400.0f, 350.0f, 0.5f, 1.0f, 0xfff00000, }, //v1
		{ 525.0f, 300.0f, 0.5f, 1.0f, 0xff0fffff, }, //v2
		{ 525.0f, 350.0f, 0.5f, 1.0f, 0xffffffff, }, //v3
	};

	if (FAILED(g_pd3dDevice->CreateVertexBuffer(3 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_SecondVB, NULL)))
	{
		return E_FAIL;
	}
	void* pVertices;

	if (FAILED(g_SecondVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	memcpy(pVertices, vertices, sizeof(vertices));
	g_SecondVB->Unlock();

	return S_OK;
}

//삼각형 Init
HRESULT InitThirdVB()
{
	//->그리는 순서(점찍는 순서에 주의)
	CUSTOMVERTEX vertices[] =
	{
		// x, y, z, rhw, color
		{ 750.0f, 250.0f, 0.5f, 1.0f, 0xfff00000, }, //v1
		{ 850.0f, 200.0f, 0.5f, 1.0f, 0xff0fffff, }, //v2
		{ 850.0f, 300.0f, 0.5f, 1.0f, 0xff0fffff, }, //v3
		{ 750.0f, 350.0f, 0.5f, 1.0f, 0xffffffff, }, //v4
		{ 650.0f, 300.0f, 0.5f, 1.0f, 0xffffffff, }, //v5
		{ 650.0f, 200.0f, 0.5f, 1.0f, 0xffffffff, }, //v6
		{ 750.0f, 150.0f, 0.5f, 1.0f, 0xffffffff, }, //v7
		{ 850.0f, 200.0f, 0.5f, 1.0f, 0xffffffff, }, //v8
	};

	if (FAILED(g_pd3dDevice->CreateVertexBuffer(8 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_ThirdVB, NULL)))
	{
		return E_FAIL;
	}
	void* pVertices;

	if (FAILED(g_ThirdVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	memcpy(pVertices, vertices, sizeof(vertices));
	g_ThirdVB->Unlock();

	return S_OK;
}

HRESULT InitGeometry()
{
	if (FAILED(InitFirstVB()))
	{
		return E_FAIL;
	}
	if (FAILED(InitSecondVB()))
	{
		return E_FAIL;
	}
	if (FAILED(InitThirdVB()))
	{
		return E_FAIL;
	}
		

	return S_OK;
}

/**========================================================================
 * 초기화 객체들 Release
 *=========================================================================*/
void Cleanup()
{
	//해제 순서가 중요 인터페이스 생성의 역순으로 해제하자.
	//해체는 조립의 역순....
	if (g_ThirdVB != NULL)
		g_SecondVB->Release();

	if (g_SecondVB != NULL)
		g_SecondVB->Release();

	if (g_FirstVB != NULL)
		g_FirstVB->Release();

	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	if (g_pD3D != NULL)
		g_pD3D->Release();
}

/*******************************************************
		DrawPrimitive()
인자값:
PrimitiveType: 렌더링 하는 기본도형의 종류
StartVertex: 로드하는 최초의 정점의 인덱스
PrimitiveCount: 렌더링하는 기본도형의 수, 기본적으로 라인 리스트 경우 2개, 삼각형리스트인 경우 3개
*******************************************************/
/**========================================================================
 * 화면 그리기
 *=========================================================================*/
void Render()
{
	if (NULL == g_pd3dDevice)
		return;

	// 후면 버퍼를 파란색(0, 0, 255)으로 지운다.
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	
	// 랜더링 시작
	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		//실제 렌더링 명령들이 나열될 곳

		//사각형
		// 정점 정보가 담겨 있는 정점 버퍼를 출력 스트림으로 할당한다.
		g_pd3dDevice->SetStreamSource(0, g_FirstVB, 0, sizeof(CUSTOMVERTEX));
		// D3D에게 정점 셰이더 정보를 지정한다. 대부분의 경우에는 FVF만 지정한다.
		g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

		//삼각형
		g_pd3dDevice->SetStreamSource(0, g_SecondVB, 0, sizeof(CUSTOMVERTEX));
		g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

		//
		g_pd3dDevice->SetStreamSource(0, g_ThirdVB, 0, sizeof(CUSTOMVERTEX));
		g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
		g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, 0, 6);

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
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"D3D Triangle", NULL };

	//winclass 레지스터에 등록
	RegisterClassEx(&wc);

	HWND hWnd = CreateWindow("D3D Triangle", "D3D Triangle", WS_OVERLAPPEDWINDOW, 100, 100, 1024, 768,
		GetDesktopWindow(), NULL, NULL, wc.hInstance, NULL);

	if (SUCCEEDED(InitD3D(hWnd)))
	{
		if (SUCCEEDED(InitGeometry()))
		{
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
				{
					Render();
				}
			}
		}
	}

	//등록된 레지스트 winclass 릴리즈.
	UnregisterClass("D3D Triangle", wc.hInstance);
	return 0;
}

