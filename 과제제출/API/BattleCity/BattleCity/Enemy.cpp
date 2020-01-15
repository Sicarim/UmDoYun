#include "Enemy.h"

//초기화
Enemy* Enemy::m_hInstance = NULL;

//생성자
Enemy::Enemy()
{

}

//유닛 생성(override)
void Enemy::Create_Unit(string _name)
{
	if (_name == "Tank")
	{
		m_pUnit = new Tank;
	}
	else if (_name == "UpTank")
	{
		m_pUnit = new UpTank;
	}
}

//소멸자
Enemy::~Enemy()
{

}