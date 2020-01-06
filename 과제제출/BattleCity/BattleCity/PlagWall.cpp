#include "PlagWall.h"
#include "ResourcesManager.h"
#include "GameManager.h"
#include "MapTool.h"

//������
PlagWall::PlagWall()
{
	m_vEgle.clear();
	m_wSize = 0;
	m_hSize = 0;
	m_posx = 0;
	m_posy = 0;
}

//�ʱ�ȭ(override)
void PlagWall::Init(int _x, int _y)
{
	DoEngine::BitMap* tmp_bit = NULL;
	m_vEgle.reserve(2);

	//��Ʈ�� ���� �ֱ�
	tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block13.bmp");
	m_vEgle.push_back(tmp_bit);
	tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block14.bmp");
	m_vEgle.push_back(tmp_bit);

	m_wSize = (m_vEgle[0]->get_Width() * OBJECT_COL);
	m_hSize = (m_vEgle[0]->get_Height() * OBJECT_COL);
	m_posx = _x;
	m_posy = _y;
	
	isDestroy = false;
	//�ݶ��̴� ���� �ʱ�ȭ
	m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, (m_vEgle[0]->get_Width()) * OBJECT_COL, (m_vEgle[0]->get_Height()) * OBJECT_COL);
}

//Ű�Է�(override)
bool PlagWall::Input(int _state)
{
	return false;
}

//Update�Լ�(override)
void PlagWall::Update(float _fETime)
{
	//ź�˿� �¾Ҵٸ�..
	if (m_Coll.isCollider("Bullet"))
	{
		isDestroy = true;
		GameManager::get_Instance()->Game_Lose();
	}
}

//Draw �Լ�(override)
void PlagWall::Draw()
{
	//�� �׸���
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

//Draw �Լ�(override)
void PlagWall::Draw(int _x, int _y)
{

}

//Release() �Լ�(override)
void PlagWall::Release()
{
	m_vEgle.clear();
}

//�±� ���� 
void PlagWall::set_tag(string _tag)
{
	m_tag = _tag;
}

//�Ҹ���
PlagWall::~PlagWall()
{

}