#pragma once
#include "Mecro.h"
#include "Singleton.h"
#include "BitMap.h"

class BitMapManager : public Singleton<BitMapManager>
{
private:
	BitMap* m_bit;

	HDC hAlphaDC;
	HBITMAP hAlphaImage;
	HBITMAP hAlphaOldBitMap;

	HDC BackDC;
	HBITMAP hBackImage;
	HBITMAP hBackOldBitMap;

	vector<BitMap> m_ChessMap; //�� ���Ϳ� ���
	vector<BitMap> m_White_Unit; //��� ���� ���Ϳ� ���
	vector<BitMap> m_Black_Unit; //���� ���� ���Ϳ� ���

public:
	BitMapManager();

	void All_Init(HWND hWnd); //�ϰ� �ʱ�ȭ
	void All_Draw(HWND hWnd); //�ϰ� �׸���

	void Map_Init(HWND hWnd); //�� �ʱ�ȭ
	void Map_Draw(HWND hWnd); //�� �׸���
	void Unit_Init(HWND hWnd); //ü���� �ʱ�ȭ
	void Unit_Draw(HWND hWnd, int _unix, int _uniy, UNIT_CLASS _class, int _num); //ü���� �׸���
	void Unit_BlendDraw(HWND hWnd, int _unix, int _uniy); //������ ���� �ִ°��� �׸���
	void Select_Draw(HWND hWnd, int _unix, int _uniy); //���� ĭ �׸���
	void Data_Release(); //������ ����
	~BitMapManager();
};