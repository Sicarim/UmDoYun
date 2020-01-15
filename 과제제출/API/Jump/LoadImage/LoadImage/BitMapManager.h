#pragma once
#include "Mecro.h"
#include "BitMap.h"
#include "Singleton.h"

class BitMapManager : public Singleton<BitMapManager>
{
private:
	BitMap* m_BIt;
public:
	BitMapManager(); //생성자
	
	void Init(HWND hWnd); //초기화
	void Draw(HDC hdc, int _posx, int _posy, int _x = 0, int _y = 0); //그리기

	~BitMapManager(); //소멸자
};