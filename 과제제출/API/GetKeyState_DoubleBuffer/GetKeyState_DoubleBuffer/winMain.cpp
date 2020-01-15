#include "Mecro.h"
#include "Character.h"
#include "GameManager.h"

void CALLBACK TimeWorking(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

#define _USE_MATH_DEFINES
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("GetKey & DoubleBuffer");

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

int charX = 300;
int charY = 500;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint

	switch (iMessage)
	{
	case WM_CREATE:
		m_Char.Char_Init(hWnd, charX, charY);
		SetTimer(hWnd, 1, 10, TimeWorking);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		
		m_Char.Char_Draw(hWnd);

		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void CALLBACK TimeJump(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	m_Char.Char_Jump(hWnd);
}

void CALLBACK TimeWorking(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	m_Char.Char_Working(hWnd);
}