#include "Bullet.h"
#include "ResourcesManager.h"

//생성자
Bullet::Bullet()
{
	tmp_Bullet = NULL;
	m_vBulletBit.clear();
	pos_x = 0;
	pos_y = 0;
	m_sTag = "Bullet";
}

//초기화(override)
void Bullet::Init(int _x, int _y)
{
	pos_x = _x;
	pos_y = _y;
	Fire_Time = 0.0f;
	curTime = 0.0f;
	is_Save = true;

	//탄알 리소스 받아오기
	for (int i = 0; i < 4; i++)
	{
		wsprintf(buf, "RES\\missile_0%d.bmp", i);
		tmp_Bullet = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vBulletBit.push_back(tmp_Bullet);
	}
	m_BulletDir = m_vBulletBit[1];
	
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
}

//Draw 함수(override)
void Bullet::Draw()
{
	Fire_Time += curTime;

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

	m_BulletDir->Draw((pos_x + 25), pos_y + 25, 2.0f, 2.0f);

	if (m_BulletDir == m_vBulletBit[1] || m_BulletDir == m_vBulletBit[2])
	{
		m_Coll.Init_Collider(m_sTag, pos_x + 25, pos_y + 25, m_BulletDir->get_Width() * COL_SIZE, m_BulletDir->get_Height() * COL_SIZE);
		m_Coll.Draw_Collider();
	}
	else
	{
		m_Coll.Init_Collider(m_sTag, pos_x + 25, pos_y + 25, m_BulletDir->get_Width() * COL_SIZE, m_BulletDir->get_Height() * COL_SIZE);
		m_Coll.Draw_Collider();
	}
	
	if (Fire_Time >= SAVE_TIME)
	{
		is_Save = false;
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

//소멸자
Bullet::~Bullet()
{

}