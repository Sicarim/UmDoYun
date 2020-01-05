#include "BushWall.h"
#include "ResourcesManager.h"
#include "GameManager.h"
#include "MapTool.h"

//������
BushWall::BushWall()
{
	m_wSize = 0;
	m_hSize = 0;
	m_posx = 0;
	m_posy = 0;
}

//�ʱ�ȭ(override)
void BushWall::Init(int _x, int _y)
{
	tmp_Block = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block06.bmp");

	m_wSize = (tmp_Block->get_Width() * OBJECT_COL);
	m_hSize = (tmp_Block->get_Height() * OBJECT_COL);
	m_posx = _x;
	m_posy = _y;

	HitSel = 0;
	BeforeHit = false;
	//�ݶ��̴� ���� �ʱ�ȭ
	m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, tmp_Block->get_Width() * OBJECT_COL, tmp_Block->get_Height() * OBJECT_COL);
}

//Ű�Է�(override)
bool BushWall::Input(int _state)
{
	return false;
}

//Update�Լ�(override)
void BushWall::Update(float _fETime)
{
	BeforeHit = false;
}

//Draw �Լ�(override)
void BushWall::Draw()
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

	m_Coll.Draw_Collider();
}

//Draw �Լ�(override)
void BushWall::Draw(int _x, int _y)
{

}

//Release() �Լ�(override)
void BushWall::Release()
{

}

//�±� ���� 
void BushWall::set_tag(string _tag)
{
	m_tag = _tag;
}

//�Ҹ���
BushWall::~BushWall()
{

}