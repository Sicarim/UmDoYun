#include "Player.h"

//�ʱ�ȭ
Player* Player::m_hInstance = NULL;

//������
Player::Player()
{

}

//Unit����(override)
void Player::Create_Unit(string _name)
{
	if (_name == "Player")
	{
		m_pUnit = new PlayerTank;
	}
}

//�Ҹ���
Player::~Player()
{

}