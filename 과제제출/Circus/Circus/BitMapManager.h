#pragma once
#include "Mecro.h"
#include "Singleton.h"
#include "BitMapFactory.h"

class BitMapManager : public Singleton <BitMapManager>
{
private:
	BitMapFactory* m_BitFac;

	BitMapFactory* m_playerBit;
	BitMapFactory* m_MapBit;
	BitMapFactory* m_ObjectBit;
	BitMapFactory* m_First;
	vector<BitMapFactory*> m_FrontRingBit;
	vector<BitMapFactory*> m_BackRingBit;
	vector<BitMapFactory*> m_FireBit;
	vector<BitMapFactory*> m_Bonus;

	vector<RECT> Fire_collider;
	vector<RECT> Ring_collider;
	vector<RECT> Bonus_collider;

	HDC hBackDC; //숨겨 그릴 장소(도화지)를 준비
	HBITMAP hBitBackDC;
	HBITMAP hOldDC;

	BITMAP BackMapInfo;
	SIZE BackSize;

	RECT m_pRect;
	RECT m_eRect;
	RECT m_GoalRect;

	int BonusCount;
	bool bitGenCheck;
public:
	BitMapManager(); //생성자
	
	void All_Init(HWND hWnd); //초기화
	void Make_FireRing(HWND hWnd, float _curx); //화염 고리 만들기
	void All_Draw(HWND hWnd, float _curx, float _cury, float _dftime); //그리기
	void First_Draw(HWND hWnd, float _curx, float _cury, float _dftime); //시작화면 그리기

	void Make_BackGround(HDC _hBackDC, HWND hWnd); //배경화면 만들기
	void Make_Player(HDC _hBackDC, HWND hWnd); //플레이어 만들기
	void Make_FrontEnemy(HDC _hBackDC, HWND hWnd, float _curx); //적(앞부분) 만들기
	void Make_BackEnemy(HDC _hBackDC, HWND hWnd, float _curx); //적(뒷부분) 만들기
	void Make_FireEnemy(HDC _hBackDC, HWND hWnd); //적(파이어~) 만들기
	void Make_Object(HDC _hBackDC, HWND hWnd); //오브젝트 만들기
	void Make_SelectView(HDC _hBackDC, HWND hWnd); //시작화면 만들기
	void Make_Bonus(HDC _hBackDC, HWND hWnd, float _curx); //보너스 주머니 만들기

	void BackGround_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //배경화면 그리기
	void Player_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //플레이어 그리기
	void FrontEnemy_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //적(앞부분) 그리기
	void BackEnemy_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //적(뒷부분) 그리기
	void FireEnemy_Draw(HDC _hBackDC, float _curx, float _cury); //적(파이어) 그리기
	void Object_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //오브젝트 그리기
	void SelectView_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //시작화면 그리기

	void Delete_Ring(); //링 삭제
	RECT get_pRect(); //플레이어 렉스 리턴
	vector<RECT> get_FireCol(); //Fire콜라이더 리턴
	vector<RECT> get_RingCol(); //Ring콜라이더 리턴
	RECT get_GoalRect(); //골지점 렉트 반환
	vector<RECT> get_BonusCol(); //보너스 콜라이더 반환


	void Release(); //데이터 삭제

	~BitMapManager(); //소멸자
};