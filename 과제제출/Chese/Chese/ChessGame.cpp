#include "ChessGame.h"
#include "BitMapManager.h"
#include "GameManager.h"

ChessGame::ChessGame()
{
	turn_Count = 0;
}

//Game All initalize
void ChessGame::Game_Init(HWND hWnd)
{
	BitMapManager::get_Instence()->All_Init(hWnd);
	GameManager::get_Instence()->Postion_Init();

	//플레이어 유닛 위치 초기화
	m_Player1.set_Player_Num(PLAYER_ONE);
	m_Player1.Make_Unit(hWnd, 6, 7);
	
	m_Player2.set_Player_Num(PLAYER_TWO);
	m_Player2.Make_Unit(hWnd, 1, 0);
}

//Game Start
void ChessGame::Game_Play(HWND hWnd)
{
	m_Player1.Unit_DrawInit(hWnd);
	m_Player2.Unit_DrawInit(hWnd);
}

//Unit's Click
void ChessGame::Click_Unit(HWND hWnd, int _ptx, int _pty)
{
	if (turn_Count % 2 == 0)
	{
		if (!m_Player1.get_Selecting())
		{
			m_Player1.Click(hWnd, _ptx, _pty);
		}
		else
		{
			m_Player1.Move_Click(hWnd, _ptx, _pty);
			turn_Count++;
			End_Game(hWnd, turn_Count);
		}
	}
	else
	{
		if (!m_Player2.get_Selecting())
		{
			m_Player2.Click(hWnd, _ptx, _pty);
		}
		else
		{
			m_Player2.Move_Click(hWnd, _ptx, _pty);
			turn_Count++;
			End_Game(hWnd, turn_Count);
		}
	}
}

// 게임 종료 확인
void ChessGame::End_Game(HWND hWnd, int _num)
{
	if (GameManager::get_Instence()->get_DieUnit() == CLASS_KING)
	{
		if (_num % 2 == 0)
		{
			MessageBox(hWnd, "White 승리!", "게임 종료!", MB_OK);
		}
		else
		{
			MessageBox(hWnd, "Black 승리!", "게임 종료!", MB_OK);
		}
		if (MessageBox(hWnd, "게임을 다시 시작하겠습니까?", "게임 종료!", MB_YESNO) == IDNO)
		{
			DestroyWindow(hWnd);
		}
		else
		{
			Released_Data();
			turn_Count = 0;
			Game_Init(hWnd);
			Game_Play(hWnd);
			//InvalidateRect(hWnd, NULL, true);
		}
	}
}

void ChessGame::Released_Data()
{
	BitMapManager::get_Instence()->Data_Release();
	GameManager::get_Instence()->pos_Release();
	m_Player1.Player_Release();
	m_Player2.Player_Release();
}


ChessGame::~ChessGame()
{

}