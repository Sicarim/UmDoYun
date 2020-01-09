#include "SelectScene.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "UIManager.h"
#include "TitleScene.h"
#include "GameManager.h"

//생성자
SelectScene::SelectScene()
{
	Select_Bit = NULL;
}

//초기화(overrride)
void SelectScene::Init(HWND hWnd)
{
	GameManager::get_Instance()->Init();
	curTime = 0.0f;
	sumTime = 0.0f;
	isClick = false; //게임 클릭
	isCard = false; //카드게임 클릭
	isFlight = false; //비행기 게임 클릭
	//선택화면 비트
	Select_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\GameSelect.bmp");

	//게임 선택 버튼 등록
	//CardGame
	DoEngine::UIManager::get_Instance()->AddButton(320, 167, "RES\\OnSelect.bmp", std::bind(&SelectScene::OnCardClick, this));
	//FlightGame
	DoEngine::UIManager::get_Instance()->AddButton(320, 248, "RES\\OnSelect.bmp", std::bind(&SelectScene::OnFlightClick, this));
}

//키입력(overrride)
bool SelectScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	if (isClick)
	{
		curTime += _fETime;
		DoEngine::UIManager::get_Instance()->ReleaseUI();

		if (curTime > 0.1f)
		{
			if (isCard)
			{
				DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_CARD);
			}
			if (isFlight)
			{
				DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_FLIGHT);
			}
		}
	}
	return false;
}

//Update함수(overrride)
void SelectScene::Update(float _fETime)
{

}

//Draw 함수(overrride)
void SelectScene::Draw(HDC hdc)
{
	Select_Bit->Draw(0, 0);
	
	if (isClick)
	{
		GameManager::get_Instance()->Loading_Draw();
	}
}

//Release() 함수(overrride)
void SelectScene::Release()
{
	curTime = 0.0f;
	sumTime = 0.0f;
	isClick = false;
	isCard = false;
	isFlight = false;
	DoEngine::UIManager::get_Instance()->ReleaseUI();
}

//카드게임
bool SelectScene::OnCardClick()
{
	isClick = true;
	isCard = true;

	return true;
}

//비행기 게임
bool SelectScene::OnFlightClick()
{
	isClick = true;
	isFlight = true;

	return true;
}


//소멸자
SelectScene::~SelectScene()
{

}