#include "Tank.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"

//생성자
Tank::Tank()
{
	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();

	pos_x = 0;
	pos_y = 0;
}

//초기화(override)
void Tank::Init(int _x, int _y)
{
	//임시 비트맵 선언
	DoEngine::BitMap* tmp_bit = NULL;

	//태크 지정
	m_sTag = "Enemy";

	//시작 위치 초기화
	pos_x = _x;
	pos_y = _y;
	is_Destroy = false;
	curTime = 0.0f;
	Boom_Time = 0.0f;

	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();

	m_vLeft.reserve(ENEMY_KIND);
	m_vRight.reserve(ENEMY_KIND);	
	m_vUp.reserve(ENEMY_KIND);
	m_vDown.reserve(ENEMY_KIND);

	//비트맵 집어 넣기
	for (int i = 0; i < ENEMY_KIND; i++)
	{
		wsprintf(buf, "RES\\e_left_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vLeft.push_back(tmp_bit);
		wsprintf(buf, "RES\\e_right_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vRight.push_back(tmp_bit);
		wsprintf(buf, "RES\\e_up_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vUp.push_back(tmp_bit);
		wsprintf(buf, "RES\\e_down_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vDown.push_back(tmp_bit);
	}

	for (int i = 0; i < ENEMY_KIND + 3; i++)
	{
		wsprintf(buf, "RES\\explosion_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vDestroy.push_back(tmp_bit);
	}
}

//키입력(override)
bool Tank::Input(int _state)
{
	return false;
}

//Update함수(override)
void Tank::Update(float _fETime)
{
	curTime = _fETime;

	//탄알에 맞았다면...
	if (m_Coll.isCollider("Bullet"))
	{
		is_Destroy = true;
	}
}

//Draw 함수(override)
void Tank::Draw()
{	
	if (is_Destroy)
	{
		Boom_Time += curTime;
		if (Boom_Time <= 0.2f)
		{
			m_vDestroy[0]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
		}
		else if (Boom_Time <= 0.3f)
		{
			m_vDestroy[1]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
		}
		else if (Boom_Time <= 0.4f)
		{
			m_vDestroy[2]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
		}
		else if (Boom_Time <= 0.5f)
		{
			m_vDestroy[3]->Draw(pos_x, pos_y, COL_SIZE - 0.8f, COL_SIZE - 0.8f);
		}
		else if (Boom_Time <= 0.6f)
		{
			m_vDestroy[4]->Draw(pos_x, pos_y, COL_SIZE - 0.8f, COL_SIZE - 0.8f);
		}
	}
	else
	{
		m_Coll.Init_Collider(m_sTag, pos_x, pos_y, m_vDown[1]->get_Width() * COL_SIZE, m_vDown[1]->get_Height() * COL_SIZE);
		m_vDown[1]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
		m_Coll.Draw_Collider(pos_x, pos_y, m_vDown[1]->get_Width() * COL_SIZE, m_vDown[1]->get_Height() * COL_SIZE);
	}
	
}

//Draw 함수(override)
void Tank::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void Tank::Release()
{

}

//소멸자
Tank::~Tank()
{

}