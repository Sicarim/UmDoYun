#pragma once
#include "State.h"

namespace DoEngine
{
	class Move : public State
	{
	private:
	public:
		Move(); //생성자

		virtual void Enter(); //다음 상태로 전환(override)
		virtual void Excute(); //현재 상황에서 할 행동(override)
		virtual void Exit(); //다음 상황으로 넘어가기전 해야하는 행동(override)

		virtual ~Move(); //소멸자
	};
}