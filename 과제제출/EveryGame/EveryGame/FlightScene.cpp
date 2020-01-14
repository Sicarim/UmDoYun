#include "FlightScene.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GameManager.h"

//������
FlightScene::FlightScene()
{
	Flight_Bit = NULL;
}

//�ʱ�ȭ(overrride)
void FlightScene::Init(HWND hWnd)
{
	Flight_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameBack.bmp");
	TimeOver_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\TimeOver.bmp");
	m_Game.Init();
	MoveTimeOver = 0;
	curTime = 0.0f;
	isEnd = false;
}

//Ű�Է�(overrride)
bool FlightScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}
	
	//����� ���� Input
	m_Game.Input(_fETime);

	return false;
}

//Update�Լ�(overrride)
void FlightScene::Update(float _fETime)
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
void FlightScene::Draw(HDC hdc)
{
	Flight_Bit->Draw(0, 0);
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
void FlightScene::Release()
{
	curTime = 0.0f;
	m_Game.Release();
	isEnd = false;
	MoveTimeOver = 0;
}

//�Ҹ���
FlightScene::~FlightScene()
{

}