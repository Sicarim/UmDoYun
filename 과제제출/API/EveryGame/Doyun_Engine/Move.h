#pragma once
#include "State.h"

namespace DoEngine
{
	class Move : public State
	{
	private:
	public:
		Move(); //������

		virtual void Enter(); //���� ���·� ��ȯ(override)
		virtual void Excute(); //���� ��Ȳ���� �� �ൿ(override)
		virtual void Exit(); //���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ(override)

		virtual ~Move(); //�Ҹ���
	};
}