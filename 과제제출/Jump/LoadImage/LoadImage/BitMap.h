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
	BitMap(); //������

	void Bit_Init(HWND hWnd); //��Ʈ�� �ʱ�ȭ
	void Bit_Draw(HDC hdc, int posx, int posy, int _x = 0, int _y = 0); //��Ʈ�� �׸���
	void Bit_Release(); //��Ʈ�� �����

	~BitMap(); //�Ҹ���
};