#include "Bullet.h"
#include "ResourcesManager.h"

//������
Bullet::Bullet()
{
	m_BulletBit = NULL;
	pos_x = 0;
	pos_y = 0;
}

//�ʱ�ȭ(override)
void Bullet::Init(int _x, int _y)
{
	pos_x = _x;
	pos_y = _y;

	//ź�� ���ҽ� �޾ƿ���
	m_BulletBit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\missile_00.bmp");

}

//Ű�Է�(override)
bool Bullet::Input(int _state)
{
	return false;
}

//Update�Լ�(override)
void Bullet::Update(float _fETime)
{

}

//Draw �Լ�(override)
void Bullet::Draw()
{
	m_BulletBit->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
	m_Coll.Draw_Collider(pos_x, pos_y, m_BulletBit->get_Height() * COL_SIZE, m_BulletBit->get_Height() * COL_SIZE);
}

//Draw �Լ�(override)
void Bullet::Draw(int _x, int _y)
{
	
}

//Release() �Լ�(override)
void Bullet::Release()
{
}

//�Ҹ���
Bullet::~Bullet()
{

}