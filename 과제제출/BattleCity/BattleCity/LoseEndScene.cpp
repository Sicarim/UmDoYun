#include "LoseEndScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"

//������
LoseEndScene::LoseEndScene()
{

}

//�ʱ�ȭ(override)
void LoseEndScene::Init(HWND hWnd)
{
	Select_x = 380;
	Select_y = 330;
	Select_Count = 3;

	//������ ���ȭ�� �����
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);
	//You Die
	DoEngine::UIManager::get_Instance()->AddText("G   A   M   E", 100, 60, 120, 255, 255, 255, TRANSPARENT, "���� ���");
	DoEngine::UIManager::get_Instance()->AddText("O V E R", 700, 160, 120, 255, 255, 255, TRANSPARENT, "���� ���");
}

//Ű�Է�(override)
bool LoseEndScene::Input(float _fETime)
{

	return false;
}

//Update�Լ�(override)
void LoseEndScene::Update(float _fETime)
{

}

//�� ���� 24ĭ, 2ĭ ���� 12��
//Draw �Լ�(override)
void LoseEndScene::Draw(HDC hdc)
{
	m_BlackBG->Draw(0, 0);
}

//Release() �Լ�(override)
void LoseEndScene::Release()
{

}

//�Ҹ���
LoseEndScene::~LoseEndScene()
{

}