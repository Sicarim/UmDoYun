#pragma once
#include "Mecro.h"

class UnitFactory
{
private:
protected:
	string Class_Name;
	RECT tmp_BlendRect;
	vector<RECT> tmp_vBlend;
	RECT tmp_BitRECT;

	int Unit_posX;
	int Unit_posY;
	int Unit_DrawX;
	int Unit_DrawY;
	int Unit_PlayerNum;
	int Current_State;
public:
	UnitFactory();
	virtual int get_PlayerUnit() = 0; //�÷��̾� ���� Ȯ��

	virtual int get_Class() = 0; //���� ���� ��ȯ
	virtual void Unit_Rect(int _unix, int _uniy) = 0; //Unit Rect
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num) = 0; //Unit's Behavior
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy) = 0; //������ ������
	virtual void Unit_Draw(HWND hWnd, int _num) = 0; //�ٽ� �׷��������� �׷����� ���ֵ�
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy) = 0; //���� �����̱�
	virtual void Unit_DrawUpdate(int _posx, int _posy) = 0; //������ �׷��� ������ ��ġ �ֽ�ȭ
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0) = 0; //������ ���� �ִ� ��ġ�� �׸���.
	virtual void Draw_Blend(HWND hWnd) = 0; //������ ���� �ִ� ��ġ�� �׸���.
	virtual RECT get_Rect() = 0; //Rect's returns
	virtual vector<RECT> get_vblend() = 0; //���� ���� �ִ� ��ġ ��ȯ
	virtual int get_PosX() = 0; //���� ��ġ�� ��ȯ(x)
	virtual int get_PosY() = 0; //���� ��ġ�� ��ȯ(y)
	virtual int attecked_Unit() = 0; //���� ���ߴ�!!!
	virtual void Release() = 0; //������ ����
	virtual ~UnitFactory();
};

class Pawn : public UnitFactory
{
private:
	bool First_Start;
public:
	Pawn();

	virtual int get_PlayerUnit(); //�÷��̾� ���� Ȯ��

	virtual int get_Class(); //���� ���� ��ȯ(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //������ ������(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //�ٽ� �׷��������� �׷����� ���ֵ�
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //���� �����̱�(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //������ ���� �ִ� ��ġ�� �׸���.
	virtual void Draw_Blend(HWND hWnd); //������ ���� �ִ� ��ġ�� �׸���.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //���� x��ǥ ��ȯ(Overrride)
	virtual int get_PosX(); //���� ��ġ�� ��ȯ(x)
	virtual int get_PosY(); //���� ��ġ�� ��ȯ(y)
	virtual int attecked_Unit(); //���� ���ߴ�!!!
	virtual void Release(); //������ ����

	virtual ~Pawn();
};

class King : public UnitFactory
{
private:
public:
	King();

	virtual int get_PlayerUnit(); //�÷��̾� ���� Ȯ��

	virtual int get_Class(); //���� ���� ��ȯ(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //������ ������(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //�ٽ� �׷��������� �׷����� ���ֵ�
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //���� �����̱�(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //������ ���� �ִ� ��ġ�� �׸���.
	virtual void Draw_Blend(HWND hWnd); //������ ���� �ִ� ��ġ�� �׸���.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //���� x��ǥ ��ȯ(Overrride)
	virtual int get_PosX(); //���� ��ġ�� ��ȯ(x)
	virtual int get_PosY(); //���� ��ġ�� ��ȯ(y)
	virtual int attecked_Unit(); //���� ���ߴ�!!!
	virtual void Release(); //������ ����

	virtual ~King();
};

class Queen : public UnitFactory
{
private:
public:
	Queen();

	virtual int get_PlayerUnit(); //�÷��̾� ���� Ȯ��

	virtual int get_Class(); //���� ���� ��ȯ(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //������ ������(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //�ٽ� �׷��������� �׷����� ���ֵ�
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //���� �����̱�(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //������ ���� �ִ� ��ġ�� �׸���.
	virtual void Draw_Blend(HWND hWnd); //������ ���� �ִ� ��ġ�� �׸���.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //���� x��ǥ ��ȯ(Overrride)
	virtual int get_PosX(); //���� ��ġ�� ��ȯ(x)
	virtual int get_PosY(); //���� ��ġ�� ��ȯ(y)
	virtual int attecked_Unit(); //���� ���ߴ�!!!
	virtual void Release(); //������ ����

	virtual ~Queen();
};

class Knight : public UnitFactory
{
private:
public:
	Knight();

	virtual int get_PlayerUnit(); //�÷��̾� ���� Ȯ��

	virtual int get_Class(); //���� ���� ��ȯ(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //������ ������(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //�ٽ� �׷��������� �׷����� ���ֵ�
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //���� �����̱�(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //������ ���� �ִ� ��ġ�� �׸���.
	virtual void Draw_Blend(HWND hWnd); //������ ���� �ִ� ��ġ�� �׸���.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //���� x��ǥ ��ȯ(Overrride)
	virtual int get_PosX(); //���� ��ġ�� ��ȯ(x)
	virtual int get_PosY(); //���� ��ġ�� ��ȯ(y)
	virtual int attecked_Unit(); //���� ���ߴ�!!!
	virtual void Release(); //������ ����

	virtual ~Knight();
};

class Rook : public UnitFactory
{
private:
public:
	Rook();

	virtual int get_PlayerUnit(); //�÷��̾� ���� Ȯ��

	virtual int get_Class(); //���� ���� ��ȯ(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //������ ������(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //�ٽ� �׷��������� �׷����� ���ֵ�
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //���� �����̱�(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //������ ���� �ִ� ��ġ�� �׸���.
	virtual void Draw_Blend(HWND hWnd); //������ ���� �ִ� ��ġ�� �׸���.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //���� x��ǥ ��ȯ(Overrride)
	virtual int get_PosX(); //���� ��ġ�� ��ȯ(x)
	virtual int get_PosY(); //���� ��ġ�� ��ȯ(y)
	virtual int attecked_Unit(); //���� ���ߴ�!!!
	virtual void Release(); //������ ����

	virtual ~Rook();
};

class Bishop : public UnitFactory
{
private:
public:
	Bishop();

	virtual int get_PlayerUnit(); //�÷��̾� ���� Ȯ��

	virtual int get_Class(); //���� ���� ��ȯ(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //������ ������(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //�ٽ� �׷��������� �׷����� ���ֵ�
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //���� �����̱�(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //������ �׷��� ������ ��ġ �ֽ�ȭ(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //������ ���� �ִ� ��ġ�� �׸���.
	virtual void Draw_Blend(HWND hWnd); //������ ���� �ִ� ��ġ�� �׸���.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //���� x��ǥ ��ȯ(Overrride)
	virtual int get_PosX(); //���� ��ġ�� ��ȯ(x)
	virtual int get_PosY(); //���� ��ġ�� ��ȯ(y)
	virtual int attecked_Unit(); //���� ���ߴ�!!!
	virtual void Release(); //������ ����

	virtual ~Bishop();
};