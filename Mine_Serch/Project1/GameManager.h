#pragma once
#include "Mecro.h"
#include "Interface.h"
#include "Player.h"

class GameManager
{
private:
	static GameManager* m_hInstence; //싱글톤 맴버 변수

	//첫 커서의 위치
	int First_X;
	int First_Y;
	int Player_Click;

	//깃발을 세웠나 체크
	bool bPlag;

	Interface m_Inter;
	Player m_Player;
public:
	static GameManager* get_Instence()
	{
		if (m_hInstence == NULL)
		{
			m_hInstence = new GameManager();
		}
		return m_hInstence;
	}

	static void del_Instence()
	{
		if (m_hInstence != NULL)
		{
			delete m_hInstence;
			m_hInstence = NULL;
		}
		m_hInstence = NULL;
	}

	GameManager(); //생성자
	void Game_Init(); //게임 초기화.
	void Game_Start(); //게임 시작
	void Mine_Start(); //지뢰찾기 게임 시작
	void Return_Menu(); //스페이스바 입력시 메뉴화면으로 돌아감
	~GameManager(); //소멸자
};