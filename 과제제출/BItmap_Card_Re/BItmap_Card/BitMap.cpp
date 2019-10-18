#include "BItMap.h"

//생성자
BitMap::BitMap()
{	
	MemDC = NULL;
	myBitmap = NULL;
	oldBitmap = NULL;
	Bit_ID = 0;
	Enable_Check = true;
}

//초기화 함수
void BitMap::Init(HDC hdc, HINSTANCE _hInst, int _id)
{
	Bit_ID = _id;
	MemDC = CreateCompatibleDC(hdc);
	myBitmap = LoadBitmap(_hInst, MAKEINTRESOURCE(_id));
	oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);

	BITMAP bit_Info;

	GetObject(myBitmap, sizeof(bit_Info), &bit_Info);

	size.cx = bit_Info.bmWidth;
	size.cy = bit_Info.bmHeight;
}

void BitMap::Bit_Draw(HDC hdc, int _setX, int _setY, float _corX, float _corY)
{
	StretchBlt(hdc, _setX, _setY, size.cx * _corX, size.cy * _corY, MemDC, 0, 0, size.cx, size.cy, SRCCOPY);
}

//지우기 함수
void BitMap::Erase(HDC hdc, int _setX, int _setY, float _corX, float _corY)
{
	StretchBlt(hdc, _setX, _setY, size.cx * _corX, size.cy * _corY, MemDC, 0, 0, size.cx, size.cy, WHITENESS);
}

int BitMap::get_ID()
{
	return Bit_ID;
}

//가로 
int BitMap::get_sizeW()
{
	return size.cx;
}

//세로
int BitMap::get_sizeH()
{
	return size.cy;
}

HDC BitMap::get_hdc()
{
	return MemDC;
}

//지우기
void BitMap::DCRelease()
{
	SelectObject(MemDC, oldBitmap);
	DeleteObject(myBitmap);
	DeleteDC(MemDC);
}

//소멸자
BitMap::~BitMap()
{

}