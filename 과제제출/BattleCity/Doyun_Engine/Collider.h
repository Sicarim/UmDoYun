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
		//�׸��� �׸� �귯��
		HPEN m_Collider;
		HPEN m_oldCollider;

		HBRUSH brush_Collider;
		HBRUSH brush_oldCollider;
	public:
		Collider(); //������

		void Init_Collider(string _tag, int _left, int _top, int _right, int _bottom); //�ݶ��̴� ���� ����
		void Draw_Collider(int _left, int _top, int _right, int _bottom); //�ݶ��̴� ���� �׸���
		RECT get_Collider(); //�ݶ��̴� ���� ����
		bool isCollider(string _tag); //�ݶ��̴��� �浹 ���� �׸���

		~Collider(); //�Ҹ���
	};
}