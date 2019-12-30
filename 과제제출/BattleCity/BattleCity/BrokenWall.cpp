#include "BrokenWall.h"
#include "ResourcesManager.h"
#include "GameManager.h"
#include "MapTool.h"

//생성자
BrokenWall::BrokenWall()
{
	m_vBlockBit.clear();
	m_wSize = 0;
	m_hSize = 0;
	m_posx = 0;
	m_posy = 0;
}

//초기화(override)
void BrokenWall::Init(int _x, int _y)
{
	DoEngine::BitMap* tmp_bit = NULL;
	m_vBlockBit.reserve(BLOCK_COUNT);

	//비트맵 집어 넣기
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		wsprintf(buf, "RES\\block0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vBlockBit.push_back(tmp_bit);
	}

	m_wSize = (m_vBlockBit[0]->get_Width() * OBJECT_COL);
	m_hSize = (m_vBlockBit[0]->get_Height() * OBJECT_COL);
	m_posx = _x;
	m_posy = _y;

	tmp_Block = m_vBlockBit[0];
	HitBlock = 0;
	HitSel = 0;
	BeforeHit = false;
	isDestroy = false;
	//콜라이더 범위 초기화
	m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, (m_vBlockBit[0]->get_Width()) * OBJECT_COL, (m_vBlockBit[0]->get_Height()) * OBJECT_COL);
}

//키입력(override)
bool BrokenWall::Input(int _state)
{
	return false;
}

//Update함수(override)
void BrokenWall::Update(float _fETime)
{
	BeforeHit = false;
	//탄알에 맞았다면..
	if (m_Coll.isCollider("Bullet"))
	{
		HitBlock++;
		BeforeHit = true;
	}
}

//Draw 함수(override)
void BrokenWall::Draw()
{
	//블럭 그리기
	if (!isDestroy)
	{
		if (m_posx == 0 && m_posy == 0)
		{
			tmp_Block->Draw(W_SPACE + m_posx, H_SPACE + m_posy, OBJECT_COL, OBJECT_COL);
		}
		else if (m_posx == 0 && m_posy != 0)
		{
			tmp_Block->Draw(W_SPACE + m_posx, H_SPACE + m_posy * m_hSize, OBJECT_COL, OBJECT_COL);
		}
		else if (m_posx != 0 && m_posy == 0)
		{
			tmp_Block->Draw(W_SPACE + m_posx * m_wSize, H_SPACE + m_posy, OBJECT_COL, OBJECT_COL);
		}
		else
		{
			tmp_Block->Draw(W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, OBJECT_COL, OBJECT_COL);
		}
	}

	//충돌한 방향을 저장
	if (HitBlock == 1 && BeforeHit)
	{
		Broken_wall = GameManager::get_Instance()->get_BulletDir();
		
		switch (Broken_wall)
		{
		case LOOK_UP:
			tmp_Block = m_vBlockBit[1];
			m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, ((m_vBlockBit[0]->get_Width()) * OBJECT_COL), ((m_vBlockBit[0]->get_Height()) * OBJECT_COL) / 2);
			break;
		case LOOK_DOWN:
			tmp_Block = m_vBlockBit[3];
			m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize + (m_hSize * 0.5), ((m_vBlockBit[0]->get_Width()) * OBJECT_COL), ((m_vBlockBit[0]->get_Height()) * OBJECT_COL) / 2);
			break;
		case LOOK_LEFT:
			tmp_Block = m_vBlockBit[2];
			m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, ((m_vBlockBit[0]->get_Width()) * OBJECT_COL) / 2, (m_vBlockBit[0]->get_Height()) * OBJECT_COL);
			break;
		case LOOK_RIGHT:
			tmp_Block = m_vBlockBit[4];
			m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize + (m_wSize * 0.5), H_SPACE + m_posy * m_hSize, ((m_vBlockBit[0]->get_Width()) * OBJECT_COL) / 2, (m_vBlockBit[0]->get_Height()) * OBJECT_COL);
			break;
		}
	}

	else if (HitBlock == BLOCK_HEALTH)
	{
		m_Coll.DeleteCollider();
		isDestroy = true;
		//파괴되면 길로 바꾼다
		DoEngine::MapTool::get_Instance()->set_MapInfo(m_posx, m_posx, NO_WALL);
	}

	m_Coll.Draw_Collider();
}

//Draw 함수(override)
void BrokenWall::Draw(int _x, int _y)
{
	
}

//Release() 함수(override)
void BrokenWall::Release()
{

}

//태그 저장 
void BrokenWall::set_tag(string _tag)
{
	m_tag = _tag;
}

//소멸자
BrokenWall::~BrokenWall()
{

}