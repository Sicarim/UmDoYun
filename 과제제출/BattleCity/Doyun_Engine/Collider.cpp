#include "Collider.h"
#include "ResourcesManager.h"

namespace DoEngine
{
	//������
	Collider::Collider()
	{

	}

	//�ݶ��̴� ���� �׸���
	void Collider::Draw_Collider(int _left, int _top, int _right, int _bottom)
	{
		//�ʷϻ����� �׸���
		m_Collider = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		m_oldCollider = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collider);

		//�����ϰ� �׸���
		brush_Collider = (HBRUSH)GetStockObject(NULL_BRUSH);
		brush_oldCollider = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collider);

		Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), _left, _top, _left + _right, _top + _bottom);
	}

	//�ݶ��̴��� �浹 ���� �׸���
	bool Collider::isCollider(RECT _rcOther)
	{
		return m_Rect.isCollision(_rcOther);
	}

	//�Ҹ���
	Collider::~Collider()
	{

	}
}