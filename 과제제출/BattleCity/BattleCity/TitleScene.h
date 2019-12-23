#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"
#include "Tank.h"
#include "Player.h"
#include "Map.h"

class TitleScene : public DoEngine::Scene
{
private:
	DoEngine::BitMap* m_BlackBG; //아무것도 없는 검은 배경화면
	vector<DoEngine::Object*> m_vEnemy; //몬스터 저장
	Player m_pPlayer; //플레이어 객체 선언

	DoEngine::Command* m_Command;
	InputHandler m_Input;

	Map m_Map;
public:
	TitleScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(override)
	virtual bool Input(float _fETime); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(HDC hdc); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	~TitleScene(); //소멸자
};