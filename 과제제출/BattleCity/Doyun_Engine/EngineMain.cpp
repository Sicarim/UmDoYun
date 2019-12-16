#include "EngineMain.h"
#include "SceneManager.h"
#include "GlobalDefine.h"


namespace DoEngine
{
	//default
	EngineMain::EngineMain()
	{

	}

	//������
	EngineMain::EngineMain(string _title, int _cx, int _cy)
	{
		m_strTitle = _title;
		m_winSizeX = _cx;
		m_winSizeY = _cy;
	}

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	HINSTANCE g_hInst;

	//���� ����
	int EngineMain::StartEngine(HINSTANCE hInstance)
	{
		MSG Message;
		WNDCLASS WndClass;
		g_hInst = hInstance;

		WndClass.cbClsExtra = 0;
		WndClass.cbWndExtra = 0;
		WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WndClass.hInstance = hInstance;
		WndClass.lpfnWndProc = WndProc;
		WndClass.lpszClassName = m_strTitle.c_str();
		WndClass.lpszMenuName = NULL; //�޴� �߰�
		WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		RegisterClass(&WndClass);

		HWND hWnd = CreateWindow(m_strTitle.c_str(), m_strTitle.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
		ShowWindow(hWnd, SW_SHOWDEFAULT);

		SceneManager::get_Instance()->Init(hWnd, m_winSizeX, m_winSizeY);

		while (true)
		{
			/// �޽���ť�� �޽����� ������ �޽��� ó��
			if (PeekMessage(&Message, NULL, 0U, 0U, PM_REMOVE))
			{
				if (Message.message == WM_QUIT)
					break;

				TranslateMessage(&Message);
				DispatchMessage(&Message);
			}
			else
			{
				//SceneManager�� ���� ���� �����츦 �ݴ´�. �� �����Ѵ�
				if (SceneManager::get_Instance()->Update())
				{
					SendMessage(hWnd, WM_DESTROY, 0, 0);
				}
			}
		}

		SceneManager::get_Instance()->Release();

		return (int)Message.wParam;
	}

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		switch (iMessage)
		{

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return(DefWindowProc(hWnd, iMessage, wParam, lParam));
	}

	//�Ҹ���
	EngineMain::~EngineMain()
	{

	}
}