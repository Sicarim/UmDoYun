#pragma once
#include "Mecro.h"

class Player
{
private:
	string Player_Name;
	string Player_Class;
	string Player_Weapom;
public:
	Player(); //������
	void set_Name(string _name); //�÷��̾� �̸� ����.
	void set_Class(string _class); //�÷��̾� ���� ����.
	void set_Weapon(string _weapon); //�÷��̾� ���� ����.

	~Player(); //�Ҹ���
};