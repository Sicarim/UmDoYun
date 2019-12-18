#include "ObjectPool.h"

namespace DoEngine
{
	//생성자
	template <typename T>
	ObjectPool<T>::ObjectPool()
	{
		
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
	template <typename T>
	void ObjectPool<T>::Return_Data(T* _data)
	{
		m_Datas.push_back(_data);
	}

	//소멸자
	template <typename T>
	ObjectPool<T>::~ObjectPool()
	{
		while (m_Datas.size())
		{
			T* tmp_obj = m_Datas.front();
			m_Datas.pop_front();
			delete tmp_obj;
		}
	}
}