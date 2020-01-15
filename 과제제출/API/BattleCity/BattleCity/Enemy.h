#pragma once
#include "UnitFactory.h"
#include "Tank.h"
#include "UpTank.h"

//�̱��� ����
class Enemy : public UnitFactory
{
private:
	virtual void Create_Unit(string _name); //���� ����(override)
	static Enemy* m_hInstance; //���� ���� ��ü ����
public:
	Enemy(); //������

	//��ü ����
	static Enemy* get_Instance()
	{
		if (m_hInstance == NULL)
		{
			m_hInstance = new Enemy;
		}
		return m_hInstance;
	}

	//��ü ����
	static inline void Release()
	{
		delete m_hInstance;
	}

	~Enemy(); //�Ҹ���
};