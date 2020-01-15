#include "BitMapManager.h"

//������
BitMapManager::BitMapManager()
{
	m_BIt = NULL;
}

//�ʱ�ȭ
void BitMapManager::Init(HWND hWnd)
{
	m_BIt = new BitMap;
	m_BIt->Bit_Init(hWnd);
}

//�׸���
void BitMapManager::Draw(HDC hdc, int _posx, int _posy, int _x, int _y)
{
	m_BIt->Bit_Draw(hdc, _posx, _posy, _x, _y);
}

//�Ҹ���
BitMapManager::~BitMapManager()
{
	if (m_BIt != NULL)
	{
		delete m_BIt;
	}
	m_BIt = NULL;
}