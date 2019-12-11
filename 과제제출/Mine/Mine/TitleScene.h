#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h" //디파인을 모아놈

/*
* @brief 게임 시작화면(제목)
* @details 게임에 들어가는 기초적인 초기화(키 등록, 키 명령어)등을 실행한다
*/

//엔진의 Scene을 상속 받는 TitleScene
class TitleScene : public DoEngine::Scene
{
private:
	DoEngine::BitMap* m_pBack; //BackDC 비트맵 등록

	float m_fTitleX; //타이틀 크기(x)
	float m_fTitleY; //타이틀 크기(y)

	std::function<bool()> clickEvent; //클릭 이벤트

public:
	TitleScene(); //생성자

	virtual void Init(HWND hWnd); //초기화 함수(override)
	virtual bool Input(float _fETime); //각 키에 맞는 명령어 입력(override)
	virtual void Update(float _fETime); //Update 함수(override)
	virtual void Draw(HDC hdc); //그리기 함수(override)
	virtual void Release(); //삭제 함수. DC나 BitMap이 아닌 변수 값등을 원래대로 돌리거나 삭제하는 함수(주의할것....)(overrride)
	bool OnClick(); //클릭하면 true를 리턴(override)

	virtual ~TitleScene(); //소멸자
};

