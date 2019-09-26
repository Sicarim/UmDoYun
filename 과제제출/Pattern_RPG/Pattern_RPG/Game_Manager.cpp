#include "Game_Manager.h"

//생성자
Game_Manager::Game_Manager()
{

}

//게임 시작
void Game_Manager::Game_Start()
{
	int Menu_iSelect = 0;

	m_Game = new RPG_Game();
	m_Game->Main_Loby();
}

//소멸자
Game_Manager::~Game_Manager()
{
	delete m_Game;
}