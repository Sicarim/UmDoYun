#pragma once
#include "GlobalDefine.h"
#include "Action.h"
#include "DoEngine.h"
#include "defines.h"

/*
	FlightGame�� ����
*/
class FlightInput
{
private:
	/*
		FlightInput�� FlightGame�� ���Ǵ� Ű�Է��� �޴� Class�̴�
		�Ʒ� ������ �������� FlightGame�� ���Ǵ� Ű�� ���� ���Ǹ� ��Ÿ����.
		DoEngine�� Command�� ����ϸ�, ���ӿ� ���Ǵ� Ű���� ����Ͽ� ����Ѵ�.
	*/
	DoEngine::Command* key_Left; //���� Ŭ��
	DoEngine::Command* key_Right; //������ Ŭ��
	DoEngine::Command* key_Up; //���� Ŭ��
	DoEngine::Command* key_Down; //�Ʒ��� Ŭ��
public:
	FlightInput();//������

	DoEngine::Command* CommandInput(); //����� ������ �޼����

	~FlightInput();//�Ҹ���
};
