#pragma once
#include "Mecro.h"

class BitMapFactory
{
private:
protected:
	int curPos;
public:
	BitMapFactory() {} //������

	virtual void Bit_Init(HDC hBack, HWND hWnd, float _curx = 0) = 0; //BitMap�ʱ�ȭ
	virtual void Bit_Draw(HDC hBack, float _curx = 0, float _cury = 0, float _dftime = 0) = 0; //BitMap�׸���
	virtual void set_CurPos(int _curpos) {} //���� ĳ���� ��ġ �ޱ�
	virtual RECT get_Rect() = 0; //��Ʈ ��ȯ

	virtual ~BitMapFactory() {} //�Ҹ���
};

class MapBit : public BitMapFactory
{
private:
	/*
	 * GroundDC: �ʷϻ� ��
	 * DecoDC: �ڳ���
	 * NomalDC: ����
	 * o_NomalDC: �Ͼ�� ����
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
	MapBit(); //������

	virtual void Bit_Init(HDC hBack, HWND hWnd, float _curx = 0); //BitMap�ʱ�ȭ(Override)
	virtual void Bit_Draw(HDC hBack, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap�׸���(Override)
	virtual void set_CurPos(int _curpos); //���� ĳ���� ��ġ �ޱ�(override)
	virtual RECT get_Rect(); //��Ʈ ��ȯ(override)

	virtual ~MapBit(); //�Ҹ���
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

	//Ȯ�ο� �귯��
	HBRUSH pBrush;
	HBRUSH poBrush;
public:
	PlayerBit(); //������

	virtual void Bit_Init(HDC hBack, HWND hWnd, float _curx = 0); //BitMap�ʱ�ȭ(Override)
	virtual void Bit_Draw(HDC hBack, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap�׸���(Override)
	virtual RECT get_Rect(); //��Ʈ ��ȯ(override)

	virtual ~PlayerBit(); //�Ҹ���
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

	//Ȯ�ο� �귯��
	HBRUSH efBrush;
	HBRUSH efoBrush;

public:
	EnemyFrontBit(); //������

	virtual void Bit_Init(HDC hBack, HWND hWnd, float _curx = 0); //BitMap�ʱ�ȭ(Override)
	virtual void Bit_Draw(HDC hBack, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap�׸���(Override)
	virtual void set_CurPos(int _curpos); //���� ĳ���� ��ġ �ޱ�(override)
	virtual RECT get_Rect(); //��Ʈ ��ȯ(override)

	virtual ~EnemyFrontBit(); //�Ҹ���
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
	EnemyBackBit(); //������

	virtual void Bit_Init(HDC hback, HWND hWnd, float _curx = 0); //BitMap�ʱ�ȭ(Override)
	virtual void Bit_Draw(HDC hback, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap�׸���(Override)
	virtual void set_CurPos(int _curpos); //���� ĳ���� ��ġ �ޱ�(override)
	virtual RECT get_Rect(); //��Ʈ ��ȯ(override)

	virtual ~EnemyBackBit(); //�Ҹ���
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

	//Ȯ�ο� �귯��
	HBRUSH fireBrush;
	HBRUSH ofireBrush;

	RECT Fire_Rect;

public:
	EnemyFireBit(); //������

	virtual void Bit_Init(HDC hback, HWND hWnd, float _curx = 0); //BitMap�ʱ�ȭ(Override)
	virtual void Bit_Draw(HDC hback, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap�׸���(Override)
	virtual void set_CurPos(int _curpos); //���� ĳ���� ��ġ �ޱ�(override)
	virtual RECT get_Rect(); //��Ʈ ��ȯ(override)

	~EnemyFireBit(); //�Ҹ���

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

	//Ȯ�ο� �귯��
	HBRUSH goalBrush;
	HBRUSH ogoalBrush;

	HFONT Score, oldScore;

	RECT GoalRect;
public:
	ObjectBit(); //������

	virtual void Bit_Init(HDC hback, HWND hWnd, float _curx = 0); //BitMap�ʱ�ȭ(Override)
	virtual void Bit_Draw(HDC hback, float _curx = 0, float _cury = 0, float _dftime = 0); //BitMap�׸���(Override)
	virtual void set_CurPos(int _curpos); //���� ĳ���� ��ġ �ޱ�(override)
	virtual RECT get_Rect(); //��Ʈ ��ȯ(override)

	~ObjectBit(); //�Ҹ���
};