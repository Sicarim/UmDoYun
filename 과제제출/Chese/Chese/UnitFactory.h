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
	virtual int get_PlayerUnit() = 0; //플레이어 유닛 확인

	virtual int get_Class() = 0; //유닛 종류 반환
	virtual void Unit_Rect(int _unix, int _uniy) = 0; //Unit Rect
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num) = 0; //Unit's Behavior
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy) = 0; //유닛을 눌렀따
	virtual void Unit_Draw(HWND hWnd, int _num) = 0; //다시 그려질때마다 그려지는 유닛들
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy) = 0; //유닛 움직이기
	virtual void Unit_DrawUpdate(int _posx, int _posy) = 0; //유닛이 그려질 실질적 위치 최신화
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0) = 0; //유닛이 갈수 있는 위치를 그린다.
	virtual void Draw_Blend(HWND hWnd) = 0; //유닛이 갈수 있는 위치를 그린다.
	virtual RECT get_Rect() = 0; //Rect's returns
	virtual vector<RECT> get_vblend() = 0; //유닛 갈수 있는 위치 반환
	virtual int get_PosX() = 0; //현재 위치를 반환(x)
	virtual int get_PosY() = 0; //현재 위치를 반환(y)
	virtual int attecked_Unit() = 0; //공격 당했다!!!
	virtual void Release() = 0; //데이터 삭제
	virtual ~UnitFactory();
};

class Pawn : public UnitFactory
{
private:
	bool First_Start;
public:
	Pawn();

	virtual int get_PlayerUnit(); //플레이어 유닛 확인

	virtual int get_Class(); //유닛 종류 반환(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //유닛을 눌렀따(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //다시 그려질때마다 그려지는 유닛들
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //유닛 움직이기(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //유닛이 그려질 실질적 위치 최신화(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //유닛이 갈수 있는 위치를 그린다.
	virtual void Draw_Blend(HWND hWnd); //유닛이 갈수 있는 위치를 그린다.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //유닛 x좌표 반환(Overrride)
	virtual int get_PosX(); //현재 위치를 반환(x)
	virtual int get_PosY(); //현재 위치를 반환(y)
	virtual int attecked_Unit(); //공격 당했다!!!
	virtual void Release(); //데이터 삭제

	virtual ~Pawn();
};

class King : public UnitFactory
{
private:
public:
	King();

	virtual int get_PlayerUnit(); //플레이어 유닛 확인

	virtual int get_Class(); //유닛 종류 반환(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //유닛을 눌렀따(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //다시 그려질때마다 그려지는 유닛들
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //유닛 움직이기(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //유닛이 그려질 실질적 위치 최신화(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //유닛이 갈수 있는 위치를 그린다.
	virtual void Draw_Blend(HWND hWnd); //유닛이 갈수 있는 위치를 그린다.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //유닛 x좌표 반환(Overrride)
	virtual int get_PosX(); //현재 위치를 반환(x)
	virtual int get_PosY(); //현재 위치를 반환(y)
	virtual int attecked_Unit(); //공격 당했다!!!
	virtual void Release(); //데이터 삭제

	virtual ~King();
};

class Queen : public UnitFactory
{
private:
public:
	Queen();

	virtual int get_PlayerUnit(); //플레이어 유닛 확인

	virtual int get_Class(); //유닛 종류 반환(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //유닛을 눌렀따(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //다시 그려질때마다 그려지는 유닛들
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //유닛 움직이기(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //유닛이 그려질 실질적 위치 최신화(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //유닛이 갈수 있는 위치를 그린다.
	virtual void Draw_Blend(HWND hWnd); //유닛이 갈수 있는 위치를 그린다.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //유닛 x좌표 반환(Overrride)
	virtual int get_PosX(); //현재 위치를 반환(x)
	virtual int get_PosY(); //현재 위치를 반환(y)
	virtual int attecked_Unit(); //공격 당했다!!!
	virtual void Release(); //데이터 삭제

	virtual ~Queen();
};

class Knight : public UnitFactory
{
private:
public:
	Knight();

	virtual int get_PlayerUnit(); //플레이어 유닛 확인

	virtual int get_Class(); //유닛 종류 반환(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //유닛을 눌렀따(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //다시 그려질때마다 그려지는 유닛들
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //유닛 움직이기(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //유닛이 그려질 실질적 위치 최신화(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //유닛이 갈수 있는 위치를 그린다.
	virtual void Draw_Blend(HWND hWnd); //유닛이 갈수 있는 위치를 그린다.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //유닛 x좌표 반환(Overrride)
	virtual int get_PosX(); //현재 위치를 반환(x)
	virtual int get_PosY(); //현재 위치를 반환(y)
	virtual int attecked_Unit(); //공격 당했다!!!
	virtual void Release(); //데이터 삭제

	virtual ~Knight();
};

class Rook : public UnitFactory
{
private:
public:
	Rook();

	virtual int get_PlayerUnit(); //플레이어 유닛 확인

	virtual int get_Class(); //유닛 종류 반환(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //유닛을 눌렀따(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //다시 그려질때마다 그려지는 유닛들
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //유닛 움직이기(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //유닛이 그려질 실질적 위치 최신화(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //유닛이 갈수 있는 위치를 그린다.
	virtual void Draw_Blend(HWND hWnd); //유닛이 갈수 있는 위치를 그린다.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //유닛 x좌표 반환(Overrride)
	virtual int get_PosX(); //현재 위치를 반환(x)
	virtual int get_PosY(); //현재 위치를 반환(y)
	virtual int attecked_Unit(); //공격 당했다!!!
	virtual void Release(); //데이터 삭제

	virtual ~Rook();
};

class Bishop : public UnitFactory
{
private:
public:
	Bishop();

	virtual int get_PlayerUnit(); //플레이어 유닛 확인

	virtual int get_Class(); //유닛 종류 반환(Override)
	virtual void Unit_Rect(int _unix, int _uniy); //Unit Rect(Override)
	virtual void Unit_Behavior(HWND hWnd, int _posx, int _posy, int _num); //Unit's Behavior(Override)
	virtual void Clicked_Unit(HWND hWnd, int _posx, int _posy); //유닛을 눌렀따(Override)
	virtual void Unit_Draw(HWND hWnd, int _num); //다시 그려질때마다 그려지는 유닛들
	virtual void Move_Unit(HWND hWnd, int _posx, int _posy); //유닛 움직이기(Override)
	virtual void Unit_DrawUpdate(int _posx, int _posy); //유닛이 그려질 실질적 위치 최신화(Override)
	virtual void Draw_Blend(HWND hWnd, int _pos1 = 0, int _pos2 = 0, int _unix = 0, int _uniy = 0, int _cnt = 0, int _num = 0); //유닛이 갈수 있는 위치를 그린다.
	virtual void Draw_Blend(HWND hWnd); //유닛이 갈수 있는 위치를 그린다.(Override)
	virtual RECT get_Rect(); //Rect's returns
	virtual vector<RECT> get_vblend(); //유닛 x좌표 반환(Overrride)
	virtual int get_PosX(); //현재 위치를 반환(x)
	virtual int get_PosY(); //현재 위치를 반환(y)
	virtual int attecked_Unit(); //공격 당했다!!!
	virtual void Release(); //데이터 삭제

	virtual ~Bishop();
};