#pragma once
#include "UnitFactory.h"
#include "PlayerTank.h"

class Player : public UnitFactory
{
private:
	virtual void Create_Unit(string _name); //Unit����(override)
	static Player* m_hInstance; //��ü ����
public:
	Player(); //������

	//��ü ����
	static Player* get_Instance()
	{
		if (m_hInstance == NULL)
		{
			m_hInstance = new Player;
		}
		return m_hInstance;
	}

	//��ü ����
	static inline void Release()
	{
		delete m_hInstance;
	}

	~Player(); //�Ҹ���
};