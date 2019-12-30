#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"

class BushWall : public DoEngine::Object
{
private:
	string m_tag;
public:
	BushWall(); //생성자

	void Init(int _x = 0, int _y = 0); //초기화(override)
	bool Input(int _state); //키입력(override)
	void Update(float _fETime); //Update함수(override)
	void Draw(); //Draw 함수(override)
	void Draw(int _x, int _y); //Draw 함수(override)
	void Release(); //Release() 함수(override)
	void set_tag(string _tag); //태그 저장 

	~BushWall(); //소멸자
};