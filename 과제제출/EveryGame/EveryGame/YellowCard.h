#pragma once
#include "DoEngine.h"
#include "defines.h"

class YellowCard : public DoEngine::Object
{
private:
	DoEngine::BitMap* m_YellowCard; //�۷� ī��
	int pos_x, pos_y;
	int size_x, size_y;
	int isAnswer;
	float curTime;
	bool isBefore;
	int vibe;
	
	bool isBonus;
	DoEngine::BitMap* m_Bonus;
public:
	YellowCard();

	virtual void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)(override)
	virtual bool Input(int _state); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(overloding)(override)
	virtual void Draw(int _x, int _y) ; //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	virtual ~YellowCard();
};