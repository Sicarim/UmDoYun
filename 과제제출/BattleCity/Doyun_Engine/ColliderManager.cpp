#include "ColliderManager.h"

namespace DoEngine
{
	//생성자
	ColliderManager::ColliderManager()
	{
		Draw_trigger = true;
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

	//콜라이더를 삭제한다
	void ColliderManager::Release_Collider(string _tag)
	{
		m_mapCollider.erase(_tag);
	}

	//모든 콜라이더 범위를 그린다.
	void ColliderManager::set_DrawCollider(bool _trigger)
	{
		Draw_trigger = _trigger;
	}

	//모든 콜라이더 범위를 그린다.
	bool ColliderManager::get_DrawCollider()
	{
		return Draw_trigger;
	}

	//모든 콜라이더를 비운다
	void ColliderManager::Clear_Collider()
	{
		m_mapCollider.clear();
	}

	//소멸자
	ColliderManager::~ColliderManager()
	{

	}
}