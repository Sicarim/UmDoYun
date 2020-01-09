#pragma once
#pragma once
#include "GlobalDefine.h"
#include "POINT.h"

namespace DoEngine
{
	/**
	* @brief Trigger를 감지하는 Collider
	* @details Trigger를 감지한다. Collider객체를 선언과 동시에 초기화를 하게 되면 ColliderManager에 Collider가 등록된다. 사용시 반드시 태그 지정이 필수
	*/

	class TriggerCollider
	{
	private:
		TCHAR buf[255];
		RECT m_Rect;
		RECT tmp_Rect;
		string m_Tag;
		int HitState;
		int Hit_dir;
		bool isHitCheck, isBeforeHit, isDelete;
		int m_left, m_top, m_right, m_bottom;

		//그림을 그릴 브러쉬
		HPEN m_Collider;
		HPEN m_oldCollider;

		HBRUSH brush_Collider;
		HBRUSH brush_oldCollider;

	public:
		TriggerCollider(); //생성자

		void Init_Collider(string _tag, int _left, int _top, int _right, int _bottom, int _leftsize, int _topsize); //콜라이더 범위 지정
		bool Draw_Collider(string _tag); //콜라이더 범위 그리기
		RECT get_Collider(string _tag); //콜라이더 범위 리턴

		int isCollider(string _tag); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollider(vector<string> _tags); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollider(string _tag, int _state); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		bool isCollider(vector<string> _tags, int _state); //콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
		int HitDir_Check(RECT _rc); //어느 방향에서 출동했는가??
		void DeleteCollider(); //콜라이더 삭제하기

		bool isInCollider(string _tag); //콜라이더에 충돌 여부 그리기(안에서 나가지 못하게 할때)

		int get_HitDir(); //충돌 방향 리턴

		~TriggerCollider(); //소멸자
	};
}