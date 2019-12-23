#pragma once
#include "GlobalDefine.h"
#include "POINT.h"

namespace DoEngine
{
	/**
	* @brief �浹�� �����ϴ� Collider
	* @details �浹�� �����Ѵ�. Collider��ü�� ����� ���ÿ� �ʱ�ȭ�� �ϰ� �Ǹ� ColliderManager�� Collider�� ��ϵȴ�. ���� �ݵ�� �±� ������ �ʼ�
	*/

	class Collider
	{
	private:
		RECT m_Rect;
		string m_Tag;
		int m_left, m_top, m_right, m_bottom;

		//�׸��� �׸� �귯��
		HPEN m_Collider;
		HPEN m_oldCollider;

		HBRUSH brush_Collider;
		HBRUSH brush_oldCollider;

	public:
		Collider(); //������

		void Init_Collider(string _tag, int _left, int _top, int _right, int _bottom); //�ݶ��̴� ���� ����
		void Draw_Collider(); //�ݶ��̴� ���� �׸���
		RECT get_Collider(); //�ݶ��̴� ���� ����
		bool isCollider(string _tag); //�ݶ��̴��� �浹 ���� �׸���

		~Collider(); //�Ҹ���
	};
}