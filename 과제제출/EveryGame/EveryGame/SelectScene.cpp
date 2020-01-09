#include "SelectScene.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "UIManager.h"
#include "TitleScene.h"
#include "GameManager.h"

//������
SelectScene::SelectScene()
{
	Select_Bit = NULL;
}

//�ʱ�ȭ(overrride)
void SelectScene::Init(HWND hWnd)
{
	GameManager::get_Instance()->Init();
	curTime = 0.0f;
	sumTime = 0.0f;
	isClick = false; //���� Ŭ��
	isCard = false; //ī����� Ŭ��
	isFlight = false; //����� ���� Ŭ��
	//����ȭ�� ��Ʈ
	Select_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\GameSelect.bmp");

	//���� ���� ��ư ���
	//CardGame
	DoEngine::UIManager::get_Instance()->AddButton(320, 167, "RES\\OnSelect.bmp", std::bind(&SelectScene::OnCardClick, this));
	//FlightGame
	DoEngine::UIManager::get_Instance()->AddButton(320, 248, "RES\\OnSelect.bmp", std::bind(&SelectScene::OnFlightClick, this));
}

//Ű�Է�(overrride)
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

//Update�Լ�(overrride)
void SelectScene::Update(float _fETime)
{

}

//Draw �Լ�(overrride)
void SelectScene::Draw(HDC hdc)
{
	Select_Bit->Draw(0, 0);
	
	if (isClick)
	{
		GameManager::get_Instance()->Loading_Draw();
	}
}

//Release() �Լ�(overrride)
void SelectScene::Release()
{
	curTime = 0.0f;
	sumTime = 0.0f;
	isClick = false;
	isCard = false;
	isFlight = false;
	DoEngine::UIManager::get_Instance()->ReleaseUI();
}

//ī�����
bool SelectScene::OnCardClick()
{
	isClick = true;
	isCard = true;

	return true;
}

//����� ����
bool SelectScene::OnFlightClick()
{
	isClick = true;
	isFlight = true;

	return true;
}


//�Ҹ���
SelectScene::~SelectScene()
{

}