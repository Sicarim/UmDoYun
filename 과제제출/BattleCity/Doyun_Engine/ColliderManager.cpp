#include "ColliderManager.h"

namespace DoEngine
{
	//������
	ColliderManager::ColliderManager()
	{
		Draw_trigger = true;
	}

	//�ݶ��̴� �ֱ�
	void ColliderManager::Insert_Collider(string _tag, RECT _rect)
	{
		//�ݶ��̴��� ã�� �ִٸ� ���� ����, ���ٸ� ���� �����.
		auto iter = m_mapCollider.find(_tag);

		if (iter == m_mapCollider.end())
		{
			m_mapCollider.insert(make_pair(_tag, _rect));
		}
		else
		{
			iter->second = _rect;
		}
	}

	//�ݶ��̴� �˻��ϱ�
	RECT ColliderManager::Search_Collider(std::string _tag)
	{
		auto iter = m_mapCollider.find(_tag);

		if (iter != m_mapCollider.end())
		{
			return iter->second;
		}
	}

	//�ݶ��̴��� �����Ѵ�
	void ColliderManager::Release_Collider(string _tag)
	{
		m_mapCollider.erase(_tag);
	}

	//��� �ݶ��̴� ������ �׸���.
	void ColliderManager::set_DrawCollider(bool _trigger)
	{
		Draw_trigger = _trigger;
	}

	//��� �ݶ��̴� ������ �׸���.
	bool ColliderManager::get_DrawCollider()
	{
		return Draw_trigger;
	}

	//��� �ݶ��̴��� ����
	void ColliderManager::Clear_Collider()
	{
		m_mapCollider.clear();
	}

	//�Ҹ���
	ColliderManager::~ColliderManager()
	{

	}
}