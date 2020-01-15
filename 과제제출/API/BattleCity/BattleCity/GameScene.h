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
	Health_pos Health[MAX_ENEMY];
	int Health_Count;
	int tmp_Count;
	bool GameStop; //���� ���� ����
	float curTime;

	DoEngine::BitMap* m_tmpBlock; //���� ����
	DoEngine::BitMap* m_EnemyHealth; //���� ����
	DoEngine::BitMap* m_BlackBG; //�ƹ��͵� ���� ���� ���ȭ��
	vector<DoEngine::BitMap*> m_vEnemyCount; //���� ���� ǥ��
	Player m_pPlayer; //�÷��̾� ��ü ����
	Map m_Map; //Map ����

	//�÷��̾ ������ Ŀ�ǵ� ��ü ����
	DoEngine::Command* m_Command;
	InputHandler m_Input;

public:
	GameScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(override)
	virtual bool Input(float _fETime); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(HDC hdc); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	~GameScene(); //�Ҹ���
};