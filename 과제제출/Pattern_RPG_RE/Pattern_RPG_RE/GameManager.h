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
	GameManager(); //생성자 

	void Game_Start(); //게임 시작

	void Make_Name(); //플레이어 이름 기입
	void Make_Class(string _class); //플레이어 직업 기입
	void Make_Weapon(WEAPON_SELECT _SELECT_WEAPON); //플레이어 직업 기입

	string get_Name();
	string get_Class();
	string get_Weapon();

	~GameManager(); //소멸자
};