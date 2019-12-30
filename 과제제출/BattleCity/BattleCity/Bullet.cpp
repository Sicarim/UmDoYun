#include "Bullet.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//생성자
Bullet::Bullet()
{
	tmp_Bullet = NULL;
	m_vBulletBit.clear();
	pos_x = 0;
	pos_y = 0;
	Boom_Time = 0.0f;	
}

//초기화(override)
void Bullet::Init(int _x, int _y)
{
	pos_x = _x + 25;
	pos_y = _y + 25;
	Fire_Time = 0.0f;
	curTime = 0.0f;
	is_Save = true;
	isDestroy = false;
	Boom_Time = 0.0f;
	m_sTag = "Bullet";

	//탄알 리소스 받아오기
	for (int i = 0; i < 4; i++)
	{
		wsprintf(buf, "RES\\missile_0%d.bmp", i);
		tmp_Bullet = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vBulletBit.push_back(tmp_Bullet);
	}

	//폭팔 이미지
	for (int i = 0; i < ENEMY_KIND + 3; i++)
	{
		wsprintf(buf, "RES\\explosion_0%d.bmp", i);
		tmp_Bullet = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vDestroy.push_back(tmp_Bullet);
	}

	m_BulletDir = m_vBulletBit[1];
	Add_Coll();
}

//충돌을 저장할 목록
void Bullet::Add_Coll()
{
	int tmp_Count;

	m_vColl.push_back("Enemy");

	//부서지는 벽 등록
	tmp_Count = GameManager::get_Instance()->get_BrokenCount();
	for (int i = 0; i < tmp_Count; i++)
	{
		wsprintf(buf, "BrokenWall%d", i);
		m_vColl.push_back((string)buf);
	}

	//강철 벽 등록
	tmp_Count = GameManager::get_Instance()->get_StillCount();
	for (int i = 0; i < tmp_Count; i++)
	{
		wsprintf(buf, "StiilWall%d", i);
		m_vColl.push_back((string)buf);
	}
}

//키입력(override)
bool Bullet::Input(int _state)
{
	return false;
}

//Update함수(override)
void Bullet::Update(float _fETime)
{
	curTime = _fETime;

	if (m_Coll.get_Collider("BackGround").left >= pos_x || m_Coll.get_Collider("BackGround").top >= pos_y || m_Coll.get_Collider("BackGround").bottom <= pos_y + (m_BulletDir->get_Height()) * COL_SIZE || m_Coll.get_Collider("BackGround").right <= pos_x + (m_BulletDir->get_Width()) * COL_SIZE)
	{
		isDestroy = true;
	}

	if (m_Coll.isCollider(m_vColl))
	{
		isDestroy = true;
	}
	
}

//Draw 함수(override)
void Bullet::Draw()
{
	//탄알이 부서졌다면...
	if (isDestroy)
	{
		m_Coll.DeleteCollider();

		Boom_Time += curTime;

		if (Boom_Time <= 0.2f)
		{
			m_vDestroy[0]->Draw(pos_x - 25, pos_y - 20, COL_SIZE, COL_SIZE);
		}
		else if (Boom_Time <= 0.3f)
		{
			m_vDestroy[1]->Draw(pos_x - 25, pos_y - 20, COL_SIZE, COL_SIZE);
		}
		else if (Boom_Time <= 0.4f)
		{
			m_vDestroy[2]->Draw(pos_x - 25, pos_y - 20, COL_SIZE, COL_SIZE);
		}
		else if (Boom_Time <= 0.5f)
		{
			m_vDestroy[3]->Draw(pos_x - 25, pos_y - 20, COL_SIZE - 0.8f, COL_SIZE - 0.8f);
		}
		else if (Boom_Time <= 0.6f)
		{
			m_vDestroy[4]->Draw(pos_x - 25, pos_y - 20, COL_SIZE - 0.8f, COL_SIZE - 0.8f);
			is_Save = false;
		}
	}
	else
	{
		//총알 방향
		switch (Bullet_dir)
		{
		case LOOK_UP:
			m_BulletDir = m_vBulletBit[1];
			pos_y -= curTime * FIRE_SPEED;
			break;
		case LOOK_DOWN:
			m_BulletDir = m_vBulletBit[2];
			pos_y += curTime * FIRE_SPEED;
			break;
		case LOOK_LEFT:
			m_BulletDir = m_vBulletBit[3];
			pos_x -= curTime * FIRE_SPEED;
			break;
		case LOOK_RIGHT:
			m_BulletDir = m_vBulletBit[0];
			pos_x += curTime * FIRE_SPEED;
			break;
		}

		GameManager::get_Instance()->set_BulletDir(Bullet_dir);

		m_BulletDir->Draw(pos_x, pos_y, 2.0f, 2.0f);

		if (m_BulletDir == m_vBulletBit[1] || m_BulletDir == m_vBulletBit[2])
		{
			m_Coll.Init_Collider(m_sTag, pos_x, pos_y, m_BulletDir->get_Width() * COL_SIZE, m_BulletDir->get_Height() * COL_SIZE);
		}
		else
		{
			m_Coll.Init_Collider(m_sTag, pos_x, pos_y, m_BulletDir->get_Width() * COL_SIZE, m_BulletDir->get_Height() * COL_SIZE);
		}
		m_Coll.Draw_Collider();
	}
}

//Draw 함수(override)
void Bullet::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void Bullet::Release()
{

}

//탄알 세이브 여부
bool Bullet::get_FireSave()
{
	return is_Save;
}

//총알 방향 지정
void Bullet::set_BulletDir(int _dir)
{
	Bullet_dir = _dir;
}

//탄알 방향 리턴
int Bullet::get_BulletDir()
{
	return Bullet_dir;
}


//소멸자
Bullet::~Bullet()
{

}