#include "Collider.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"

namespace DoEngine
{
	//������
	Collider::Collider()
	{
		
	}

	//�ݶ��̴� ���� ����
	void Collider::Init_Collider(string _tag, int _left, int _top, int _right, int _bottom)
	{
		m_Tag = _tag;
		m_Rect.Set(_left, _top, _left + _right, _top + _bottom);
		//ColliderManager�� �ݶ��̴� ���
		DoEngine::ColliderManager::get_Instance()->Insert_Collider(m_Tag, m_Rect.get_Rect());

		m_left = _left;
		m_top = _top;
		m_right = _left + _right;
		m_bottom = _top + _bottom;
	}

	//�ݶ��̴� ���� �׸���
	void Collider::Draw_Collider()
	{
		//�ʷϻ����� �׸���
		m_Collider = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		m_oldCollider = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collider);

		//�����ϰ� �׸���
		brush_Collider = (HBRUSH)GetStockObject(NULL_BRUSH);
		brush_oldCollider = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collider);

		Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_left, m_top, m_right, m_bottom);

		DeleteObject(m_oldCollider);
		DeleteObject(brush_oldCollider);
	}

	//�ݶ��̴��� �浹 ���� �׸���
	bool Collider::isCollider(string _tag)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);

		return m_Rect.isCollision(tmp_rc);
	}

	//�ݶ��̴� ���� ����
	RECT Collider::get_Collider()
	{
		return m_Rect.get_Rect();
	}

	//�Ҹ���
	Collider::~Collider()
	{

	}
}