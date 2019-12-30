#include "StillWall.h"
#include "ResourcesManager.h"

//������
StillWall::StillWall()
{
	m_pBlockBit = NULL;
	m_wSize = 0;
	m_hSize = 0;
}

//�ʱ�ȭ(override)
void StillWall::Init(int _x, int _y)
{
	m_posx = _x;
	m_posy = _y;
	m_pBlockBit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block08.bmp");
	m_wSize = m_pBlockBit->get_Width() * OBJECT_COL;
	m_hSize = m_pBlockBit->get_Height() * OBJECT_COL;

	//�ݶ��̴� ���� �ʱ�ȭ
	m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, (m_pBlockBit->get_Width()) * OBJECT_COL, (m_pBlockBit->get_Height()) * OBJECT_COL);
}

//Ű�Է�(override)
bool StillWall::Input(int _state)
{
	return false;
}

//Update�Լ�(override)
void StillWall::Update(float _fETime)
{

}

//Draw �Լ�(override)
void StillWall::Draw()
{
	if (m_posx == 0 && m_posy == 0)
	{
		m_pBlockBit->Draw(W_SPACE + m_posx, H_SPACE + m_posy, OBJECT_COL, OBJECT_COL);
	}
	else if (m_posx == 0 && m_posy != 0)
	{
		m_pBlockBit->Draw(W_SPACE + m_posx, H_SPACE + m_posy * m_hSize, OBJECT_COL, OBJECT_COL);
	}
	else if (m_posx != 0 && m_posy == 0)
	{
		m_pBlockBit->Draw(W_SPACE + m_posx * m_wSize, H_SPACE + m_posy, OBJECT_COL, OBJECT_COL);
	}
	else
	{
		m_pBlockBit->Draw(W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, OBJECT_COL, OBJECT_COL);
	}
	m_Coll.Draw_Collider();
}

//Draw �Լ�(override)
void StillWall::Draw(int _x, int _y)
{
	
}

//Release() �Լ�(override)
void StillWall::Release()
{

}

//�±� ���� 
void StillWall::set_tag(string _tag)
{
	m_tag = _tag;
}

//�Ҹ���
StillWall::~StillWall()
{

}