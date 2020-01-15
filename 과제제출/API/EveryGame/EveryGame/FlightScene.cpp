#include "FlightScene.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "GameManager.h"

//생성자
FlightScene::FlightScene()
{
	Flight_Bit = NULL;
}

//초기화(overrride)
void FlightScene::Init(HWND hWnd)
{
	Flight_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameBack.bmp");
	TimeOver_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\TimeOver.bmp");
	m_Game.Init();
	MoveTimeOver = 0;
	curTime = 0.0f;
	isEnd = false;
}

//키입력(overrride)
bool FlightScene::Input(float _fETime)
{
	//ESC를 누르면 종료
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}
	
	//비행기 게임 Input
	m_Game.Input(_fETime);

	return false;
}

//Update함수(overrride)
void FlightScene::Update(float _fETime)
{
	m_Game.Update(_fETime);
	//만약 GameOver라면 일정시간이 지난 후 선택화면으로 돌아간다.
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
void FlightScene::Draw(HDC hdc)
{
	Flight_Bit->Draw(0, 0);
	m_Game.Draw();

	//게임이 끝나면 TimeOver객체를 그린다.
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
void FlightScene::Release()
{
	curTime = 0.0f;
	m_Game.Release();
	isEnd = false;
	MoveTimeOver = 0;
}

//소멸자
FlightScene::~FlightScene()
{

}