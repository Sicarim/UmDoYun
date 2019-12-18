#include "Bullet.h"
#include "ResourcesManager.h"

//생성자
Bullet::Bullet()
{
	m_BulletBit = NULL;
	pos_x = 0;
	pos_y = 0;
}

//초기화(override)
void Bullet::Init(int _x, int _y)
{
	pos_x = _x;
	pos_y = _y;

	//탄알 리소스 받아오기
	m_BulletBit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\missile_00.bmp");

}

//키입력(override)
bool Bullet::Input(int _state)
{
	return false;
}

//Update함수(override)
void Bullet::Update(float _fETime)
{

}

//Draw 함수(override)
void Bullet::Draw()
{
	m_BulletBit->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
	m_Coll.Draw_Collider(pos_x, pos_y, m_BulletBit->get_Height() * COL_SIZE, m_BulletBit->get_Height() * COL_SIZE);
}

//Draw 함수(override)
void Bullet::Draw(int _x, int _y)
{
	
}

//Release() 함수(override)
void Bullet::Release()
{
}

//소멸자
Bullet::~Bullet()
{

}