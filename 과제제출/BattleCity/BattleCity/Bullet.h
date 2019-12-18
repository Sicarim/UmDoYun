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
public:
	Bullet(); //생성자

	virtual void Init(int _x = 0, int _y = 0); //초기화(override)
	virtual bool Input(int _state); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(); //Draw 함수(override)
	virtual void Draw(int _x, int _y); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	~Bullet(); //소멸자
};