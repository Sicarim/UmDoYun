#include "EndScene.h"
#include "defines.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//생성자
EndScene::EndScene()
{

}

//초기화(override)
void EndScene::Init(HWND hWnd)
{
	m_pBackDC = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\back.bmp");
	if (GameManager::get_Instance()->get_GameResult() == GAME_WIN)
	{
		DoEngine::UIManager::get_Instance()->AddText("YOU WIN!", 370, 100, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	}
	else
	{
		DoEngine::UIManager::get_Instance()->AddText("YOU DIE!", 370, 100, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	}
	DoEngine::UIManager::get_Instance()->AddText("다시하기 : x", 350, 350, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	DoEngine::UIManager::get_Instance()->AddText("종료 : ESC", 350, 400, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");
}

//키 입력(override)
bool EndScene::Input(float _fETime)
{
	//ESC를 누르면 종료
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

//Draw함수(Override)
void EndScene::Draw(HDC hdc)
{
	//배경화면을 그린다.
	m_pBackDC->Draw(0, 0);
}

//Release()함수 (override)
void EndScene::Release()
{

}

//소멸자
EndScene::~EndScene()
{
	Release();
}