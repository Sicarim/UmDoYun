#include "Collider.h"
#include "ResourcesManager.h"

namespace DoEngine
{
	//생성자
	Collider::Collider()
	{

	}

	//콜라이더 범위 그리기
	void Collider::Draw_Collider(int _left, int _top, int _right, int _bottom)
	{
		//초록색으로 그리기
		m_Collider = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		m_oldCollider = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collider);

		//투명하게 그리기
		brush_Collider = (HBRUSH)GetStockObject(NULL_BRUSH);
		brush_oldCollider = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collider);

		Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), _left, _top, _left + _right, _top + _bottom);
	}

	//콜라이더에 충돌 여부 그리기
	bool Collider::isCollider(RECT _rcOther)
	{
		return m_Rect.isCollision(_rcOther);
	}

	//소멸자
	Collider::~Collider()
	{

	}
}