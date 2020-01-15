#include "BitMapManager.h"

//생성자
BitMapManager::BitMapManager()
{
	m_BIt = NULL;
}

//초기화
void BitMapManager::Init(HWND hWnd)
{
	m_BIt = new BitMap;
	m_BIt->Bit_Init(hWnd);
}

//그리기
void BitMapManager::Draw(HDC hdc, int _posx, int _posy, int _x, int _y)
{
	m_BIt->Bit_Draw(hdc, _posx, _posy, _x, _y);
}

//소멸자
BitMapManager::~BitMapManager()
{
	if (m_BIt != NULL)
	{
		delete m_BIt;
	}
	m_BIt = NULL;
}