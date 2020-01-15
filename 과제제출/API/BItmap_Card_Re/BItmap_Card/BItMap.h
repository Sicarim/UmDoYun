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
	BitMap(); //생성자

	void Init(HDC hdc, HINSTANCE _hInst, int _id);//초기화 함수
	void Bit_Draw(HDC hdc, int _setX, int _setY, float _corX = 0.7, float _corY = 0.7);
	void Erase(HDC hdc, int _setX, int _setY, float _corX = 0.7, float _corY = 0.7); //지우기 함수
	void DCRelease(); //지우기

	int get_sizeW(); //가로
	int get_sizeH(); //세로
	int get_ID(); //ID 리턴
	HDC get_hdc(); //MemDC가져오기

	~BitMap(); //소멸자

	inline bool get_ChangeEnable()
	{
		return Enable_Check;
	}
	inline void set_ChangeEnable(bool _check)
	{
		Enable_Check = _check;
	}
};