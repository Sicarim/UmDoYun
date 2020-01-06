#include "PlagWall.h"
#include "ResourcesManager.h"
#include "GameManager.h"
#include "MapTool.h"

//생성자
PlagWall::PlagWall()
{
	m_vEgle.clear();
	m_wSize = 0;
	m_hSize = 0;
	m_posx = 0;
	m_posy = 0;
}

//초기화(override)
void PlagWall::Init(int _x, int _y)
{
	DoEngine::BitMap* tmp_bit = NULL;
	m_vEgle.reserve(2);

	//비트맵 집어 넣기
	tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block13.bmp");
	m_vEgle.push_back(tmp_bit);
	tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block14.bmp");
	m_vEgle.push_back(tmp_bit);

	m_wSize = (m_vEgle[0]->get_Width() * OBJECT_COL);
	m_hSize = (m_vEgle[0]->get_Height() * OBJECT_COL);
	m_posx = _x;
	m_posy = _y;
	
	isDestroy = false;
	//콜라이더 범위 초기화
	m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, (m_vEgle[0]->get_Width()) * OBJECT_COL, (m_vEgle[0]->get_Height()) * OBJECT_COL);
}

//키입력(override)
bool PlagWall::Input(int _state)
{
	return false;
}

//Update함수(override)
void PlagWall::Update(float _fETime)
{
	//탄알에 맞았다면..
	if (m_Coll.isCollider("Bullet"))
	{
		isDestroy = true;
		GameManager::get_Instance()->Game_Lose();
	}
}

//Draw 함수(override)
void PlagWall::Draw()
{
	//블럭 그리기
	if (!isDestroy)
	{
		m_vEgle[0]->Draw(W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, OBJECT_COL, OBJECT_COL);
	}
	else
	{
		m_vEgle[1]->Draw(W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, OBJECT_COL, OBJECT_COL);
	}
	m_Coll.Draw_Collider();
}

//Draw 함수(override)
void PlagWall::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void PlagWall::Release()
{
	m_vEgle.clear();
}

//태그 저장 
void PlagWall::set_tag(string _tag)
{
	m_tag = _tag;
}

//소멸자
PlagWall::~PlagWall()
{

}