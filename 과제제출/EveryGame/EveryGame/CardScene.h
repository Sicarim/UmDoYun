#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"
#include "CardGame.h"

class CardScene : public DoEngine::Scene
{
private:
	int MoveTimeOver;
	float curTime;
	bool isEnd;
	DoEngine::BitMap* Card_Bit; //카드 비트맵
	DoEngine::BitMap* TimeOver_Bit; //타임 오버 비트맵
	CardGame m_Game;

public:
	CardScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(overrride)
	virtual bool Input(float _fETime); //키입력(overrride)
	virtual void Update(float _fETime); //Update함수(overrride)
	virtual void Draw(HDC hdc); //Draw 함수(overrride)
	virtual void Release(); //Release() 함수(overrride)

	virtual ~CardScene(); //소멸자
};