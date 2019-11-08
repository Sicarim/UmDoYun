#pragma once
#include "Mecro.h"
#include "Player.h"

class ChessGame
{
private:
	Player m_Player1;
	Player m_Player2;
	int turn_Count;
public:
	ChessGame();

	void Game_Init(HWND hWnd); //Game All initalize
	void Game_Play(HWND hWnd); //Game Start
	void Click_Unit(HWND hWnd, int _ptx, int _pty); //Unit's Click
	void End_Game(HWND hWnd, int _num); //게임 종료 확인
	void Released_Data();

	~ChessGame();
};