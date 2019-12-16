#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "Enemy.h"
#include "Player.h"

class GameManager : public Singleton<GameManager>
{
private:
	vector<DoEngine::Object*> tmp_vEnemy; //적 vector
	DoEngine::Object* tmp_Player; //Player Object

public:
	GameManager(); //생성자

	void Init(); //초기화
	void Key_Init(); //키 등록
	void Regist_Scene(); //씬 등록
	vector<DoEngine::Object*> Make_Enemy(); //몬스터 만들기
	DoEngine::Object* Make_Player(); //플레이어 만들기

	~GameManager(); //소멸자
};