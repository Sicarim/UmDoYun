#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"
#include "Tank.h"
#include "Player.h"

class TitleScene : public DoEngine::Scene
{
private:
	//TitleScene 배경회면 등록
	DoEngine::BitMap* m_pBack;
	//몬스터 저장
	vector<DoEngine::Object*> m_vEnemy;
	//플레이어 객체 선언
	Player m_pPlayer;

	DoEngine::Command* m_Command;
	InputHandler m_Input;

public:
	TitleScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(override)
	virtual bool Input(float _fETime); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(HDC hdc); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	~TitleScene(); //소멸자
};