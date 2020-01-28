/**========================================================================
 * KeyFrameAnimation
 * 선형 보간을 이용한 애니메이션 처리
 *=========================================================================*/

#include <d3d9.h>
#include <d3dx9.h>
#include "defines.h"

 /**========================================================================
  * 전역 변수
  *=========================================================================*/

LPDIRECT3D9				g_pD3D = NULL;
LPDIRECT3DDEVICE9		g_pd3dDevice = NULL;
LPDIRECT3DVERTEXBUFFER9	g_pVB = NULL;
LPDIRECT3DINDEXBUFFER9	g_pIB = NULL;

D3DXMATRIXA16			g_TMParent; //부모의 기본 행렬
D3DXMATRIXA16			g_RParent; //부모의 회전 행렬

D3DXMATRIXA16			g_TMChild; //자식의 기본 행렬
D3DXMATRIXA16			g_RChild; //자식의 회전 행렬

RECT rc; //폰트 출력
LPD3DXFONT pFont = NULL;


//부모 회전
float g_ParentRot = 0.0f;
//부모 이동
float g_ParentPos = 0.0f;
//자식 회전
float g_ChildRot = 0.0f;
//오토 회전
bool isAuto = false;

struct CUSTOMVERTEX
{
	FLOAT x, y, z;
	DWORD color;
};

#define ROT_DELTA 0.1f;
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)


struct MYINDEX
{
	WORD _0, _1, _2;
};

D3DXVECTOR3			g_aniPos[2];
D3DXQUATERNION		g_aniRot[2];

/**========================================================================
 * Direct3D 초기화 - 건들 필요 x
 *=========================================================================*/
HRESULT InitD3D(HWND hWnd)
{
	if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
	{
		return E_FAIL;
	}

	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	D3DXCreateFont(g_pd3dDevice, -20, 0, FW_DONTCARE, 1, FALSE, DEFAULT_CHARSET,OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "System", &pFont);

	return S_OK;
}

/**========================================================================
 * 정점 버퍼
 * 정점 버퍼를 생성하고 정점값을 채워넣는다.
 *=========================================================================*/

HRESULT InitVB()
{
	CUSTOMVERTEX vertices[] =
	{
		{0, 1, 0, 0xffff0d00},	//v0
		{ -1, 0, 1, 0xff00ffd0}, //v1
		{ 1, 0, 1, 0xff000dff}, //v2
		{-1, 0,-1, 0xfffff000}, //v3
		{1, 0, -1, 0xfff00000}, //v4
		{0, -1, 0, 0xfff00000}, //v5
	};

	if (FAILED(g_pd3dDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_pVB, NULL)))
	{
		return E_FAIL;
	}

	void* pVertices;

	if (FAILED(g_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
		return E_FAIL;

	memcpy(pVertices, vertices, sizeof(vertices));

	g_pVB->Unlock();

	return S_OK;
}

/**========================================================================
 * 인덱스 버퍼
 * 인덱스 버퍼를 생성하고 정점값을 채워넣는다.
 *=========================================================================*/

HRESULT InitIB()
{
	MYINDEX indices[] =
	{
		{1, 0, 3}, // 왼면(위)
		{5, 1, 3}, // 왼면

		{0, 2, 4}, // 오른면(위)
		{5, 4, 2}, // 오른면(아)

		{0, 1, 2}, // 앞면(위)
		{5, 2, 1}, // 앞면(아)

		{3, 0, 4}, // 뒷면(위)
		{5, 3, 4}, // 뒷면(아)
	};

	if (FAILED(g_pd3dDevice->CreateIndexBuffer(8 * sizeof(MYINDEX), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &g_pIB, NULL)))
	{
		return E_FAIL;
	}

	void** pIndices;

	if (FAILED(g_pIB->Lock(0, sizeof(indices), (void**)&pIndices, 0)))
	{
		return E_FAIL;
	}

	memcpy(pIndices, indices, sizeof(indices));

	g_pIB->Unlock();

	return S_OK;
}

/**========================================================================
 * 애니메이션 초기화 - 건들 필요 x
 *=========================================================================*/
void InitAnimation()
{
	g_aniPos[0] = D3DXVECTOR3(0, 0, 0); // 위치 변화에 사용 할 벡터 값
	g_aniPos[1] = D3DXVECTOR3(0, 5, -5); // 위치 변화에 사용 할 벡터 값

	FLOAT Yaw = D3DX_PI * 90.0f / 180.0f; // Y축 90도 회전
	FLOAT Pitch = 0;
	FLOAT Roll = 0;

	Yaw = 0;
	Pitch = D3DX_PI * 90.0f / 180.0f; // X축 90도 회전
	Roll = 0;
}

/**========================================================================
 * 기하 정보 초기화 - 건들 필요 x
 *=========================================================================*/

HRESULT InitGeometry()
{
	if (FAILED(InitVB()))
		return E_FAIL;

	if (FAILED(InitIB()))
		return E_FAIL;

	InitAnimation();

	return S_OK;
}

/**========================================================================
 * 카메라 행렬 설정
 *=========================================================================*/
void SetupCamera()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

	D3DXVECTOR3 vEyePt(0.0f, 10.0f, -20.0f);
	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);

	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}

/**========================================================================
 * 애니메이션 행렬 생성
 *=========================================================================*/
