#include "Player.h"
#include "GameManager.h"
#include "BitMapManager.h"

//생성자
Player::Player()
{
	m_Unit = NULL;
	m_SelectRect = {0};
	rcRect = {0};
	Selecting = false;
	tmp_Num = 0;
	Current_Unit = 0;
}

//플레이어 구분을 위한 정보
void Player::set_Player_Num(int _num)
{
	Player_Num = _num;
}

//플레이어 구분을 위한 정보
int Player::get_Player_Num()
{
	return Player_Num;
}

//Unit's Make
void Player::Make_Unit(HWND hWnd, int _posy1, int _posy2)
{
	int Unit_Count = 1;
	/*
	기준점 75, 75(맵 가장 첫번째 칸
	가로 간격: 101
	세로 간격: 101
	*/
	
	//Make Pawn
	for (int i = 0; i < 8; i++)
	{
		m_Unit = Generate_Class(CLASS_PAWN);
		m_Unit->Unit_Behavior(hWnd, i, _posy1, Player_Num);
		m_vPawn.push_back(m_Unit);
	}

	//Make Knight
	for (int i = 0; i < 2; i++)
	{
		m_Unit = Generate_Class(CLASS_KNIGHT);
		m_Unit->Unit_Behavior(hWnd, Unit_Count, _posy2, Player_Num);
		m_vKnight.push_back(m_Unit);
		Unit_Count += 5;
	}

	Unit_Count = 0;

	//Make Rook
	for (int i = 0; i < 2; i++)
	{
		m_Unit = Generate_Class(CLASS_ROOK);
		m_Unit->Unit_Behavior(hWnd, Unit_Count, _posy2, Player_Num);
		m_vRook.push_back(m_Unit);
		Unit_Count += 7;
	}

	Unit_Count = 2;

	//MakeBishop
	for (int i = 0; i < 2; i++)
	{
		m_Unit = Generate_Class(CLASS_BISHOP);
		m_Unit->Unit_Behavior(hWnd, Unit_Count, _posy2, Player_Num);
		m_vBishop.push_back(m_Unit);
		Unit_Count += 3;
	}

	//Make King
	m_Unit = Generate_Class(CLASS_KING);
	m_Unit->Unit_Behavior(hWnd, 3, _posy2, Player_Num);
	m_vKing.push_back(m_Unit);

	//Make Queen
	m_Unit = Generate_Class(CLASS_QUEEN);
	m_Unit->Unit_Behavior(hWnd, 4, _posy2, Player_Num);
	m_vQueen.push_back(m_Unit);
}

///unit all Draw(제일 처음)
void Player::Unit_DrawInit(HWND hWnd)
{
	//Pawn
	Draw_Update(hWnd, m_vPawn, Player_Num);
	//Knight
	Draw_Update(hWnd, m_vKnight, Player_Num);
	//Rook
	Draw_Update(hWnd, m_vRook, Player_Num);
	//Bishop
	Draw_Update(hWnd, m_vBishop, Player_Num);
	//King
	Draw_Update(hWnd, m_vKing, Player_Num);
	//Queen
	Draw_Update(hWnd, m_vQueen, Player_Num);

	if (Player_Num == PLAYER_ONE)
	{
		GameManager::get_Instence()->insert_WhiteUnit(m_vBishop, m_vKing, m_vKnight, m_vPawn, m_vQueen, m_vRook);
	}
	else
	{
		GameManager::get_Instence()->insert_BlackUnit(m_vBishop, m_vKing, m_vKnight, m_vPawn, m_vQueen, m_vRook);
	}
}

//Click
void Player::Click(HWND hWnd, int _ptx, int _pty)
{
	int tmp_ptx = floor(GameManager::get_Instence()->get_UnitXY(_ptx));
	int tmp_pty = floor(GameManager::get_Instence()->get_UnitXY(_pty));
	int Box_ptx = GameManager::get_Instence()->get_DrawXY(tmp_ptx);
	int Box_pty = GameManager::get_Instence()->get_DrawXY(tmp_pty);
	int tmp_UnitPosX = 0;
	int tmp_UnitPosY = 0;
	
	BitMapManager::get_Instence()->Select_Draw(hWnd, Box_ptx, Box_pty);
	m_SelectRect = { Box_ptx, Box_pty, Box_ptx + 101, Box_pty + 101};
	Delete_unitVector();
	//충돌 처리
	//Pawn
	Hit_Update(hWnd, m_vPawn, tmp_ptx, tmp_pty);
	//Rook
	Hit_Update(hWnd, m_vRook, tmp_ptx, tmp_pty);
	//Knight
	Hit_Update(hWnd, m_vKnight, tmp_ptx, tmp_pty);
	//Bishop
	Hit_Update(hWnd, m_vBishop, tmp_ptx, tmp_pty);
	//King
	Hit_Update(hWnd, m_vKing, tmp_ptx, tmp_pty);
	//Queen
	Hit_Update(hWnd, m_vQueen, tmp_ptx, tmp_pty);
	Player_reInit();
}

