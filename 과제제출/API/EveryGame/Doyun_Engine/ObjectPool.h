#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	/*
		(12/18 �߰�)
		@brief ������Ʈ Ǯ�� �ٷ�� ���� Ŭ���� ����
		@details �ʱ� ��ü�� �Ҵ��س���, �ʿ��Ҷ� ��������, �ʿ䰡 ���ٸ� ��ȯ�Ѵ�.
		�ʱ� �Ҵ��� �� �Ҵ��� �� ���ٸ� �׶� ���� �����.
	*/
	template <typename T>
	class ObjectPool
	{
	private:
		list<Object*> m_Datas; //Object Pool�� ����ϱ� ���� Data����

	public:
		//Defalut������
		ObjectPool() {}

		void Make_Pool(int _size); //������Ʈ Ǯ �����
		T* get_Data(); //Data ����
		void Return_Data(T* _data); //�� ����ߴٸ� �ڷḦ ����
		void Clear_Data(); //������ ����

		//�Ҹ���
		~ObjectPool()
		{
			m_Datas.clear();
		}
	};

	//������Ʈ Ǯ �����
	template <typename T>
	void ObjectPool<T>::Make_Pool(int _size)
	{
		for (int i = 0; i < _size; i++)
		{
			Object* tmp_data = new T;
			m_Datas.push_back(tmp_data);
		}
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
	/*
		������ list�� �ƴ� �ٸ� ������ �ٲܲ�!!!!!!!!
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