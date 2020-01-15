#include "BitMapManager.h"

//생성자
BitMapManager::BitMapManager()
{
	m_Bit = NULL;
}

//초기화
void BitMapManager::Init(HWND hWnd, int _posx, int _posy)
{
	m_Bit = new BitMap;
	m_Bit->Bit_Init(hWnd, _posx, _posy);
}

//그리기
void BitMapManager::Draw(HWND hWnd, int _posx, int _posy, int _shapex, int _shapey)
{
	m_Bit->Bit_Draw(hWnd, _posx, _posy, _shapex, _shapey);
}

//소멸자
BitMapManager::~BitMapManager()
{
	if (m_Bit != NULL)
	{
		delete m_Bit;
	}
	m_Bit = NULL;
}