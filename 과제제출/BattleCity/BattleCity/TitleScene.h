#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"
#include "Tank.h"

class TitleScene : public DoEngine::Scene
{
private:
	//TitleScene ���ȸ�� ���
	DoEngine::BitMap* m_pBack;
	//���� ����
	vector<DoEngine::Object*> m_vEnemy;
	DoEngine::Object* m_pPlayer;

public:
	TitleScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(override)
	virtual bool Input(float _fETime); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(HDC hdc); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	~TitleScene(); //�Ҹ���
};