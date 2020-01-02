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
	TCHAR buf[255];
	TCHAR buf2[255];

	TCHAR buf3[255];
	TCHAR buf4[255];



	DoEngine::BitMap* m_BlackBG; //�ƹ��͵� ���� ���� ���ȭ��
	//vector<DoEngine::Object*> m_vEnemy; //���� ����
	Player m_pPlayer; //�÷��̾� ��ü ����

	//�÷��̾ ������ Ŀ�ǵ� ��ü ����
	DoEngine::Command* m_Command;
	InputHandler m_Input;

	Map m_Map;

public:
	TitleScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(override)
	virtual bool Input(float _fETime); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(HDC hdc); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	~TitleScene(); //�Ҹ���
};