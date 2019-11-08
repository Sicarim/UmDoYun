#include "UnitFactory.h"
#include "GameManager.h"
#include "BitMapManager.h"

Pawn::Pawn()
{
	Class_Name = "Pawn";
	Unit_posX = 0;
	Unit_posY = 0;
	First_Start = false;
}

int Pawn::get_PlayerUnit()
{
	return Unit_PlayerNum;
}

//���� ���� ��ȯ(Override)
int Pawn::get_Class()
{
	return CLASS_PAWN;
}

void Pawn::Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_PlayerNum = _num;
	GameManager::get_Instence()->set_UnitPos(_posx, _posy, CLASS_PAWN);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
}

//������ ������(Override)
void Pawn::Clicked_Unit(HWND hWnd, int _posx, int _posy)
{
	tmp_vBlend.clear();

	int tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx);
	int tmp_Drawy = 0;

	if (!First_Start)
	{
		if (Unit_PlayerNum == PLAYER_ONE)
		{
			for (int i = 1; i <= 2; i++)
			{
				tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - i);
				Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
			}
		}
		else
		{
			for (int i = 1; i <= 2; i++)
			{
				tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + i);
				Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
			}
		}
	}
	else
	{
		if (Unit_PlayerNum == PLAYER_ONE)
		{
			tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - 1);
			tmp_vBlend.clear();
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
		else
		{
			tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + 1);
			tmp_vBlend.clear();
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}
	
	First_Start = true;
}

//�ٽ� �׷��������� �׷����� ���ֵ�
void Pawn::Unit_Draw(HWND hWnd, int _num)
{
	if (Current_State != CLASS_DIE)
	{
		Unit_DrawUpdate(Unit_posX, Unit_posY);
		BitMapManager::get_Instence()->Unit_Draw(hWnd, Unit_DrawX, Unit_DrawY, CLASS_PAWN, _num);
	}
}

//���� �����̱�(Override)
void Pawn::Move_Unit(HWND hWnd, int _posx, int _posy)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_PAWN);
}

//������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
void Pawn::Unit_DrawUpdate(int _posx, int _posy)
{
	Unit_DrawX = GameManager::get_Instence()->get_DrawXY(_posx);
	Unit_DrawY = GameManager::get_Instence()->get_DrawXY(_posy);
}

//������ ���� �ִ� ��ġ�� �׸���.
void Pawn::Draw_Blend(HWND hWnd, int _pos1, int _pos2, int _unix, int _uniy, int _cnt, int _num)
{
	BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _pos1, _pos2);
	tmp_BlendRect = { _pos1, _pos2, _pos1 + 101, _pos2 + 101 };
	tmp_vBlend.push_back(tmp_BlendRect);
}

//Unit Rect(Override)
void Pawn::Unit_Rect(int _unix, int _uniy)
{
	tmp_BitRECT = { _unix, _uniy, _unix + 101, _uniy + 101 };
}

//���� ���ߴ�!!!
int Pawn::attecked_Unit()
{
	Current_State = CLASS_DIE;
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_END);
	return CLASS_PAWN;
}

RECT Pawn::get_Rect()
{
	return tmp_BitRECT;
}

//���� x��ǥ ��ȯ(Overrride)
vector<RECT> Pawn::get_vblend()
{
	return tmp_vBlend;
}

//���� ��ġ�� ��ȯ(x)
int Pawn::get_PosX()
{
	return Unit_posX;
}

//���� ��ġ�� ��ȯ(y)
int Pawn::get_PosY()
{
	return Unit_posY;
}

//������ ����
void Pawn::Release()
{
	tmp_vBlend.clear();
}


Pawn::~Pawn()
{
	Release();
}