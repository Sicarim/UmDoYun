#include "StageScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "MapTool.h"

//������
StageScene::StageScene()
{

}

//�ʱ�ȭ(override)
void StageScene::Init(HWND hWnd)
{
	curTime = 0.0f;
	curStage = GameManager::get_Instance()->get_NextStage();
	//������ ���ȭ�� �����
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);
	//���� ���
	wsprintf(buf, "%d STAGE", curStage);
	DoEngine::UIManager::get_Instance()->AddText(buf, 380, 300, 80, 255, 255, 255, TRANSPARENT, "���� ���");
}

//Ű�Է�(override)
bool StageScene::Input(float _fETime)
{
	//����
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	return false;
}

//Update�Լ�(override)
void StageScene::Update(float _fETime)
{
	curTime += _fETime;

	if (curTime > 2.5f)
	{
		wsprintf(buf, "Map\\Stage%d.txt", curStage);
		DoEngine::MapTool::get_Instance()->Make_Stage(buf);
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_GAME);
	}
}

//�� ���� 24ĭ, 2ĭ ���� 12��
//Draw �Լ�(override)
void StageScene::Draw(HDC hdc)
{
	//���� ���ȭ���� �׸���
	m_BlackBG->Draw(0, 0);
}

//Release() �Լ�(override)
void StageScene::Release()
{

}

//�Ҹ���
StageScene::~StageScene()
{

}