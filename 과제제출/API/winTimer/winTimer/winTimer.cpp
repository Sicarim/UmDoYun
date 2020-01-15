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
	//WndClass�� �⺻ ������ȯ���� ����� ����ü��. �ɹ������� �ؿ��� ����.
	WndClass.cbClsExtra = 0; //���࿵��
	WndClass.cbWndExtra = 0; //���࿵�� (�Ű�x)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); //����
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); //Ŀ��
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //������ ���
	WndClass.hInstance = hInstance; //(���α׷� �ڵ鰪(��ȣ)���)
	WndClass.lpfnWndProc = WndProc; //���μ��� �Լ� ȣ��
	WndClass.lpszClassName = lpszClass; //Ŭ���� �̸�
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW; //�������� ������ ������ ���� �� �ٽ� �׸���.
	RegisterClass(&WndClass); //������� WidClass�� ���
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
		(HMENU)NULL, hInstance, NULL); //â ũ�� ����
	ShowWindow(hWnd, nCmdShow);
	while (GetMessage(&Message, NULL, 0, 0)) //����ڿ��� �޽����� �޾ƿ��� �Լ�(WM_QUIT �޽��� ���� �� ����), �޽����� ������� ��⸦ �ϰ��ִٰ� ���� �۵�.
	{
		TranslateMessage(&Message); // Ű���� �Է� �޽��� ó���Լ�
		DispatchMessage(&Message); //���� �޽����� WndProc�� �����ϴ� �Լ�
	}
	return (int)Message.wParam;
}

//1�� ����!!!!!!Ȯ�ν� �ּ��� �������ּ���!!
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps; //�׸��� ���� ����ü BeginPaint
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
		Rectangle(hdc, r_Left, r_Top, r_Right, r_Bottom); //�簢�� �׸���
		Ellipse(hdc, x - 50, y - 50, x + 50, y + 50); // ->�� �׸���
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}



//2�� ����!!!!!!Ȯ�ν� �ּ��� �������ּ���!!
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps; //�׸��� ���� ����ü BeginPaint
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
//		Ellipse(hdc, 500, 100, 800, 400); // ->�� �׸���
//		SetPixel(hdc, 650, 250, RGB(255, 0, 0)); //��� ������ ���
//
//		//��ħ
//		MoveToEx(hdc, 650, 250, NULL);
//		LineTo(hdc, 650, 190);
//
//		//��ħ
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