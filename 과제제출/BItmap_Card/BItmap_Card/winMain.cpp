#include "Mecro.h"
#include "GameManager.h"
#include "CardManager.h"
#include "CardGame.h"

#define _USE_MATH_DEFINES
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("BitMap");

//마우스 클릭값 초기화
int x = 0;
int y = 0;

//Game선언
CardGame m_Game;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITENESS);
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


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, MemDC;
	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint
	SYSTEMTIME st;

	switch (iMessage)
	{
	case WM_CREATE:
		CardManager::get_Instence()->All_Init(hWnd, g_hInst);
		GameManager::get_Instence()->Card_Shffle();
		return 0;

		//시작 메뉴바에 있는 돋보기 모양에 제어판 검색->제어판 들어가서 프로그램 제거 클릭->Insyde Airplane Mode를 우클릭하여 제거

	case WM_LBUTTONDOWN:
		m_Game.Click_Card(hWnd, LOWORD(lParam), HIWORD(lParam));
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GameManager::get_Instence()->All_Draw(hdc);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		GameManager::del_Instence();
		CardManager::del_Instence();
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	HDC hdc = GetDC(hWnd);
	GameManager::get_Instence()->Answer_Check(hWnd);
}