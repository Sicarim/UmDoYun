#include "UnitFactory.h"
#include "GameManager.h"
#include "BitMapManager.h"

Rook::Rook()
{
	Class_Name = "Rook";
	Unit_posX = 0;
	Unit_posY = 0;
}

int Rook::get_PlayerUnit()
{
	return Unit_PlayerNum;
}

//유닛 종류 반환(Override)
int Rook::get_Class()
{
	return CLASS_ROOK;
}

void Rook::Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_PlayerNum = _num;
	GameManager::get_Instence()->set_UnitPos(_posx, _posy, CLASS_ROOK);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
}

//유닛을 눌렀따(Override)
void Rook::Clicked_Unit(HWND hWnd, int _posx, int _posy)
{
	tmp_vBlend.clear();

	int tmp_UnitPosx1 = _posx, tmp_UnitPosx2 = _posx;
	int tmp_UnitPosy1 = _posy, tmp_UnitPosy2 = _posy;

	int tmp_Drawx = GameManager::get_Instence()->get_DrawXY(Unit_posX);
	int tmp_Drawy = GameManager::get_Instence()->get_DrawXY(Unit_posY);

	for (int i = 0; i < 8; i++)
	{
		Draw_Blend(hWnd, tmp_UnitPosy1, tmp_UnitPosy2, tmp_Drawx, tmp_Drawy, i, 2);
	}

	tmp_UnitPosx1 = _posx, tmp_UnitPosx2 = _posx;
	tmp_UnitPosy1 = _posy, tmp_UnitPosy2 = _posy;
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(Unit_posY);

	for (int i = 0; i < 8; i++)
	{
		Draw_Blend(hWnd, tmp_UnitPosy1, tmp_UnitPosy2, tmp_Drawx, tmp_Drawy, i, 1);
	}
}

//다시 그려질때마다 그려지는 유닛들
void Rook::Unit_Draw(HWND hWnd, int _num)
{
	if (Current_State != CLASS_DIE)
	{
		Unit_DrawUpdate(Unit_posX, Unit_posY);
		BitMapManager::get_Instence()->Unit_Draw(hWnd, Unit_DrawX, Unit_DrawY, CLASS_ROOK, _num);
	}
}

//유닛 움직이기(Override)
void Rook::Move_Unit(HWND hWnd, int _posx, int _posy)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_ROOK);
}

//유닛이 그려질 실질적 위치 최신화(Override)
void Rook::Unit_DrawUpdate(int _posx, int _posy)
{
	Unit_DrawX = GameManager::get_Instence()->get_DrawXY(_posx);
	Unit_DrawY = GameManager::get_Instence()->get_DrawXY(_posy);
}

//유닛이 갈수 있는 위치를 그린다.
void Rook::Draw_Blend(HWND hWnd, int _pos1, int _pos2, int _unix, int _uniy, int _cnt, int _num)
{
	if (_num == 1)
	{
		_unix = GameManager::get_Instence()->get_DrawXY(_pos1 - _cnt);
		if (GameManager::get_Instence()->get_UnitXY(_unix) >= 0)
		{
			BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _unix, _uniy);
			tmp_BlendRect = { _unix, _uniy, _unix + 101, _uniy + 101 };
			tmp_vBlend.push_back(tmp_BlendRect);
		}

		_unix = GameManager::get_Instence()->get_DrawXY(_pos2 + _cnt);
		if (GameManager::get_Instence()->get_UnitXY(_unix) <= 7)
		{
			BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _unix, _uniy);
			tmp_BlendRect = { _unix, _uniy, _unix + 101, _uniy + 101 };
			tmp_vBlend.push_back(tmp_BlendRect);
		}
	}
	else
	{
		_uniy = GameManager::get_Instence()->get_DrawXY(_pos1 - _cnt);
		if (GameManager::get_Instence()->get_UnitXY(_uniy) >= 0)
		{
			BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _unix, _uniy);
			tmp_BlendRect = { _unix, _uniy, _unix + 101, _uniy + 101 };
			tmp_vBlend.push_back(tmp_BlendRect);
		}

		_uniy = GameManager::get_Instence()->get_DrawXY(_pos2 + _cnt);
		if (GameManager::get_Instence()->get_UnitXY(_uniy) <= 7)
		{
			BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _unix, _uniy);
			tmp_BlendRect = { _unix, _uniy, _unix + 101, _uniy + 101 };
			tmp_vBlend.push_back(tmp_BlendRect);
		}
	}
}

//Unit Rect(Override)
void Rook::Unit_Rect(int _unix, int _uniy)
{
	tmp_BitRECT = { _unix, _uniy, _unix + 101, _uniy + 101 };
}

//공격 당했다!!!
int Rook::attecked_Unit()
{
	Current_State = CLASS_DIE;
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_END);

	return CLASS_ROOK;
}

RECT Rook::get_Rect()
{
	return tmp_BitRECT;
}

//유닛 x좌표 반환(Overrride)
vector<RECT> Rook::get_vblend()
{
	return tmp_vBlend;
}

//현재 위치를 반환(x)
int Rook::get_PosX()
{
	return Unit_posX;
}

//현재 위치를 반환(y)
int Rook::get_PosY()
{
	return Unit_posY;
}

//데이터 삭제
void Rook::Release()
{
	tmp_vBlend.clear();
}

Rook::~Rook()
{
	Release();
}