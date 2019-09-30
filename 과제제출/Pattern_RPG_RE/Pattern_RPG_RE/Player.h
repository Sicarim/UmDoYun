#pragma once
#include "Mecro.h"

class Player
{
private:
	string Player_Name;
	string Player_Class;
	string Player_Weapom;
public:
	Player(); //생성자
	void set_Name(string _name); //플레이어 이름 기입.
	void set_Class(string _class); //플레이어 직업 기입.
	void set_Weapon(string _weapon); //플레이어 무기 기입.

	~Player(); //소멸자
};