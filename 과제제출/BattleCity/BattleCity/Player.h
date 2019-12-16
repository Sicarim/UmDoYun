#pragma once
#include "UnitFactory.h"
#include "PlayerTank.h"

class Player : public UnitFactory
{
private:
	virtual void Create_Unit(string _name); //Unit积己(override)
	static Player* m_hInstance; //按眉 积己
public:
	Player(); //积己磊

	//按眉 积己
	static Player* get_Instance()
	{
		if (m_hInstance == NULL)
		{
			m_hInstance = new Player;
		}
		return m_hInstance;
	}

	//按眉 昏力
	static inline void Release()
	{
		delete m_hInstance;
	}

	~Player(); //家戈磊
};