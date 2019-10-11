#include "BitMapManager.h"

BitMapManager* BitMapManager::m_hInstence = NULL;

//������
BitMapManager::BitMapManager()
{
	m_Bit.reserve(10);
}

//�ʱ�ȭ
void BitMapManager::Init(HWND hWnd, HINSTANCE _hInst)
{
	HDC hdc = GetDC(hWnd);
	int bit_id = 113;

	BitMap* tmp_bit;

	for (int i = 0; i < 10; i++)
	{
		tmp_bit = new BitMap;
		tmp_bit->Init(hdc, _hInst, bit_id);

		m_Bit.push_back(*tmp_bit);
		bit_id++;
	}
}

//�Ҹ���
BitMapManager::~BitMapManager()
{
	m_Bit.clear();
}