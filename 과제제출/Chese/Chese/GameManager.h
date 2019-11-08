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

	int Die_Unit;
public:
	GameManager();

	void Postion_Init(); //Position(Map, Unit) initalize

	void set_UnitPos(int _posx, int _posy, int _unitNum); //���� ��ġ �ֱ�
	int get_UnitPos(int _posx, int _posy); //���� ��ġ Ȯ�ο�

	int get_UnitXY(int _tmp); //���콺 Ŭ���� �簢���� ���� ��� ���� ���
	int get_DrawXY(int _tmp); //���ϴ� ���� �׸��� ������ �׸��� ���� �������� ������ ��ǥ���� ����.

	void inspection_Unit(int _posx, int _posy, int _pnum);
	void insert_BlackUnit(vector<UnitFactory*> _vBishop, vector<UnitFactory*> _vKing, vector<UnitFactory*> _vKnight, vector<UnitFactory*> _vPawn, vector<UnitFactory*> _vQueen, vector<UnitFactory*> _vRook);
	void insert_WhiteUnit(vector<UnitFactory*> _vBishop, vector<UnitFactory*> _vKing, vector<UnitFactory*> _vKnight, vector<UnitFactory*> _vPawn, vector<UnitFactory*> _vQueen, vector<UnitFactory*> _vRook);

	int get_DieUnit(); //���� ���� ��ȯ
	void pos_Release(); //������ ����
	
	~GameManager();
};