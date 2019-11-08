#pragma once
#include "Mecro.h"
#include "UnitFactory.h"

class Player
{
private:
	UnitFactory* m_Unit;
	vector<UnitFactory*> m_vPawn; //Pawn's vector
	vector<UnitFactory*> m_vKnight; //Knight's vector
	vector<UnitFactory*> m_vRook; //Rook's vector
	vector<UnitFactory*> m_vBishop; //Bishop's vector
	vector<UnitFactory*> m_vKing; //Bishop's vector
	vector<UnitFactory*> m_vQueen; //Queen's vector

	vector<UnitFactory*> tmp_vUnit;
	vector<RECT> tmp_vRect;

	RECT m_SelectRect;
	RECT tmp_UnitRect;
	RECT rcRect;

	bool Selecting;
	int tmp_Num;
	int Current_Unit;
	int Player_Num;
public:
	Player();

	void Make_Unit(HWND hWnd, int _posy1, int _posy2); //Unit's Make
	void Unit_DrawInit(HWND hWnd); ///unit all Draw(제일 처음)
	void Click(HWND hWnd, int _ptx, int _pty); //Click
	void Move_Click(HWND hWnd, int _ptx, int _pty); //유닛을 움직이기 위해 클릭
	void Hit_Update(HWND hWnd, vector<UnitFactory*> _vunit, int _posx, int _posy); //충돌 처리
	void Draw_Update(HWND hWnd, vector<UnitFactory*> _vunit, int _num); //유닛 그리기
	UnitFactory* Generate_Class(UNIT_CLASS _class); //Unit's Class Generate
	bool get_Selecting(); //이동하기 위해 유닛을 선택했는지 알려준다.
	void set_Player_Num(int _num); //플레이어 구분을 위한 정보
	void Player_reInit();
	void Player_Release(); //데이터 삭제

	~Player();
};