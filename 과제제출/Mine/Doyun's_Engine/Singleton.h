#pragma once
#include "GlobalDefine.h"

template <typename T>
class Singleton
{
private:
	static T* m_hInstance;
public:
	static T* get_Instance()
	{
		if (m_hInstance == NULL)
		{
			m_hInstance = new T();
		}
		return m_hInstance;
	}

	static void del_Instance()
	{
		if (m_hInstance != NULL)
		{
			delete m_hInstance;
		}
		m_hInstance = NULL;
	}
	Singleton() {} //持失切

	~Singleton() {} //社瑚切
};

template <typename T> T* Singleton<T>::m_hInstance = NULL;
