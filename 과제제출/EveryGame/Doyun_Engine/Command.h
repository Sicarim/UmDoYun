#pragma once
#include "GlobalDefine.h"
#include "Object.h"

namespace DoEngine
{
	/*
		(12/16 �߰�)
		Command Pattern, � ������ ������ �����ϰų� �Լ��� ������ �� �ֵ��� ������, �� ��ü�� �ٲܼ� �ִܰ� �ǹ��Ѵ�.
		���⼭ ��� ������ '�ż��� ȣ���� ��üȭ �Ѱ�'�̶�� �Ѱ��� �Լ� ȣ���� ��ü�� �����ٴ°��� �ǹ��Ѵ�.
		-����� ��ü�� ���·� ĸ��ȭ-
	*/
	
	class Command
	{
	protected:
		
	public:
		Command(); //������

		virtual void excute(Object& _actor) = 0; //�ൿ�� �����ϴ� �Լ�

		virtual ~Command(); //�Ҹ���
	};
}