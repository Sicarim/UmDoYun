#pragma once
#include "GlobalDefine.h"
#include "POINT.h"

namespace DoEngine
{
	/**
	* @brief 충돌을 감당하는 Collider
	* @details 충돌을 감지한다. Collider객체를 선언과 동시에 초기화를 하게 되면 ColliderManager에 Collider가 등록된다. 사용시 반드시 태그 지정이 필수
	*/

	class Collider
	{
	private:
		RECT m_Rect;
		RECT tmp_Rect;
		string m_Tag;
		int HitState;
		bool isHitCheck, isBeforeHit, isDelete;
		int m_left, m_top, m_right, m_bottom;

		//그림을 그릴 브러쉬
		HPEN m_Collider;
		HPEN m_oldCollider;

		HBRUSH brush_Collider;
		HBRUSH brush_oldCollider;

	public:
		Collider(); //생성자

		void Init_Collider(string _tag, int _left, int _top, int _right, int _bottom); //콜라이더 범위 지정
		void Draw_Collider(); //콜라이더 범위 그리기
		RECT get_Collider(string _tag); //콜라이더 범위 리턴

		bool isCollider(string _tag); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollider(vector<string> _tags); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollider(string _tag, int _state); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollider(vector<string> _tags, int _state); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		void DeleteCollider(); //콜라이더 삭제하기

		bool isInCollider(string _tag); //콜라이더에 충돌 여부 그리기(안에서 나가지 못하게 할때)

		~Collider(); //소멸자
	};
}