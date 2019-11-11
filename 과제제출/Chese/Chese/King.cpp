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

//���� ���� ��ȯ(Override)
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

//������ ������(Override)
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

//�ٽ� �׷��������� �׷����� ���ֵ�
void King::Unit_Draw(HWND hWnd, int _num)
{
	if (Current_State != CLASS_DIE)
	{
		Unit_DrawUpdate(Unit_posX, Unit_posY);
		BitMapManager::get_Instence()->Unit_Draw(hWnd, Unit_DrawX, Unit_DrawY, CLASS_KING, _num);
	}
}

//���� �����̱�(Override)
void King::Move_Unit(HWND hWnd, int _posx, int _posy)
{
	Unit_posX = _posx;
	Unit_posY = _posy;
	Unit_DrawUpdate(Unit_posX, Unit_posY);
	Unit_Rect(Unit_DrawX, Unit_DrawY);
	GameManager::get_Instence()->set_UnitPos(Unit_posX, Unit_posY, CLASS_KING);
}

//������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
void King::Unit_DrawUpdate(int _posx, int _posy)
{
	Unit_DrawX = GameManager::get_Instence()->get_DrawXY(_posx);
	Unit_DrawY = GameManager::get_Instence()->get_DrawXY(_posy);
}

//������ ���� �ִ� ��ġ�� �׸���.
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

//������ ���� �ִ� ��ġ�� �׸���.(Override)
void King::Draw_Blend(HWND hWnd)
{
}

//���� ���ߴ�!!!
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

//���� x��ǥ ��ȯ(Overrride)
vector<RECT> King::get_vblend()
{
	return tmp_vBlend;
}

//���� ��ġ�� ��ȯ(x)
int King::get_PosX()
{
	return Unit_posX;
}

//���� ��ġ�� ��ȯ(y)
int King::get_PosY()
{
	return Unit_posY;
}

//������ ����
void King::Release()
{
	tmp_vBlend.clear();
}

King::~King()
{
	Release();
}