#include "BitMapManager.h"

//������
BitMapManager::BitMapManager()
{
	m_Bit = NULL;
}

//�ʱ�ȭ
void BitMapManager::Init(HWND hWnd, int _posx, int _posy)
{
	m_Bit = new BitMap;
	m_Bit->Bit_Init(hWnd, _posx, _posy);
}

//�׸���
void BitMapManager::Draw(HWND hWnd, int _posx, int _posy, int _shapex, int _shapey)
{
	m_Bit->Bit_Draw(hWnd, _posx, _posy, _shapex, _shapey);
}

//�Ҹ���
BitMapManager::~BitMapManager()
{
	if (m_Bit != NULL)
	{
		delete m_Bit;
	}
	m_Bit = NULL;
}