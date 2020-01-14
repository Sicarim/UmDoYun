#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"
#include "FlightGame.h"

class FlightScene : public DoEngine::Scene
{
private:
	int MoveTimeOver;
	float curTime;
	bool isEnd;

	FlightGame m_Game;
	DoEngine::BitMap* Flight_Bit; //비행기 비트맵
	DoEngine::BitMap* TimeOver_Bit; //타임 오버 비트맵
public:
	FlightScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(overrride)
	virtual bool Input(float _fETime); //키입력(overrride)
	virtual void Update(float _fETime); //Update함수(overrride)
	virtual void Draw(HDC hdc); //Draw 함수(overrride)
	virtual void Release(); //Release() 함수(overrride)

	virtual ~FlightScene(); //소멸자
};