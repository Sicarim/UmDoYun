#pragma once
#include "Mecro.h"
#include "Player.h"

class ChessGame
{
private:
	Player m_Player1;
	Player m_Player2;
	int turn_Count;
	int CurrentTurn;
public:
	ChessGame();

	void Game_Init(HWND hWnd); //Game All initalize
	void Game_Play(HWND hWnd); //Game Start
	void Click_Unit(HWND hWnd, int _ptx, int _pty); //Unit's Click
	void Change_Turn(); //�� �ٲٱ�
	void End_Game(HWND hWnd, int _num); //���� ���� Ȯ��
	void Released_Data();

	~ChessGame();
};