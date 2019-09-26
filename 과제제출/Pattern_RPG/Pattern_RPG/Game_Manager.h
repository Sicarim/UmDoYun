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
	Game_Manager(); //������ 
	void Game_Start(); //���� ����

	~Game_Manager(); //�Ҹ���
};