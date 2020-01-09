#include "TriggerCollider.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"

namespace DoEngine
{
	//생성자
	TriggerCollider::TriggerCollider()
	{
		isHitCheck = false;
		isDelete = false;
		Hit_dir = 0;
	}

	//콜라이더 범위 지정 (태그, 좌표 = Left, Top, Right, Bottom)
	void TriggerCollider::Init_Collider(string _tag, int _left, int _top, int _right, int _bottom, int _leftsize, int _topsize)
	{
		wsprintf(buf, "Trigger%s", _tag);
		m_Tag = buf;
		m_left = _left - _leftsize;
		m_top = _top - _topsize;
		m_right = _left + _right + _leftsize;
		m_bottom = _top + _bottom + _topsize;

		m_Rect.Set(m_left, m_top, m_right, m_bottom);
		m_Rect = { m_left, m_top, m_right, m_bottom };
		//ColliderManager에 콜라이더 등록
		DoEngine::ColliderManager::get_Instance()->Insert_Collider(m_Tag, m_Rect.get_Rect());
	}

	//콜라이더 범위 그리기
	bool TriggerCollider::Draw_Collider(string _tag)
	{
		if (ColliderManager::get_Instance()->get_DrawCollider())
		{
			if (!isDelete)
			{
				//범위 안에 들어왔다면 빨간색으로 그리기
				if (isCollider(_tag) > 0)
				{
					//초록색으로 그리기
					m_Collider = CreatePen(PS_SOLID, 3, RGB(205, 16, 57));
					m_oldCollider = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collider);

					//투명하게 그리기
					brush_Collider = (HBRUSH)GetStockObject(NULL_BRUSH);
					brush_oldCollider = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collider);

					Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_left, m_top, m_right, m_bottom);

					DeleteObject(m_oldCollider);
					DeleteObject(brush_oldCollider);

					return true;
				}
				else
				{
					//파란색으로 그리기
					m_Collider = CreatePen(PS_SOLID, 3, RGB(0, 100, 255));
					m_oldCollider = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collider);

					//투명하게 그리기
					brush_Collider = (HBRUSH)GetStockObject(NULL_BRUSH);
					brush_oldCollider = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collider);

					Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_left, m_top, m_right, m_bottom);

					DeleteObject(m_oldCollider);
					DeleteObject(brush_oldCollider);

					return false;
				}
			}
		}
	}
	
	//콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)
	int TriggerCollider::isCollider(string _tag)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);
		Hit_dir = HitDir_Check(tmp_rc);

		return m_Rect.isOutCollision(tmp_rc);
	}

	//콜라이더에 충돌 여부 그리기(밖에서 무언가 부딛칠때)(overloading)
	bool TriggerCollider::isCollider(vector<string> _tags)
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

	bool TriggerCollider::isCollider(string _tag, int _state)
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

	bool TriggerCollider::isCollider(vector<string> _tags, int _state)
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

	//어느 방향에서 출동했는가??
	int TriggerCollider::HitDir_Check(RECT _rc)
	{
		if (m_left < _rc.right && m_right > _rc.right && m_top < _rc.top && m_bottom > _rc.bottom)
		{
			return LEFT;
		}

		else if (m_right > _rc.left && m_left < _rc.left && m_top < _rc.top && m_bottom > _rc.bottom)
		{
			return RIGHT;
		}

		else if (m_top < _rc.bottom && m_left < _rc.left && m_right > _rc.right && m_bottom > _rc.bottom)
		{
			return UP;
		}

		else if (m_bottom > _rc.top && m_left < _rc.left && m_right > _rc.right && m_top < _rc.top)
		{
			return DOWN;
		}
	}

	//콜라이더에 충돌 여부 그리기(안에서 나가지 못하게 할때)
	bool TriggerCollider::isInCollider(string _tag)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);

		return m_Rect.isInCollision(tmp_rc);
	}

	//콜라이더 범위 리턴
	RECT TriggerCollider::get_Collider(string _tag)
	{
		return DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);
	}

	//콜라이더 삭제하기
	void TriggerCollider::DeleteCollider()
	{
		DoEngine::ColliderManager::get_Instance()->Release_Collider(m_Tag);
		isDelete = true;
	}

	//충돌 방향 리턴
	int TriggerCollider::get_HitDir()
	{
		return Hit_dir;
	}

	//소멸자
	TriggerCollider::~TriggerCollider()
	{

	}
}