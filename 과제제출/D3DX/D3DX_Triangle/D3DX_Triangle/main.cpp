/**========================================================================
 * ����̽� ����
 * D3D ����̽��� �����ϰ�, �̸� ����ؼ� ȭ���� ����� ����� ���ؼ� �����ϰ� �ȴ�.
 *=========================================================================*/

 // Direct3D9�� ����ϱ� ���� ���
#include <d3d9.h>
#include <d3dx9.h>

/**========================================================================
 * ���� ����
 *=========================================================================*/

LPDIRECT3D9			g_pD3D = NULL;			// D3D ����̽��� ������ D3D ��ü ����
LPDIRECT3DDEVICE9	g_pd3dDevice = NULL;	// �������� ���� D3D ����̽�

LPDIRECT3DVERTEXBUFFER9 g_FirstVB = NULL; //�簢�� ���� ����
LPDIRECT3DVERTEXBUFFER9 g_SecondVB = NULL; //�ﰢ�� ���� ����
LPDIRECT3DVERTEXBUFFER9 g_ThirdVB = NULL; //������ ���� ����
LPDIRECT3DVERTEXBUFFER9 g_OrionVB = NULL; //������ ���� ����

struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw; //(rhw ���� ������ ��ȯ�� �Ϸ�� �����̴�.)
	DWORD color;
};

// ����� ���� ����ü�� ���� ������ ��Ÿ���� FVF��
// ����ü�� x, y, z, RHW ���� Diffuse ���� ������ �̷���� ������ �� �� �ִ�.
// D3DFVF_DIFFUSE �ɼ����� �������� ������ �ִٴ°� �˷��ش�.
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

/**========================================================================
 * Direct3D �ʱ�ȭ
 *=========================================================================*/
HRESULT InitD3D(HWND hWnd)
{
	// ����̽��� �����ϱ� ���� D3D ��ü ����
	if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS	d3dpp;				// ����̽� ������ ���� ����ü
	ZeroMemory(&d3dpp, sizeof(d3dpp));			// �ݵ�� ZeroMemory() �Լ��� �̸� ����ü�� ������ ������ �Ѵ�.

	d3dpp.Windowed = TRUE;						// â ���� ����
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// ���� ȿ������ SWAP ȿ��
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;	// ���� ����ȭ�� ��忡 ���缭 �ĸ� ���۸� ����.

	// ����̽��� �����ؼ� ����
	// ����Ʈ ����ī�带 ����ϰ�, HAL ����̽��� �����Ѵ�.
	// ���� ó���� ��� ī�忡�� �����ϴ� SWó���� �����Ѵ�.
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
	{
		return E_FAIL;
	}
	// ����̽� ���� ������ ó���� ��� ���⿡�� �Ѵ�.

	return S_OK;
}

