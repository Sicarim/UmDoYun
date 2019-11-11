#pragma once
#include "Mecro.h"
#include "Singleton.h"
#include "UnitFactory.h"

class GameManager : public Singleton<GameManager>
{
private:
	vector<vector<int> > m_Position; //(multy(two) Vector)

	vector<UnitFactory*> tmpw_Bishop;
	vector<UnitFactory*> tmpw_King;
	vector<UnitFactory*> tmpw_Knight;
	vector<UnitFactory*> tmpw_Pawn;
	vector<UnitFactory*> tmpw_Queen;
	vector<UnitFactory*> tmpw_Rook;

	vector<UnitFactory*> tmpb_Bishop;
	vector<UnitFactory*> tmpb_King;
	vector<UnitFactory*> tmpb_Knight;
	vector<UnitFactory*> tmpb_Pawn;
	vector<UnitFactory*> tmpb_Queen;
	vector<UnitFactory*> tmpb_Rook;
	UnitFactory* tmp_Unit;
	int Die_Unit;
	bool isChange;
public:
	GameManager();

	void Postion_Init(); //Position(Map, Unit) initalize

	void set_UnitPos(int _posx, int _posy, int _unitNum); //유닛 위치 넣기
	int get_UnitPos(int _posx, int _posy); //유닛 위치 확인용

	int get_UnitXY(int _tmp); //마우스 클릭시 사각형의 좌측 상단 값을 계산
	int get_DrawXY(int _tmp); //원하는 곳에 그리고 싶을때 그리기 위한 실질적인 윈도우 좌표값을 얻어낸다.

	bool inspection_Unit(int _posx, int _posy, int _pnum);
	bool inspection_Pawn(int _posx, int _posy, int _pnum);
	void insert_BlackUnit(vector<UnitFactory*> _vBishop, vector<UnitFactory*> _vKing, vector<UnitFactory*> _vKnight, vector<UnitFactory*> _vPawn, vector<UnitFactory*> _vQueen, vector<UnitFactory*> _vRook);
	void insert_WhiteUnit(vector<UnitFactory*> _vBishop, vector<UnitFactory*> _vKing, vector<UnitFactory*> _vKnight, vector<UnitFactory*> _vPawn, vector<UnitFactory*> _vQueen, vector<UnitFactory*> _vRook);

	void Change_Unit(HWND hWnd, int _posx, int _posy, int _player, int _class); //유닛 변경하기
	UnitFactory* isChange_Unit();
	bool get_isChange();
	int get_DieUnit(); //죽은 유닛 반환
	void pos_Release(); //데이터 삭제
	
	~GameManager();
};