#pragma once
#include "UnitFactory.h"
#include "Tank.h"
#include "UpTank.h"

//教臂沛 菩畔
class Enemy : public UnitFactory
{
private:
	virtual void Create_Unit(string _name); //蜡粗 积己(override)
	static Enemy* m_hInstance; //蜡老 公扁 按眉 积己
public:
	Enemy(); //积己磊

	//按眉 积己
	static Enemy* get_Instance()
	{
		if (m_hInstance == NULL)
		{
			m_hInstance = new Enemy;
		}
		return m_hInstance;
	}

	//按眉 昏力
	static inline void Release()
	{
		delete m_hInstance;
	}

	~Enemy(); //家戈磊
};