#pragma once
#include "Mecro.h"

template <typename T>
class Singleton
{
private:
	//窜老 按眉 积己
	static T* m_hInstence;
public:
	//按眉 积己 棺 龋免
	static T* get_Instence()
	{
		if (m_hInstence == NULL)
		{
			m_hInstence = new T;
		}
		return m_hInstence;
	}

	//按眉 昏力
	static void Del_Instence()
	{
		if (m_hInstence != NULL)
		{
			delete m_hInstence;
			m_hInstence = NULL;
		}
		m_hInstence = NULL;
	}
	
	Singleton() {}; //积己磊
	~Singleton() {}; //家戈磊
};

template <typename T> T* Singleton<T>::m_hInstence = NULL;