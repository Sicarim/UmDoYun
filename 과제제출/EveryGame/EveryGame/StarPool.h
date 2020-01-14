#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "BlueStar.h"
#include "GreenStar.h"
#include "YellowStar.h"

class StarPool
{
private:
	float curTime;
	DoEngine::Object* m_Star;

	list<DoEngine::Object*> m_vStandPool; //미리 만들어 논후, 대기
	vector<DoEngine::Object*> m_vStarPool; //실제 움직이는 vector
public:
	StarPool(); //생성자

	void Init(); //초기화
	bool Input(float _fETime); //입력 받기
	void Update(float _fETime); //Update
	void Draw(); //그리기
	void Release(); //삭제하기

	void get_Data(); //데이터 꺼내기
	void Return_Data(int _num); //데이터 다시 집어넣기

	~StarPool(); //소멸자
};