#pragma once
#include "Mecro.h"

class BitMapFactory
{
private:
protected:
	int curPos;
public:
	BitMapFactory() {} //생성자

	virtual void Bit_Init(HDC hBack, HWND hWnd, float _curx = 0) = 0; //BitMap초기화
	virtual void Bit_Draw(HDC hBack, float _curx = 0, float _cury = 0, float _dftime = 0) = 0; //BitMap그리기
	virtual void set_CurPos(int _curpos) {} //현재 캐릭터 위치 받기
	virtual RECT get_Rect() = 0; //렉트 반환

	virtual ~BitMapFactory() {} //소멸자
};

class MapBit : public BitMapFactory
{
private:
	/*
	 * GroundDC: 초록색 땅
	 * DecoDC: 코끼리
	 * NomalDC: 관중
	 * o_NomalDC: 하얀색 관중
	*/
	HDC BlackDC;
	HBITMAP bitBlack;
	HBITMAP oldbitBlack;

	HDC GroundDC, DecoDC, NormalDC[2], MiterDC;
	HBITMAP bitGroundDC, bitDecoDC, bitNormalDC[2], bitMiterDC;
	HBITMAP GroundOldDC, DecoOldDC, NormalOldDC[2], MiterOldDC;

	BITMAP GroundMapInfo, DecoMapInfo, NormalMapInfo[2], MiterMapInfo;
	SIZE GroundSize, DecoSize, NormalSize[2], MiterSize;

	HFONT font, oldfont;
	RECT Map_Rect;

public:
	MapBit(); //생성자

	virtual void Bit_Init(HDC hBack, HWND hWnd, float _curx = 0); //BitMap초기화(Override)
	virtual void Bit_Draw(HDC hBack, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap그리기(Override)
	virtual void set_CurPos(int _curpos); //현재 캐릭터 위치 받기(override)
	virtual RECT get_Rect(); //렉트 반환(override)

	virtual ~MapBit(); //소멸자
};

class PlayerBit : public BitMapFactory
{
private:
	float EndTime;
	int winPos;
	float moveX;
	float moveY;
	HDC PlayerDC[6];
	HBITMAP bitPlayerDC[6];
	HBITMAP PlayerOldDC[6];

	BITMAP playerInfo[4];
	SIZE pSize[4];

	RECT Player_Rect;

	//확인용 브러쉬
	HBRUSH pBrush;
	HBRUSH poBrush;
public:
	PlayerBit(); //생성자

	virtual void Bit_Init(HDC hBack, HWND hWnd, float _curx = 0); //BitMap초기화(Override)
	virtual void Bit_Draw(HDC hBack, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap그리기(Override)
	virtual RECT get_Rect(); //렉트 반환(override)

	virtual ~PlayerBit(); //소멸자
};

class EnemyFrontBit : public BitMapFactory
{
private:
	int MovePos;
	HDC EnemyDC;
	HBITMAP bitEnemyDC;
	HBITMAP EnemyOldDC;
	
	BITMAP EnemyInfo;
	SIZE eSize;

	RECT Front_Rect;

	//확인용 브러쉬
	HBRUSH efBrush;
	HBRUSH efoBrush;

public:
	EnemyFrontBit(); //생성자

	virtual void Bit_Init(HDC hBack, HWND hWnd, float _curx = 0); //BitMap초기화(Override)
	virtual void Bit_Draw(HDC hBack, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap그리기(Override)
	virtual void set_CurPos(int _curpos); //현재 캐릭터 위치 받기(override)
	virtual RECT get_Rect(); //렉트 반환(override)

	virtual ~EnemyFrontBit(); //소멸자
};

class EnemyBackBit : public BitMapFactory
{
private:
	int MovePos;
	HDC EnemyDC;
	HBITMAP bitEnemyDC;
	HBITMAP EnemyOldDC;
	
	BITMAP EnemyInfo;
	SIZE eSize;

	RECT Back_Rect;
public:
	EnemyBackBit(); //생성자

	virtual void Bit_Init(HDC hback, HWND hWnd, float _curx = 0); //BitMap초기화(Override)
	virtual void Bit_Draw(HDC hback, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap그리기(Override)
	virtual void set_CurPos(int _curpos); //현재 캐릭터 위치 받기(override)
	virtual RECT get_Rect(); //렉트 반환(override)

	virtual ~EnemyBackBit(); //소멸자
};

class EnemyFireBit : public BitMapFactory
{
private:
	int Fire_Pos;
	int tmp_iL, tmp_iT, tmp_iR, tmp_iB;

	HDC EnemyFireDC[2];
	HBITMAP bitEnemyFireDC[2];
	HBITMAP OldEnemyFireDC[2];

	BITMAP EnemyFireInfo[2];
	SIZE efSize[2];

	//확인용 브러쉬
	HBRUSH fireBrush;
	HBRUSH ofireBrush;

	RECT Fire_Rect;

public:
	EnemyFireBit(); //생성자

	virtual void Bit_Init(HDC hback, HWND hWnd, float _curx = 0); //BitMap초기화(Override)
	virtual void Bit_Draw(HDC hback, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap그리기(Override)
	virtual void set_CurPos(int _curpos); //현재 캐릭터 위치 받기(override)
	virtual RECT get_Rect(); //렉트 반환(override)

	~EnemyFireBit(); //소멸자

};

class ObjectBit : public BitMapFactory
{
private:
	int Health_Point;
	HDC HealthDC, GoalDC;
	HBITMAP bitHealthDC, bitGoalDC;
	HBITMAP oldHealthDC, oldGoalDC;

	BITMAP HealthInfo, GoalInfo;
	SIZE HealthSize, GoalSize;

	//확인용 브러쉬
	HBRUSH goalBrush;
	HBRUSH ogoalBrush;

	HFONT Score, oldScore;

	RECT GoalRect;
public:
	ObjectBit(); //생성자

	virtual void Bit_Init(HDC hback, HWND hWnd, float _curx = 0); //BitMap초기화(Override)
	virtual void Bit_Draw(HDC hback, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap그리기(Override)
	virtual void set_CurPos(int _curpos); //현재 캐릭터 위치 받기(override)
	virtual RECT get_Rect(); //렉트 반환(override)

	~ObjectBit(); //소멸자
};