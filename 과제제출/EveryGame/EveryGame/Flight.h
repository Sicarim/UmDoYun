#pragma once
#include "DoEngine.h"
#include "defines.h"

class Flight : public DoEngine::Object
{
private:
	int pos_x, pos_y;
	int size_x, size_y;
	string m_Tag;
	float curTime, sumTime;
	bool isDestroy;
	TCHAR buf[255];

	DoEngine::Collider m_Coll;
	vector<string> m_vColl;
	DoEngine::BitMap* Flight_Bit; //비행기 그릴 BItMap 객체
	DoEngine::BitMap* Flight_Boom[3]; //비행기 폭팔
public:
	Flight(); //생성자

	virtual void Init(int _x = 0, int _y = 0); //초기화(시작 위치 초기화 가능)(override)
	virtual bool Input(int _state = 0); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(); //Draw 함수(overloding)(override)
	virtual void Draw(int _x, int _y); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	virtual ~Flight(); //소멸자
};