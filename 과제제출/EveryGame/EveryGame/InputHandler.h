#pragma once
#include "GlobalDefine.h"
#include "Action.h"
#include "DoEngine.h"
#include "defines.h"

/*
 CardGame�� ����
*/
class InputHandler
{
private:
	/*
		InputHandler�� CardGame�� ���Ǵ� Ű�Է��� �޴� Class�̴�
		�Ʒ� ������ �������� CardGame�� ���Ǵ� Ű�� ���� ���Ǹ� ��Ÿ����. 
		DoEngine�� Command�� ����ϸ�, ���ӿ� ���Ǵ� Ű���� ����Ͽ� ����Ѵ�.
	*/
	DoEngine::Command* key_Left; //���� Ŭ��
	DoEngine::Command* key_Right; //������ Ŭ��
	DoEngine::Command* key_Up; //���� Ŭ��
	DoEngine::Command* key_Down; //�Ʒ��� Ŭ��
public:
	InputHandler();//������

	DoEngine::Command* CommandInput(); //����� ������ �޼����

	~InputHandler();//�Ҹ���
};
