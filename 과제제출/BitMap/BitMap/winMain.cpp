#include "Mecro.h"
#include "Animal.h"
#include "BitMapManager.h"
#define _USE_MATH_DEFINES
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("BitMap");

//���콺 Ŭ���� �ʱ�ȭ
int x = 0;
int y = 0;

//BitMap ����
Animal m_Ani;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	// HWND hWnd2;
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

	/*
	hWnd2 = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
		(HMENU)NULL, hInstance, NULL); //â ũ�� ����
	ShowWindow(hWnd2, nCmdShow);
	*/
	//�� �̰� �ǳ�
	


	while (GetMessage(&Message, NULL, 0, 0)) //����ڿ��� �޽����� �޾ƿ��� �Լ�(WM_QUIT �޽��� ���� �� ����), �޽����� ������� ��⸦ �ϰ��ִٰ� ���� �۵�.
	{
		TranslateMessage(&Message); // Ű���� �Է� �޽��� ó���Լ�
		DispatchMessage(&Message); //���� �޽����� WndProc�� �����ϴ� �Լ�
	}
	return (int)Message.wParam;
}

/*
�١١١١١١١١١١١�
�����....��������� �����ϼ̴µ�...���� �ָ����� �����Ѵٰ� �̸� �f���Ⱦ��....
��� �ڵ� �ٽ� ¥����, �ڵ�м� ö���� �߽��ϴ�...����^^7
�١١١١١١١١١١١١١�

���� ���
�޽��� �ڽ��� ������ ������ â�� �ƴѰ��ΰ�?
HINSTANCE�� ���α׷��� �ڵ鷯 ���̶�� �ΰ� �̻��� �翬�� �������°��ΰ�?
�׷��ٸ� �����带 ����ϴ���, �翬�� HINTEANCE���� �ϳ��ΰ�?
�ٸ� �����츦 ����ϰ� �ʹٸ� �׳� �ٸ� hwnd2 <--�̷������� �����ϸ� �Ǵ°��ΰ�-> Ȯ�� �Ϸ�
*/

/*
HWND: ������ �ڵ鷯, ���Ͽ� �����ϱ� ���ؼ� �̸� �̿��� �����ؾ���.
DC: ��¿� �ʿ��� ������ ������ ������ ����ü, ��ǥ, ��, ���� �� ��¿� �ʿ��� ��� ������ ����ִ�.
->�ᱹ HDC�� DC�� ������ �����ϴ� ������ ����ü�� ��ġ�� �˱� ����.

HINSTENCE: �ڵ� �ν��Ͻ�, ���α׷��� �ν��Ͻ� �ĺ���, ���α׷� ��ü�� ��üȭ�� �ּ�
-> ���α׷� ��ü�� �ڵ�
*/

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, MemDC;
	PAINTSTRUCT ps; //�׸��� ���� ����ü BeginPaint

	switch (iMessage)
	{
	case WM_CREATE:
		/*
		�����찡 �����Ǹ� �ް� �Ǵ� �޽���
		�����찡 ���� �Ǿ ���̱� �� �ʱ�ȭ�� �ʿ��ϴٸ� ��� ����.
		*/

		//�����찡 ���� �Ǳ� ���� BitMap���� ������ �ʱ�ȭ�Ѵ�. 
		//Init�Լ��� ������ ���α׷� �ĺ��ڸ� �Ű������� �Ѱ��ִµ� �ϴ�.
		BitMapManager::get_Instence()->Init(hWnd, g_hInst);
		return 0;

	case WM_LBUTTONDOWN:
		m_Ani.Send_Message(hWnd, LOWORD(lParam), HIWORD(lParam));
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		m_Ani.All_Draw(hdc);
		
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}