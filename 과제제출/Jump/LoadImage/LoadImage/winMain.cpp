#include "Mecro.h"
#include "Character.h"
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

#define _USE_MATH_DEFINES
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("LoadImage");

//마우스 클릭값 초기화
int charX = 0;
int charY = 0;
bool isJump = false;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

//캐릭터 선언
Character m_Char;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint

	switch (iMessage)
	{
	case WM_CREATE:
		m_Char.Char_Init(hWnd);
		return 0;
		
	case WM_KEYDOWN:
		if (wParam == VK_LEFT)
		{
			charX -= 1;
			m_Char.set_direction(false);
		}

		if (wParam == VK_RIGHT)
		{
			charX += 1;
			m_Char.set_direction(true);	
		}

		if (wParam == VK_SPACE)
		{
			isJump = true;
			SetTimer(hWnd, 1, JUMPSPEED, TimeProc);
		}

		InvalidateRect(hWnd, NULL, TRUE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		if (isJump)
		{
			m_Char.Char_Jump(hWnd, charX);
			isJump = m_Char.get_Jump();
		}
		else
		{
			m_Char.Char_Working(hdc, charX);
		}

		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		charX--;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		charX++;
	}

	InvalidateRect(hWnd, NULL, TRUE);
}