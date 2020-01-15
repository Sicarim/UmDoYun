#pragma once
#include "Mecro.h"
#include "Interface.h"
#include "Player.h"

class GameManager
{
private:
	static GameManager* m_hInstence; //�̱��� �ɹ� ����

	//ù Ŀ���� ��ġ
	int First_X;
	int First_Y;
	int Player_Click;

	//����� ������ üũ
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

	GameManager(); //������
	void Game_Init(); //���� �ʱ�ȭ.
	void Game_Start(); //���� ����
	void Mine_Start(); //����ã�� ���� ����
	void Return_Menu(); //�����̽��� �Է½� �޴�ȭ������ ���ư�
	~GameManager(); //�Ҹ���
};