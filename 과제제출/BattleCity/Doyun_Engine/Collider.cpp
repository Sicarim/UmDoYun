#include "Collider.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"

namespace DoEngine
{
	//생성자
	Collider::Collider()
	{
		
	}

	//콜라이더 범위 지정
	void Collider::Init_Collider(string _tag, int _left, int _top, int _right, int _bottom)
	{
		m_Tag = _tag;
		m_Rect.Set(_left, _top, _left + _right, _top + _bottom);
		//ColliderManager에 콜라이더 등록
		DoEngine::ColliderManager::get_Instance()->Insert_Collider(m_Tag, m_Rect.get_Rect());

		m_left = _left;
		m_top = _top;
		m_right = _left + _right;
		m_bottom = _top + _bottom;
	}

	//콜라이더 범위 그리기
	void Collider::Draw_Collider()
	{
		//초록색으로 그리기
		m_Collider = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		m_oldCollider = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collider);

		//투명하게 그리기
		brush_Collider = (HBRUSH)GetStockObject(NULL_BRUSH);
		brush_oldCollider = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collider);

		Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_left, m_top, m_right, m_bottom);

		DeleteObject(m_oldCollider);
		DeleteObject(brush_oldCollider);
	}

	//콜라이더에 충돌 여부 그리기
	bool Collider::isCollider(string _tag)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);

		return m_Rect.isCollision(tmp_rc);
	}

	//콜라이더 범위 리턴
	RECT Collider::get_Collider()
	{
		return m_Rect.get_Rect();
	}

	//소멸자
	Collider::~Collider()
	{

	}
}