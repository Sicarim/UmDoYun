#pragma once
#include "DoEngine.h"
#include "defines.h"

/*
	FlightGame에서 사용하는 BlueStar
*/

class BlueStar : public DoEngine::Object
{
private:
	int size_x, size_y;
	int Fever;
	int Random, Birth_dir;
	float curTime;
	float pos_x, pos_y;
	string m_tag;

	bool isDestroy;

	DoEngine::Collider m_Coll;
	DoEngine::BitMap* BlueStar_Bit;
	
public:
	BlueStar(); //생성자

	virtual void Init(int _x = 0, int _y = 0); //초기화(시작 위치 초기화 가능)(override)
	virtual bool Input(int _state = 0); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(); //Draw 함수(overloding)(override)
	virtual void Draw(int _x, int _y); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	virtual ~BlueStar(); //소멸자
};