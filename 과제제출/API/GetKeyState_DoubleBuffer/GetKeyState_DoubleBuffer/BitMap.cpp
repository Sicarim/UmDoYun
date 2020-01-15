#include "BitMap.h"

//������
BitMap::BitMap()
{
	curX = 0;
	curY = 0;
}

//��Ʈ�� �ʱ�ȭ
void BitMap::Bit_Init(HWND hWnd, int _posx, int _posy)
{
	HDC hdc = GetDC(hWnd);
	curX = _posx;
	curY = _posy;

	//���� �׸� ��ȭ��
	HideBackDC = CreateCompatibleDC(hdc);
	HideBitBackDC = CreateCompatibleBitmap(hdc, 1024, 768);
	HideOldDC = (HBITMAP)SelectObject(HideBackDC, HideBitBackDC);
	
	//��ȭ���� �׸� ���ȭ��(��ũ��ũ)
	g_BackDC = CreateCompatibleDC(HideBackDC);
	g_btBack = (HBITMAP)LoadImage(NULL, "back.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	g_btOldBack = (HBITMAP)SelectObject(g_BackDC, g_btBack);

	//��ȭ���� �׸� ĳ����(�߾Ͽ� ����)
	g_PlayerDC = CreateCompatibleDC(HideBackDC);
	g_btPlayer = (HBITMAP)LoadImage(NULL, "image.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	g_btOldPlayer = (HBITMAP)SelectObject(g_PlayerDC, g_btPlayer);

	GetObject(g_btPlayer, sizeof(g_mapInfo), &g_mapInfo);

	g_size.cx = g_mapInfo.bmWidth;
	g_size.cy = g_mapInfo.bmHeight;

	ReleaseDC(hWnd, hdc);
}

//��Ʈ�� �׸���
void BitMap::Bit_Draw(HWND hWnd, int _posx, int _posy, int _shapex, int _shapey)
{
	HDC hdc = GetDC(hWnd);

	//���� �׸� ��ҿ� ����� �׸���.
	BitBlt(HideBackDC, 0, 0, 1024, 768, g_BackDC, 0, 0, SRCCOPY);

	//���� �׸� ��ҿ� ĳ���͸� �׸���.
	TransparentBlt(HideBackDC, curX + _posx, curX + _posy, g_size.cx / 4, g_size.cy / 4, g_PlayerDC, (g_size.cx / 4) * _shapex, (g_size.cy / 4) * _shapey,
		g_size.cx / 4, g_size.cy / 4, RGB(255, 0, 255));

	//���������� ȭ�鿡 �Ѹ���.
	BitBlt(hdc, 0, 0, 1024, 768, HideBackDC, 0, 0, SRCCOPY);
}

//��Ʈ�� �����
void BitMap::Bit_Release()
{
	//SelectObject(hMemDC, hOldBitMap);
	//DeleteObject(hImage);
	//DeleteDC(hMemDC);
}

//�Ҹ���
BitMap::~BitMap()
{
	Bit_Release();
}