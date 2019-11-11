#include "UnitFactory.h"
#include "GameManager.h"
#include "BitMapManager.h"

Knight::Knight()
{
	Class_Name = "Knight";
	Unit_posX = 0;
	Unit_posY = 0;
}

int Knight::get_PlayerUnit()
{
	return Unit_PlayerNum;
}

//���� ���� ��ȯ(Override)
int Knight::get_Class()
{
	return CLASS_KNIGHT;
}

void Knight::Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_PlayerNum = _num;
	GameManager::get_Instence()->set_UnitPos(_posx, _posy, CLASS_KNIGHT);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
}

//������ ������(Override)
void Knight::Clicked_Unit(HWND hWnd, int _posx, int _posy)
{
	tmp_vBlend.clear();
	int tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx);
	int tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy);

	for (int i = 1; i <= 2; i++)
	{
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - i);
		Draw_Blend(hWnd, tmp_Drawy, tmp_Drawx, tmp_Drawx, tmp_Drawy, 0);
	}

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx + 1);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - 3);

	Draw_Blend(hWnd, tmp_Drawy, tmp_Drawx, tmp_Drawx, tmp_Drawy, 0);

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx - 1);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - 3);

	Draw_Blend(hWnd, tmp_Drawy, tmp_Drawx, tmp_Drawx, tmp_Drawy, 0);

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy);

	for (int i = 1; i <= 2; i++)
	{
		tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + i);
		Draw_Blend(hWnd, tmp_Drawy, tmp_Drawx, tmp_Drawx, tmp_Drawy, 7);
	}

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx + 1);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + 3);
	Draw_Blend(hWnd, tmp_Drawy, tmp_Drawx, tmp_Drawx, tmp_Drawy, 7);

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx - 1);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + 3);
	Draw_Blend(hWnd, tmp_Drawy, tmp_Drawx, tmp_Drawx, tmp_Drawy, 7);

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy);

	for (int i = 1; i <= 2; i++)
	{
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx - i);
		Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy, tmp_Drawx, tmp_Drawy, 0);
	}

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx - 3);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + 1);
	Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy, tmp_Drawx, tmp_Drawy, 0);

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx - 3);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - 1);
	Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy, tmp_Drawx, tmp_Drawy, 0);

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy);

	for (int i = 1; i <= 2; i++)
	{
		tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx + i);
		Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy, tmp_Drawx, tmp_Drawy, 7);
	}

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx + 3);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy + 1);
	Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy, tmp_Drawx, tmp_Drawy, 7);

	tmp_Drawx = GameManager::get_Instence()->get_DrawXY(_posx + 3);
	tmp_Drawy = GameManager::get_Instence()->get_DrawXY(_posy - 1);
	Draw_Blend(hWnd, tmp_Drawx, tmp_Drawy, tmp_Drawx, tmp_Drawy, 7);
}

//�ٽ� �׷��������� �׷����� ���ֵ�
void Knight::Unit_Draw(HWND hWnd, int _num)
{
	if (Current_State != CLASS_DIE)
	{
		Unit_DrawUpdate(Unit_posX, Unit_posY);
		BitMapManager::get_Instence()->Unit_Draw(hWnd, Unit_DrawX, Unit_DrawY, CLASS_KNIGHT, _num);
	}
}

//���� �����̱�(Override)
void Knight::Move_Unit(HWND hWnd, int _posx, int _posy)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_KNIGHT);
}

//������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
void Knight::Unit_DrawUpdate(int _posx, int _posy)
{
	Unit_DrawX = GameManager::get_Instence()->get_DrawXY(_posx);
	Unit_DrawY = GameManager::get_Instence()->get_DrawXY(_posy);
}

//������ ���� �ִ� ��ġ�� �׸���.
void Knight::Draw_Blend(HWND hWnd, int _pos1, int _pos2, int _unix, int _uniy, int _cnt, int _num)
{
	if (_cnt == 0)
	{
		if (GameManager::get_Instence()->get_UnitXY(_pos1) >= _cnt)
		{
			if (GameManager::get_Instence()->get_UnitXY(_pos2) >= 0 && GameManager::get_Instence()->get_UnitXY(_pos2) <= 7)
			{
				BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _unix, _uniy);
				tmp_BlendRect = { _unix, _uniy, _unix + 101, _uniy + 101 };
				tmp_vBlend.push_back(tmp_BlendRect);
			}
		}
	}

	else
	{
		if (GameManager::get_Instence()->get_UnitXY(_pos1) <= _cnt)
		{
			if (GameManager::get_Instence()->get_UnitXY(_pos2) >= 0 && GameManager::get_Instence()->get_UnitXY(_pos2) <= 7)
			{
				BitMapManager::get_Instence()->Unit_BlendDraw(hWnd, _unix, _uniy);
				tmp_BlendRect = { _unix, _uniy, _unix + 101, _uniy + 101 };
				tmp_vBlend.push_back(tmp_BlendRect);
			}
		}
	}
}

//������ ���� �ִ� ��ġ�� �׸���.(Override)
void Knight::Draw_Blend(HWND hWnd)
{
}

//���� ���ߴ�!!!
int Knight::attecked_Unit()
{
	Current_State = CLASS_DIE;
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_END);
	return CLASS_KNIGHT;
}

//Unit Rect(Override)
void Knight::Unit_Rect(int _unix, int _uniy)
{
	tmp_BitRECT = { _unix, _uniy, _unix + 101, _uniy + 101 };
}

RECT Knight::get_Rect()
{
	return tmp_BitRECT;
}

//���� x��ǥ ��ȯ(Overrride)
vector<RECT> Knight::get_vblend()
{
	return tmp_vBlend;
}

//���� ��ġ�� ��ȯ(x)
int Knight::get_PosX()
{
	return Unit_posX;
}

//���� ��ġ�� ��ȯ(y)
int Knight::get_PosY()
{
	return Unit_posY;
}

//������ ����
void Knight::Release()
{
	tmp_vBlend.clear();
}

Knight::~Knight()
{
	Release();
}