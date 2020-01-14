#include "CardScene.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GameManager.h"

//생성자
CardScene::CardScene()
{
	Card_Bit = NULL;
}

//초기화(overrride)
void CardScene::Init(HWND hWnd)
{
	Card_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\ColoredPaperBack.bmp");
	TimeOver_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\TimeOver.bmp");
	m_Game.Init(); //카드게임 초기화
	MoveTimeOver = 0;
	curTime = 0.0f;
	isEnd = false;
}

//키입력(overrride)
bool CardScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	//카드 게임 Input
	m_Game.Input(_fETime);

	return false;
}

//Update함수(overrride)
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

//Draw 함수(overrride)
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

//Release() 함수(overrride)
void CardScene::Release()
{
	curTime = 0.0f;
	m_Game.Release();
	isEnd = false;
	MoveTimeOver = 0;
}

//소멸자
CardScene::~CardScene()
{

}