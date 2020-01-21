#include <d3d9.h>
#include <d3dx9.h>

 /**========================================================================
  * ���� ����
  *=========================================================================*/
LPDIRECT3D9	g_pD3D = NULL; //IDeirectX3D9 interface�� typedef�� ��������
LPDIRECT3DDEVICE9 g_pd3dDevice = NULL; //�׷��� ī���� �߻�ȭ��� �Ѵ�.

//����ü(1)
LPDIRECT3DVERTEXBUFFER9 g_FirstVB = NULL; //������ ������ ����
LPDIRECT3DINDEXBUFFER9 g_FirstIB = NULL; // �ε����� ������ �ε��� ����
//�簢��
LPDIRECT3DVERTEXBUFFER9 g_SecondVB = NULL; //������ ������ ����
LPDIRECT3DINDEXBUFFER9 g_SecondIB = NULL; // �ε����� ������ �ε��� ����
//����ü(2)
LPDIRECT3DVERTEXBUFFER9 g_ThirdVB = NULL; //������ ������ ����
LPDIRECT3DINDEXBUFFER9 g_ThirdIB = NULL; // �ε����� ������ �ε��� ����

struct CUSTOMVERTEX
{
	FLOAT x, y, z;
	DWORD color;
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)

//�ε����� ���ڰ� 3��!!!!
struct MYINDEX
{
	WORD _0, _1, _2;	// �Ϲ������� �ε����� 16��Ʈ�� ũ�⸦ ���´�.
};

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

	D3DPRESENT_PARAMETERS	d3dpp; //����̽� ������ ���� ����ü
	ZeroMemory(&d3dpp, sizeof(d3dpp)); //�ݵ�� ����ü�� ����.

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; //���� ȿ������ swapȿ��
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	d3dpp.EnableAutoDepthStencil = TRUE; // ���̰� �ִ� z���۰� �ʿ��ϹǷ� �����Ѵ�.
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	// ����̽��� �����ؼ� ����
	// ����Ʈ ����ī�带 ����ϰ�, HAL ����̽��� �����Ѵ�.
	// ���� ó���� ��� ī�忡�� �����ϴ� SWó���� �����Ѵ�.
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
	{
		return E_FAIL;
	}

	//�ø������ ����. �ﰢ���� �ո�, �޸��� ��� �������Ѵ�. �ø�: ī�޶� ���� �ִ� ���⸸ ������ �ϴ°�
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	//Z(����) ���� ����� �Ҵ�.
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	//������ ������ �����Ƿ� ���� ����� ����.
	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	return S_OK;
}

/**========================================================================
 * ���� �ʱ�ȭ : ���� ���۸� �����ϰ� �������� ä�� �ִ´�.
 *=========================================================================*/
HRESULT InitVB()
{
	// ����(cube)�� �������ϱ� ���� 8���� ���� ����
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

	// ���� ���۸� �����Ѵ�.
	// ���� ����ü 3���� ������ �޸𸮸� �Ҵ��Ѵ�.
	// FVF�� �����Ͽ� ������ �������� ������ �����Ѵ�.
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(8 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_FirstVB, NULL)))
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

	//�޸� ī��
	memcpy(pVertices, vertices, sizeof(vertices));
	//UnLock����� Render��밡��
	g_FirstVB->Unlock();
}

/**========================================================================
 * �ε��� ���� ����
 *=========================================================================*/
HRESULT InitIB()
{
	MYINDEX indices[] =
	{
		{0, 1, 2}, {0, 2, 3}, // ����
		{4, 5, 6}, {4, 7, 6}, // �Ʒ���
		{0, 3, 7}, {0, 7, 4}, // �޸�
		{1, 5, 6}, {1, 6, 2}, // ������
		{3, 2, 6}, {3, 6, 7}, // �ո�
		{0, 4, 5}, {0, 5, 1}, // �޸�
	};

	//�ε��� ���� ����
	//D3DFMT_INDEX16�� �ε����� ������ 16��Ʈ��� ��.
	//MYINDEX ����ü���� WORD������ �������Ƿ� D3DFMT_INDEX16�� ����Ѵ�.
	if (FAILED(g_pd3dDevice->CreateIndexBuffer(12 * sizeof(MYINDEX), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &g_FirstIB, NULL)))
	{
		return E_FAIL;
	}

	//�ε��� ���۸� ������ ä���.
	void* pIndices;

	//�ε��� ������ Lock() �Լ��� ȣ���Ͽ� �����͸� ���ͼ� ������ ä���.
	if (FAILED(g_FirstIB->Lock(0, sizeof(indices), (void**)&pIndices, 0)))
	{
		return E_FAIL;
	}

	//�޸� ī��
	memcpy(pIndices, indices, sizeof(indices));

	//UnLock����� Render��밡��
	g_FirstIB->Unlock();

	return S_OK;
}