//�簢�� Init
HRESULT InitFirstVB()
{
	//->�׸��� ����(����� ������ ����)
	CUSTOMVERTEX vertices[] =
	{
		// x, y, z, rhw, color
		{ 125.0f, 150.0f, 0.5f, 1.0f, 0xff00ffff, }, //LeftTop 0
		{ 350.0f, 150.0f, 0.5f, 1.0f, 0xffff0000, }, //RightTop 1
		{ 125.0f, 350.0f, 0.5f, 1.0f, 0xff00ffff, }, //LeftBottom 2
		{ 350.0f, 350.0f, 0.5f, 1.0f, 0xff00fff0, } //RightBottom 3

		/*
			0------------------------------------1
		   ��                                   ��
		   ��                                   ��
		   ��                                   ��
			2------------------------------------3
		*/
	};

	// ���� ���۸� �����Ѵ�.
	// ���� ����ü 4���� ������ �޸𸮸� �Ҵ��Ѵ�.
	// FVF�� �����Ͽ� ������ �������� ������ �����Ѵ�.
	//->n * sizeof(CUSTOMVETEX) ���� ����!!!
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(4 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_FirstVB, NULL)))
	{
		return E_FAIL;
	}

	//������ ���۸� ������ ä���.
	//���� ������ Lock() �Լ��� ȣ���Ͽ� �����͸� ���´�.
	void* pVertices;

	if (FAILED(g_FirstVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	memcpy(pVertices, vertices, sizeof(vertices));
	//UnLock����� Render��밡��
	g_FirstVB->Unlock();

	return S_OK;
}

//�ﰢ�� Init
HRESULT InitSecondVB()
{
	//->�׸��� ����(����� ������ ����)
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

//�ﰢ�� Init
HRESULT InitThirdVB()
{
	//->�׸��� ����(����� ������ ����)
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

//�������ڸ� Init
HRESULT InitOrionVB()
{
	//->�׸��� ����(����� ������ ����)
	CUSTOMVERTEX vertices[] =
	{
		// x, y, z, rhw, color
		{ 200.0f, 400.0f, 0.5f, 1.0f, 0xfff00000, }, //v1
		{ 150.0f, 500.0f, 0.5f, 1.0f, 0xff0fffff, }, //v2
		{ 140.0f, 510.0f, 0.5f, 1.0f, 0xff0fffff, }, //v3
		{ 210.0f, 610.0f, 0.5f, 1.0f, 0xff0fffff, }, //v4
		{ 220.0f, 640.0f, 0.5f, 1.0f, 0xff0fffff, }, //v5
		{ 230.0f, 740.0f, 0.5f, 1.0f, 0xff0fffff, }, //v6
		{ 180.0f, 840.0f, 0.5f, 1.0f, 0xff0fffff, }, //v7
		{ 360.0f, 800.0f, 0.5f, 1.0f, 0xff0fffff, }, //v8
		{ 290.0f, 730.0f, 0.5f, 1.0f, 0xff0fffff, }, //v9
		{ 330.0f, 630.0f, 0.5f, 1.0f, 0xff0fffff, }, //v10
		{ 280.0f, 580.0f, 0.5f, 1.0f, 0xff0fffff, }, //v11
		{ 220.0f, 640.0f, 0.5f, 1.0f, 0xff0fffff, }, //v12
		{ 330.0f, 630.0f, 0.5f, 1.0f, 0xff0fffff, }, //v13
		{ 440.0f, 500.0f, 0.5f, 1.0f, 0xff0fffff, }, //v14
		{ 480.0f, 550.0f, 0.5f, 1.0f, 0xff0fffff, }, //v15
		{ 480.0f, 580.0f, 0.5f, 1.0f, 0xff0fffff, }, //v16
		{ 478.0f, 600.0f, 0.5f, 1.0f, 0xff0fffff, }, //v17
		{ 475.0f, 610.0f, 0.5f, 1.0f, 0xff0fffff, }, //v18
	};

	if (FAILED(g_pd3dDevice->CreateVertexBuffer(18 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_OrionVB, NULL)))
	{
		return E_FAIL;
	}
	void* pVertices;

	if (FAILED(g_OrionVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	memcpy(pVertices, vertices, sizeof(vertices));
	g_OrionVB->Unlock();

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
	if (FAILED(InitOrionVB()))
	{
		return E_FAIL;
	}
		

	return S_OK;
}

/**========================================================================
 * �ʱ�ȭ ��ü�� Release
 *=========================================================================*/
void Cleanup()
{
	//���� ������ �߿� �������̽� ������ �������� ��������.
	//��ü�� ������ ����....
	if (g_OrionVB != NULL)
		g_OrionVB->Release();

	if (g_ThirdVB != NULL)
		g_ThirdVB->Release();

	if (g_SecondVB != NULL)
		g_SecondVB->Release();

	if (g_FirstVB != NULL)
		g_FirstVB->Release();

	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	if (g_pD3D != NULL)
		g_pD3D->Release();
}

void Draw(LPDIRECT3DVERTEXBUFFER9 _vertexBuffer, _D3DPRIMITIVETYPE _type, int _figure)
{
	// ���� ������ ��� �ִ� ���� ���۸� ��� ��Ʈ������ �Ҵ��Ѵ�.
	g_pd3dDevice->SetStreamSource(0, _vertexBuffer, 0, sizeof(CUSTOMVERTEX));
	// D3D���� ���� ���̴� ������ �����Ѵ�. ��κ��� ��쿡�� FVF�� �����Ѵ�.
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	g_pd3dDevice->DrawPrimitive(_type, 0, _figure);
}

/*******************************************************
		DrawPrimitive()
���ڰ�:
PrimitiveType: ������ �ϴ� �⺻������ ����
StartVertex: �ε��ϴ� ������ ������ �ε���
PrimitiveCount: �������ϴ� �⺻������ ��, �⺻������ ���� ����Ʈ ��� 2��, �ﰢ������Ʈ�� ��� 3��
*******************************************************/
/**========================================================================
 * ȭ�� �׸���
 *=========================================================================*/
void Render()
{
	if (NULL == g_pd3dDevice)
		return;

	// �ĸ� ���۸� �Ķ���(0, 0, 255)���� �����.
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	
	// ������ ����
	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		//���� ������ ��ɵ��� ������ ��
		//�簢��
		Draw(g_FirstVB, D3DPT_TRIANGLESTRIP, 2);
		//�ﰢ��
		Draw(g_SecondVB, D3DPT_TRIANGLELIST, 1);
		//������
		Draw(g_ThirdVB, D3DPT_TRIANGLEFAN, 6);
		//������ �ڸ�
		Draw(g_OrionVB, D3DPT_LINESTRIP, 17);

		//������ ����
		g_pd3dDevice->EndScene();
	}

	// �ĸ� ���۸� ���̴� ȭ������ ��ȯ.
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
 * Window ����
 *=========================================================================*/
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
	//������ Ŭ���� ���
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "D3D Triangle", NULL };

	//winclass �������Ϳ� ���
	RegisterClassEx(&wc);

	HWND hWnd = CreateWindow("D3D Triangle", "D3D Triangle", WS_OVERLAPPEDWINDOW, 100, 0, 1024, 1000, GetDesktopWindow(), NULL, NULL, wc.hInstance, NULL);

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

	//��ϵ� ������Ʈ winclass ������.
	UnregisterClass("D3D Triangle", wc.hInstance);
	return 0;
}

