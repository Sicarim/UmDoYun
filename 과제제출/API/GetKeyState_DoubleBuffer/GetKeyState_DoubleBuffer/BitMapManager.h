#pragma once
#include "Mecro.h"
#include "BitMap.h"
#include "Singleton.h"

class BitMapManager : public Singleton<BitMapManager>
{
private:
	BitMap* m_Bit;
public:
	BitMapManager(); //������

	void Init(HWND hWnd, int _posx, int _posy); //�ʱ�ȭ
	void Draw(HWND hWnd, int _posx, int _posy, int _shapex, int _shapey); //�׸���

	~BitMapManager(); //�Ҹ���
};