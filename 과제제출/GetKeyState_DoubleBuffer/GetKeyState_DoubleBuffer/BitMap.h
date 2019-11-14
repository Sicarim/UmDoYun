#pragma once
#include "Mecro.h"

class BitMap
{
private:
	HDC HideBackDC; //숨겨 그릴 장소(도화지)를 준비
	HBITMAP HideBitBackDC;
	HBITMAP HideOldDC;

	HDC g_PlayerDC, g_BackDC;
	HBITMAP g_btPlayer, g_btBack;
	HBITMAP g_btOldPlayer, g_btOldBack;
	BITMAP g_mapInfo;
	SIZE g_size;

	int curX;
	int curY;

public:
	BitMap(); //생성자

	void Bit_Init(HWND hWnd, int _posx, int _posy); //비트맵 초기화
	void Bit_Draw(HWND hWnd, int _posx, int _posy, int _shapex, int _shapey); //비트맵 그리기
	void Bit_Release(); //비트맵 지우기

	~BitMap(); //소멸자
};