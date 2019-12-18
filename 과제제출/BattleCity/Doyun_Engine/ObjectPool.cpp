#include "ObjectPool.h"

namespace DoEngine
{
	//������
	template <typename T>
	ObjectPool<T>::ObjectPool()
	{
		
	}

	//Data ����
	template <typename T>
	T* ObjectPool<T>::get_Data()
	{
		//���� �����Ͱ� ���ٸ� ���� �����ؼ� �����Ѵ�
		if (m_Datas.empty())
		{
			return new T;
		}
		else
		{
			T* tmp_Data = m_Datas.front(); //���� �ִٸ� ���� ù��° ��ġ�� ���� �����Ѵ�
			m_Datas.pop_front(); //���� �� �Ǿ��� �����͸� �����Ѵ�(������ ù��° �����͸� ã�� �ȴ�.)
			return tmp_Data; //�� �� �ӽ� �����Ͱ��� ��ȯ�Ѵ�
		}
	}

	//�� ����ߴٸ� �ڷḦ ����
	//����!!!!!)Return_Data�� ����ϱ� ���� �ݵ�� �ʱ�ȭor���� �� ���!!!!!!
	template <typename T>
	void ObjectPool<T>::Return_Data(T* _data)
	{
		m_Datas.push_back(_data);
	}

	//�Ҹ���
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