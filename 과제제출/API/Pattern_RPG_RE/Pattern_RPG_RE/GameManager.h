#pragma once
#include "Mecro.h"
#include "Singleton.h"
#include "Interface.h"
#include "Game.h"

class GameManager : public Singleton<GameManager>
{
private:
	RPG_Game* m_Game;
	Player m_Player;

	string Player_Name;
	string Player_Class;
	string Player_Weapon;
	
protected:

public:
	GameManager(); //������ 

	void Game_Start(); //���� ����

	void Make_Name(); //�÷��̾� �̸� ����
	void Make_Class(string _class); //�÷��̾� ���� ����
	void Make_Weapon(WEAPON_SELECT _SELECT_WEAPON); //�÷��̾� ���� ����

	string get_Name();
	string get_Class();
	string get_Weapon();

	~GameManager(); //�Ҹ���
};