//유닛을 움직이기 위해 클릭
bool Player::Move_Click(HWND hWnd, int _ptx, int _pty)
{
	bool tmp_bo = true;
	int tmp_ptx = floor(GameManager::get_Instence()->get_UnitXY(_ptx));
	int tmp_pty = floor(GameManager::get_Instence()->get_UnitXY(_pty));
	int Box_ptx = GameManager::get_Instence()->get_DrawXY(tmp_ptx);
	int Box_pty = GameManager::get_Instence()->get_DrawXY(tmp_pty);

	m_SelectRect = { Box_ptx, Box_pty, Box_ptx + 101, Box_pty + 101 };

	tmp_vRect = tmp_vUnit[tmp_Num]->get_vblend();

	for (int i = 0; i < tmp_vRect.size(); i++)
	{
		//블랜드(유닛이 갈수 있는곳)을 클릭했을때
		if (IntersectRect(&rcRect, &m_SelectRect, &tmp_vRect[i]))
		{
			//자신이 있던 위치를 빈공간으로 만든다.
			int tmp_posx = tmp_vUnit[tmp_Num]->get_PosX();
			int tmp_posy = tmp_vUnit[tmp_Num]->get_PosY();
			GameManager::get_Instence()->set_UnitPos(tmp_posx, tmp_posy, CLASS_END);
			//

			if (GameManager::get_Instence()->get_UnitPos(tmp_ptx, tmp_pty) != CLASS_END)
			{
				tmp_bo = GameManager::get_Instence()->inspection_Unit(tmp_ptx, tmp_pty, Player_Num);
			}
			if (tmp_bo)
			{
				tmp_vUnit[tmp_Num]->Move_Unit(hWnd, tmp_ptx, tmp_pty);
				Player_reInit();
				Selecting = false;
				return true;
			}
		}
	}
	Selecting = false;
	return false;
}

//충돌 처리
void Player::Hit_Update(HWND hWnd, vector<UnitFactory*> _vunit, int _posx, int _posy)
{
	for (int i = 0; i < _vunit.size(); i++)
	{
		tmp_UnitRect = _vunit[i]->get_Rect();

		if (IntersectRect(&rcRect, &m_SelectRect, &tmp_UnitRect))
		{
			_vunit[i]->Clicked_Unit(hWnd, _posx, _posy);
			tmp_vUnit = _vunit;
			tmp_Num = i;
			Current_Unit = _vunit[i]->get_Class();
			Selecting = true;
		}
	}
}

//벡터 삭제하기
void Player::Delete_unitVector()
{
	UnitFactory* tmp_unit;

	if (GameManager::get_Instence()->get_isDelete())
	{
		tmp_unit = GameManager::get_Instence()->Delete_Unit();
		tmp_unit->get_Class();

		if (tmp_unit->get_Class() == CLASS_PAWN)
		{
			for (int i = 0; m_vPawn.size(); i++)
			{
				if (m_vPawn[i] == tmp_unit)
				{
					m_vPawn.erase(m_vPawn.begin() + i);
					GameManager::get_Instence()->set_isDelete(false);
					break;
				}
			}
		}
		if (tmp_unit->get_Class() == CLASS_QUEEN)
		{
			for (int i = 0; m_vQueen.size(); i++)
			{
				if (m_vQueen[i] == tmp_unit)
				{
					m_vQueen.erase(m_vQueen.begin() + i);
					GameManager::get_Instence()->set_isDelete(false);
					break;
				}
			}
		}
		if (tmp_unit->get_Class() == CLASS_ROOK)
		{
			for (int i = 0; m_vRook.size(); i++)
			{
				if (m_vRook[i] == tmp_unit)
				{
					m_vRook.erase(m_vRook.begin() + i);
					GameManager::get_Instence()->set_isDelete(false);
					return;
				}
			}
		}
		if (tmp_unit->get_Class() == CLASS_KNIGHT)
		{
			for (int i = 0; m_vKnight.size(); i++)
			{
				if (m_vKnight[i] == tmp_unit)
				{
					m_vKnight.erase(m_vKnight.begin() + i);
					GameManager::get_Instence()->set_isDelete(false);
					return;
				}
			}
		}
		if (tmp_unit->get_Class() == CLASS_BISHOP)
		{
			for (int i = 0; m_vBishop.size(); i++)
			{
				if (m_vBishop[i] == tmp_unit)
				{
					m_vBishop.erase(m_vBishop.begin() + i);
					GameManager::get_Instence()->set_isDelete(false);
					return;
				}
			}
		}
	}
}

