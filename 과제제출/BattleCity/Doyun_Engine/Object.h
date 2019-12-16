#pragma once
#include "GlobalDefine.h"

namespace DoEngine
{
	/*
	* @brief 게임에 사용되는 UnitObject들의 부모 클래스
	* @details 게임에 사용되는 Unit들의 부모 클래스(중요!!!).Scene구현해야 하는 항목을 순수 가상 함수로 가지고
		있음
	*/
	class Object
	{
	protected:
		string m_sTag; //태그(Key, 유닛 구별 등등에 사용)
		string m_sName; //이름
		vector<string> vec_Trait; //특성저장
	public:
		Object(); //생성자

		virtual void Init() = 0; //초기화
		virtual bool Input(float _fETime) = 0; //키입력
		virtual void Update(float _fETime) = 0; //Update함수
		virtual void Draw() = 0; //Draw 함수(overloding)
		virtual void Draw(int _x, int _y) = 0; //Draw 함수
		virtual void Release() = 0; //Release() 함수

		void set_Info(string _tag, string _name);//태그와 이름 입력
		string get_Name();//태그와 이름 입력
		string get_Tag();//태그와 이름 입력

		virtual ~Object(); //소멸자
	};
}