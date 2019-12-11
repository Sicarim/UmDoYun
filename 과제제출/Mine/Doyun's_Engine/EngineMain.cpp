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

	//윈도우 리소드 등록
	void EngineMain::Reigst_Resource(int _menu)
	{
		Menu = _menu;
	}

	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam);
	HINSTANCE g_hInst;
	static HWND Check;
	static bool Mine_Trigger;
	static int Number_Trigger;

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

		WndClass.lpszMenuName = MAKEINTRESOURCE(Menu); //메뉴 추가

		//WndClass.lpszMenuName = NULL; //메뉴 추가
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
		case WM_COMMAND:

			switch (LOWORD(wParam))
			{
			case ID_HINT:

				DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, AboutDlgProc);
				break;
			}
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return(DefWindowProc(hWnd, iMessage, wParam, lParam));
	}

	BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		HWND hCheck;
		switch (iMessage)
		{
		case WM_INITDIALOG:
			if (Mine_Trigger)
			{
				hCheck = GetDlgItem(hDlg, IDC_CHECK1);
				SendMessage(hCheck, BM_SETCHECK, BST_CHECKED, 0);
			}
			return TRUE;

		case WM_COMMAND:

			switch (wParam)
			{
			case IDC_CHECK1:
				
				//Mine_Trigger = true;
				if (IsDlgButtonChecked(hDlg, IDC_CHECK1) == BST_CHECKED)
				{
					Mine_Trigger = true;
				}
				else
				{
					Mine_Trigger = false;
				}

				return TRUE;

			case IDOK:

				if (IsDlgButtonChecked(hDlg, IDC_RADIO1) == BST_CHECKED)
				{
					Number_Trigger = 1;
				}
				else if (IsDlgButtonChecked(hDlg, IDC_RADIO2) == BST_CHECKED)
				{
					Number_Trigger = 2;
				}
				else if (IsDlgButtonChecked(hDlg, IDC_RADIO3) == BST_CHECKED)
				{
					Number_Trigger = 3;
				}
				else if (IsDlgButtonChecked(hDlg, IDC_RADIO4) == BST_CHECKED)
				{
					Number_Trigger = 4;
				}
				else if (IsDlgButtonChecked(hDlg, IDC_RADIO5) == BST_CHECKED)
				{
					Number_Trigger = 5;
				}
				else if (IsDlgButtonChecked(hDlg, IDC_RADIO6) == BST_CHECKED)
				{
					Number_Trigger = 6;
				}
				else if (IsDlgButtonChecked(hDlg, IDC_RADIO7) == BST_CHECKED)
				{
					Number_Trigger = 7;
				}
				else if (IsDlgButtonChecked(hDlg, IDC_RADIO8) == BST_CHECKED)
				{
					Number_Trigger = 8;
				}

				EndDialog(hDlg, 0);

				return TRUE;

			}

			break;
		}

		return FALSE;
	}

	bool EngineMain::get_MineTrigger()
	{
		return Mine_Trigger;
	}

	int EngineMain::get_NumTrigger()
	{
		return Number_Trigger;
	}


	//소멸자
	EngineMain::~EngineMain()
	{

	}
}