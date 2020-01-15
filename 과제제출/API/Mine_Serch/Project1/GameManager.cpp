#include "GameManager.h"
#include "MapManager.h"
GameManager* GameManager::m_hInstence = NULL;

//������
GameManager::GameManager()
{
	First_X = 0;
	First_Y = 0;
	Player_Click = 0;
	bPlag = false;
}

 //���� �ʱ�ȭ.
void GameManager::Game_Init()
{
	First_X = 10;
	First_Y = 7;
	Player_Click = 0;
	bPlag = false;
	MapManager::get_Instence()->Map_Reset(); //�� �����ϱ�
	m_Player.Player_Init(First_X, First_Y); //�÷��̾� ù ��ġ �ʱ�ȭ
	MapManager::get_Instence()->Mine_InIt(); //���� ��ġ �ʱ�ȭ
}

//����ã�� ���� ����
void GameManager::Mine_Start()
{
	int Player_X = 0;
	int Player_Y = 0;
	int Object_Num = 0;
	//������� ���� �ʱ�ȭ
	Game_Init();

	m_Inter.Main_Game_View();
	//MapManager::get_Instence()->Test_Map(); //�׽�Ʈ�� ��¹�

	while (1)
	{
		//�÷��̾ �̵� �� ���, Ŭ��
		Player_Click = m_Player.Serch_Mine();
		Player_X = m_Player.get_First_X();
		Player_Y = m_Player.get_First_Y();
		Object_Num = MapManager::get_Instence()->Check_Map(Player_X, Player_Y);

		switch (Player_Click)
		{
		case OBJECT_CHECK_CLICK:
			if (Object_Num == OBJECT_CHECK_MINE)
			{
				m_Inter.Player_Die();
				Return_Menu();
				return;
			}
			else if (Object_Num == OBJECT_CHECK_NULL)
			{
				MapManager::get_Instence()->Draw_Remove(Player_X, Player_Y);
				//system("cls");
			}
			break;

		case OBJECT_CHECK_PLAG:
			MapManager::get_Instence()->Draw_Object(Player_X, Player_Y, OBJECT_CHECK_PLAG);

			//�¸� üũ
			if (MapManager::get_Instence()->get_Answer_Count() == MINE_COUNT)
			{
				m_Inter.Player_Win();
				Return_Menu();
				return;
			}
			break;
		}
		
	}
}

//���� ����
void GameManager::Game_Start()
{
	int iSelect = 0;

	while (1)
	{
		m_Inter.Start_View();
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Mine_Start();
			break;
		case 2:
			return;
		}
	}
	
}

//�����̽��� �Է½� �޴�ȭ������ ���ư�
void GameManager::Return_Menu()
{
	//�����̽��� �Է½� ����
	while (1)
	{
		char ch = getch();
		if (ch == 32)
		{
			break;
		}
	}
}

//�Ҹ���
GameManager::~GameManager()
{
}