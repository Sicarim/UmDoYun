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

//���� ���� ��ȯ(Override)
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

//������ ������(Override)
void Rook::Clicked_Unit(HWND hWnd, int _posx, int _posy)
{
	tmp_vBlend.clear();

	int tmp_UnitPosx1 = _posx, tmp_UnitPosx2 = _posx;
	int tmp_UnitPosy1 = _posy, tmp_UnitPosy2 = _posy;

	int tmp_Drawx = GameManager::get_Instence()->get_DrawXY(Unit_posX);
	int tmp_Drawy = GameManager::get_Instence()->get_DrawXY(Unit_posY);

	tmp_GoCount = 0;
	for (int i = 0; i < 8; i++)
	{
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(tmp_UnitPosy1 - i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawy) >= 0)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);

		}
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(tmp_UnitPosy1 + i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawy) <= 7)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}

	tmp_UnitPosx1 = _posx, tmp_UnitPosx2 = _posx;
	tmp_UnitPosy1 = _posy, tmp_UnitPosy2 = _posy;
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(Unit_posY);

	tmp_GoCount = 0;
	for (int i = 0; i < 8; i++)
	{
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(tmp_UnitPosy1 - i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawx) >= 0)
		{
			int tmp_posx = GameManager::get_Instence()->get_UnitXY(tmp_Drawx);
			int tmp_posy = GameManager::get_Instence()->get_UnitXY(tmp_Drawy);
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}

		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(tmp_UnitPosy2 + i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawx) <= 7)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}
}

//�ٽ� �׷��������� �׷����� ���ֵ�
void Rook::Unit_Draw(HWND hWnd, int _num)
{
	if (Current_State != CLASS_DIE)
	{
		Unit_DrawUpdate(Unit_posX, Unit_posY);
		BitMapManager::get_Instence()->Unit_Draw(hWnd, Unit_DrawX, Unit_DrawY, CLASS_ROOK, _num);
	}
}

//���� �����̱�(Override)
void Rook::Move_Unit(HWND hWnd, int _posx, int _posy)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_ROOK);
}

//������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
void Rook::Unit_DrawUpdate(int _posx, int _posy)
{
	Unit_DrawX = GameManager::get_Instence()->get_DrawXY(_posx);
	Unit_DrawY = GameManager::get_Instence()->get_DrawXY(_posy);
}

//������ ���� �ִ� ��ġ�� �׸���.
void Rook::Draw_Blend(HWND hWnd, int _pos1, int _pos2, int _unix, int _uniy, int _cnt, int _num)
{

	int tmp_posx = GameManager::get_Instence()->get_UnitXY(_pos1);
	int tmp_posy = GameManager::get_Instence()->get_UnitXY(_pos2);

	if (GameManager::get_Instence()->inspection_Pawn(tmp_posx, tmp_posy, Unit_PlayerNum))
	{
		tmp_GoCount++;
	}

	if (tmp_GoCount < 2)
	{
		BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _pos1, _pos2);
		tmp_BlendRect = { _pos1, _pos2, _pos1 + 101, _pos2 + 101 };
		tmp_vBlend.push_back(tmp_BlendRect);
	}
}

//Unit Rect(Override)
void Rook::Unit_Rect(int _unix, int _uniy)
{
	tmp_BitRECT = { _unix, _uniy, _unix + 101, _uniy + 101 };
}

//���� ���ߴ�!!!
int Rook::attecked_Unit()
{
	tmp_GoCount = 0;
	Current_State = CLASS_DIE;
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_END);

	return CLASS_ROOK;
}

RECT Rook::get_Rect()
{
	return tmp_BitRECT;
}

//���� x��ǥ ��ȯ(Overrride)
vector<RECT> Rook::get_vblend()
{
	return tmp_vBlend;
}

//���� ��ġ�� ��ȯ(x)
int Rook::get_PosX()
{
	return Unit_posX;
}

//���� ��ġ�� ��ȯ(y)
int Rook::get_PosY()
{
	return Unit_posY;
}

//������ ����
void Rook::Release()
{
	tmp_vBlend.clear();
	tmp_GoCount = 0;
}

Rook::~Rook()
{
	Release();
}
