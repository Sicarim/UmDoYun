#include "Interface.h"

//������
Interface::Interface()
{
}

//���� ���� ȭ�� - ������ ���� ���� ȭ��
void Interface::Start_View()
{
	system("cls");
	m_Draw.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	m_Draw.DrawMidText("Mine Search", WIDTH, HALF_Y - 5);
	m_Draw.DrawMidText("1. ���� ����", WIDTH, HALF_Y - 3);
	m_Draw.DrawMidText("2. ����", WIDTH - 3, HALF_Y - 1);
	m_Draw.DrawMidText("���� : ", WIDTH - 3, HALF_Y + 1);
}

//���� ã�� ȭ��
void Interface::Main_Game_View()
{
	system("cls");
	m_Draw.CrossDraw(START_X, START_Y, MINE_WIDTH, MINE_HEIGHT);
	m_Draw.TextDraw("��� ���� : ", 0, 21);
	m_Draw.TextDraw("Ŀ�� �����̱� : ����Ű", 0, 22);
	m_Draw.TextDraw("Ŭ�� : x", 0, 23);
	m_Draw.TextDraw("��� ���� : c", 12, 23);
}

//�÷��̾ �̰��!
void Interface::Player_Win()
{
	system("cls");
	m_Draw.DrawMidText("---W  I  N---", WIDTH, HALF_Y - 1);
	m_Draw.DrawMidText("Return Menu : SpaceBar", WIDTH, HALF_Y);
}

//�÷��̾ �׾���!
void Interface::Player_Die()
{
	system("cls");
	m_Draw.DrawMidText("---B  O  O  M---", WIDTH, HALF_Y - 1);
	m_Draw.DrawMidText("YOU DIE", WIDTH, HALF_Y);
	m_Draw.DrawMidText("Return Menu : SpaceBar", WIDTH, HALF_Y + 1);
}


//�Ҹ���
Interface::~Interface()
{
}