#include "TitleScene.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "SceneManager.h"

//������
TitleScene::TitleScene()
{
	Title_Bit = NULL;
}

//�ʱ�ȭ(overrride)
void TitleScene::Init(HWND hWnd)
{
	Title_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\Title.bmp");
}

//Ű�Է�(overrride)
bool TitleScene::Input(float _fETime)
{
	//ESC�� ������ ����
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	//EnterŰ�� ������ ����ȭ������ �Ѿ��
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RETURN))
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_SELECT);
	}

	return false;
}

//Update�Լ�(overrride)
void TitleScene::Update(float _fETime)
{
}

//Draw �Լ�(overrride)
void TitleScene::Draw(HDC hdc)
{
	Title_Bit->Draw(0, 0);
}

//Release() �Լ�(overrride)
void TitleScene::Release()
{
}

//�Ҹ���
TitleScene::~TitleScene()
{

}