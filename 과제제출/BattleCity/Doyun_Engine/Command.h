#pragma once
#include "GlobalDefine.h"
#include "Object.h"

namespace DoEngine
{
	/*
		(12/16 추가)
		Command Pattern, 어떤 개념을 변수에 저장하거나 함수에 전달할 수 있도록 데이터, 즉 객체로 바꿀수 있단걸 의미한다.
		여기서 명령 패턴을 '매서드 호출을 실체화 한것'이라고 한것은 함수 호출을 객체로 감쌋다는것을 의미한다.
		-명령을 객체의 형태로 캡슐화-
	*/
	
	class Command
	{
	protected:
		
	public:
		Command(); //생성자

		virtual void excute(Object& _actor) = 0; //행동을 실행하는 함수

		virtual ~Command(); //소멸자
	};
}