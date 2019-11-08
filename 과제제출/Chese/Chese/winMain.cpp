#include "Mecro.h"
#include "ChessGame.h"
#include "BitMapManager.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Chess");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
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
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1000, 1000,
		NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

ChessGame m_Game;
int ptx = 0;
int pty = 0;
bool start = false;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	POINT in_Pt;

	switch (iMessage)
	{
	case WM_CREATE:
		m_Game.Game_Init(hWnd);
		break;

	case WM_LBUTTONDOWN:
		start = true;

		in_Pt.x = LOWORD(lParam);
		in_Pt.y = HIWORD(lParam);

		ptx = in_Pt.x;
		pty = in_Pt.y;
		InvalidateRect(hWnd, NULL, false);

		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		BitMapManager::get_Instence()->All_Draw(hWnd);

		if (start)
		{
			m_Game.Click_Unit(hWnd, ptx, pty);
		}

		m_Game.Game_Play(hWnd); //유닛을 계속 다시 그린다.

		EndPaint(hWnd, &ps);

		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}