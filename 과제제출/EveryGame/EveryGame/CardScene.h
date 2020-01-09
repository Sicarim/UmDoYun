#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"
#include "CardGame.h"

class CardScene : public DoEngine::Scene
{
private:
	int MoveTimeOver;
	float curTime;
	bool isEnd;
	DoEngine::BitMap* Card_Bit; //ī�� ��Ʈ��
	DoEngine::BitMap* TimeOver_Bit; //Ÿ�� ���� ��Ʈ��
	CardGame m_Game;

public:
	CardScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(overrride)
	virtual bool Input(float _fETime); //Ű�Է�(overrride)
	virtual void Update(float _fETime); //Update�Լ�(overrride)
	virtual void Draw(HDC hdc); //Draw �Լ�(overrride)
	virtual void Release(); //Release() �Լ�(overrride)

	virtual ~CardScene(); //�Ҹ���
};