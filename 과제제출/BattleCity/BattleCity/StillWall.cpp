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
	m_posx = _x;
	m_posy = _y;
	m_pBlockBit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block08.bmp");
	m_wSize = m_pBlockBit->get_Width() * OBJECT_COL;
	m_hSize = m_pBlockBit->get_Height() * OBJECT_COL;

	//콜라이더 범위 초기화
	m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, (m_pBlockBit->get_Width()) * OBJECT_COL, (m_pBlockBit->get_Height()) * OBJECT_COL);
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
	if (m_posx == 0 && m_posy == 0)
	{
		m_pBlockBit->Draw(W_SPACE + m_posx, H_SPACE + m_posy, OBJECT_COL, OBJECT_COL);
	}
	else if (m_posx == 0 && m_posy != 0)
	{
		m_pBlockBit->Draw(W_SPACE + m_posx, H_SPACE + m_posy * m_hSize, OBJECT_COL, OBJECT_COL);
	}
	else if (m_posx != 0 && m_posy == 0)
	{
		m_pBlockBit->Draw(W_SPACE + m_posx * m_wSize, H_SPACE + m_posy, OBJECT_COL, OBJECT_COL);
	}
	else
	{
		m_pBlockBit->Draw(W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, OBJECT_COL, OBJECT_COL);
	}
	m_Coll.Draw_Collider();
}

//Draw 함수(override)
void StillWall::Draw(int _x, int _y)
{
	
}

//Release() 함수(override)
void StillWall::Release()
{

}

//태그 저장 
void StillWall::set_tag(string _tag)
{
	m_tag = _tag;
}

//소멸자
StillWall::~StillWall()
{

}