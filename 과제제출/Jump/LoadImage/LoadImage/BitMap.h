#pragma once
#include "Mecro.h"

class BitMap
{
private:
	HDC hMemDC;
	HBITMAP hImage;
	HBITMAP hOldBitMap;
	int bx;
	int by;
	BITMAP bit;

public:
	BitMap(); //생성자

	void Bit_Init(HWND hWnd); //비트맵 초기화
	void Bit_Draw(HDC hdc, int posx, int posy, int _x = 0, int _y = 0); //비트맵 그리기
	void Bit_Release(); //비트맵 지우기

	~BitMap(); //소멸자
};