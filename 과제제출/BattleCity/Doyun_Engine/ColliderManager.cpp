#include "ColliderManager.h"

namespace DoEngine
{
	//������
	ColliderManager::ColliderManager()
	{

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

	//�Ҹ���
	ColliderManager::~ColliderManager()
	{

	}
}