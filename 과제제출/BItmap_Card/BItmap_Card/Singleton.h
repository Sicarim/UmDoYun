#pragma once
#include "Mecro.h"

template <typename T>
class Singleton
{
private:
	static T* m_hInstence;
public:
	static T* get_Instence()
	{
		if (m_hInstence == NULL)
		{
			m_hInstence = new T;
		}
		return m_hInstence;
	}

	void del_Instence()
	{
		if (m_hInstence != NULL)
		{
			delete m_hInstence;
		}
		m_hInstence = NULL;
	}

	//持失切
	Singleton() {}
	//社瑚切
	~Singleton() {}
};

template <typename T> T* Singleton<T>::m_hInstence = NULL;