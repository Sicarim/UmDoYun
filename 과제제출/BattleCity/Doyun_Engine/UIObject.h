#pragma once
#include "POINT.h"

namespace DoEngine
{
	class UIObject
	{
	protected:
		DoEngine::RECT m_rcPos;

		void set_Pos(int _left, int _top, int _right, int _bottom); //������Ʈ ��ġ �Է�
	public:
		UIObject(); //������

		virtual void Draw() = 0; //�׸��� �Լ�
		virtual bool Update() = 0; //Update �Լ�

		virtual ~UIObject(); //�Ҹ���
	};
}

