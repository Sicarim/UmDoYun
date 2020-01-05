#include "TriggerCollider.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"

namespace DoEngine
{
	//������
	TriggerCollider::TriggerCollider()
	{
		isHitCheck = false;
		isDelete = false;
		Hit_dir = 0;
	}

	//�ݶ��̴� ���� ���� (�±�, ��ǥ = Left, Top, Right, Bottom)
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
		//ColliderManager�� �ݶ��̴� ���
		DoEngine::ColliderManager::get_Instance()->Insert_Collider(m_Tag, m_Rect.get_Rect());
	}

	//�ݶ��̴� ���� �׸���
	bool TriggerCollider::Draw_Collider(string _tag)
	{
		if (ColliderManager::get_Instance()->get_DrawCollider())
		{
			if (!isDelete)
			{
				//���� �ȿ� ���Դٸ� ���������� �׸���
				if (isCollider(_tag) > 0)
				{
					//�ʷϻ����� �׸���
					m_Collider = CreatePen(PS_SOLID, 3, RGB(205, 16, 57));
					m_oldCollider = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collider);

					//�����ϰ� �׸���
					brush_Collider = (HBRUSH)GetStockObject(NULL_BRUSH);
					brush_oldCollider = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Collider);

					Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_left, m_top, m_right, m_bottom);

					DeleteObject(m_oldCollider);
					DeleteObject(brush_oldCollider);

					return true;
				}
				else
				{
					//�Ķ������� �׸���
					m_Collider = CreatePen(PS_SOLID, 3, RGB(0, 100, 255));
					m_oldCollider = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_Collider);

					//�����ϰ� �׸���
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
	
	//�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)
	int TriggerCollider::isCollider(string _tag)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);
		Hit_dir = HitDir_Check(tmp_rc);

		return m_Rect.isOutCollision(tmp_rc);
	}

	//�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
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

		//�浹 üũ ����
		if (!m_Rect.isOutCollision(tmp_rc))
		{
			isHitCheck = false;
			return false;
		}

		else
		{
			//���ʷ� �ε����°�?
			if (!isHitCheck)
			{
				isHitCheck = true;
				HitState = _state;
			}

			//�ε�ģ ����� ������ �ϴ� ������ ������?
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

			//�浹 üũ ����
			if (!m_Rect.isOutCollision(tmp_rc) && !isHitCheck)
			{
				isHitCheck = false;
				isBeforeHit = false;
			}

			else
			{
				//���ʷ� �ε����°�?
				if (!isHitCheck)
				{
					isBeforeHit = true;
					isHitCheck = true;
					HitState = _state;
				}

				//�ε�ģ ����� ������ �ϴ� ������ ������?
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

	//��� ���⿡�� �⵿�ߴ°�??
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

	//�ݶ��̴��� �浹 ���� �׸���(�ȿ��� ������ ���ϰ� �Ҷ�)
	bool TriggerCollider::isInCollider(string _tag)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);

		return m_Rect.isInCollision(tmp_rc);
	}

	//�ݶ��̴� ���� ����
	RECT TriggerCollider::get_Collider(string _tag)
	{
		return DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);
	}

	//�ݶ��̴� �����ϱ�
	void TriggerCollider::DeleteCollider()
	{
		DoEngine::ColliderManager::get_Instance()->Release_Collider(m_Tag);
		isDelete = true;
	}

	//�浹 ���� ����
	int TriggerCollider::get_HitDir()
	{
		return Hit_dir;
	}

	//�Ҹ���
	TriggerCollider::~TriggerCollider()
	{

	}
}