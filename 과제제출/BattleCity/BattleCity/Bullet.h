#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"

//총알 클래스 - DoEngine::Object class 를 상속 받는다.

class Bullet : public DoEngine::Object
{
private:
	DoEngine::BitMap* m_BulletBit;
	DoEngine::Collider m_Coll; 

	float pos_x;
	float pos_y;
	float curTime;
	float Fire_Time;
	bool is_Save;
	int Bullet_dir; //총알을 발사하는 방향
public:
	Bullet(); //생성자

	virtual void Init(int _x = 0, int _y = 0); //초기화(override)
	virtual bool Input(int _state); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(); //Draw 함수(override)
	virtual void Draw(int _x, int _y); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	bool get_FireSave(); //탄알 세이브 여부
	void set_BulletDir(int _dir); //총알 방향 지정

	~Bullet(); //소멸자
};