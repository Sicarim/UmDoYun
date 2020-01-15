#pragma once
#include "Mecro.h"
#include "BitMap.h"
#include "Singleton.h"

class BitMapManager : public Singleton<BitMapManager>
{
private:
	BitMap* m_BIt;
public:
	BitMapManager(); //������
	
	void Init(HWND hWnd); //�ʱ�ȭ
	void Draw(HDC hdc, int _posx, int _posy, int _x = 0, int _y = 0); //�׸���

	~BitMapManager(); //�Ҹ���
};