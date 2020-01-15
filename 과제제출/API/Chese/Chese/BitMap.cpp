#include "BitMap.h"

//생성자
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

//비트맵 초기화
void BitMap::Bit_Init(HWND hWnd, LPCSTR _fileName)
{
	HDC hdc = GetDC(hWnd);

	//그릴 체스말
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

//비트맵 그리기
void BitMap::Bit_Draw(HWND hWnd, int _dx, int _dy)
{
	HDC hdc = GetDC(hWnd);
	TransparentBlt(hdc, _dx, _dy, m_size.cx * CORRENTCION, m_size.cx * CORRENTCION, hMemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
}

//비트맵 반투명하게 그리기
void BitMap::Bit_BlendDraw(HWND hWnd, int _dx, int _dy)
{
	HDC hdc = GetDC(hWnd);

	//도화지
	AlphaDC = CreateCompatibleDC(hdc); //hMemDC와 동일한 AlphaDC를 만든다.
	//hAlphaImage = CreateCompatibleBitmap(hdc, 1000, 1000);
	hAlphaImage = (HBITMAP)LoadImage(NULL, "RES//block_b_01.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hAlphaOldBitMap = (HBITMAP)SelectObject(AlphaDC, hAlphaImage);
	
	//블랜딩 옵션
	BLENDFUNCTION _bf;
	_bf.BlendOp = 0;
	_bf.BlendFlags = 0;
	_bf.SourceConstantAlpha = 100; //<--알파값 조절하기	
	_bf.AlphaFormat = AC_SRC_OVER;

	AlphaBlend(hdc, _dx, _dy, m_size.cx * CORRENTCION, m_size.cx * CORRENTCION, AlphaDC, 0, 0, m_size.cx, m_size.cy, _bf);
}

//비트맵 지우기
void BitMap::Bit_Release()
{
	SelectObject(hMemDC, hOldBitMap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);
}

//소멸자
BitMap::~BitMap()
{
	Bit_Release();
}