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
	void Unit_DrawInit(HWND hWnd); ///unit all Draw(���� ó��)
	void Click(HWND hWnd, int _ptx, int _pty); //Click
	void Move_Click(HWND hWnd, int _ptx, int _pty); //������ �����̱� ���� Ŭ��
	void Hit_Update(HWND hWnd, vector<UnitFactory*> _vunit, int _posx, int _posy); //�浹 ó��
	void Draw_Update(HWND hWnd, vector<UnitFactory*> _vunit, int _num); //���� �׸���
	UnitFactory* Generate_Class(UNIT_CLASS _class); //Unit's Class Generate
	bool get_Selecting(); //�̵��ϱ� ���� ������ �����ߴ��� �˷��ش�.
	void set_Player_Num(int _num); //�÷��̾� ������ ���� ����
	void Player_reInit();
	void Player_Release(); //������ ����

	~Player();
};