#include "UnitFactory.h"
#include "GameManager.h"
#include "BitMapManager.h"

King::King()
{
	Class_Name = "King";
	Unit_posX = 0;
	Unit_posY = 0;
}

int King::get_PlayerUnit()
{
	return Unit_PlayerNum;
}

//유닛 종류 반환(Override)
int King::get_Class()
{
	return CLASS_KING;
}

void King::Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_PlayerNum = _num;
	GameManager::get_Instence()->set_UnitPos(_posx, _posy, CLASS_KING);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
}

//유닛을 눌렀따(Override)
void King::Clicked_Unit(HWND hWnd, int _posx, int _posy)
{
	tmp_vBlend.clear();
	int tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx);
	int tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy);
	
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - 1);
	if (GameManager::get_Instence()->get_UnitXY(tmp_Drawy) >= 0)
	{
		Draw_Blend(hWnd, _posx, _posy, tmp_Drawx, tmp_Drawy);
	}
	
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy);
	Draw_Blend(hWnd, _posx, _posy, tmp_Drawx, tmp_Drawy);

	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + 1);
	if (GameManager::get_Instence()->get_UnitXY(tmp_Drawy) <= 7)
	{
		Draw_Blend(hWnd, _posx, _posy, tmp_Drawx, tmp_Drawy);
	}
}

//다시 그려질때마다 그려지는 유닛들
void King::Unit_Draw(HWND hWnd, int _num)
{
	if (Current_State != CLASS_DIE)
	{
		Unit_DrawUpdate(Unit_posX, Unit_posY);
		BitMapManager::get_Instence()->Unit_Draw(hWnd, Unit_DrawX, Unit_DrawY, CLASS_KING, _num);
	}
}

//유닛 움직이기(Override)
void King::Move_Unit(HWND hWnd, int _posx, int _posy)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_KING);
}

//유닛이 그려질 실질적 위치 최신화(Override)
void King::Unit_DrawUpdate(int _posx, int _posy)
{
	Unit_DrawX = GameManager::get_Instence()->get_DrawXY(_posx);
	Unit_DrawY = GameManager::get_Instence()->get_DrawXY(_posy);
}

//유닛이 갈수 있는 위치를 그린다.
void King::Draw_Blend(HWND hWnd, int _pos1, int _pos2, int _unix, int _uniy, int _cnt, int _num)
{
	_unix = GameManager::get_Instence()->get_DrawXY(_pos1 - 1);
	if (GameManager::get_Instence()->get_UnitXY(_unix) >= 0)
	{
		BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _unix, _uniy);
		tmp_BlendRect = { _unix, _uniy, _unix + 101, _uniy + 101 };
		tmp_vBlend.push_back(tmp_BlendRect);
	}
	
	_unix = GameManager::get_Instence()->get_DrawXY(_pos1);
	BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _unix, _uniy);
	tmp_BlendRect = { _unix, _uniy, _unix + 101, _uniy + 101 };
	tmp_vBlend.push_back(tmp_BlendRect);
	
	
	_unix = GameManager::get_Instence()->get_DrawXY(_pos1 + 1);
	if (GameManager::get_Instence()->get_UnitXY(_unix) <= 7)
	{
		BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _unix, _uniy);
		tmp_BlendRect = { _unix, _uniy, _unix + 101, _uniy + 101 };
		tmp_vBlend.push_back(tmp_BlendRect);
	}
}

//유닛이 갈수 있는 위치를 그린다.(Override)
void King::Draw_Blend(HWND hWnd)
{
}

//공격 당했다!!!
int King::attecked_Unit()
{
	Current_State = CLASS_DIE;
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_END);
	return CLASS_KING;
}

//Unit Rect(Override)
void King::Unit_Rect(int _unix, int _uniy)
{
	tmp_BitRECT = { _unix, _uniy, _unix + 101, _uniy + 101 };
}

RECT King::get_Rect()
{
	return tmp_BitRECT;
}

//유닛 x좌표 반환(Overrride)
vector<RECT> King::get_vblend()
{
	return tmp_vBlend;
}

//현재 위치를 반환(x)
int King::get_PosX()
{
	return Unit_posX;
}

//현재 위치를 반환(y)
int King::get_PosY()
{
	return Unit_posY;
}

//데이터 삭제
void King::Release()
{
	tmp_vBlend.clear();
}

King::~King()
{
	Release();
}