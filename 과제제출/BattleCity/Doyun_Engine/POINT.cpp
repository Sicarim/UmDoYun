#include "POINT.h"

namespace DoEngine
{
	POINT::POINT()
	{
		x = 0;
		y = 0;
	}

	POINT::POINT(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	POINT::~POINT()
	{

	}


	POINTF::POINTF()
	{
		x = 0;
		y = 0;
	}

	POINTF::POINTF(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	POINTF::~POINTF()
	{

	}

	RECT::RECT()
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}

	RECT::RECT(int _left, int _top, int _right, int _bottom)
	{
		left = _left;
		top = _top;
		right = _right;
		bottom = _bottom;
	}

	RECT::~RECT()
	{

	}

	//충돌 여부 검사
	bool RECT::isCollision(RECT _rcOther)
	{
		if (left < _rcOther.right && top <= _rcOther.bottom && right > _rcOther.left&& bottom > _rcOther.top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//마우스 포인트가 안에 있는가 검사
	bool RECT::isPtin(POINT _ptOther)
	{
		if (left < _ptOther.x && right > _ptOther.x&& top < _ptOther.y && bottom > _ptOther.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
