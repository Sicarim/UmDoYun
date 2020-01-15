#pragma once
#include "Mecro.h"
#include "BitMap.h"
#include "Singleton.h"

class BitMapManager : public Singleton<BitMapManager>
{
private:
	BitMap* m_Bit;
public:
	BitMapManager(); //생성자

	void Init(HWND hWnd, int _posx, int _posy); //초기화
	void Draw(HWND hWnd, int _posx, int _posy, int _shapex, int _shapey); //그리기

	~BitMapManager(); //소멸자
};