#pragma once
#pragma once
#include <Windows.h>

namespace DoEngine
{
	/**
	* @brief 2차원 int 좌표를 표현하는 클레스
	* @details 2차원 int 좌표를 표현하는 클레스
	*/

	class POINT
	{
	public:
		int x;
		int y;

		POINT();
		POINT(int _x, int _y);
		~POINT();
	};

	/**
	* @brief 2차원 float 좌표를 표현하는 클레스
	* @details 2차원 float 좌표를 표현하는 클레스
	*/

	class POINTF
	{
	public:
		float x;
		float y;

		POINTF();
		POINTF(float _x, float _y);
		~POINTF();
	};

	/**
	* @brief RECT 좌표를 표현하는 클레스
	* @details RECT 좌표를 표현하는 클레스
	*/

	class RECT
	{
	public:
		int left;
		int top;
		int right;
		int bottom;

		inline void Set(int _left, int _top, int _right, int _bottom)
		{
			left = _left;
			top = _top;
			right = _right;
			bottom = _bottom;
		}

		inline ::RECT ToWinRECT()
		{
			::RECT rc = { left , top , right , bottom };
			return rc;
		}

		RECT get_Rect()
		{
			RECT rc = { left , top , right , bottom };
			return rc;
		}

		bool isOutCollision(RECT _rcOther); //충돌 여부 검사(밖에서 부딪치는지 검사, 무언가가 부딪칠때)
		bool isInCollision(RECT _rcOther); //충돌 여부 검사(안에서 밖으로 부딪치는지 검사, 무언가를 범위 밖으로 나가지 못하게)
		bool isPtin(POINT _ptOther); //마우스 포인트가 안에 있는가 검사
		RECT();
		RECT(int _left, int _top, int _right, int _bottom);
		~RECT();
	};
}

