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

	DoEngine::BitMap* m_BlackBG; //�ƹ��͵� ���� ���� ���ȭ��
public:
	StageScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(override)
	virtual bool Input(float _fETime); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(HDC hdc); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	~StageScene(); //�Ҹ���
};