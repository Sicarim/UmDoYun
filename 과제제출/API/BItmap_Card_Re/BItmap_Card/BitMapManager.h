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
	BitMapManager(); //������

	void All_Init(HWND hWnd, HINSTANCE _hInst); //��� �ʱ�ȭ
	void All_Draw(HDC hdc); //��� �׸���
	void Maching_Card(HDC hdc, int _ID, int _setX, int _setY); //ī�� ��Ī
	void BlackCard_Draw(HDC hdc, int _setX, int _setY); //���� ī�� �׸���
	void BitMap_Erase(HDC hdc, int _ID, int _setX, int _setY); //ī�� �����
	int get_BitID(int _ID); //ID����


	~BitMapManager(); //�Ҹ���

	inline int get_Size()
	{
		return CardW * CORRECTION;
	}
};