#include "Action.h"

namespace DoEngine
{
	//왼쪽으로 이동하기
	void LeftCommand::excute(Object& _actor)
	{
		_actor.Input(LEFT);
	}

	//오른쪽으로 이동하기
	void RightCommand::excute(Object& _actor)
	{
		_actor.Input(RIGHT);
	}

	//위로 이동하기
	void UpCommand::excute(Object& _actor)
	{
		_actor.Input(UP);
	}

	//아래로 이동하기
	void DownCommand::excute(Object& _actor)
	{
		_actor.Input(DOWN);
	}

	//점프하기
	void JumpCommand::excute(Object& _actor)
	{

	}

	//공격하기
	void AttackCommand::excute(Object& _actor)
	{
		_actor.Input(ATTACK);
	}
}
