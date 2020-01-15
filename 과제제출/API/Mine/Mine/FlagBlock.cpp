#include "FlagBlock.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//생성자
FlagBlock::FlagBlock()
{
	Pos_x = 0;
	Pos_y = 0;
	FlagDraw_Check = false;
}

//초기화 함수
void FlagBlock::Init()
{
	m_pFlag = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\flag.bmp");
}

//그리기(overloading)
void FlagBlock::Draw()
{
	m_pFlag->Draw((Pos_x * STAND_WH) + BLOCKSTART_X, (Pos_y * STAND_WH) + BLOCKSTART_Y);
}

//그리기(overloading)
void FlagBlock::Draw(int _x, int _y)
{
	m_pFlag->Draw((_x * STAND_WH) + BLOCKSTART_X, (_y * STAND_WH) + BLOCKSTART_Y);
}

//x좌표 리턴
int FlagBlock::get_PosX()
{
	return Pos_x;
}

//Y좌표 리턴
int FlagBlock::get_PosY()
{
	return Pos_y;
}

//x값 입력
void FlagBlock::set_Posx(int _x)
{
	Pos_x = _x;
}

//y값 입력
void FlagBlock::set_Posy(int _y)
{
	Pos_y = _y;
}

//플래그 그리기 체크
bool FlagBlock::get_FlagCheck()
{
	return FlagDraw_Check;
}

//소멸자
FlagBlock::~FlagBlock()
{

}