#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"

class StillWall : public DoEngine::Object
{
private:
	DoEngine::BitMap* m_pBlockBit; //TitleScene 배경회면 등록
	int m_wSize, m_hSize;
	int m_posx, m_posy;
	string m_tag;
	DoEngine::Collider m_Coll;

public:
	StillWall(); //생성자

	virtual void Init(int _x = 0, int _y = 0); //초기화(override)
	virtual bool Input(int _state); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(); //Draw 함수(override)
	virtual void Draw(int _x, int _y); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	void set_tag(string _tag); //태그 저장 

	~StillWall(); //소멸자
};
