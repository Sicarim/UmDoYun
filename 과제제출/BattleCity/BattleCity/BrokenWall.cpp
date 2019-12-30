#include "BrokenWall.h"
#include "ResourcesManager.h"
#include "GameManager.h"
#include "MapTool.h"

//������
BrokenWall::BrokenWall()
{
	m_vBlockBit.clear();
	m_wSize = 0;
	m_hSize = 0;
	m_posx = 0;
	m_posy = 0;
}

//�ʱ�ȭ(override)
void BrokenWall::Init(int _x, int _y)
{
	DoEngine::BitMap* tmp_bit = NULL;
	m_vBlockBit.reserve(BLOCK_COUNT);

	//��Ʈ�� ���� �ֱ�
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		wsprintf(buf, "RES\\block0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vBlockBit.push_back(tmp_bit);
	}

	m_wSize = (m_vBlockBit[0]->get_Width() * OBJECT_COL);
	m_hSize = (m_vBlockBit[0]->get_Height() * OBJECT_COL);
	m_posx = _x;
	m_posy = _y;

	tmp_Block = m_vBlockBit[0];
	HitBlock = 0;
	HitSel = 0;
	BeforeHit = false;
	isDestroy = false;
	//�ݶ��̴� ���� �ʱ�ȭ
	m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, (m_vBlockBit[0]->get_Width()) * OBJECT_COL, (m_vBlockBit[0]->get_Height()) * OBJECT_COL);
}

//Ű�Է�(override)
bool BrokenWall::Input(int _state)
{
	return false;
}

//Update�Լ�(override)
void BrokenWall::Update(float _fETime)
{
	BeforeHit = false;
	//ź�˿� �¾Ҵٸ�..
	if (m_Coll.isCollider("Bullet"))
	{
		HitBlock++;
		BeforeHit = true;
	}
}

//Draw �Լ�(override)
void BrokenWall::Draw()
{
	//�� �׸���
	if (!isDestroy)
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
	}

	//�浹�� ������ ����
	if (HitBlock == 1 && BeforeHit)
	{
		Broken_wall = GameManager::get_Instance()->get_BulletDir();
		
		switch (Broken_wall)
		{
		case LOOK_UP:
			tmp_Block = m_vBlockBit[1];
			m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, ((m_vBlockBit[0]->get_Width()) * OBJECT_COL), ((m_vBlockBit[0]->get_Height()) * OBJECT_COL) / 2);
			break;
		case LOOK_DOWN:
			tmp_Block = m_vBlockBit[3];
			m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize + (m_hSize * 0.5), ((m_vBlockBit[0]->get_Width()) * OBJECT_COL), ((m_vBlockBit[0]->get_Height()) * OBJECT_COL) / 2);
			break;
		case LOOK_LEFT:
			tmp_Block = m_vBlockBit[2];
			m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize, H_SPACE + m_posy * m_hSize, ((m_vBlockBit[0]->get_Width()) * OBJECT_COL) / 2, (m_vBlockBit[0]->get_Height()) * OBJECT_COL);
			break;
		case LOOK_RIGHT:
			tmp_Block = m_vBlockBit[4];
			m_Coll.Init_Collider(m_tag, W_SPACE + m_posx * m_wSize + (m_wSize * 0.5), H_SPACE + m_posy * m_hSize, ((m_vBlockBit[0]->get_Width()) * OBJECT_COL) / 2, (m_vBlockBit[0]->get_Height()) * OBJECT_COL);
			break;
		}
	}

	else if (HitBlock == BLOCK_HEALTH)
	{
		m_Coll.DeleteCollider();
		isDestroy = true;
		//�ı��Ǹ� ��� �ٲ۴�
		DoEngine::MapTool::get_Instance()->set_MapInfo(m_posx, m_posx, NO_WALL);
	}

	m_Coll.Draw_Collider();
}

//Draw �Լ�(override)
void BrokenWall::Draw(int _x, int _y)
{
	
}

//Release() �Լ�(override)
void BrokenWall::Release()
{

}

//�±� ���� 
void BrokenWall::set_tag(string _tag)
{
	m_tag = _tag;
}

//�Ҹ���
BrokenWall::~BrokenWall()
{

}