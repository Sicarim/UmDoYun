#include "Player.h"

//������
Player::Player()
{
	Player_Name = "";
	Player_Class = "";
}

//�÷��̾� �̸� ����.
void Player::set_Name(string _name)
{
	Player_Name = _name;
}

//�÷��̾� ���� ����.
void Player::set_Class(string _class)
{
	Player_Class = _class;
}

//�÷��̾� ���� ����.
void Player::set_Weapon(string _weapon)
{
	Player_Class = _weapon;
}

 //�Ҹ���
Player::~Player()
{

}