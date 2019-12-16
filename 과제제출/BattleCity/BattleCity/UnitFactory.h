#pragma once
#include "GlobalDefine.h"
#include "defines.h"
#include "DoEngine.h"

/*
	패턴에서 가장 중요한 것중 하나는 캡슐화라는 개념으로 바뀌는 부분과 바뀌지 않는 부분을 분리하고, 바뀌는 부분을 묶어 두는것!
	어떤 클래스의 객체를 생성할지 미리 알지 못하는 경우 유용
*/
class UnitFactory
{
private:
	virtual void Create_Unit(string _name) = 0; //유닛 생성 생성은 private로
protected:
	DoEngine::Object* m_pUnit; //Unit 변수 선언
public:
	UnitFactory(); //생성자
	
	DoEngine::Object* Order_Unit(string _name); //입맛대로 만들기
	
	~UnitFactory(); //소멸자
};