#include "ChessGame.h"
#include "BitMapManager.h"
#include "GameManager.h"

ChessGame::ChessGame()
{
	turn_Count = 0;
	CurrentTurn = 1;
}

//Game All initalize
void ChessGame::Game_Init(HWND hWnd)
{
	BitMapManager::get_Instence()->All_Init(hWnd);
	GameManager::get_Instence()->Postion_Init();

	//�÷��̾� ���� ��ġ �ʱ�ȭ
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
		if (CurrentTurn == m_Player1.get_Player_Num())
		{
			if (!m_Player1.get_Selecting())
			{
				m_Player1.Click(hWnd, _ptx, _pty);
			}
			else
			{
				if (m_Player1.Move_Click(hWnd, _ptx, _pty))
				{
					turn_Count++;
					Change_Turn();
					End_Game(hWnd, turn_Count);
				}
			}
		}
	}

	else
	{
		if (CurrentTurn == m_Player2.get_Player_Num())
		{
			if (!m_Player2.get_Selecting())
			{
				m_Player2.Click(hWnd, _ptx, _pty);
			}
			else
			{
				if (m_Player2.Move_Click(hWnd, _ptx, _pty))
				{
					turn_Count++;
					Change_Turn();
					End_Game(hWnd, turn_Count);
				}
			}
		}
	}
}

//�� �ٲٱ�
void ChessGame::Change_Turn()
{
	if (CurrentTurn == 1)
	{
		CurrentTurn = 2;
	}
	else
	{
		CurrentTurn = 1;
	}
}

// ���� ���� Ȯ��
void ChessGame::End_Game(HWND hWnd, int _num)
{
	if (GameManager::get_Instence()->get_DieUnit() == CLASS_KING)
	{
		if (_num % 2 == 0)
		{
			MessageBox(hWnd, "Black �¸�!", "���� ����!", MB_OK);
		}
		else
		{
			MessageBox(hWnd, "White �¸�!", "���� ����!", MB_OK);
		}
		if (MessageBox(hWnd, "������ �ٽ� �����ϰڽ��ϱ�?", "���� ����!", MB_YESNO) == IDNO)
		{
			DestroyWindow(hWnd);
		}
		else
		{
			Released_Data();
			Game_Init(hWnd);
			Game_Play(hWnd);
		}
	}
}

void ChessGame::Released_Data()
{
	BitMapManager::get_Instence()->Data_Release();
	GameManager::get_Instence()->pos_Release();
	m_Player1.Player_Release();
	m_Player2.Player_Release();
	turn_Count = 0;
	CurrentTurn = 1;
}


ChessGame::~ChessGame()
{

}