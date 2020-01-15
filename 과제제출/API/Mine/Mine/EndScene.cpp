#include "EndScene.h"
#include "defines.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//������
EndScene::EndScene()
{

}

//�ʱ�ȭ(override)
void EndScene::Init(HWND hWnd)
{
	m_pBackDC = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\back.bmp");
	if (GameManager::get_Instance()->get_GameResult() == GAME_WIN)
	{
		DoEngine::UIManager::get_Instance()->AddText("YOU WIN!", 370, 100, 50, 255, 255, 255, TRANSPARENT, "���� ���");
	}
	else
	{
		DoEngine::UIManager::get_Instance()->AddText("YOU DIE!", 370, 100, 50, 255, 255, 255, TRANSPARENT, "���� ���");
	}
	DoEngine::UIManager::get_Instance()->AddText("�ٽ��ϱ� : x", 350, 350, 50, 255, 255, 255, TRANSPARENT, "���� ���");
	DoEngine::UIManager::get_Instance()->AddText("���� : ESC", 350, 400, 50, 255, 255, 255, TRANSPARENT, "���� ���");
}

//Ű �Է�(override)
bool EndScene::Input(float _fETime)
{
	//ESC�� ������ ����
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}
	if (DoEngine::InputManager::get_Instance()->isKeyUp(BUTTON_X))
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_TITLE);
	}

	return false;
}

//Update(override)
void EndScene::Update(float _fETime)
{

}

//Draw�Լ�(Override)
void EndScene::Draw(HDC hdc)
{
	//���ȭ���� �׸���.
	m_pBackDC->Draw(0, 0);
}

//Release()�Լ� (override)
void EndScene::Release()
{

}

//�Ҹ���
EndScene::~EndScene()
{
	Release();
}