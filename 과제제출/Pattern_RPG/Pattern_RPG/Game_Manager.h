#pragma once
#include "Mecro.h"
#include "Singleton.h"
#include "Interface.h"
#include "Game.h"

class Game_Manager : public Singleton<Game_Manager>
{
private:
	RPG_Game* m_Game;
protected:
	
public:
	Game_Manager(); //생성자 
	void Game_Start(); //게임 시작

	~Game_Manager(); //소멸자
};