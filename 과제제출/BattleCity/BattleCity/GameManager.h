#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "Enemy.h"
#include "Player.h"

class GameManager : public Singleton<GameManager>
{
private:
	vector<DoEngine::Object*> tmp_vEnemy; //�� vector
	DoEngine::Object* tmp_Player; //Player Object

public:
	GameManager(); //������

	void Init(); //�ʱ�ȭ
	void Key_Init(); //Ű ���
	void Regist_Scene(); //�� ���
	vector<DoEngine::Object*> Make_Enemy(); //���� �����
	DoEngine::Object* Make_Player(); //�÷��̾� �����

	~GameManager(); //�Ҹ���
};