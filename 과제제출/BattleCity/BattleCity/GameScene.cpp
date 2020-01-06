#include "GameScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "AIManager.h"
#include "MapTool.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "ColliderManager.h"

//������
GameScene::GameScene()
{

}

//�ʱ�ȭ(override)
void GameScene::Init(HWND hWnd)
{
	//���� ���� �ʱ�ȭ
	Health_Count = MAX_ENEMY;
	GameManager::get_Instance()->set_PlayerDie(false);
	//���� ���� ����
	GameStop = false;
	GameManager::get_Instance()->Game_Start();

	tmp_Count = 0;
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (i < 10)
		{
			Health[i].posx = 960;
			Health[i].posy = 50 + tmp_Count * 30;
			tmp_Count++;
		}
		else
		{
			Health[i].posx = 990;
			Health[i].posy = 50 + tmp_Count * 30;
			tmp_Count++;
		}
		if (i == 9)
		{
			tmp_Count = 0;
		}
	}

	m_Command = NULL;
	//������ ���ȭ�� �����
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);
	//Ű ���
	GameManager::get_Instance()->Key_Init();
	//�ݶ��̴� ���� �׸���
	GameManager::get_Instance()->All_Draw();
	//�� �����
	m_Map.Init(W_COUNT, H_COUNT);
	//�� �ʱ�ȭ�ϱ�
	AIManager::get_Instance()->Init();
	//�÷��̾� �����
	m_pPlayer.Init(4, 13);

	//���� ����
	m_EnemyHealth = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\enemy_icon.bmp");
	m_tmpBlock = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block08.bmp");
}

//Ű�Է�(override)
bool GameScene::Input(float _fETime)
{
	//����
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}
	//ȭ�� �Ѿ��
	if (GameStop && DoEngine::InputManager::get_Instance()->isKeyUp(VK_RETURN))
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_TITLE);
	}

	//Player
	m_Command = m_Input.CommandInput();

	if (m_Command)
	{
		m_Command->excute(m_pPlayer);
	}
	//Enemy
	AIManager::get_Instance()->Input();

	return false;
}

//Update�Լ�(override)
void GameScene::Update(float _fETime)
{
	//������ �������̶��
	if (!GameStop)
	{
		//Map
		m_Map.Update(_fETime); //���� ���������� Update
		//Player
		m_pPlayer.Update(_fETime);
		//Enemy
		AIManager::get_Instance()->Update(_fETime);
	}

	if (GameManager::get_Instance()->get_WinAndLose() == WIN)
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_WIN);	
	}
}

//�� ���� 24ĭ, 2ĭ ���� 12��
//Draw �Լ�(override)
void GameScene::Draw(HDC hdc)
{
	//���ȭ�� �׸���
	m_BlackBG->Draw(0, 0);

	//��� �� �׸���(����)
	for (int i = 0; i < 15; i++)
	{
		m_tmpBlock->Draw(0, 10 + i * 50, OBJECT_COL, OBJECT_COL);
	}

	//��� �� �׸���(������)
	for (int i = 0; i < 15; i++)
	{
		m_tmpBlock->Draw(955, 10 + i * 50, OBJECT_COL, OBJECT_COL);
	}

	//���� ��� ī��Ʈ
	for (int i = 0; i < Health_Count - GameManager::get_Instance()->get_HealthCount(); i++)
	{
		m_EnemyHealth->Draw(Health[i].posx, Health[i].posy, 1.5, 1.5);
	}
	//�÷��̾� �׸���
	m_pPlayer.Draw();
	//�� �׸���
	AIManager::get_Instance()->Draw();
	//�� �����
	m_Map.Draw();

	//You Die
	if (GameManager::get_Instance()->get_WinAndLose() == LOSE || GameManager::get_Instance()->get_PlayerDie() == true)
	{
		GameStop = true;
		DoEngine::UIManager::get_Instance()->AddText("G   A   M   E", 350, 160, 80, 255, 255, 255, TRANSPARENT, "���� ���");
		DoEngine::UIManager::get_Instance()->AddText("O V E R", 420, 230, 80, 255, 255, 255, TRANSPARENT, "���� ���");
		DoEngine::UIManager::get_Instance()->AddText("PRESS ENTER", 390, 330, 60, 255, 255, 255, TRANSPARENT, "���� ���");
	}
}

//Release() �Լ�(override)
void GameScene::Release()
{
	m_pPlayer.Release();
	m_Map.Release();
	DoEngine::ColliderManager::get_Instance()->Clear_Collider();
	AIManager::get_Instance()->Release();
}

//�Ҹ���
GameScene::~GameScene()
{

}