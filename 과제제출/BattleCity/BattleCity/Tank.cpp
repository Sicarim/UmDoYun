#include "Tank.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"

//������
Tank::Tank()
{
	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();

	pos_x = 0;
	pos_y = 0;
}

//�ʱ�ȭ(override)
void Tank::Init(int _x, int _y)
{
	//�ӽ� ��Ʈ�� ����
	DoEngine::BitMap* tmp_bit = NULL;

	//��ũ ����
	m_sTag = "Enemy";

	//���� ��ġ �ʱ�ȭ
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

	//��Ʈ�� ���� �ֱ�
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

//Ű�Է�(override)
bool Tank::Input(int _state)
{
	return false;
}

//Update�Լ�(override)
void Tank::Update(float _fETime)
{
	curTime = _fETime;

	//ź�˿� �¾Ҵٸ�...
	if (m_Coll.isCollider("Bullet"))
	{
		is_Destroy = true;
	}
}

//Draw �Լ�(override)
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

//Draw �Լ�(override)
void Tank::Draw(int _x, int _y)
{

}

//Release() �Լ�(override)
void Tank::Release()
{

}

//�Ҹ���
Tank::~Tank()
{

}