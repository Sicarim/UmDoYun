#include "TitleScene.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "SceneManager.h"

//생성자
TitleScene::TitleScene()
{
	Title_Bit = NULL;
}

//초기화(overrride)
void TitleScene::Init(HWND hWnd)
{
	Title_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\Title.bmp");
}

//키입력(overrride)
bool TitleScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RETURN))
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_SELECT);
	}

	return false;
}

//Update함수(overrride)
void TitleScene::Update(float _fETime)
{
}

//Draw 함수(overrride)
void TitleScene::Draw(HDC hdc)
{
	Title_Bit->Draw(0, 0);
}

//Release() 함수(overrride)
void TitleScene::Release()
{
}

//소멸자
TitleScene::~TitleScene()
{

}