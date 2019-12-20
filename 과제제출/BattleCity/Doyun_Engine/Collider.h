#pragma once
#include "GlobalDefine.h"
#include "POINT.h"

namespace DoEngine
{
	class Collider
	{
	private:
		RECT m_Rect;
		string m_Tag;
		//그림을 그릴 브러쉬
		HPEN m_Collider;
		HPEN m_oldCollider;

		HBRUSH brush_Collider;
		HBRUSH brush_oldCollider;
	public:
		Collider(); //생성자

		void Init_Collider(string _tag, int _left, int _top, int _right, int _bottom); //콜라이더 범위 지정
		void Draw_Collider(int _left, int _top, int _right, int _bottom); //콜라이더 범위 그리기
		RECT get_Collider(); //콜라이더 범위 리턴
		bool isCollider(string _tag); //콜라이더에 충돌 여부 그리기

		~Collider(); //소멸자
	};
}