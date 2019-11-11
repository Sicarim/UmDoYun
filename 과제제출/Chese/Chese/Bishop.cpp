#include "UnitFactory.h"
#include "GameManager.h"
#include "BitMapManager.h"

Bishop::Bishop()
{
	Class_Name = "Bishop";
	Unit_posX = 0;
	Unit_posY = 0;
}

int Bishop::get_PlayerUnit()
{
	return Unit_PlayerNum;
}

//유닛 종류 반환(Override)
int Bishop::get_Class()
{
	return CLASS_BISHOP;
}

void Bishop::Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_PlayerNum = _num;
	GameManager::get_Instence()->set_UnitPos(_posx, _posy, CLASS_BISHOP);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
}

//유닛을 눌렀따(Override)
void Bishop::Clicked_Unit(HWND hWnd, int _posx, int _posy)
{
	tmp_vBlend.clear();
	int tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx);
	int tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy);

	for (int i = 1; i <= 7; i++)
	{
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx - i);
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawx) >= 0 && GameManager::get_Instence()->get_UnitXY(tmp_Drawy) >= 0)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}

	for (int i = 1; i <= 7; i++)
	{
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx + i);
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawx) <= 7 && GameManager::get_Instence()->get_UnitXY(tmp_Drawy) >= 0)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}

	for (int i = 1; i <= 7; i++)
	{
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx + i);
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawx) <= 7 && GameManager::get_Instence()->get_UnitXY(tmp_Drawy) <= 7)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}

	for (int i = 1; i <= 7; i++)
	{
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx - i);
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawx) >= 0 && GameManager::get_Instence()->get_UnitXY(tmp_Drawy) <= 7)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}
}

//다시 그려질때마다 그려지는 유닛들
void Bishop::Unit_Draw(HWND hWnd, int _num)
{
	if (Current_State != CLASS_DIE)
	{
		Unit_DrawUpdate(Unit_posX, Unit_posY);
		BitMapManager::get_Instence()->Unit_Draw(hWnd, Unit_DrawX, Unit_DrawY, CLASS_BISHOP, _num);
	}
}

//유닛 움직이기(Override)
void Bishop::Move_Unit(HWND hWnd, int _posx, int _posy)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_BISHOP);
}

//유닛이 그려질 실질적 위치 최신화(Override)
void Bishop::Unit_DrawUpdate(int _posx, int _posy)
{
	Unit_DrawX = GameManager::get_Instence()->get_DrawXY(_posx);
	Unit_DrawY = GameManager::get_Instence()->get_DrawXY(_posy);
}

//유닛이 갈수 있는 위치를 그린다.
void Bishop::Draw_Blend(HWND hWnd, int _pos1, int _pos2, int _unix, int _uniy, int _cnt, int _num)
{
	BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _pos1, _pos2);
	tmp_BlendRect = { _pos1, _pos2, _pos1 + 101, _pos2 + 101 };
	tmp_vBlend.push_back(tmp_BlendRect);
}

//유닛이 갈수 있는 위치를 그린다.(Override)
void Bishop::Draw_Blend(HWND hWnd)
{
}

//공격 당했다!!!
int Bishop::attecked_Unit()
{
	Current_State = CLASS_DIE;
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_END);
	return CLASS_BISHOP;
}

//Unit Rect(Override)
void Bishop::Unit_Rect(int _unix, int _uniy)
{
	tmp_BitRECT = { _unix, _uniy, _unix + 101, _uniy + 101 };
}

RECT Bishop::get_Rect()
{
	return tmp_BitRECT;
}

//유닛 x좌표 반환(Overrride)
vector<RECT> Bishop::get_vblend()
{
	return tmp_vBlend;
}

//현재 위치를 반환(x)
int Bishop::get_PosX()
{
	return Unit_posX;
}

//현재 위치를 반환(y)
int Bishop::get_PosY()
{
	return Unit_posY;
}

//데이터 삭제
void Bishop::Release()
{
	tmp_vBlend.clear();
}

Bishop::~Bishop()
{
	Release();
}