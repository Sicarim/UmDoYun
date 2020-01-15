#include <Windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Hello World");
TCHAR str[256]; //키보드를 사용하기 위함.

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint
	int len;
	double gak = 2 * M_PI / 100;
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		

		//점 찍기
		for (int i = 0; i < 30; i++)
		{
			//SetPixel(hdc, 10 + (i * 3), 10, RGB(255, 0, 0));
			SetPixel(hdc, 300 + 50 * -cos(i * gak), 300 + 50 * -sin(i * gak), RGB(255, 0, 0)); //x = 중심점 + 반지름 * 좌표(cos), y = 중심점 + 반지름 * 좌표(sin)
		}

		//점 찍기
		for (int i = 0; i < 100; i++)
		{
			//SetPixel(hdc, 10 + (i * 3), 10, RGB(255, 0, 0));
			SetPixel(hdc, 800 + 120 * cos(i * gak), 300 + (120 + i) * sin(i * gak), RGB(255, 0, 0)); //x = 중심점 + 반지름 * 좌표(cos), y = 중심점 + 반지름 * 좌표(sin)
		}

		MoveToEx(hdc, 350, 50, NULL); //선의 시작점
		LineTo(hdc, 650, 50); //선의 끝점
		Rectangle(hdc, 50, 100, 250, 80); //사각형 그리기

		//원 다다다다닥 찍기
		for (int i = 0; i < 10; i++)
		{
			Ellipse(hdc, 350 + (i*100), 480, 400 + (i * 100), 530);
		}

		//타원 다다다다닥 찍기
		for (int i = 0; i < 10; i++)
		{
			Ellipse(hdc, 350 + (i * 100), 550, 400 + (i * 100), 650);
		}
		
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}