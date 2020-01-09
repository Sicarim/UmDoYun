#include "FlightScene.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "SceneManager.h"

//������
FlightScene::FlightScene()
{
	Flight_Bit = NULL;
}

//�ʱ�ȭ(overrride)
void FlightScene::Init(HWND hWnd)
{
	Flight_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameBack.bmp");
}

//Ű�Է�(overrride)
bool FlightScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	return false;
}

//Update�Լ�(overrride)
void FlightScene::Update(float _fETime)
{
}

//Draw �Լ�(overrride)
void FlightScene::Draw(HDC hdc)
{
	Flight_Bit->Draw(0, 0);
}

//Release() �Լ�(overrride)
void FlightScene::Release()
{
}

//�Ҹ���
FlightScene::~FlightScene()
{

}