#pragma once
#include "GlobalDefine.h"
#include "Action.h"
#include "DoEngine.h"
#include "defines.h"

/*
	FlightGame을 조작
*/
class FlightInput
{
private:
	/*
		FlightInput는 FlightGame에 사용되는 키입력을 받는 Class이다
		아래 선언한 변수들은 FlightGame에 사용되는 키에 대한 정의를 나타낸다.
		DoEngine의 Command를 사용하며, 게임에 사용되는 키들을 등록하여 사용한다.
	*/
	DoEngine::Command* key_Left; //왼쪽 클릭
	DoEngine::Command* key_Right; //오른쪽 클릭
	DoEngine::Command* key_Up; //위쪽 클릭
	DoEngine::Command* key_Down; //아래쪽 클릭
public:
	FlightInput();//생성자

	DoEngine::Command* CommandInput(); //명령을 실행할 메서드들

	~FlightInput();//소멸자
};
