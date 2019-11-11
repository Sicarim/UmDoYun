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

//���� ���� ��ȯ(Override)
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

//������ ������(Override)
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

//�ٽ� �׷��������� �׷����� ���ֵ�
void Bishop::Unit_Draw(HWND hWnd, int _num)
{
	if (Current_State != CLASS_DIE)
	{
		Unit_DrawUpdate(Unit_posX, Unit_posY);
		BitMapManager::get_Instence()->Unit_Draw(hWnd, Unit_DrawX, Unit_DrawY, CLASS_BISHOP, _num);
	}
}

//���� �����̱�(Override)
void Bishop::Move_Unit(HWND hWnd, int _posx, int _posy)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_BISHOP);
}

//������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
void Bishop::Unit_DrawUpdate(int _posx, int _posy)
{
	Unit_DrawX = GameManager::get_Instence()->get_DrawXY(_posx);
	Unit_DrawY = GameManager::get_Instence()->get_DrawXY(_posy);
}

//������ ���� �ִ� ��ġ�� �׸���.
void Bishop::Draw_Blend(HWND hWnd, int _pos1, int _pos2, int _unix, int _uniy, int _cnt, int _num)
{
	BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _pos1, _pos2);
	tmp_BlendRect = { _pos1, _pos2, _pos1 + 101, _pos2 + 101 };
	tmp_vBlend.push_back(tmp_BlendRect);
}

//������ ���� �ִ� ��ġ�� �׸���.(Override)
void Bishop::Draw_Blend(HWND hWnd)
{
}

//���� ���ߴ�!!!
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

//���� x��ǥ ��ȯ(Overrride)
vector<RECT> Bishop::get_vblend()
{
	return tmp_vBlend;
}

//���� ��ġ�� ��ȯ(x)
int Bishop::get_PosX()
{
	return Unit_posX;
}

//���� ��ġ�� ��ȯ(y)
int Bishop::get_PosY()
{
	return Unit_posY;
}

//������ ����
void Bishop::Release()
{
	tmp_vBlend.clear();
}

Bishop::~Bishop()
{
	Release();
}