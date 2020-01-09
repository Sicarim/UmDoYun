#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	/**
	* 12/19 추가
	* @brief Collider를 관리하는 Manager
	* @details 콜라이더를 선언하면 자동적으로 배열을 만든다. 기존에 같은 태그를 가진 배열이 존재한다면 추가를 하고, 없다면 새로 만들어서 추가를 한다.
	*/

	class ColliderManager : public Singleton<ColliderManager>
	{
	private:
		map<string, RECT> m_mapCollider; //일련의 태그를 가진 RECT(콜라이더)의 집합
		bool Draw_trigger;

	public:
		ColliderManager(); //생성자

		void Insert_Collider(string _tag, RECT _rect); //콜라이더 넣기
		RECT Search_Collider(std::string _tag); //콜라이더 검색하기
		void Release_Collider(string _tag); //콜라이더를 삭제한다
		void set_DrawCollider(bool _trigger = true); //모든 콜라이더 범위를 그린다.
		bool get_DrawCollider(); //모든 콜라이더 범위를 그린다.
		void Clear_Collider(); //모든 콜라이더를 비운다

		~ColliderManager(); //소멸자
	};
}