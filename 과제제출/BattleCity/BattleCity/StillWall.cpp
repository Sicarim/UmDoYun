#include "StillWall.h"
#include "ResourcesManager.h"

//생성자
StillWall::StillWall()
{
	m_pBlockBit = NULL;
	m_wSize = 0;
	m_hSize = 0;
}

//초기화(override)
void StillWall::Init(int _x, int _y)
{
	m_pBlockBit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block08.bmp");
	m_wSize = m_pBlockBit->get_Width() * OBJECT_COL;
	m_hSize = m_pBlockBit->get_Height() * OBJECT_COL;
}

//키입력(override)
bool StillWall::Input(int _state)
{
	return false;
}

//Update함수(override)
void StillWall::Update(float _fETime)
{

}

//Draw 함수(override)
void StillWall::Draw()
{

}

//Draw 함수(override)
void StillWall::Draw(int _x, int _y)
{
	if (_x == 0 && _y == 0)
	{
		m_pBlockBit->Draw(W_SPACE + _x, H_SPACE + _y, OBJECT_COL, OBJECT_COL);
	}
	else if (_x == 0 && _y != 0)
	{
		m_pBlockBit->Draw(W_SPACE + _x, H_SPACE + _y * m_hSize, OBJECT_COL, OBJECT_COL);
	}
	else if (_x != 0 && _y == 0)
	{
		m_pBlockBit->Draw(W_SPACE + _x * m_wSize, H_SPACE + _y, OBJECT_COL, OBJECT_COL);
	}
	else
	{
		m_pBlockBit->Draw(W_SPACE + _x * m_wSize, H_SPACE + _y * m_hSize, OBJECT_COL, OBJECT_COL);
	}
}

//Release() 함수(override)
void StillWall::Release()
{

}

//소멸자
StillWall::~StillWall()
{

}