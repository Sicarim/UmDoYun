#pragma once
#include "State.h"

namespace DoEngine
{
	//��� ����
	class Standing : public State
	{
	private:
	public:
		Standing(); //������

		virtual void Enter(); //���� ���·� ��ȯ(override)
		virtual void Excute(); //���� ��Ȳ���� �� �ൿ(override)
		virtual void Exit(); //���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)

		virtual ~Standing(); //�Ҹ���
	};
}