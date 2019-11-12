#include "UnitFactory.h"
#include "GameManager.h"
#include "BitMapManager.h"

Queen::Queen()
{
	Class_Name = "Queen";
	Unit_posX = 0;
	Unit_posY = 0;
}

int Queen::get_PlayerUnit()
{
	return Unit_PlayerNum;
}

//���� ���� ��ȯ(Override)
int Queen::get_Class()
{
	return CLASS_QUEEN;
}

void Queen::Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_PlayerNum = _num;
	GameManager::get_Instence()->set_UnitPos(_posx, _posy, CLASS_QUEEN);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
}

//������ ������(Override)
void Queen::Clicked_Unit(HWND hWnd, int _posx, int _posy)
{
	tmp_vBlend.clear();
	int tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx);
	int tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy);

	tmp_GoCount = 0;
	//���� ������
	for (int i = 1; i <= 8; i++)
	{
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - i);

		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawy) >= 0)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}

	tmp_GoCount = 0;
	//���������� ������
	for (int i = 1; i <= 8; i++)
	{
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - i);
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx + i);

		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawy) >= 0 && GameManager::get_Instence()->get_UnitXY(tmp_Drawx) <= 7)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}

	tmp_GoCount = 0;
	//�������� ���Ｑ
	for (int i = 1; i <= 8; i++)
	{
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - i);
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx - i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawy) >= 0 && GameManager::get_Instence()->get_UnitXY(tmp_Drawx) >= 0)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}
	////////////////////////////////////////////////
	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy);

	tmp_GoCount = 0;
	//���� ������
	for (int i = 1; i <= 8; i++)
	{
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + i);

		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawy) <= 7)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}

	tmp_GoCount = 0;
	//���������� ������
	for (int i = 1; i <= 8; i++)
	{
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + i);
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx + i);

		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawy) <= 7 && GameManager::get_Instence()->get_UnitXY(tmp_Drawx) <= 7)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}

	tmp_GoCount = 0;
	//�������� ���Ｑ
	for (int i = 1; i <= 8; i++)
	{
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + i);
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx - i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawy) <= 7 && GameManager::get_Instence()->get_UnitXY(tmp_Drawx) >= 0)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}
	//////////////////////////////////

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy);
	tmp_GoCount = 0;
	//�������� ���Ｑ
	for (int i = 1; i <= 8; i++)
	{
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx - i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawx) >= 0)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}
	tmp_GoCount = 0;
	for (int i = 1; i <= 8; i++)
	{
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx + i);
		if (GameManager::get_Instence()->get_UnitXY(tmp_Drawx) <= 7)
		{
			Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy);
		}
	}
}

//�ٽ� �׷��������� �׷����� ���ֵ�
void Queen::Unit_Draw(HWND hWnd, int _num)
{
	if (Current_State != CLASS_DIE)
	{
		Unit_DrawUpdate(Unit_posX, Unit_posY);
		BitMapManager::get_Instence()->Unit_Draw(hWnd, Unit_DrawX, Unit_DrawY, CLASS_QUEEN, _num);
	}
}

//���� �����̱�(Override)
void Queen::Move_Unit(HWND hWnd, int _posx, int _posy)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_QUEEN);
}

//������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
void Queen::Unit_DrawUpdate(int _posx, int _posy)
{
	Unit_DrawX = GameManager::get_Instence()->get_DrawXY(_posx);
	Unit_DrawY = GameManager::get_Instence()->get_DrawXY(_posy);
}

//������ ���� �ִ� ��ġ�� �׸���.
void Queen::Draw_Blend(HWND hWnd, int _pos1, int _pos2, int _unix, int _uniy, int _cnt, int _num)
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
void Queen::Unit_Rect(int _unix, int _uniy)
{
	tmp_BitRECT = { _unix, _uniy, _unix + 101, _uniy + 101 };
}

//���� ���ߴ�!!!
int Queen::attecked_Unit()
{
	Current_State = CLASS_DIE;
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_END);
	return CLASS_QUEEN;
}

RECT Queen::get_Rect()
{
	return tmp_BitRECT;
}

//���� x��ǥ ��ȯ(Overrride)
vector<RECT> Queen::get_vblend()
{
	return tmp_vBlend;
}

//���� ��ġ�� ��ȯ(x)
int Queen::get_PosX()
{
	return Unit_posX;
}

//���� ��ġ�� ��ȯ(y)
int Queen::get_PosY()
{
	return Unit_posY;
}

//������ ����
void Queen::Release()
{
	tmp_vBlend.clear();
}

Queen::~Queen()
{
	Release();
}