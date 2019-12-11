#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "POINT.h"

class EndScene : public DoEngine::Scene
{
private:
	DoEngine::BitMap* m_pBackDC; //���ȭ�� ���

public:
	EndScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(override)
	virtual bool Input(float _fETime); //Ű �Է�(override)
	virtual void Update(float _fETime); //Update(override)
	virtual void Draw(HDC hdc); //Draw�Լ� (override)
	virtual void Release(); //Release�Լ� (override)

	~EndScene(); //�Ҹ���
};