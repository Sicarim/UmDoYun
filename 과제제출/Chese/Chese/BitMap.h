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
	BitMap(); //������

	void Bit_Init(HWND hWnd, LPCSTR _fileName); //��Ʈ�� �ʱ�ȭ
	void Bit_Draw(HWND hWnd, int _dx, int _dy); //��Ʈ�� �׸���
	void Bit_BlendDraw(HWND hWnd, int _dx, int _dy); //��Ʈ�� �������ϰ� �׸���
	void Bit_Release(); //��Ʈ�� �����

	~BitMap(); //�Ҹ���
};