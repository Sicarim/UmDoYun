#pragma once
#include "GlobalDefine.h"
#include "ResourcesManager.h"

namespace DoEngine
{
	/*
	* @brief 게임에 사용되는 UnitObject들의 부모 클래스
	* @details 게임에 사용되는 Unit들의 부모 클래스(중요!!!).구현해야 하는 항목을 순수 가상 함수로 가지고
		있음 - 정말 필요한 메서드들만 모아두었다. 나머진 Composition해서 사용하기 바란다. - 컴포넌트 패턴을 잘 활용하라.
	*/
	class Object
	{
	protected:
		string m_sTag; //태그(Key, 유닛 구별 등등에 사용)
		string m_sName; //이름
		vector<string> vec_Trait; //특성저장
	public:
		Object(); //생성자

		virtual void Init(int _x = 0, int _y = 0) = 0; //초기화(시작 위치 초기화 가능)
		virtual bool Input(int _state) = 0; //키입력
		virtual void Update(float _fETime) = 0; //Update함수
		virtual void Draw() = 0; //Draw 함수(overloding)
		virtual void Draw(int _x, int _y) = 0; //Draw 함수
		virtual void Release() = 0; //Release() 함수

		virtual void set_Info(string _tag);//태그와 이름 입력
		string get_Name();//태그와 이름 입력
		string get_Tag();//태그와 이름 입력

		virtual ~Object(); //소멸자
	};
}