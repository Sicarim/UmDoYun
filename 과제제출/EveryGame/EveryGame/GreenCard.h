#pragma once
#include "DoEngine.h"
#include "defines.h"

class GreenCard : public DoEngine::Object
{
private:
	DoEngine::BitMap* m_GreenCard; //퍼런 카드
	int pos_x, pos_y;
	int size_x, size_y;
	int isAnswer;
	float curTime;
	bool isBefore;
	int vibe;

	bool isBonus;
	DoEngine::BitMap* m_Bonus;

public:
	GreenCard();

	virtual void Init(int _x = 0, int _y = 0); //초기화(시작 위치 초기화 가능)(override)
	virtual bool Input(int _state); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(); //Draw 함수(overloding)(override)
	virtual void Draw(int _x, int _y); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	virtual ~GreenCard();
};