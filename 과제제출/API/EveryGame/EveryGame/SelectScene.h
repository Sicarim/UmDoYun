#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

/*
	GameSelect ȭ�� ���
*/
class SelectScene : public DoEngine::Scene
{
private:
	bool isClick, isCard, isFlight;
	float curTime, sumTime;
	DoEngine::BitMap* Select_Bit; //���Ӽ��� ��Ʈ��
	std::function<bool()> clickEvent;
public:
	SelectScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(overrride)
	virtual bool Input(float _fETime); //Ű�Է�(overrride)
	virtual void Update(float _fETime); //Update�Լ�(overrride)
	virtual void Draw(HDC hdc); //Draw �Լ�(overrride)
	virtual void Release(); //Release() �Լ�(overrride)
	bool OnCardClick(); //ī�����
	bool OnFlightClick(); //����� ����

	virtual ~SelectScene(); //�Ҹ���
};