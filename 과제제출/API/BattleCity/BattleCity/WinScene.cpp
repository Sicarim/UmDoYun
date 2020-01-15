#include "WinScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "MapTool.h"

//������
WinScene::WinScene()
{

}

//�ʱ�ȭ(override)
void WinScene::Init(HWND hWnd)
{
	curTime = 0.0f;
	Tank_Score = TANK_SCORE * GameManager::get_Instance()->get_Tank();
	UpTank_Score = UPTANK_SCORE * GameManager::get_Instance()->get_UpTank();
	curStage = GameManager::get_Instance()->get_NextStage();

	//Tank���
	Tank = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\e_up_00.bmp");
	UpTank = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\e_up_02.bmp");

	//������ ���ȭ�� �����
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);

	//Text ���
	wsprintf(buf, "S T A G E %d", curStage);
	DoEngine::UIManager::get_Instance()->AddText(buf, 400, 150, 50, 255, 255, 255, TRANSPARENT, "���� ���");
}

//Ű�Է�(override)
bool WinScene::Input(float _fETime)
{
	//����
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	return false;
}

//Update�Լ�(override)
void WinScene::Update(float _fETime)
{
	curTime += _fETime;

	if (curStage == 5)
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_TITLE);
	}

	if (curTime > 2.0f)
	{
		GameManager::get_Instance()->ScenePlus();
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_STAGE);
	}
}

//�� ���� 24ĭ, 2ĭ ���� 12��
//Draw �Լ�(override)
void WinScene::Draw(HDC hdc)
{
	//���� ���ȭ���� �׸���
	m_BlackBG->Draw(0, 0);

	//���� ǥ��
	Tank->Draw(300, 300, 1.5, 1.5);
	wsprintf(cTank_S, "-> %d X 100", GameManager::get_Instance()->get_Tank());
	DoEngine::UIManager::get_Instance()->AddText(cTank_S, 380, 300, 40, 255, 255, 255, TRANSPARENT, "���� ���");

	wsprintf(cTank, "= %d", Tank_Score);
	DoEngine::UIManager::get_Instance()->AddText(cTank, 600, 300, 40, 255, 255, 255, TRANSPARENT, "���� ���");


	UpTank->Draw(300, 400, 1.5, 1.5);
	wsprintf(cUpTank_S, "-> %d X 200", GameManager::get_Instance()->get_UpTank());
	DoEngine::UIManager::get_Instance()->AddText(cUpTank_S, 380, 400, 40, 255, 255, 255, TRANSPARENT, "���� ���");

	wsprintf(cUpTank, "= %d", UpTank_Score);
	DoEngine::UIManager::get_Instance()->AddText(cUpTank, 600, 400, 40, 255, 255, 255, TRANSPARENT, "���� ���");
	DoEngine::UIManager::get_Instance()->AddText("����������������������������", 280, 450, 40, 255, 255, 255, TRANSPARENT, "���� ���");

	wsprintf(Total_Score, "T O T A L  :  %d", UpTank_Score + Tank_Score);
	DoEngine::UIManager::get_Instance()->AddText(Total_Score, 400, 500, 40, 255, 255, 255, TRANSPARENT, "���� ���");
}

//Release() �Լ�(override)
void WinScene::Release()
{

}

//�Ҹ���
WinScene::~WinScene()
{

}