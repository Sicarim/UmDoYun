#pragma once
#include "Mecro.h"
#include "BItMap.h"
#include "Singleton.h"

class BitMapManager : public Singleton <BitMapManager>
{
private:
	vector<BitMap> m_Bit;
	BitMap* tmp_BitMap;

	int setX;
	int setY;
	int CardW;

public:
	BitMapManager(); //생성자

	void All_Init(HWND hWnd, HINSTANCE _hInst); //모두 초기화
	void All_Draw(HDC hdc); //모두 그리기
	void Maching_Card(HDC hdc, int _ID, int _setX, int _setY); //카드 매칭
	void BlackCard_Draw(HDC hdc, int _setX, int _setY); //검정 카드 그리기
	void BitMap_Erase(HDC hdc, int _ID, int _setX, int _setY); //카드 지우기
	int get_BitID(int _ID); //ID리턴


	~BitMapManager(); //소멸자

	inline int get_Size()
	{
		return CardW * CORRECTION;
	}
};