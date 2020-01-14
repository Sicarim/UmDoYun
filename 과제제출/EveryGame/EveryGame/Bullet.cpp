#include "Bullet.h"

//������
Bullet::Bullet()
{

}

//�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)(override)
void Bullet::Init(int _x, int _y)
{
	Bullet_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameBullet.bmp");
	pos_x = _x;
	pos_y = _y;
	size_x = Bullet_Bit->get_Width();
	size_y = Bullet_Bit->get_Height();
	curTime = 0.0f;
	Random = rand() % 10 + 1;
	BirthCount = 0;

	isDestroy = false;
	Birth_dir = rand() % 2;

	//ź���� ������ ���Ѵ�.
	if (Birth_dir == 0)
	{
		Birth_Add = 1;
	}
	else
	{
		Birth_Add = -1;
	}
}

//Ű�Է�(override)
bool Bullet::Input(int _state)
{
	//���� �ı��ȴٸ� false�� �����Ѵ�
	if (isDestroy)
	{
		return false;
	}
}

//Update�Լ�(override)
void Bullet::Update(float _fETime)
{
	curTime = _fETime;

	//������ġ�� ���� �������� ����
	if (BirthCount == 0)
	{
		//��
		pos_x += 0.1 * Random * Birth_Add;
		pos_y += curTime * BULLET_SPEED;
	}
	else if (BirthCount == 1)
	{
		//����
		pos_x += curTime * BULLET_SPEED;
		pos_y += 0.1 * Random * Birth_Add;
	}
	else if (BirthCount == 2)
	{
		//�Ʒ�
		pos_x += 0.1 * Random * Birth_Add;
		pos_y -= curTime * BULLET_SPEED;
	}
	else if (BirthCount == 3)
	{
		//������
		pos_x -= curTime * BULLET_SPEED;
		pos_y += 0.1 * Random * Birth_Add;
	}
	if (m_Coll.get_Collider("BackGround").top > pos_y || m_Coll.get_Collider("BackGround").bottom < pos_y + size_y || m_Coll.get_Collider("BackGround").left > pos_x || m_Coll.get_Collider("BackGround").right < pos_x + size_y)
	{
		isDestroy = true;
	}
}

//Draw �Լ�(overloding)(override)
void Bullet::Draw()
{
	if (!isDestroy)
	{
		//ź���� �׸��� ���������� �±� ���
		m_Coll.Init_Collider(m_tag, pos_x, pos_y, size_x * 0.8, size_y * 0.8);
		Bullet_Bit->Draw(pos_x, pos_y, 0.8, 0.8);
		m_Coll.Draw_Collider();
	}
}

//Draw �Լ�(override)
void Bullet::Draw(int _x, int _y)
{

}

//Release() �Լ�(override)
void Bullet::Release()
{
	pos_x = 0;
	pos_y = 0;
	curTime = 0.0f;
	isDestroy = false;
	BirthCount = 0;
	Birth_Add = 0;
	m_Coll.DeleteCollider();
}

//��������
void Bullet::set_Birth(int _num)
{
	wsprintf(buf, "Bullet%d", _num);
	m_tag = buf;
	BirthCount = _num % 4;
}

//�Ҹ���
Bullet::~Bullet()
{

}