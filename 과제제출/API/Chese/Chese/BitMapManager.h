#pragma once
#include "Mecro.h"
#include "Singleton.h"
#include "BitMap.h"

class BitMapManager : public Singleton<BitMapManager>
{
private:
	BitMap* m_bit;

	HDC hAlphaDC;
	HBITMAP hAlphaImage;
	HBITMAP hAlphaOldBitMap;

	HDC BackDC;
	HBITMAP hBackImage;
	HBITMAP hBackOldBitMap;

	vector<BitMap> m_ChessMap; //맵 벡터에 담기
	vector<BitMap> m_White_Unit; //흰색 유닛 벡터에 담기
	vector<BitMap> m_Black_Unit; //검정 유닛 벡터에 담기

public:
	BitMapManager();

	void All_Init(HWND hWnd); //일괄 초기화
	void All_Draw(HWND hWnd); //일괄 그리기

	void Map_Init(HWND hWnd); //맵 초기화
	void Map_Draw(HWND hWnd); //맵 그리기
	void Unit_Init(HWND hWnd); //체스말 초기화
	void Unit_Draw(HWND hWnd, int _unix, int _uniy, UNIT_CLASS _class, int _num); //체스말 그리기
	void Unit_BlendDraw(HWND hWnd, int _unix, int _uniy); //유닛이 갈수 있는곳을 그리기
	void Select_Draw(HWND hWnd, int _unix, int _uniy); //선택 칸 그리기
	void Data_Release(); //데이터 삭제
	~BitMapManager();
};