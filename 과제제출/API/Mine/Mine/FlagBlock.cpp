#include "FlagBlock.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//������
FlagBlock::FlagBlock()
{
	Pos_x = 0;
	Pos_y = 0;
	FlagDraw_Check = false;
}

//�ʱ�ȭ �Լ�
void FlagBlock::Init()
{
	m_pFlag = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\flag.bmp");
}

//�׸���(overloading)
void FlagBlock::Draw()
{
	m_pFlag->Draw((Pos_x * STAND_WH) + BLOCKSTART_X, (Pos_y * STAND_WH) + BLOCKSTART_Y);
}

//�׸���(overloading)
void FlagBlock::Draw(int _x, int _y)
{
	m_pFlag->Draw((_x * STAND_WH) + BLOCKSTART_X, (_y * STAND_WH) + BLOCKSTART_Y);
}

//x��ǥ ����
int FlagBlock::get_PosX()
{
	return Pos_x;
}

//Y��ǥ ����
int FlagBlock::get_PosY()
{
	return Pos_y;
}

//x�� �Է�
void FlagBlock::set_Posx(int _x)
{
	Pos_x = _x;
}

//y�� �Է�
void FlagBlock::set_Posy(int _y)
{
	Pos_y = _y;
}

//�÷��� �׸��� üũ
bool FlagBlock::get_FlagCheck()
{
	return FlagDraw_Check;
}

//�Ҹ���
FlagBlock::~FlagBlock()
{

}