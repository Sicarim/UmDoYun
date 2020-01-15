#pragma once
#include "POINT.h"

namespace DoEngine
{
	class UIObject
	{
	protected:
		DoEngine::RECT m_rcPos;

		void set_Pos(int _left, int _top, int _right, int _bottom); //오브젝트 위치 입력
	public:
		UIObject(); //생성자

		virtual void Draw() = 0; //그리기 함수
		virtual bool Update() = 0; //Update 함수

		virtual ~UIObject(); //소멸자
	};
}