void Animate()
{
	static float t = 0;
	D3DXQUATERNION quat;
	float x, y, z;

	if (t > 1.0f)
		t = 0.0f;

	D3DXVECTOR3 v;
	//이동값의 선형 보간 aniPos[1] -------> aniPos[2]로 이동
	D3DXVec3Lerp(&v, &g_aniPos[0], &g_aniPos[1], t);
	//이동 행렬값으로 변환(부모 이동)
	D3DXMatrixTranslation(&g_TMParent, v.x + g_ParentPos, v.y, v.z);

	//회전값의 구면 선형 보간(부모와 자식간의 간격 or 오브젝트와 오브젝트 사이의 간격)
	D3DXQuaternionSlerp(&quat, &g_aniRot[0], &g_aniRot[1], t);

	//요(y축을 중심으로 하는 Yaw)·피치(x축을 중심으로 하는 pitch)·롤(z축을 중심으로 하는 roll)을 지정해 쿼터니온을 생성
	//부모 회전
	D3DXQuaternionRotationYawPitchRoll(&quat, g_ParentRot, 0, 0);
	//사원수를 회전 행렬값으로 변환
	D3DXMatrixRotationQuaternion(&g_RParent, &quat);

	//스페이스 클릭시 부모 자동회전 
	if (isAuto)
	{
		g_ParentRot += 0.01;
		g_ChildRot += 0.01;
		t += 0.005;
	}

	//요(y축을 중심으로 하는 Yaw)·피치(x축을 중심으로 하는 pitch)·롤(z축을 중심으로 하는 roll)을 지정해 쿼터니온을 생성
	//자식의 회전
	D3DXQuaternionRotationYawPitchRoll(&quat, 0, g_ChildRot, 0);
	//사원수를 회전 행렬값으로 변환 -> 위의 메서드 (PitchRoll 선언 후 적용해주는 과정이 필요)
	D3DXMatrixRotationQuaternion(&g_RChild, &quat);

	//자식 메시는 원점으로 부터 (3, 3, 3)의 거리에 있다.
	D3DXMatrixTranslation(&g_TMChild, 5, 0, 0);
}

/**========================================================================
 * Release - 초기화 객체들 소거
 *=========================================================================*/
void Cleanup()
{
	if (g_pIB != NULL)
		g_pIB->Release();

	if (g_pVB != NULL)
		g_pVB->Release();

	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	if (g_pD3D != NULL)
		g_pD3D->Release();
}

/**========================================================================
 * 메시 그리기
 *=========================================================================*/
void DrawMesh(D3DXMATRIXA16* pMat)
{
	g_pd3dDevice->SetTransform(D3DTS_WORLD, pMat);
	g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	g_pd3dDevice->SetIndices(g_pIB);
	g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 6, 0, 8);
}

/**========================================================================
 * 화면 그리기
 *=========================================================================*/
void Render()
{
	D3DXMATRIXA16 matWorld;

	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	Animate();

	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		SetRect(&rc, 10, 10, 0, 0);
		pFont->DrawText(NULL, "부모 회전: 방향키(좌 , 우) ", -1, &rc, DT_NOCLIP, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		SetRect(&rc, 10, 30, 0, 0);
		pFont->DrawText(NULL, "부모 이동: F1(좌), F2(우)", -1, &rc, DT_NOCLIP, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		SetRect(&rc, 10, 50, 0, 0);
		pFont->DrawText(NULL, "자식 회전: 방향키 (위 , 아래)", -1, &rc, DT_NOCLIP, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		SetRect(&rc, 10, 70, 0, 0);
		pFont->DrawText(NULL, "자동 회전 시작/멈춤: SPACE", -1, &rc, DT_NOCLIP, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

		//그리는 순서가 아닌 행렬 적용 순서가 중요하다.
		//부모의 변환을 만든다 - 회전 * 기본 변환
		matWorld = g_RParent * g_TMParent;
		//적용된 변환을 기반으로 부모 객체를 그린다.
		DrawMesh(&matWorld);

		//자식의 변환을 만든다 - 자신의 회전 * 자신의 기본 변환 * 부모의 회전 * 부모의 기본변환
		matWorld = g_RChild * g_TMChild * g_RParent * g_TMParent;
		//적용된 변환을 기반으로 자식 객체를 그린다.
		DrawMesh(&matWorld);

		g_pd3dDevice->EndScene();
	}

	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

/**========================================================================
 * 윈도우 프로시저
 *=========================================================================*/
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		Cleanup();
		PostQuitMessage(0);
		return 0;

	case WM_KEYDOWN:
		if (wParam == VK_LEFT)
		{
			g_ParentRot -= ROT_DELTA;
		}
		if (wParam == VK_RIGHT)
		{
			g_ParentRot += ROT_DELTA;
		}	
		if (wParam == VK_UP)
		{
			g_ChildRot -= ROT_DELTA;
		}
		if (wParam == VK_DOWN)
		{
			g_ChildRot += ROT_DELTA;

		}
		if (wParam == VK_F1)
		{
			g_ParentPos -= ROT_DELTA;
		}
		if (wParam == VK_F2)
		{
			g_ParentPos += ROT_DELTA;
		}

		if (wParam == VK_SPACE)
		{
			if (!isAuto)
			{
				isAuto = true;
			}
			else
			{
				isAuto = false;
			}
		}

		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

/**========================================================================
 * WinMain
 *=========================================================================*/
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc,
		0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"D3D Animation", NULL };

	RegisterClassEx(&wc);

	HWND hWnd = CreateWindow("D3D Animation", "D3D Animation", WS_OVERLAPPEDWINDOW,
		100, 100, 1500, 1000, GetDesktopWindow(), NULL, wc.hInstance, NULL);

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
				{
					Render();
				}
			}
		}
	}

	UnregisterClass("D3D Animation", wc.hInstance);
	return 0;
}