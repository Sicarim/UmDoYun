#include "GameManager.h"
#include "MapDraw.h"
//������
GameManager::GameManager()
{
	Player_Name = "";
}

//���� ����
void GameManager::Game_Start()
{
	m_Game = new RPG_Game();

	m_Game->Init();
	m_Game->Update();
	m_Game->Release();
}

void GameManager::Make_Name()
{
	MapDraw::BoxErase(40, 20);
	MapDraw::DrawPoint("Player �̸� : ", 20, 9);
	cin >> Player_Name;

	m_Player.set_Name(Player_Name);
}

void GameManager::Make_Class(string _class)
{
	Player_Class = _class;
	m_Player.set_Class(Player_Class);
}

//�÷��̾� ���� ����
void GameManager::Make_Weapon(WEAPON_SELECT _SELECT_WEAPON)
{
	if (_SELECT_WEAPON == WEAPON_BOW)
	{
		Player_Weapon = "Bow";
	}
	else if(_SELECT_WEAPON == WEAPON_DAGGER)
	{
		Player_Weapon = "Dagger";
	}
	else if (_SELECT_WEAPON == WEAPON_GUN)
	{
		Player_Weapon = "Gun";
	}
	else if (_SELECT_WEAPON == WEAPON_SWORD)
	{
		Player_Weapon = "Sword";
	}
	else if (_SELECT_WEAPON == WEAPON_WAND)
	{
		Player_Weapon = "Wand";
	}
	else if (_SELECT_WEAPON == WEAPON_HAMMER)
	{
		Player_Weapon = "Hammer";
	}
	m_Player.set_Weapon(Player_Weapon);
}

string GameManager::get_Name()
{
	return Player_Name;
}

string GameManager::get_Class()
{
	return Player_Class;
}

string GameManager::get_Weapon()
{
	return Player_Weapon;
}

//�Ҹ���
GameManager::~GameManager()
{
	delete m_Game;
}