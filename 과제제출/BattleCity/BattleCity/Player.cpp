#include "Player.h"

//초기화
Player* Player::m_hInstance = NULL;

//생성자
Player::Player()
{

}

//Unit생성(override)
void Player::Create_Unit(string _name)
{
	if (_name == "Player")
	{
		m_pUnit = new PlayerTank;
	}
}

//소멸자
Player::~Player()
{

}