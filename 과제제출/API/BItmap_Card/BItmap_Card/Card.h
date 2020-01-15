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
	Card(); //생성자

	void Init(HDC hdc, HINSTANCE _hInst, int _id);//초기화 함수
	void Range_Init(int _x, int _y); //범위 초기화
	void Draw(HDC hdc);//그리기 함수
	void Black_Draw(HDC hdc, int x, int y);//블랙 카드 그리기 함수
	void DCRelease(); //지우기
	void Erase(HDC hdc); //지우기 함수

	~Card(); //소멸자

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