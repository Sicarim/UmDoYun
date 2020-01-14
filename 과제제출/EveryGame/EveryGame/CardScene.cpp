#include "CardScene.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GameManager.h"

//������
CardScene::CardScene()
{
	Card_Bit = NULL;
}

//�ʱ�ȭ(overrride)
void CardScene::Init(HWND hWnd)
{
	Card_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\ColoredPaperBack.bmp");
	TimeOver_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\TimeOver.bmp");
	m_Game.Init(); //ī����� �ʱ�ȭ
	MoveTimeOver = 0;
	curTime = 0.0f;
	isEnd = false;
}

//Ű�Է�(overrride)
bool CardScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	//ī�� ���� Input
	m_Game.Input(_fETime);

	return false;
}

//Update�Լ�(overrride)
void CardScene::Update(float _fETime)
{
	m_Game.Update(_fETime);
	if (GameManager::get_Instance()->get_GameOver())
	{
		isEnd = true;
		curTime += _fETime;
		if (curTime > 2.0f)
		{
			DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_SELECT);
		}
	}
}

//Draw �Լ�(overrride)
void CardScene::Draw(HDC hdc)
{
	Card_Bit->Draw(0, 0);
	m_Game.Draw();

	if (isEnd)
	{
		if (MoveTimeOver <= 300)
		{
			MoveTimeOver += 3;
		}
		TimeOver_Bit->Draw(100, MoveTimeOver);
	}
}

//Release() �Լ�(overrride)
void CardScene::Release()
{
	curTime = 0.0f;
	m_Game.Release();
	isEnd = false;
	MoveTimeOver = 0;
}

//�Ҹ���
CardScene::~CardScene()
{

}