/**========================================================================
 * ���� �ʱ�ȭ : ���� ���۸� �����ϰ� �������� ä�� �ִ´�.
 *=========================================================================*/
HRESULT InitVB_Second()
{
	// ����(cube)�� �������ϱ� ���� 8���� ���� ����
	CUSTOMVERTEX vertices[] =
	{
		{0, 1, 0, 0xffff0d00},	//v0
		{ -1, 0, 1, 0xff00ffd0}, //v1
		{ 1, 0, 1, 0xff000dff}, //v2
		{-1, 0,-1, 0xfffff000}, //v3
		{1, 0, -1, 0xfff00000}, //v4
	};

	// ���� ���۸� �����Ѵ�.
	// ���� ����ü 3���� ������ �޸𸮸� �Ҵ��Ѵ�.
	// FVF�� �����Ͽ� ������ �������� ������ �����Ѵ�.
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(5 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_SecondVB, NULL)))
	{
		return E_FAIL;
	}

	//������ ���۸� ������ ä���.
	//���� ������ Lock() �Լ��� ȣ���Ͽ� �����͸� ���´�.
	void* pVertices;

	if (FAILED(g_SecondVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	//�޸� ī��
	memcpy(pVertices, vertices, sizeof(vertices));
	//UnLock����� Render��밡��
	g_SecondVB->Unlock();

	return S_OK;
}

/**========================================================================
 * �ε��� ���� ����
 *=========================================================================*/
HRESULT InitIB_Second()
{
	MYINDEX indices[] =
	{
		{1, 0, 3}, // �޸�
		{0, 2, 4}, // ������
		{1, 0, 2}, // �ո�
		{3, 0, 4}, // �޸�
		{2, 1, 3}, {3, 4, 2}, // �Ʒ���
	};

	//�ε��� ���� ����
	//D3DFMT_INDEX16�� �ε����� ������ 16��Ʈ��� ��.
	//MYINDEX ����ü���� WORD������ �������Ƿ� D3DFMT_INDEX16�� ����Ѵ�.
	if (FAILED(g_pd3dDevice->CreateIndexBuffer(6 * sizeof(MYINDEX), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &g_SecondIB, NULL)))
	{
		return E_FAIL;
	}

	//�ε��� ���۸� ������ ä���.
	void* pIndices;

	//�ε��� ������ Lock() �Լ��� ȣ���Ͽ� �����͸� ���ͼ� ������ ä���.
	if (FAILED(g_SecondIB->Lock(0, sizeof(indices), (void**)&pIndices, 0)))
	{
		return E_FAIL;
	}
	//�޸� ī��
	memcpy(pIndices, indices, sizeof(indices));
	//UnLock����� Render��밡��
	g_SecondIB->Unlock();

	return S_OK;
}

/**========================================================================
 * ���� �ʱ�ȭ : ���� ���۸� �����ϰ� �������� ä�� �ִ´�.
 *=========================================================================*/
HRESULT InitVB_Third()
{
	// ����(cube)�� �������ϱ� ���� 8���� ���� ����
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

	// ���� ���۸� �����Ѵ�.
	// ���� ����ü 3���� ������ �޸𸮸� �Ҵ��Ѵ�.
	// FVF�� �����Ͽ� ������ �������� ������ �����Ѵ�.
	if (FAILED(g_pd3dDevice->CreateVertexBuffer(8 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_ThirdVB, NULL)))
	{
		return E_FAIL;
	}

	//������ ���۸� ������ ä���.
	//���� ������ Lock() �Լ��� ȣ���Ͽ� �����͸� ���´�.
	void* pVertices;

	if (FAILED(g_ThirdVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	//�޸� ī��
	memcpy(pVertices, vertices, sizeof(vertices));
	//UnLock����� Render��밡��
	g_ThirdVB->Unlock();

	return S_OK;
}

/**========================================================================
 * �ε��� ���� ����
 *=========================================================================*/
HRESULT InitIB_Third()
{
	MYINDEX indices[] =
	{
		{0, 1, 2}, {0, 2, 3}, // ����
		{5, 4, 6}, {4, 7, 6}, // �Ʒ���
		{0, 3, 7}, {0, 7, 4}, // �޸�
		{1, 5, 6}, {1, 6, 2}, // ������
		{3, 2, 6}, {3, 6, 7}, // �ո�
		{0, 4, 5}, {0, 5, 1}, // �޸�
	};

	//�ε��� ���� ����
	//D3DFMT_INDEX16�� �ε����� ������ 16��Ʈ��� ��.
	//MYINDEX ����ü���� WORD������ �������Ƿ� D3DFMT_INDEX16�� ����Ѵ�.
	if (FAILED(g_pd3dDevice->CreateIndexBuffer(12 * sizeof(MYINDEX), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &g_ThirdIB, NULL)))
	{
		return E_FAIL;
	}

	//�ε��� ���۸� ������ ä���.
	void* pIndices;

	//�ε��� ������ Lock() �Լ��� ȣ���Ͽ� �����͸� ���ͼ� ������ ä���.
	if (FAILED(g_ThirdIB->Lock(0, sizeof(indices), (void**)&pIndices, 0)))
	{
		return E_FAIL;
	}
	//�޸� ī��
	memcpy(pIndices, indices, sizeof(indices));
	//UnLock����� Render��밡��
	g_ThirdIB->Unlock();

	return S_OK;
}


/**========================================================================
 * ���� ���� �ʱ�ȭ
 * ���� ������ŭ ���� ���ۿ� �ε��� ���۸� �����Ѵ�.
 * �ڵ忡�� �簢��1, �ﰢ�� 1
 *=========================================================================*/
HRESULT InitGeometry()
{
	//ù��° VerTexBuffer
	if (FAILED(InitVB()))
	{
		return E_FAIL;
	}
	//ù��° IndexBuffer
	if (FAILED(InitIB()))
	{
		return E_FAIL;
	}
	//�ι�° VerTexBuffer
	if (FAILED(InitVB_Second()))
	{
		return E_FAIL;
	}
	//�ι�° IndexBuffer
	if (FAILED(InitIB_Second()))
	{
		return E_FAIL;
	}
	//����° VerTexBuffer
	if (FAILED(InitVB_Third()))
	{
		return E_FAIL;
	}
	//����° IndexBuffer
	if (FAILED(InitIB_Third()))
	{
		return E_FAIL;
	}
		
	return S_OK;
}

/**========================================================================
 * ī�޶� ��� ����
 *=========================================================================*/
void SetupCamera()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld); //���� �����̽��� ����
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld); //���� �����̽��� ����̽��� �����Ѵ�.

	//�� ���(ī�޶�)�� �����ϱ� ���ؼ��� 3���� ���� �ʿ��ϴ�.
	D3DXVECTOR3 vEyePt(0.0f, 10.0f, -20.0f);						//���� ��ġ(0.0f, 10.0f, -20.0f)
	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);						// ���� �ٶ󺸴� ��ġ(0.0f, 0.0f, 0.0f)
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);							// �� ������ ��Ÿ���� ��� ����(0.0f, 1.0f, 0.0f)

	D3DXMATRIXA16 matView;
	// 3���� Point�� �̿��� �� ����� �����Ѵ�.
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);		//��� ��Ŀ� ī�޶� ���� ��ġ, ����, ���͸� �����Ѵ�.
	g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);				// ������ �� ����� ����̽��� �����Ѵ�.

	// �������� ����� �����ϱ� ���ؼ��� �þ߰�(FOV = Field Of View)�� ��Ⱦ��(aspect ratio), Ŭ���� ����� ���� �ʿ��ϴ�.
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);			//������ �������� ����� ����̽��� ����.
}

