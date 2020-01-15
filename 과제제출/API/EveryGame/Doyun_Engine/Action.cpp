#include "Action.h"

namespace DoEngine
{
	//�������� �̵��ϱ�
	void LeftCommand::excute(Object& _actor)
	{
		_actor.Input(LEFT);
	}

	//���������� �̵��ϱ�
	void RightCommand::excute(Object& _actor)
	{
		_actor.Input(RIGHT);
	}

	//���� �̵��ϱ�
	void UpCommand::excute(Object& _actor)
	{
		_actor.Input(UP);
	}

	//�Ʒ��� �̵��ϱ�
	void DownCommand::excute(Object& _actor)
	{
		_actor.Input(DOWN);
	}

	//�����ϱ�
	void JumpCommand::excute(Object& _actor)
	{

	}

	//�����ϱ�
	void AttackCommand::excute(Object& _actor)
	{
		_actor.Input(ATTACK);
	}
}
