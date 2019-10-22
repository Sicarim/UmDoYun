#include "BitMap.h"

//생성자
BitMap::BitMap()
{
	bx = 0;
	by = 0;
}

//비트맵 초기화
void BitMap::Bit_Init(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	hMemDC = CreateCompatibleDC(hdc);
	hImage = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hOldBitMap = (HBITMAP)SelectObject(hMemDC, hImage);

	GetObject(hImage, sizeof(BITMAP), &bit);

	bx = bit.bmWidth;
	by = bit.bmHeight;
}

//비트맵 그리기
void BitMap::Bit_Draw(HDC hdc, int posx, int posy, int _x, int _y)
{
	TransparentBlt(hdc, 650 + _x * SPEED, 300 + _y, bx / 4, by / 4,
		hMemDC, (bx / 4) * posx, (by / 4) * posy, bx / 4, by / 4, RGB(255, 0, 255));

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