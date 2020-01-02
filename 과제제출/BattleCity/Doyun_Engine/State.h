#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	/**
	(01/02)
	* @brief 상태 패턴
	* @details 상태를 정의하여 각각의 행동에 맞는 행동을 하도록 한다.
	*/

	class State
	{
	private:

	public:
		State(); //생성자

		virtual void Enter() = 0; //다음 상태로 전환
		virtual void Excute() = 0; //현재 상황에서 할 행동
		virtual void Exit() = 0; //다음 상황으로 넘어가기전 해야하는 행동

		virtual ~State(); //소멸자
	};
}