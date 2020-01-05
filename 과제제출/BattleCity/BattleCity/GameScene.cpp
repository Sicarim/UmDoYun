#include "GameScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "AIManager.h"
#include "MapTool.h"
#include "UIManager.h"

//������
GameScene::GameScene()
{

}

//�ʱ�ȭ(override)
void GameScene::Init(HWND hWnd)
{
	//���� ���� �ʱ�ȭ
	Health_Count = MAX_ENEMY;

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
	//�÷��̾� �����
	m_pPlayer.Init(4, 13);
	//���� ����
	m_EnemyHealth = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\enemy_icon.bmp");
	m_tmpBlock = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block08.bmp");
	//�� �ʱ�ȭ�ϱ�
	AIManager::get_Instance()->Init();
}

//Ű�Է�(override)
bool GameScene::Input(float _fETime)
{
	//����
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
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
	//Enemy
	AIManager::get_Instance()->Update(_fETime);
	//Map
	m_Map.Update(_fETime); //���� ���������� Update
	//Player
	m_pPlayer.Update(_fETime);

	/*wsprintf(buf, "Grid x: %d", GameManager::get_Instance()->get_CurrentX());
	DoEngine::UIManager::get_Instance()->AddText(buf, 0, 0, 50, 255, 255, 255, TRANSPARENT, "���� ���");

	wsprintf(buf2, "Grid y: %d", GameManager::get_Instance()->get_CurrentY());
	DoEngine::UIManager::get_Instance()->AddText(buf2, 0, 60, 50, 255, 255, 255, TRANSPARENT, "���� ���");

	wsprintf(buf3, "Real x: %d", GameManager::get_Instance()->get_RealX());
	DoEngine::UIManager::get_Instance()->AddText(buf3, 0, 120, 50, 255, 255, 255, TRANSPARENT, "���� ���");

	wsprintf(buf4, "Real y: %d", GameManager::get_Instance()->get_RealY());
	DoEngine::UIManager::get_Instance()->AddText(buf4, 0, 180, 50, 255, 255, 255, TRANSPARENT, "���� ���");*/
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
	//�� �����
	m_Map.Draw();
	//�� �׸���
	AIManager::get_Instance()->Draw();
}

//Release() �Լ�(override)
void GameScene::Release()
{

}

//�Ҹ���
GameScene::~GameScene()
{

}