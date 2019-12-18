#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	/*
		@brief 오브젝트 풀을 다루기 위한 클래스 선언
		@details 초기 객체를 할당해놓고, 필요할때 꺼내쓰고, 필요가 없다면 반환한다.
		초기 할당한 뒤 할당을 다 쓴다면 그때 새로 만든다.
	*/
	template <typename T>
	class ObjectPool
	{
	private:
		//Object Pool를 사용하기 위한 Data선언
		list<T*> m_Datas;

	public:
		ObjectPool(); //생성자

		T* get_Data(); //Data 리턴
		void Return_Data(T* _data); //다 사용했다면 자료를 리턴

		~ObjectPool(); //소멸자
	};
}