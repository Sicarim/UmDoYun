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
	BitMap(); //������

	//�ʱ�ȭ �Լ�
	void Init(HDC hdc, HINSTANCE _hInst, int _id);
	//�׸� �׸��� �Լ�
	void Draw(HDC hdc, int x, int y, int _bitsizeW = 1, int _bitsizeH = 1);

	~BitMap(); //�Ҹ���

	inline int get_Width()
	{
		return size.cx;
	}
};