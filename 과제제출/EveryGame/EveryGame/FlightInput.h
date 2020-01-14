#pragma once
#include "GlobalDefine.h"
#include "Action.h"
#include "DoEngine.h"
#include "defines.h"

class FlightInput
{
private:
	DoEngine::Command* key_Left; //���� Ŭ��
	DoEngine::Command* key_Right; //������ Ŭ��
	DoEngine::Command* key_Up; //���� Ŭ��
	DoEngine::Command* key_Down; //�Ʒ��� Ŭ��
public:
	FlightInput();//������

	DoEngine::Command* CommandInput(); //����� ������ �޼����

	~FlightInput();//�Ҹ���
};
