#include "Enemy.h"

//�ʱ�ȭ
Enemy* Enemy::m_hInstance = NULL;

//������
Enemy::Enemy()
{

}

//���� ����(override)
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

//�Ҹ���
Enemy::~Enemy()
{

}