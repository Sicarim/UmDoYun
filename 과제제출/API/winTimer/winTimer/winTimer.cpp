#include <Windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Hello World");
bool RnL = false;
int i = 0;
int x = 350;
int y = 300;
int secX = 0;
int secY = 0;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;
	//WndClass는 기본 윈도우환경을 만드는 구조체다. 맴버변수는 밑에와 같다.
	WndClass.cbClsExtra = 0; //예약영역
	WndClass.cbWndExtra = 0; //예약영역 (신경x)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); //배경색
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); //커서
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //아이콘 모양
	WndClass.hInstance = hInstance; //(프로그램 핸들값(번호)등록)
	WndClass.lpfnWndProc = WndProc; //프로세스 함수 호출
	WndClass.lpszClassName = lpszClass; //클레스 이름
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW; //윈도우의 수직과 수평이 변경 시 다시 그린다.
	RegisterClass(&WndClass); //만들어진 WidClass를 등록
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
		(HMENU)NULL, hInstance, NULL); //창 크기 설정
	ShowWindow(hWnd, nCmdShow);
	while (GetMessage(&Message, NULL, 0, 0)) //사용자에게 메시지를 받아오는 함수(WM_QUIT 메시지 받을 시 종료), 메시지가 오기까지 대기를 하고있다가 오면 작동.
	{
		TranslateMessage(&Message); // 키보드 입력 메시지 처리함수
		DispatchMessage(&Message); //받은 메시지를 WndProc에 전달하는 함수
	}
	return (int)Message.wParam;
}

//1번 문제!!!!!!확인시 주석을 해제해주세욥!!
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint
	SYSTEMTIME st;
	int r_Left = 300;
	int r_Top = 100;
	int r_Right = 600;
	int r_Bottom = 400;


	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, NULL);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;

	case WM_TIMER:
		GetLocalTime(&st);

		if (x + 50 == r_Right)
			RnL = false;
		else if(x - 50 == r_Left)
			RnL = true;
		if (RnL)
			x += 5;
		else if (!RnL)
			x -= 5;

		InvalidateRect(hWnd, NULL, TRUE);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, r_Left, r_Top, r_Right, r_Bottom); //사각형 그리기
		Ellipse(hdc, x - 50, y - 50, x + 50, y + 50); // ->원 그리기
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}



//2번 문제!!!!!!확인시 주석을 해제해주세욥!!
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint
//	SYSTEMTIME st;
//	double gak = 2 * M_PI / 60;
//
//	switch (iMessage)
//	{
//	case WM_CREATE:
//		SetTimer(hWnd, 1, 1000, NULL);
//		SendMessage(hWnd, WM_TIMER, 1, 0);
//		return 0;
//
//	case WM_TIMER:
//		GetLocalTime(&st);
//		i++;
//		InvalidateRect(hWnd, NULL, TRUE);
//		return 0;
//
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		Ellipse(hdc, 500, 100, 800, 400); // ->원 그리기
//		SetPixel(hdc, 650, 250, RGB(255, 0, 0)); //가운데 기준점 찍기
//
//		//시침
//		MoveToEx(hdc, 650, 250, NULL);
//		LineTo(hdc, 650, 190);
//
//		//초침
//		MoveToEx(hdc, 650, 250, NULL);
//
//		secX = 650 + 100 * cos(i * gak);
//		secY = 250 + 100* sin(i * gak);
//		LineTo(hdc, secX, secY);
//
//		EndPaint(hWnd, &ps);
//		return 0;
//
//	case WM_DESTROY:
//		KillTimer(hWnd, 1);
//		PostQuitMessage(0);
//		return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}