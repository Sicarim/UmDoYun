#pragma once
#include "Mecro.h"

class Card
{
private:
	HDC MemDC;
	HBITMAP myBitmap;
	HBITMAP oldBitmap;
	SIZE size;
	BITMAP bit_Info;

	int id;
	int cardX, cardY;
	int cardW, cardH;
	bool Enable_Check;

public:
	Card(); //������

	void Init(HDC hdc, HINSTANCE _hInst, int _id);//�ʱ�ȭ �Լ�
	void Range_Init(int _x, int _y); //���� �ʱ�ȭ
	void Draw(HDC hdc);//�׸��� �Լ�
	void Black_Draw(HDC hdc, int x, int y);//�� ī�� �׸��� �Լ�
	void DCRelease(); //�����
	void Erase(HDC hdc); //����� �Լ�

	~Card(); //�Ҹ���

	inline int get_Width()
	{
		return cardW;
	}

	inline int get_Number()
	{
		return id;
	}
	inline void set_CardInfo(int _cardx, int _cardy)
	{
		cardX = _cardx;
		cardY = _cardy;
	}
	inline bool get_ChangeEnable()
	{
		return Enable_Check;
	}
	inline void set_ChangeEnable(bool _check)
	{
		Enable_Check = _check;
	}
};