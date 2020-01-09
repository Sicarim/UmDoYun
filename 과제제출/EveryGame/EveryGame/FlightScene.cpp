#include "FlightScene.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "SceneManager.h"

//생성자
FlightScene::FlightScene()
{
	Flight_Bit = NULL;
}

//초기화(overrride)
void FlightScene::Init(HWND hWnd)
{
	Flight_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameBack.bmp");
}

//키입력(overrride)
bool FlightScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	return false;
}

//Update함수(overrride)
void FlightScene::Update(float _fETime)
{
}

//Draw 함수(overrride)
void FlightScene::Draw(HDC hdc)
{
	Flight_Bit->Draw(0, 0);
}

//Release() 함수(overrride)
void FlightScene::Release()
{
}

//소멸자
FlightScene::~FlightScene()
{

}