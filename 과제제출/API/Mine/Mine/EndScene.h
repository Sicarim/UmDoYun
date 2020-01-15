#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "POINT.h"

class EndScene : public DoEngine::Scene
{
private:
	DoEngine::BitMap* m_pBackDC; //배경화면 등록

public:
	EndScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(override)
	virtual bool Input(float _fETime); //키 입력(override)
	virtual void Update(float _fETime); //Update(override)
	virtual void Draw(HDC hdc); //Draw함수 (override)
	virtual void Release(); //Release함수 (override)

	~EndScene(); //소멸자
};