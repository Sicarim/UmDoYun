#pragma once
#include "GlobalDefine.h"
#include "Action.h"
#include "DoEngine.h"
#include "defines.h"


class InputHandler
{
private:
	DoEngine::Command* key_Left; //왼쪽 클릭
	DoEngine::Command* key_Right; //오른쪽 클릭
	DoEngine::Command* key_Up; //위쪽 클릭
	DoEngine::Command* key_Down; //아래쪽 클릭
	DoEngine::Command* Key_Attack; //공격 클릭
public:
	InputHandler();//생성자

	DoEngine::Command* CommandInput(); //명령을 실행할 메서드들

	~InputHandler();//소멸자
};
