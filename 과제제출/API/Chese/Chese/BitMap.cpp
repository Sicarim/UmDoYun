#include "BitMap.h"

//������
BitMap::BitMap()
{
	hMemDC = NULL;
	hImage = NULL;
	hOldBitMap = NULL;

	AlphaDC = NULL;
	hAlphaImage = NULL;
	hAlphaOldBitMap = NULL;

	bx = 0;
	by = 0;
}

//��Ʈ�� �ʱ�ȭ
void BitMap::Bit_Init(HWND hWnd, LPCSTR _fileName)
{
	HDC hdc = GetDC(hWnd);

	//�׸� ü����
	hMemDC = CreateCompatibleDC(hdc);
	hImage = (HBITMAP)LoadImage(NULL, _fileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitMap = (HBITMAP)SelectObject(hMemDC, hImage);

	GetObject(hImage, sizeof(BITMAP), &bit_Info);
	/*
	Card Width: 125
	Card Height: 125
	*/
	m_size.cx = bit_Info.bmWidth;
	m_size.cy = bit_Info.bmHeight;

	//ReleaseDC(hWnd, hdc);
}

//��Ʈ�� �׸���
void BitMap::Bit_Draw(HWND hWnd, int _dx, int _dy)
{
	HDC hdc = GetDC(hWnd);
	TransparentBlt(hdc, _dx, _dy, m_size.cx * CORRENTCION, m_size.cx * CORRENTCION, hMemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
}

//��Ʈ�� �������ϰ� �׸���
void BitMap::Bit_BlendDraw(HWND hWnd, int _dx, int _dy)
{
	HDC hdc = GetDC(hWnd);

	//��ȭ��
	AlphaDC = CreateCompatibleDC(hdc); //hMemDC�� ������ AlphaDC�� �����.
	//hAlphaImage = CreateCompatibleBitmap(hdc, 1000, 1000);
	hAlphaImage = (HBITMAP)LoadImage(NULL, "RES//block_b_01.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hAlphaOldBitMap = (HBITMAP)SelectObject(AlphaDC, hAlphaImage);
	
	//���� �ɼ�
	BLENDFUNCTION _bf;
	_bf.BlendOp = 0;
	_bf.BlendFlags = 0;
	_bf.SourceConstantAlpha = 100; //<--���İ� �����ϱ�	
	_bf.AlphaFormat = AC_SRC_OVER;

	AlphaBlend(hdc, _dx, _dy, m_size.cx * CORRENTCION, m_size.cx * CORRENTCION, AlphaDC, 0, 0, m_size.cx, m_size.cy, _bf);
}

//��Ʈ�� �����
void BitMap::Bit_Release()
{
	SelectObject(hMemDC, hOldBitMap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);
}

//�Ҹ���
BitMap::~BitMap()
{
	Bit_Release();
}