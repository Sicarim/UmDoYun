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

	//�浹 ���� �˻�(�ۿ��� �ε�ġ���� �˻�, ���𰡰� �ε�ĥ��)
	bool RECT::isOutCollision(RECT _rcOther)
	{
		if (left <= _rcOther.right && top <= _rcOther.bottom && right >= _rcOther.left && bottom >= _rcOther.top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//�浹 ���� �˻�(�ȿ��� ������ �ε�ġ���� �˻�, ���𰡸� ���� ������ ������ ���ϰ�)
	bool RECT::isInCollision(RECT _rcOther)
	{
		if (right < _rcOther.right && bottom <= _rcOther.bottom && left > _rcOther.left && top > _rcOther.top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//���콺 ����Ʈ�� �ȿ� �ִ°� �˻�
	bool RECT::isPtin(POINT _ptOther)
	{
		if (left < _ptOther.x && right > _ptOther.x && top < _ptOther.y && bottom > _ptOther.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
