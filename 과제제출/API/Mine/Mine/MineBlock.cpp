#include "MineBlock.h"
#include "ResourcesManager.h"

//������
MineBlock::MineBlock()
{
	m_pMine = NULL;
	Pos_x = 0;
	Pos_x = 0;
}

//�ʱ�ȭ
void MineBlock::Init()
{
	m_pMine = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\mine.bmp");
}

//�׸���(overloading)
void MineBlock::Draw()
{
	m_pMine->Draw((Pos_x * STAND_WH) + BLOCKSTART_X, (Pos_y * STAND_WH) + BLOCKSTART_Y);
}

//�׸���(overloading)
void MineBlock::Draw(int _x, int _y)
{
	m_pMine->Draw((_x * STAND_WH) + BLOCKSTART_X, (_y * STAND_WH) + BLOCKSTART_Y);
}

//x��ǥ ����
int MineBlock::get_PosX()
{
	return Pos_x;
}

//Y��ǥ ����
int MineBlock::get_PosY()
{
	return Pos_y;
}

//x�� �Է�
void MineBlock::set_Posx(int _x)
{
	Pos_x = _x;
}

//y�� �Է�
void MineBlock::set_Posy(int _y)
{
	Pos_y = _y;
}

//�Ҹ���
MineBlock::~MineBlock()
{

}