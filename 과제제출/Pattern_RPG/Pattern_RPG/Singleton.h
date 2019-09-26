#pragma once
#include "Mecro.h"

template <typename T>
class Singleton
{
private:
	//���� ��ü ����
	static T* m_hInstence;
public:
	//��ü ���� �� ȣ��
	static T* get_Instence()
	{
		if (m_hInstence == NULL)
		{
			m_hInstence = new T;
		}
		return m_hInstence;
	}

	//��ü ����
	static void Del_Instence()
	{
		if (m_hInstence != NULL)
		{
			delete m_hInstence;
			m_hInstence = NULL;
		}
		m_hInstence = NULL;
	}
	
	Singleton() {}; //������
	~Singleton() {}; //�Ҹ���
};

template <typename T> T* Singleton<T>::m_hInstence = NULL;