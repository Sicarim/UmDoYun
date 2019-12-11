#include "MineBlock.h"
#include "ResourcesManager.h"

//생성자
MineBlock::MineBlock()
{
	m_pMine = NULL;
	Pos_x = 0;
	Pos_x = 0;
}

//초기화
void MineBlock::Init()
{
	m_pMine = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\mine.bmp");
}

//그리기(overloading)
void MineBlock::Draw()
{
	m_pMine->Draw((Pos_x * STAND_WH) + BLOCKSTART_X, (Pos_y * STAND_WH) + BLOCKSTART_Y);
}

//그리기(overloading)
void MineBlock::Draw(int _x, int _y)
{
	m_pMine->Draw((_x * STAND_WH) + BLOCKSTART_X, (_y * STAND_WH) + BLOCKSTART_Y);
}

//x좌표 리턴
int MineBlock::get_PosX()
{
	return Pos_x;
}

//Y좌표 리턴
int MineBlock::get_PosY()
{
	return Pos_y;
}

//x값 입력
void MineBlock::set_Posx(int _x)
{
	Pos_x = _x;
}

//y값 입력
void MineBlock::set_Posy(int _y)
{
	Pos_y = _y;
}

//소멸자
MineBlock::~MineBlock()
{

}