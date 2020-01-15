#pragma once
#include "Mecro.h"

class BitMap
{
private:
	HDC MemDC;
	HBITMAP myBitmap;
	HBITMAP oldBitmap;
	SIZE size;
public:
	BitMap(); //생성자

	//초기화 함수
	void Init(HDC hdc, HINSTANCE _hInst, int _id);
	//그림 그리는 함수
	void Draw(HDC hdc, int x, int y, int _bitsizeW = 1, int _bitsizeH = 1);

	~BitMap(); //소멸자

	inline int get_Width()
	{
		return size.cx;
	}
};