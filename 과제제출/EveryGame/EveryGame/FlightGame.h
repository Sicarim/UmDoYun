#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "FlightInput.h"
#include "Text.h"
#include "Flight.h"
#include "Bullet.h"
#include "BlueStar.h"
#include "GreenStar.h"
#include "YellowStar.h"
#include "StarPool.h"
#include "BulletPool.h"

class FlightGame
{
private:
	int Flight_Count;
	float curTime;
	TCHAR Flight_Score[255];

	DoEngine::Text m_Text;
	Flight m_Flight; //비행기 객체
	Bullet m_Bullet; //총알 객체
	DoEngine::Collider m_BackGroundColl; //배경 콜라이더
	//Star
	StarPool m_StarPool;
	//Bullet
	BulletPool m_BulletPool;

	//비행기를 움직일 커맨드 객체 선언
	DoEngine::Command* m_Command;
	FlightInput m_Input;
public:
	FlightGame(); //생성자

	void Init(); //게임 초기화
	bool Input(float _fETime); //키 입력
	void Update(float _fETime); //Update함수
	void Draw(); //게임 그리기
	void Release(); //삭제 함수

	~FlightGame(); //소멸자
};