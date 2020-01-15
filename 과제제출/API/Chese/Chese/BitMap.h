#pragma once
#include "Mecro.h"

class BitMap
{
private:
	HDC hMemDC;
	HBITMAP hImage;
	HBITMAP hOldBitMap;

	HDC AlphaDC;
	HBITMAP hAlphaImage;
	HBITMAP hAlphaOldBitMap;

	HDC BackDC;
	HBITMAP hBackImage;
	HBITMAP hBackOldBitMap;

	HDC Back;
	HBITMAP MyBackBit;
	HBITMAP OldBackBit;

	int bx;
	int by;
	BITMAP bit_Info;
	SIZE m_size;

public:
	BitMap(); //생성자

	void Bit_Init(HWND hWnd, LPCSTR _fileName); //비트맵 초기화
	void Bit_Draw(HWND hWnd, int _dx, int _dy); //비트맵 그리기
	void Bit_BlendDraw(HWND hWnd, int _dx, int _dy); //비트맵 반투명하게 그리기
	void Bit_Release(); //비트맵 지우기

	~BitMap(); //소멸자
};