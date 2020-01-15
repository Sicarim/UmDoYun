#include "GameManager.h"
#include "BitMapManager.h"

GameManager::GameManager()
{
	Die_Unit = 0;
	isChange = false;
	isDelete = false;
	Del_posX = 0;
	Del_posY = 0;
	Del_Class = 0;
}

//Position(Map, Unit) initalize
void GameManager::Postion_Init()
{
	for (int i = 0; i < POSROW; i++)
	{
		vector<int> Element;
		Element.resize(POSCOL);
		m_Position.push_back(Element);
	}

	//Vector initalize for 0
	for (int i = 0; i < POSROW; i++)
	{
		for (int j = 0; j < POSCOL; j++)
		{
			m_Position[i][j] = CLASS_END;
		}
	}
}

/*
0 1 2 3 4 5 7
8 9 10 11 12 13 14 15
16 17 18 19 20 21 22 23
24 25 26 27 28 29 30 31 
32 33 34 35 36 37 38 39 
40 41 42 43 44 45 46 47 
48 49 50 51 52 53 54 55 
56 57 58 59 60 61 62 63
*/

//유닛 위치 넣기
void GameManager::set_UnitPos(int _posx, int _posy, int _unitNum)
{
	m_Position[_posx][_posy] = _unitNum;
}

//유닛 위칙 확인
int GameManager::get_UnitPos(int _posx, int _posy)
{
	return m_Position[_posx][_posy];
}

//마우스 클릭시 사각형의 좌측 상단 값을 계산
int GameManager::get_UnitXY(int _tmp)
{
	return (_tmp - 75) / 101; // (윈도우 좌표 - 75(맵과 시작점의 띄운간격)) / 그림 크기 = 체스 맵의 행렬 위치(버림 사용)
}

//원하는 곳에 그리고 싶을때 그리기 위한 실질적인 윈도우 좌표값을 얻어낸다.
int GameManager::get_DrawXY(int _tmp)
{
	return 75 + (_tmp * 101); // 75(맵과 시작점의 띄운간격) + (체스 맵의 행렬 위치 * 카드 크기) = 실질적인 윈도우 좌표
}

bool GameManager::inspection_Unit(int _posx, int _posy, int _pnum)
{
	int tmp_posx;
	int tmp_posy;
	int tmp_classNum;
	vector<UnitFactory*> tmp_class;
	tmp_classNum = get_UnitPos(_posx, _posy);

	if (_pnum == PLAYER_ONE)
	{
		if (tmp_classNum == CLASS_PAWN)
			tmp_class = tmpb_Pawn;
		else if (tmp_classNum == CLASS_KNIGHT)
			tmp_class = tmpb_Knight;
		else if (tmp_classNum == CLASS_ROOK)
			tmp_class = tmpb_Rook;
		else if (tmp_classNum == CLASS_KING)
			tmp_class = tmpb_King;
		else if (tmp_classNum == CLASS_QUEEN)
			tmp_class = tmpb_Queen;
		else if (tmp_classNum == CLASS_BISHOP)
			tmp_class = tmpb_Bishop;

		for (int i = 0; i < tmp_class.size(); i++)
		{
			tmp_posx = tmp_class[i]->get_PosX();
			tmp_posy = tmp_class[i]->get_PosY();

			if (_posx == tmp_posx && _posy == tmp_posy)
			{
				Die_Unit = tmp_class[i]->attecked_Unit();
				isDelete = true;
				tmp_DelUnit = tmp_class[i];
				return true;
			}
		}
		return false;
	}
	else
	{
		if (tmp_classNum == CLASS_PAWN)
			tmp_class = tmpw_Pawn;
		else if (tmp_classNum == CLASS_KNIGHT)
			tmp_class = tmpw_Knight;
		else if (tmp_classNum == CLASS_ROOK)
			tmp_class = tmpw_Rook;
		else if (tmp_classNum == CLASS_KING)
			tmp_class = tmpw_King;
		else if (tmp_classNum == CLASS_QUEEN)
			tmp_class = tmpw_Queen;
		else if (tmp_classNum == CLASS_BISHOP)
			tmp_class = tmpw_Bishop;

		for (int i = 0; i < tmp_class.size(); i++)
		{
			tmp_posx = tmp_class[i]->get_PosX();
			tmp_posy = tmp_class[i]->get_PosY();

			if (_posx == tmp_posx && _posy == tmp_posy)
			{
				Die_Unit = tmp_class[i]->attecked_Unit();
				isDelete = true;
				tmp_DelUnit = tmp_class[i];
				return true;
			}
		}
		return false;
	}
}

