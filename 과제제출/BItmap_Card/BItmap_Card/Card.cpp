#include "Card.h"

//생성자
Card::Card()
{
	id = 0;
	cardX = 0;
	cardY = 0;
	cardW = 0;
	cardH = 0;
	Enable_Check = true;
}

//초기화 함수
void Card::Init(HDC hdc, HINSTANCE _hInst, int _id)
{
	id = _id;
	MemDC = CreateCompatibleDC(hdc);
	myBitmap = LoadBitmap(_hInst, MAKEINTRESOURCE(_id));
	oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);

	//GetObject(myBitmap, sizeof(bit_Info), &bit_Info);
	/*
	SIZE가 안먹히는 이유에 대해서 araboza
	*/
}

//범위 초기화
void Card::Range_Init(int _x, int _y)
{
	/*size.cx = bit_Info.bmWidth;
	size.cy = bit_Info.bmHeight;*/

	cardX = _x;
	cardY = _y;
	cardW = CARDW * CORRECTION;
	cardH = CARDH * CORRECTION;
}

//그리기 함수
void Card::Draw(HDC hdc)
{
	StretchBlt(hdc, cardX, cardY, cardW, cardH, MemDC, 0, 0, CARDW, CARDH, SRCCOPY);
}

//블랙 카드 그리기 함수
void Card::Black_Draw(HDC hdc, int x, int y)
{
	StretchBlt(hdc, x, y, 0.7* CARDW, 0.7* CARDH, MemDC, 0, 0, CARDW, CARDH, SRCCOPY);
	//DCRelease();
}

//지우기 함수
void Card::Erase(HDC hdc)
{
	StretchBlt(hdc, cardX, cardY, 0.7 * size.cx, 0.7 * size.cy, MemDC, 0, 0, size.cx, size.cy, WHITENESS);
}

//지우기
void Card::DCRelease()
{
	SelectObject(MemDC, oldBitmap);
	DeleteObject(myBitmap);
	DeleteDC(MemDC);
}

//소멸자
Card::~Card()
{
}