//유닛 그리기
void Player::Draw_Update(HWND hWnd, vector<UnitFactory*> _vunit, int _num)
{
	for (int i = 0; i < _vunit.size(); i++)
	{
		_vunit[i]->Unit_Draw(hWnd, _num);
	}
}

//취소하기
bool Player::CancelUpdate(int _ptx, int _pty)
{
	RECT tmp_Rect;
	RECT tmp_SelectRect;
	int tmp_ptx = floor(GameManager::get_Instence()->get_UnitXY(_ptx));
	int tmp_pty = floor(GameManager::get_Instence()->get_UnitXY(_pty));
	int Box_ptx = GameManager::get_Instence()->get_DrawXY(tmp_ptx);
	int Box_pty = GameManager::get_Instence()->get_DrawXY(tmp_pty);

	tmp_SelectRect = { Box_ptx, Box_pty, Box_ptx + 101, Box_pty + 101 };
	Selecting = false;
	for (int i = 0; i < m_vPawn.size(); i++)
	{
		tmp_Rect = m_vPawn[i]->get_Rect();

		if (IntersectRect(&rcRect, &tmp_SelectRect, &tmp_Rect))
		{
			return false;
		}
	}
	return true;
}

void Player::Player_reInit()
{
	if (GameManager::get_Instence()->get_isChange() && GameManager::get_Instence()->get_changePlayer() == Player_Num)
	{
		tmp_Unit = GameManager::get_Instence()->isChange_Unit();
		if (tmp_Unit->get_Class() == CLASS_BISHOP)
		{
			m_vBishop.push_back(tmp_Unit);
		}
		else if (tmp_Unit->get_Class() == CLASS_KNIGHT)
		{
			m_vKnight.push_back(tmp_Unit);
		}
		else if (tmp_Unit->get_Class() == CLASS_QUEEN)
		{
			m_vQueen.push_back(tmp_Unit);
		}
		else if (tmp_Unit->get_Class() == CLASS_ROOK)
		{
			m_vRook.push_back(tmp_Unit);
		}
	}

	if (Player_Num == PLAYER_ONE)
	{
		GameManager::get_Instence()->insert_WhiteUnit(m_vBishop, m_vKing, m_vKnight, m_vPawn, m_vQueen, m_vRook);
	}
	else
	{
		GameManager::get_Instence()->insert_BlackUnit(m_vBishop, m_vKing, m_vKnight, m_vPawn, m_vQueen, m_vRook);
	}
}

//유닛 직업 생성
UnitFactory* Player::Generate_Class(UNIT_CLASS _class)
{
	switch (_class)
	{
	case CLASS_PAWN:
		return new Pawn;
	case CLASS_KING:
		return new King;
	case CLASS_QUEEN:
		return new Queen;
	case CLASS_ROOK:
		return new Rook;
	case CLASS_KNIGHT:
		return new Knight;
	case CLASS_BISHOP:
		return new Bishop;
	}
}

//이동하기 위해 유닛을 선택했는지 알려준다.
bool Player::get_Selecting()
{
	return Selecting;
}

//데이터 삭제
void Player::Player_Release()
{
	m_vPawn.clear();
	m_vKnight.clear();
	m_vRook.clear();
	m_vBishop.clear();
	m_vKing.clear();
	m_vQueen.clear();
	tmp_vUnit.clear();
	tmp_vUnit.clear();
	tmp_vRect.clear();
}

//소멸자
Player::~Player()
{
	Player_Release();
}