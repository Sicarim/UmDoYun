#include <Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Hello World");
int x = 100;
int y = 100;
bool bAngle = false;

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

//문제 1번!!!!(다른 번호를 확인하고 싶을땐 주석처리를 해주세요!!!)
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint

	switch (iMessage)
	{
		case WM_KEYDOWN:
			switch (wParam)
			{
			case VK_LEFT:
				x -= 1;
				break;
			case VK_RIGHT:
				x += 1;
				break;
			case VK_UP:
				y -= 1;
				break;
			case VK_DOWN:
				y += 1;
				break;
			}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;

		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			Ellipse(hdc, 350 + x, 480 + y, 400 + x, 530 + y); // ->원 그리기(키보드)
			
			EndPaint(hWnd, &ps);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

//문제 2번!!!!(다른 번호를 확인하고 싶을땐 주석처리를 해주세요!!!
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint
//
//	switch (iMessage)
//	{
//	case WM_MOUSEMOVE:
//		x = LOWORD(lParam);
//		y = HIWORD(lParam);
//
//		InvalidateRect(hWnd, NULL, TRUE);
//
//		return 0;
//
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		Ellipse(hdc, x - 50, y - 50, x + 50, y + 50); // ->원 그리기
//
//		EndPaint(hWnd, &ps);
//		return 0;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}

//문제 3번!!!!(다른 번호를 확인하고 싶을땐 주석처리를 해주세요!!!
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint
//	int r_Left = 300;
//	int r_Top = 100;
//	int r_Right = 600;
//	int r_Bottom = 400;
//
//	switch (iMessage)
//	{
//	case WM_MOUSEMOVE:
//		x = LOWORD(lParam);
//		y = HIWORD(lParam);
//
//		if (x > r_Left&& x < r_Right && y > r_Top&& y < r_Bottom)
//		{
//			InvalidateRect(hWnd, NULL, TRUE);
//		}
//
//		return 0;
//
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		Rectangle(hdc, r_Left, r_Top, r_Right, r_Bottom); //사각형 그리기
//		Ellipse(hdc, x - 50, y - 50, x + 50, y + 50); // ->원 그리기
//
//		EndPaint(hWnd, &ps);
//		return 0;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}

//문제 4번!!!!(다른 번호를 확인하고 싶을땐 주석처리를 해주세요!!!
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps; //그리기 전용 구조체 BeginPaint
//
//	switch (iMessage)
//	{
//		case WM_PAINT:
//			hdc = BeginPaint(hWnd, &ps);
//
//			if (bAngle == true)
//			{
//				Ellipse(hdc, 100, 200, 200, 300); // ->원 그리기
//			}
//			else
//			{
//				Rectangle(hdc, 100, 200, 200, 300); // ->사각형 그리기
//			}
//
//			EndPaint(hWnd, &ps);
//			return 0;
//
//		case WM_DESTROY:
//			PostQuitMessage(0);
//			return 0;
//
//		case WM_LBUTTONDOWN:
//			if (MessageBox(hWnd, TEXT("모양을 변경하고 싶다면 ok버튼을 누르세요."), TEXT("MessageBox"), MB_OK) == IDOK)
//			{
//				if (bAngle == true)
//				{
//					bAngle = false;
//				}
//				else
//				{
//					bAngle = true;
//				}
//				InvalidateRect(hWnd, NULL, TRUE);
//			}
//			return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}