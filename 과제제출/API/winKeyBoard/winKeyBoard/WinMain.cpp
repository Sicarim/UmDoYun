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

//���� 1��!!!!(�ٸ� ��ȣ�� Ȯ���ϰ� ������ �ּ�ó���� ���ּ���!!!)
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps; //�׸��� ���� ����ü BeginPaint

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
			Ellipse(hdc, 350 + x, 480 + y, 400 + x, 530 + y); // ->�� �׸���(Ű����)
			
			EndPaint(hWnd, &ps);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

//���� 2��!!!!(�ٸ� ��ȣ�� Ȯ���ϰ� ������ �ּ�ó���� ���ּ���!!!
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps; //�׸��� ���� ����ü BeginPaint
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
//		Ellipse(hdc, x - 50, y - 50, x + 50, y + 50); // ->�� �׸���
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

//���� 3��!!!!(�ٸ� ��ȣ�� Ȯ���ϰ� ������ �ּ�ó���� ���ּ���!!!
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps; //�׸��� ���� ����ü BeginPaint
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
//		Rectangle(hdc, r_Left, r_Top, r_Right, r_Bottom); //�簢�� �׸���
//		Ellipse(hdc, x - 50, y - 50, x + 50, y + 50); // ->�� �׸���
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

//���� 4��!!!!(�ٸ� ��ȣ�� Ȯ���ϰ� ������ �ּ�ó���� ���ּ���!!!
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps; //�׸��� ���� ����ü BeginPaint
//
//	switch (iMessage)
//	{
//		case WM_PAINT:
//			hdc = BeginPaint(hWnd, &ps);
//
//			if (bAngle == true)
//			{
//				Ellipse(hdc, 100, 200, 200, 300); // ->�� �׸���
//			}
//			else
//			{
//				Rectangle(hdc, 100, 200, 200, 300); // ->�簢�� �׸���
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
//			if (MessageBox(hWnd, TEXT("����� �����ϰ� �ʹٸ� ok��ư�� ��������."), TEXT("MessageBox"), MB_OK) == IDOK)
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