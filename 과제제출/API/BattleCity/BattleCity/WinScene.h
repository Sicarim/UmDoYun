#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

class WinScene : public DoEngine::Scene
{
private:
	int Tank_Score, UpTank_Score;
	int curStage;
	float curTime;
	int Select_Count;
	TCHAR buf[255];
	TCHAR cTank_S[255];
	TCHAR cTank[255];

	TCHAR cUpTank_S[255];
	TCHAR cUpTank[255];

	TCHAR Total_Score[255];

	DoEngine::BitMap* m_BlackBG; //아무것도 없는 검은 배경화면

	DoEngine::BitMap* Tank;
	DoEngine::BitMap* UpTank;
public:
	WinScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(override)
	virtual bool Input(float _fETime); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(HDC hdc); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	~WinScene(); //소멸자
};