bool GameManager::inspection_Pawn(int _posx, int _posy, int _pnum)
{
	int tmp_posx;
	int tmp_posy;
	int tmp_classNum;
	vector<UnitFactory*> tmp_class;
	tmp_classNum = get_UnitPos(_posx, _posy);

	if (_pnum == PLAYER_ONE)
	{
		if (tmp_classNum == CLASS_PAWN)
			tmp_class = tmpb_Pawn;
		else if (tmp_classNum == CLASS_KNIGHT)
			tmp_class = tmpb_Knight;
		else if (tmp_classNum == CLASS_ROOK)
			tmp_class = tmpb_Rook;
		else if (tmp_classNum == CLASS_KING)
			tmp_class = tmpb_King;
		else if (tmp_classNum == CLASS_QUEEN)
			tmp_class = tmpb_Queen;
		else if (tmp_classNum == CLASS_BISHOP)
			tmp_class = tmpb_Bishop;

		for (int i = 0; i < tmp_class.size(); i++)
		{
			tmp_posx = tmp_class[i]->get_PosX();
			tmp_posy = tmp_class[i]->get_PosY();

			if (_posx == tmp_posx && _posy == tmp_posy)
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		if (tmp_classNum == CLASS_PAWN)
			tmp_class = tmpw_Pawn;
		else if (tmp_classNum == CLASS_KNIGHT)
			tmp_class = tmpw_Knight;
		else if (tmp_classNum == CLASS_ROOK)
			tmp_class = tmpw_Rook;
		else if (tmp_classNum == CLASS_KING)
			tmp_class = tmpw_King;
		else if (tmp_classNum == CLASS_QUEEN)
			tmp_class = tmpw_Queen;
		else if (tmp_classNum == CLASS_BISHOP)
			tmp_class = tmpw_Bishop;

		for (int i = 0; i < tmp_class.size(); i++)
		{
			tmp_posx = tmp_class[i]->get_PosX();
			tmp_posy = tmp_class[i]->get_PosY();

			if (_posx == tmp_posx && _posy == tmp_posy)
			{
				return true;
			}
		}
		return false;
	}
}

void GameManager::insert_BlackUnit(vector<UnitFactory*> _vBishop, vector<UnitFactory*> _vKing, vector<UnitFactory*> _vKnight, vector<UnitFactory*> _vPawn, vector<UnitFactory*> _vQueen, vector<UnitFactory*> _vRook)
{
	tmpb_Bishop = _vBishop;
	tmpb_King = _vKing;
	tmpb_Knight = _vKnight;
	tmpb_Pawn = _vPawn;
	tmpb_Queen = _vQueen;
	tmpb_Rook = _vRook;
}

void GameManager::insert_WhiteUnit(vector<UnitFactory*> _vBishop, vector<UnitFactory*> _vKing, vector<UnitFactory*> _vKnight, vector<UnitFactory*> _vPawn, vector<UnitFactory*> _vQueen, vector<UnitFactory*> _vRook)
{
	tmpw_Bishop = _vBishop;
	tmpw_King = _vKing;
	tmpw_Knight = _vKnight;
	tmpw_Pawn = _vPawn;
	tmpw_Queen = _vQueen;
	tmpw_Rook = _vRook;
}

//유닛 변경하기
void GameManager::Change_Unit(HWND hWnd, int _posx, int _posy, int _player, int _class)
{
	isChange = true;
	isChangePlayer = _player;

	if (_class == CLASS_BISHOP)
	{
		tmp_Unit = new Bishop();
	}
	else if (_class == CLASS_KNIGHT)
	{
		tmp_Unit = new Knight();
	}
	else if (_class == CLASS_QUEEN)
	{
		tmp_Unit = new Queen();
	}
	else if (_class == CLASS_ROOK)
	{
		tmp_Unit = new Rook();
	}
	tmp_Unit->Unit_Behavior(hWnd, _posx, _posy, _player);
}

UnitFactory* GameManager::isChange_Unit()
{
	if (isChange)
	{
		isChange = false;
		return tmp_Unit;
	}
}

UnitFactory* GameManager::Delete_Unit()
{
	return tmp_DelUnit;
}

//죽은 유닛 반환
int GameManager::get_DieUnit()
{
	return Die_Unit;
}

//데이터 삭제
void GameManager::pos_Release()
{
	for (int i = 0; i < POSROW; i++)
	{
		m_Position[i].clear();
	}
	m_Position.clear();
	delete tmp_Unit;
	tmpw_Bishop.clear();
	tmpw_King.clear();
	tmpw_Knight.clear();
	tmpw_Pawn.clear();
	tmpw_Queen.clear();
	tmpw_Rook.clear();

	tmpb_Bishop.clear();
	tmpb_King.clear();
	tmpb_Knight.clear();
	tmpb_Pawn.clear();
	tmpb_Queen.clear();
	tmpb_Rook.clear();
	Die_Unit = CLASS_END;
	isChange = false;
}

bool GameManager::get_isChange()
{
	return isChange;
}

int GameManager::get_changePlayer()
{
	return isChangePlayer;
}

bool GameManager::get_isDelete()
{
	return isDelete;
}

void GameManager::set_isDelete(bool _delete)
{
	isDelete = _delete;
}

GameManager::~GameManager()
{
	pos_Release();
}