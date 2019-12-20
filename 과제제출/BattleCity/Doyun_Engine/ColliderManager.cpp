#include "ColliderManager.h"

namespace DoEngine
{
	//생성자
	ColliderManager::ColliderManager()
	{

	}

	//콜라이더 넣기
	void ColliderManager::Insert_Collider(string _tag, RECT _rect)
	{
		//콜라이더를 찾고 있다면 값을 갱신, 없다면 새로 만든다.
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

	//콜라이더 검색하기
	RECT ColliderManager::Search_Collider(std::string _tag)
	{
		auto iter = m_mapCollider.find(_tag);

		if (iter != m_mapCollider.end())
		{
			return iter->second;
		}
	}

	//소멸자
	ColliderManager::~ColliderManager()
	{

	}
}