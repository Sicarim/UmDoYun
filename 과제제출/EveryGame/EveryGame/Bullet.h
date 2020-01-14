#pragma once
#include "DoEngine.h"
#include "defines.h"

class Bullet : public DoEngine::Object
{
private:
	float pos_x, pos_y;
	int size_x, size_y;
	float curTime;
	int Random, Birth_dir;
	int BirthCount;
	int Birth_Add;
	bool isDestroy;
	string m_tag;
	TCHAR buf[255];

	DoEngine::Collider m_Coll;
	DoEngine::BitMap* Bullet_Bit;
public:
	Bullet(); //생성자

	virtual void Init(int _x = 0, int _y = 0); //초기화(시작 위치 초기화 가능)(override)
	virtual bool Input(int _state = 0); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(); //Draw 함수(overloding)(override)
	virtual void Draw(int _x, int _y); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)
	void set_Birth(int _num); //생성순서

	virtual ~Bullet(); //소멸자
};