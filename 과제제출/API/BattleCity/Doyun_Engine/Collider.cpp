#include "Collider.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"

namespace DoEngine
{
	//생성자
	Collider::Collider()
	{
		isHitCheck = false;
		isDelete = false;
	}

	//콜라이더 범위 지정 (태그, 좌표 = Left, Top, Right, Bottom)
	void Collider::Init_Collider(string _tag, int _left, int _top, int _right, int _bottom)
	{
		m_Tag = _tag;
		m_left = _left;
		m_top = _top;
		m_right = _left + _right;
		m_bottom = _top + _bottom;

		m_Rect.Set(m_left, m_top, m_right, m_bottom);
		m_Rect = { m_left, m_top, m_right, m_bottom };
		//ColliderManager에 콜라이더 등록
		DoEngine::ColliderManager::get_Instance()->Insert_Collider(m_Tag, m_Rect.get_Rect());
	}

	//콜라이더 범위 그리기
	void Collider::Draw_Collider()
	{
		if (ColliderManager::get_Instance()->get_DrawCollider())
		{
			if (!isDelete)
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
		}
	}

	//콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)
	bool Collider::isCollider(string _tag)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);

		return m_Rect.isOutCollision(tmp_rc);
	}

	//콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
	bool Collider::isCollider(vector<string> _tags)
	{
		RECT tmp_rc;

		for (int i = 0; i < _tags.size(); i++)
		{
			tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tags[i]);

			if (m_Rect.isOutCollision(tmp_rc))
			{
				return true;
			}
		}
		return false;
	}

	bool Collider::isCollider(string _tag, int _state)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);

		//충돌 체크 여부
		if (!m_Rect.isOutCollision(tmp_rc))
		{
			isHitCheck = false;
			return false;
		}

		else 
		{
			//최초로 부딛혓는가?
			if (!isHitCheck)
			{
				isHitCheck = true;
				HitState = _state;
			}

			//부딪친 방향과 가려고 하는 방향이 같은가?
			if (_state != HitState)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}

	bool Collider::isCollider(vector<string> _tags, int _state)
	{
		for (int i = 0; i < _tags.size(); i++)
		{
			RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tags[i]);

			if (m_Rect.isOutCollision(tmp_rc))
			{
				break;
			}

			if (i == _tags.size() - 1)
			{
				isHitCheck = false;
				isBeforeHit = false;
				return false;
			}
		}

		for (int i = 0; i < _tags.size(); i++)
		{
			RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tags[i]);

			//충돌 체크 여부
			if (!m_Rect.isOutCollision(tmp_rc) && !isHitCheck)
			{
				isHitCheck = false;
				isBeforeHit = false;
			}

			else
			{
				//최초로 부딛혓는가?
				if (!isHitCheck)
				{
					isBeforeHit = true;
					isHitCheck = true;
					HitState = _state;
				}

				//부딪친 방향과 가려고 하는 방향이 같은가?
				if (_state != HitState)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}

	//콜라이더에 충돌 여부 그리기(안에서 나가지 못하게 할때)
	bool Collider::isInCollider(string _tag)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);

		return m_Rect.isInCollision(tmp_rc);
	}

	//콜라이더 범위 리턴
	RECT Collider::get_Collider(string _tag)
	{
		return DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);
	}

	//콜라이더 삭제하기
	void Collider::DeleteCollider()
	{
		DoEngine::ColliderManager::get_Instance()->Release_Collider(m_Tag);
		isDelete = true;
	}

	//콜라이더 삭제하기
	void Collider::DeleteCollider(string _tag)
	{
		DoEngine::ColliderManager::get_Instance()->Release_Collider(_tag);
		isDelete = true;
	}

	//콜라이더 초기화
	void Collider::Release_Collider()
	{
		isHitCheck = false;
		isDelete = false;
	}

	//소멸자
	Collider::~Collider()
	{

	}
}