#include <Windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Hello World");
TCHAR str[256]; //Ű���带 ����ϱ� ����.

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps; //�׸��� ���� ����ü BeginPaint
	int len;
	double gak = 2 * M_PI / 100;
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		

		//�� ���
		for (int i = 0; i < 30; i++)
		{
			//SetPixel(hdc, 10 + (i * 3), 10, RGB(255, 0, 0));
			SetPixel(hdc, 300 + 50 * -cos(i * gak), 300 + 50 * -sin(i * gak), RGB(255, 0, 0)); //x = �߽��� + ������ * ��ǥ(cos), y = �߽��� + ������ * ��ǥ(sin)
		}

		//�� ���
		for (int i = 0; i < 100; i++)
		{
			//SetPixel(hdc, 10 + (i * 3), 10, RGB(255, 0, 0));
			SetPixel(hdc, 800 + 120 * cos(i * gak), 300 + (120 + i) * sin(i * gak), RGB(255, 0, 0)); //x = �߽��� + ������ * ��ǥ(cos), y = �߽��� + ������ * ��ǥ(sin)
		}

		MoveToEx(hdc, 350, 50, NULL); //���� ������
		LineTo(hdc, 650, 50); //���� ����
		Rectangle(hdc, 50, 100, 250, 80); //�簢�� �׸���

		//�� �ٴٴٴٴ� ���
		for (int i = 0; i < 10; i++)
		{
			Ellipse(hdc, 350 + (i*100), 480, 400 + (i * 100), 530);
		}

		//Ÿ�� �ٴٴٴٴ� ���
		for (int i = 0; i < 10; i++)
		{
			Ellipse(hdc, 350 + (i * 100), 550, 400 + (i * 100), 650);
		}
		
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}