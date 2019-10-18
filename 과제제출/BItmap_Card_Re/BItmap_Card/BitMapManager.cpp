#include "BitMapManager.h"

BitMapManager::BitMapManager()
{
	srand(time(NULL));
	m_Bit.reserve(BITMAX);
	tmp_BitMap = NULL;

	setX = 30;
	setY = 30;
	CardW = 0;
}

//��� �ʱ�ȭ
void BitMapManager::All_Init(HWND hWnd, HINSTANCE _hInst)
{
	HDC hdc = GetDC(hWnd);
	int Bit_ID = 101;

	for (int i = 0; i < BITMAX; i++)
	{
		tmp_BitMap = new BitMap;
		tmp_BitMap->Init(hdc, _hInst, Bit_ID);
		m_Bit.push_back(*tmp_BitMap);
		Bit_ID++;
	}

	CardW = tmp_BitMap->get_sizeW();
}

//��� �׸���
void BitMapManager::All_Draw(HDC hdc)
{
	for (int i = 0; i < CARDMAX; i++)
	{
		m_Bit[10].Bit_Draw(hdc, setX, setY);

		setX += 120;

		if (i == 9)
		{
			setX = 30;
			setY = 250;
		}
	}
}

//ī�� ��Ī
void BitMapManager::Maching_Card(HDC hdc, int _ID, int _setX, int _setY)
{
	for (int i = 0; i < BITMAX; i++)
	{
		if (m_Bit[i].get_ID() == _ID)
		{
			m_Bit[i].Bit_Draw(hdc, _setX, _setY);
		}
	}
}

int BitMapManager::get_BitID(int _ID)
{
	return m_Bit[_ID].get_ID();
}

//���� ī�� �׸���
void BitMapManager::BlackCard_Draw(HDC hdc, int _setX, int _setY)
{
	m_Bit[10].Bit_Draw(hdc, _setX, _setY);
}

//ī�� �����
void BitMapManager::BitMap_Erase(HDC hdc, int _ID, int _setX, int _setY)
{
	for (int i = 0; i < BITMAX; i++)
	{
		if (m_Bit[i].get_ID() == _ID)
		{
			m_Bit[i].Erase(hdc, _setX, _setY);
		}
	}
}

//�Ҹ���
BitMapManager::~BitMapManager()
{
	m_Bit.clear();

	if (tmp_BitMap != NULL)
	{
		delete tmp_BitMap;
	}
	tmp_BitMap = NULL;
}