/**========================================================================
 * �޽� �׸���
 *=========================================================================*/
void DrawMesh(D3DXMATRIXA16* pMat, LPDIRECT3DVERTEXBUFFER9 _vertexBuffer, LPDIRECT3DINDEXBUFFER9 _IndexBuffer, int _count)
{
		/*
		��Ʈ���� ����ü�� ������, ȸ�� ����, ȸ�� ���� �̹Ƿ�, �����Ⱑ �������� ��������. TickCount�� 1000�϶�, TickCount/100 = 10(����), TickCount/500 = 2(����)
		D3DXMatrixRotationX -> x��
		D3DXMatrixRotationY -> y��
		D3DXMatrixRotationZ -> z��
		*/
		// ���� ������ ����ϱ� ���� DrawIndexPrimitive() �Լ��� ȣ���Ѵ�.
		// ù ��° : �׸����� �ϴ� �⺻ Ÿ����
		// �� ��° : ���� ������Ʈ�� �ϳ��� ������ ������ �ѹ�.
		// �� ��° : ������ �ּ� �ε��� ��
		// �� ��° : �̹� ȣ�⿡ ������ ���ؽ��� ��
		// �ټ� ��° : �ε��� ���� ������ �б⸦ ������ ��ҷ��� �ε���
		// ���� ��° : �׸����� �ϴ� �⺻���� ��
		//g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
	//D3DXMatrixRotationY(pMat, GetTickCount() / 500.0f);
	g_pd3dDevice->SetTransform(D3DTS_WORLD, pMat); //������ ȸ�� ����� ���� ��ķ� ����̽��� �����Ѵ�.
	g_pd3dDevice->SetStreamSource(0, _vertexBuffer, 0, sizeof(CUSTOMVERTEX)); //�ٸ� ���³� ũ���� �׸��� �׸��� ���ؼ� �ݵ�� ����������Ѵ�.
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	g_pd3dDevice->SetIndices(_IndexBuffer); //�ε��� ���۸� �ҷ��´�.
	g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, _count);
}

