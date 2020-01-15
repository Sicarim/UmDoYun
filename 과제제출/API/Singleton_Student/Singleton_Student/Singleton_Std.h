#pragma once
#include "Mecro.h"

template <typename T>
class Singleton_Std
{
private:
	static T* Instence;
public:
	static T* get_Instence()
	{
		if (Instence == NULL)
		{
			Instence = new T;
		}
		return Instence;
	}

	static void Del_Instence()
	{
		if (Instence != NULL)
		{
			delete Instence;
			Instence = NULL;
		}
		Instence = NULL;
	}

	Singleton_Std() {} //������
	~Singleton_Std() {} //�Ҹ���
};

template <typename T> T* Singleton_Std<T>::Instence = NULL;