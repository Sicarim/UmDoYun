#include "Interface.h"

//생성자
Interface::Interface()
{
}

//메인 시작 화면 - 간단한 게임 시작 화면
void Interface::Start_View()
{
	system("cls");
	m_Draw.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	m_Draw.DrawMidText("Mine Search", WIDTH, HALF_Y - 5);
	m_Draw.DrawMidText("1. 게임 시작", WIDTH, HALF_Y - 3);
	m_Draw.DrawMidText("2. 종료", WIDTH - 3, HALF_Y - 1);
	m_Draw.DrawMidText("선택 : ", WIDTH - 3, HALF_Y + 1);
}

//지뢰 찾기 화면
void Interface::Main_Game_View()
{
	system("cls");
	m_Draw.CrossDraw(START_X, START_Y, MINE_WIDTH, MINE_HEIGHT);
	m_Draw.TextDraw("깃발 갯수 : ", 0, 21);
	m_Draw.TextDraw("커서 움직이기 : 방향키", 0, 22);
	m_Draw.TextDraw("클릭 : x", 0, 23);
	m_Draw.TextDraw("깃발 놓기 : c", 12, 23);
}

//플레이어가 이겼다!
void Interface::Player_Win()
{
	system("cls");
	m_Draw.DrawMidText("---W  I  N---", WIDTH, HALF_Y - 1);
	m_Draw.DrawMidText("Return Menu : SpaceBar", WIDTH, HALF_Y);
}

//플레이어가 죽었다!
void Interface::Player_Die()
{
	system("cls");
	m_Draw.DrawMidText("---B  O  O  M---", WIDTH, HALF_Y - 1);
	m_Draw.DrawMidText("YOU DIE", WIDTH, HALF_Y);
	m_Draw.DrawMidText("Return Menu : SpaceBar", WIDTH, HALF_Y + 1);
}


//소멸자
Interface::~Interface()
{
}