#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

/*
	GameSelect 화면 등록
*/
class SelectScene : public DoEngine::Scene
{
private:
	bool isClick, isCard, isFlight;
	float curTime, sumTime;
	DoEngine::BitMap* Select_Bit; //게임선택 비트맵
	std::function<bool()> clickEvent;
public:
	SelectScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(overrride)
	virtual bool Input(float _fETime); //키입력(overrride)
	virtual void Update(float _fETime); //Update함수(overrride)
	virtual void Draw(HDC hdc); //Draw 함수(overrride)
	virtual void Release(); //Release() 함수(overrride)
	bool OnCardClick(); //카드게임
	bool OnFlightClick(); //비행기 게임

	virtual ~SelectScene(); //소멸자
};