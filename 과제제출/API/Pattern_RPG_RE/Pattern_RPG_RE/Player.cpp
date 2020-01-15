#include "Player.h"

//생성자
Player::Player()
{
	Player_Name = "";
	Player_Class = "";
}

//플레이어 이름 기입.
void Player::set_Name(string _name)
{
	Player_Name = _name;
}

//플레이어 직업 기입.
void Player::set_Class(string _class)
{
	Player_Class = _class;
}

//플레이어 무기 기입.
void Player::set_Weapon(string _weapon)
{
	Player_Class = _weapon;
}

 //소멸자
Player::~Player()
{

}