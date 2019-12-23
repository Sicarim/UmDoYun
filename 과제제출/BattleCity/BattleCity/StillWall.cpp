#include "StillWall.h"
#include "ResourcesManager.h"

//������
StillWall::StillWall()
{
	m_pBlockBit = NULL;
	m_wSize = 0;
	m_hSize = 0;
}

//�ʱ�ȭ(override)
void StillWall::Init(int _x, int _y)
{
	m_pBlockBit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block08.bmp");
	m_wSize = m_pBlockBit->get_Width() * OBJECT_COL;
	m_hSize = m_pBlockBit->get_Height() * OBJECT_COL;
}

//Ű�Է�(override)
bool StillWall::Input(int _state)
{
	return false;
}

//Update�Լ�(override)
void StillWall::Update(float _fETime)
{

}

//Draw �Լ�(override)
void StillWall::Draw()
{

}

//Draw �Լ�(override)
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

//Release() �Լ�(override)
void StillWall::Release()
{

}

//�Ҹ���
StillWall::~StillWall()
{

}