#include "Game_Manager.h"

//������
Game_Manager::Game_Manager()
{

}

//���� ����
void Game_Manager::Game_Start()
{
	int Menu_iSelect = 0;

	m_Game = new RPG_Game();
	m_Game->Main_Loby();
}

//�Ҹ���
Game_Manager::~Game_Manager()
{
	delete m_Game;
}