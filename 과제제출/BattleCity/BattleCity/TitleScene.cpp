#include "TitleScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "AIManager.h"
#include "MapTool.h"

//������
TitleScene::TitleScene()
{

}

//�ʱ�ȭ(override)
void TitleScene::Init(HWND hWnd)
{
	m_Command = NULL;
	//������ ���ȭ�� �����
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);
	//Ű ���
	GameManager::get_Instance()->Key_Init();
	//�ݶ��̴� ���� �׸���
	GameManager::get_Instance()->All_Draw();
	//�� �����
	m_Map.Init(W_COUNT + 1, H_COUNT);
	//�÷��̾� �����
	m_pPlayer.Init(4, 13);
	//�� �ʱ�ȭ�ϱ�
	AIManager::get_Instance()->Init();

	/*m_vEnemy.clear();
	m_vEnemy.reserve(MAX_ENEMY);*/
	//�� �����
	//m_vEnemy = GameManager::get_Instance()->Make_Enemy();
}

//Ű�Է�(override)
bool TitleScene::Input(float _fETime)
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
void TitleScene::Update(float _fETime)
{
	//Enemy
	AIManager::get_Instance()->Update(_fETime);
	//Player
	m_pPlayer.Update(_fETime);
	//Map
	m_Map.Update(_fETime); //���� ���������� Update
}

//�� ���� 24ĭ, 2ĭ ���� 12��
//Draw �Լ�(override)
void TitleScene::Draw(HDC hdc)
{
	m_BlackBG->Draw(0, 0);
	//���ȭ�� �׸���
	m_Map.Draw();

	AIManager::get_Instance()->Draw();
	m_pPlayer.Draw();
}

//Release() �Լ�(override)
void TitleScene::Release()
{

}

//�Ҹ���
TitleScene::~TitleScene()
{

}