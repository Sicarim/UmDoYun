#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	/*
		(12/18 추가)
		@brief 오브젝트 풀을 다루기 위한 클래스 선언
		@details 초기 객체를 할당해놓고, 필요할때 꺼내쓰고, 필요가 없다면 반환한다.
		초기 할당한 뒤 할당을 다 쓴다면 그때 새로 만든다.
	*/
	template <typename T>
	class ObjectPool
	{
	private:
		list<Object*> m_Datas; //Object Pool를 사용하기 위한 Data선언

	public:
		//Defalut생성자
		ObjectPool() {}

		void Make_Pool(int _size); //오브젝트 풀 만들기
		T* get_Data(); //Data 리턴
		void Return_Data(T* _data); //다 사용했다면 자료를 리턴
		void Clear_Data(); //데이터 삭제

		//소멸자
		~ObjectPool()
		{
			m_Datas.clear();
		}
	};

	//오브젝트 풀 만들기
	template <typename T>
	void ObjectPool<T>::Make_Pool(int _size)
	{
		for (int i = 0; i < _size; i++)
		{
			Object* tmp_data = new T;
			m_Datas.push_back(tmp_data);
		}
	}

	//Data 리턴
	template <typename T>
	T* ObjectPool<T>::get_Data()
	{
		//만약 데이터가 없다면 새로 생성해서 리턴한다
		if (m_Datas.empty())
		{
			return new T;
		}
		else
		{
			T* tmp_Data = m_Datas.front(); //만약 있다면 제일 첫번째 위치의 값을 대입한다
			m_Datas.pop_front(); //대입 후 맨앞의 데이터를 삭제한다(무조건 첫번째 데이터를 찾게 된다.)
			return tmp_Data; //그 후 임시 데이터값을 반환한다
		}
	}

	//다 사용했다면 자료를 리턴
	//주의!!!!!)Return_Data를 사용하기 전에 반드시 초기화or리셋 후 사용!!!!!!
	/*
		집가서 list가 아닌 다른 구조로 바꿀껏!!!!!!!!
	*/
	template <typename T>
	void ObjectPool<T>::Return_Data(T* _data)
	{
		m_Datas.push_back(_data);
	}

	template <typename T>
	void ObjectPool<T>::Clear_Data()
	{
		m_Datas.clear();
	}
}