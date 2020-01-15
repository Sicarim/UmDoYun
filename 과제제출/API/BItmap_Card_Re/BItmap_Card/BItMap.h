#pragma once
#include "Mecro.h"

class BitMap
{
private:
	HDC MemDC;
	HBITMAP myBitmap;
	HBITMAP oldBitmap;
	SIZE size;

	int Bit_ID;
	bool Enable_Check;
public:
	BitMap(); //������

	void Init(HDC hdc, HINSTANCE _hInst, int _id);//�ʱ�ȭ �Լ�
	void Bit_Draw(HDC hdc, int _setX, int _setY, float _corX = 0.7, float _corY = 0.7);
	void Erase(HDC hdc, int _setX, int _setY, float _corX = 0.7, float _corY = 0.7); //����� �Լ�
	void DCRelease(); //�����

	int get_sizeW(); //����
	int get_sizeH(); //����
	int get_ID(); //ID ����
	HDC get_hdc(); //MemDC��������

	~BitMap(); //�Ҹ���

	inline bool get_ChangeEnable()
	{
		return Enable_Check;
	}
	inline void set_ChangeEnable(bool _check)
	{
		Enable_Check = _check;
	}
};