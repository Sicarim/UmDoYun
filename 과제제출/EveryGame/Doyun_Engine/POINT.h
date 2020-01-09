#pragma once
#pragma once
#include <Windows.h>

namespace DoEngine
{
	/**
	* @brief 2���� int ��ǥ�� ǥ���ϴ� Ŭ����
	* @details 2���� int ��ǥ�� ǥ���ϴ� Ŭ����
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
	* @brief 2���� float ��ǥ�� ǥ���ϴ� Ŭ����
	* @details 2���� float ��ǥ�� ǥ���ϴ� Ŭ����
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
	* @brief RECT ��ǥ�� ǥ���ϴ� Ŭ����
	* @details RECT ��ǥ�� ǥ���ϴ� Ŭ����
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

		bool isOutCollision(RECT _rcOther); //�浹 ���� �˻�(�ۿ��� �ε�ġ���� �˻�, ���𰡰� �ε�ĥ��)
		bool isInCollision(RECT _rcOther); //�浹 ���� �˻�(�ȿ��� ������ �ε�ġ���� �˻�, ���𰡸� ���� ������ ������ ���ϰ�)
		bool isPtin(POINT _ptOther); //���콺 ����Ʈ�� �ȿ� �ִ°� �˻�
		RECT();
		RECT(int _left, int _top, int _right, int _bottom);
		~RECT();
	};
}

