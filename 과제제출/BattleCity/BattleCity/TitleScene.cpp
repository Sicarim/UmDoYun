#include "TitleScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "AIManager.h"
#include "MapTool.h"
#include "UIManager.h"

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
	m_Map.Init(W_COUNT, H_COUNT);
	//�÷��̾� �����
	m_pPlayer.Init(4, 13);
	//�� �ʱ�ȭ�ϱ�
	AIManager::get_Instance()->Init();
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
void TitleScene::Draw(HDC hdc)
{
	m_BlackBG->Draw(0, 0);
	//���ȭ�� �׸���
	m_Map.Draw();
	//�÷��̾� �׸���
	m_pPlayer.Draw();
	//�� �׸���
	AIManager::get_Instance()->Draw();
	
}

//Release() �Լ�(override)
void TitleScene::Release()
{

}

//�Ҹ���
TitleScene::~TitleScene()
{

}