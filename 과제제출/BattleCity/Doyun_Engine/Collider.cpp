#include "Collider.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"

namespace DoEngine
{
	//������
	Collider::Collider()
	{
		isHitCheck = false;
		isDelete = false;
	}

	//�ݶ��̴� ���� ���� (�±�, ��ǥ = Left, Top, Right, Bottom)
	void Collider::Init_Collider(string _tag, int _left, int _top, int _right, int _bottom)
	{
		m_Tag = _tag;
		m_left = _left;
		m_top = _top;
		m_right = _left + _right;
		m_bottom = _top + _bottom;

		m_Rect.Set(m_left, m_top, m_right, m_bottom);
		m_Rect = { m_left, m_top, m_right, m_bottom };
		//ColliderManager�� �ݶ��̴� ���
		DoEngine::ColliderManager::get_Instance()->Insert_Collider(m_Tag, m_Rect.get_Rect());
	}

	//�ݶ��̴� ���� �׸���
	void Collider::Draw_Collider()
	{
		if (ColliderManager::get_Instance()->get_DrawCollider())
		{
			if (!isDelete)
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
		}
	}

	//�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)
	bool Collider::isCollider(string _tag)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);

		return m_Rect.isOutCollision(tmp_rc);
	}

	//�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
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

	//�ݶ��̴��� �浹 ���� �׸���(�ȿ��� ������ ���ϰ� �Ҷ�)
	bool Collider::isInCollider(string _tag)
	{
		RECT tmp_rc = DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);

		return m_Rect.isInCollision(tmp_rc);
	}

	//�ݶ��̴� ���� ����
	RECT Collider::get_Collider(string _tag)
	{
		return DoEngine::ColliderManager::get_Instance()->Search_Collider(_tag);
	}

	//�ݶ��̴� �����ϱ�
	void Collider::DeleteCollider()
	{
		DoEngine::ColliderManager::get_Instance()->Release_Collider(m_Tag);
		isDelete = true;
	}

	//�ݶ��̴� �����ϱ�
	void Collider::DeleteCollider(string _tag)
	{
		DoEngine::ColliderManager::get_Instance()->Release_Collider(_tag);
		isDelete = true;
	}

	//�ݶ��̴� �ʱ�ȭ
	void Collider::Release_Collider()
	{
		isHitCheck = false;
		isDelete = false;
	}

	//�Ҹ���
	Collider::~Collider()
	{

	}
}