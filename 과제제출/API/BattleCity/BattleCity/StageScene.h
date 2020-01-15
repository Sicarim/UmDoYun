#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

class StageScene : public DoEngine::Scene
{
private:
	TCHAR buf[255];
	float curTime;
	int curStage;

	DoEngine::BitMap* m_BlackBG; //아무것도 없는 검은 배경화면
public:
	StageScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(override)
	virtual bool Input(float _fETime); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(HDC hdc); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	~StageScene(); //소멸자
};