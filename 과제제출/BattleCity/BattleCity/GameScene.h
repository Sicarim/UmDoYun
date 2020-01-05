#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"
#include "Tank.h"
#include "Player.h"
#include "Map.h"

struct Health_pos
{
	int posx;
	int posy;
};

class GameScene : public DoEngine::Scene
{
private:
	TCHAR buf[255];
	TCHAR buf2[255];

	TCHAR buf3[255];
	TCHAR buf4[255];

	Health_pos Health[MAX_ENEMY];
	int Health_Count;
	int tmp_Count;

	DoEngine::BitMap* m_tmpBlock; //몬스터 갯수
	DoEngine::BitMap* m_EnemyHealth; //몬스터 갯수
	DoEngine::BitMap* m_BlackBG; //아무것도 없는 검은 배경화면
	vector<DoEngine::BitMap*> m_vEnemyCount; //몬스터 갯수 표시
	Player m_pPlayer; //플레이어 객체 선언
	Map m_Map; //Map 선언

	//플레이어를 움직일 커맨드 객체 선언
	DoEngine::Command* m_Command;
	InputHandler m_Input;

public:
	GameScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(override)
	virtual bool Input(float _fETime); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(HDC hdc); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	~GameScene(); //소멸자
};