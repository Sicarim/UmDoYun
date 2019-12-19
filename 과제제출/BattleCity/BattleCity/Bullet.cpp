#include "Bullet.h"
#include "ResourcesManager.h"

//������
Bullet::Bullet()
{
	m_BulletBit = NULL;
	pos_x = 0;
	pos_y = 0;
	m_sTag = "Bullet";
}

//�ʱ�ȭ(override)
void Bullet::Init(int _x, int _y)
{
	pos_x = _x;
	pos_y = _y;
	Fire_Time = 0.0f;
	curTime = 0.0f;
	is_Save = true;

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
	curTime = _fETime;
}

//Draw �Լ�(override)
void Bullet::Draw()
{
	Fire_Time += curTime;

	pos_y -= curTime * FIRE_SPEED;
	m_BulletBit->Draw(pos_x, pos_y, 2.0f, 2.0f);
	m_Coll.Draw_Collider(pos_x, pos_y, m_BulletBit->get_Height() * 5.0f, m_BulletBit->get_Height() * 2.0f);

	if (Fire_Time >= SAVE_TIME)
	{
		is_Save = false;
	}
}

//Draw �Լ�(override)
void Bullet::Draw(int _x, int _y)
{

}

//Release() �Լ�(override)
void Bullet::Release()
{

}

//ź�� ���̺� ����
bool Bullet::get_FireSave()
{
	return is_Save;
}

//�Ҹ���
Bullet::~Bullet()
{

}