/**========================================================================
 * �ʱ�ȭ ��ü�� Release
 *=========================================================================*/
void Cleanup()
{
	//���� ������ �߿� �������̽� ������ �������� ��������.
	//��ü�� ������ ����....
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
 * ȭ�� �׸���
 *=========================================================================*/
void Render()
{
	if (NULL == g_pd3dDevice)
	{
		return;
	}

	D3DXMATRIXA16 matWorld;
	//��ġ
	D3DXMATRIXA16 g_Squre; //�簢��1
	D3DXMATRIXA16 g_Squre_pyramid; //�簢��
	D3DXMATRIXA16 g_Squre_Second; //�簢��2

	//ȸ��
	D3DXMATRIXA16 rSqure; //�簢��1
	D3DXMATRIXA16 rSqure_pyramid; //�簢��
	D3DXMATRIXA16 rSqure_Second; //�簢��2

	// �ĸ� ���۸� �Ķ���(0, 0, 255)���� ����� Z���۸� ����ϱ� ���� �ʱ�ȭ �Ѵ�.
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	D3DXMatrixIdentity(&g_Squre);//����(0,0,0)�� ù��° �簢���� ��ġ�Ѵ�.

	D3DXMatrixRotationY(&rSqure, GetTickCount() / 500.0f);			//�簢�� ȸ��
	D3DXMatrixRotationZ(&rSqure_pyramid, GetTickCount() / 500.0f);	//�簢�� ȸ��
	D3DXMatrixRotationX(&rSqure_Second, GetTickCount() / 500.0f);	//�簢�� ȸ��

	D3DXMatrixTranslation(&g_Squre_pyramid, 3, 3, 3); //�ι�° �簢���� 0,0,0���� �� ������ 3��ŭ ������ ���� �ι�° �簢���� ��ġ
	D3DXMatrixTranslation(&g_Squre_Second, -3, -3, -6); //����° �簢���� 0,0,0���� �� ������ 3��ŭ ������ ���� ����° �簢���� ��ġ
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	
	// ������ ����
	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		//ũ��->����->�̵�->���� ������ �����Ѵ�!
		matWorld = rSqure * g_Squre;
		DrawMesh(&matWorld, g_FirstVB, g_FirstIB, 12);

		matWorld = rSqure_pyramid * g_Squre_pyramid;
		DrawMesh(&matWorld, g_SecondVB, g_SecondIB, 6);

		matWorld = rSqure_Second * g_Squre_Second;
		DrawMesh(&matWorld, g_ThirdVB, g_ThirdIB, 12);

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
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "D3D IndexBuffer", NULL };

	//winclass �������Ϳ� ���
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

	//��ϵ� ������Ʈ winclass ������.
	UnregisterClass("D3D IndexBuffer", wc.hInstance);
	return 0;
}



