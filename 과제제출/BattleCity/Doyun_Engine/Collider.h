#pragma once
#include "GlobalDefine.h"
#include "POINT.h"

namespace DoEngine
{
	class Collider
	{
	private:
		RECT m_Rect;
		//�׸��� �׸� �귯��
		HPEN m_Collider;
		HPEN m_oldCollider;

		HBRUSH brush_Collider;
		HBRUSH brush_oldCollider;
	public:
		Collider(); //������

		void set_Collider(int _left, int _top, int _right, int _bottom); //�ݶ��̴� ���� ����
		void Draw_Collider(int _left, int _top, int _right, int _bottom); //�ݶ��̴� ���� �׸���
		bool isCollider(RECT _rcOther); //�ݶ��̴��� �浹 ���� �׸���

		~Collider(); //�Ҹ���
	};
}