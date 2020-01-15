#include "EngineMain.h"
#include "SceneManager.h"
#include "GlobalDefine.h"


namespace DoEngine
{
	//default
	EngineMain::EngineMain()
	{

	}

	//생성자
	EngineMain::EngineMain(string _title, int _cx, int _cy)
	{
		m_strTitle = _title;
		m_winSizeX = _cx;
		m_winSizeY = _cy;
	}

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	HINSTANCE g_hInst;

	//엔진 시작
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
		WndClass.lpszMenuName = NULL; //메뉴 추가
		WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		RegisterClass(&WndClass);

		HWND hWnd = CreateWindow(m_strTitle.c_str(), m_strTitle.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
		ShowWindow(hWnd, SW_SHOWDEFAULT);

		SceneManager::get_Instance()->Init(hWnd, m_winSizeX, m_winSizeY);

		while (true)
		{
			/// 메시지큐에 메시지가 있으면 메시지 처리
			if (PeekMessage(&Message, NULL, 0U, 0U, PM_REMOVE))
			{
				if (Message.message == WM_QUIT)
					break;

				TranslateMessage(&Message);
				DispatchMessage(&Message);
			}
			else
			{
				//SceneManager가 끝이 나면 윈도우를 닫는다. 즉 종료한다
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

	//소멸자
	EngineMain::~EngineMain()
	{

	}
}