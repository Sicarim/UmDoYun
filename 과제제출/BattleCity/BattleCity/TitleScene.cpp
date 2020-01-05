#include "TitleScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "MapTool.h"

//������
TitleScene::TitleScene()
{
	
}

//�ʱ�ȭ(override)
void TitleScene::Init(HWND hWnd)
{
	Select_x = 380;
	Select_y = 330;
	Select_Count = 3;

	//������ ���ȭ�� �����
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);
	//Ű ���
	GameManager::get_Instance()->Key_Init();
	//�׸� �׸���
	tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\tank_right_00.bmp");
	//���� ���
	DoEngine::UIManager::get_Instance()->AddText("B   A   T   T   L   E", 100, 60, 120, 255, 255, 255, TRANSPARENT, "���� ���");
	DoEngine::UIManager::get_Instance()->AddText("C I T Y", 700, 160, 80, 255, 255, 255, TRANSPARENT, "���� ���");
	DoEngine::UIManager::get_Instance()->AddText("REMASTER", 720, 220, 40, 150, 75, 0, TRANSPARENT, "���� ���");

	//��������
	DoEngine::UIManager::get_Instance()->AddText("1 S T A G E", 420, 320, 40, 255, 255, 255, TRANSPARENT, "���� ���");
	DoEngine::UIManager::get_Instance()->AddText("2 S T A G E", 420, 380, 40, 255, 255, 255, TRANSPARENT, "���� ���");
	//�ҷ�����
	DoEngine::UIManager::get_Instance()->AddText("L O A D", 420, 440, 40, 255, 255, 255, TRANSPARENT, "���� ���");
	//����!
	DoEngine::UIManager::get_Instance()->AddText("U M C O T", 380, 520, 60, 255, 127, 0, TRANSPARENT, "���� ���");
	//���� ��¥
	DoEngine::UIManager::get_Instance()->AddText("��  2019 2020 UMCO LTD ", 240, 660, 60, 255, 255, 255, TRANSPARENT, "���� ���");
}

//Ű�Է�(override)
bool TitleScene::Input(float _fETime)
{
	//����
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_UP))
	{
		if (Select_Count < 3)
		{
			Select_y -= 60;
			Select_Count++;
		}
	}

	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_DOWN))
	{
		if (Select_Count > 1)
		{
			Select_y += 60;
			Select_Count--;
		}
	}

	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RETURN))
	{
		//�� �����
		DoEngine::MapTool::get_Instance()->Init(W_COUNT, H_COUNT, "RES\\block00.bmp", COL_SIZE + 0.1f, COL_SIZE + 0.1f, NO_WALL);

		if (Select_Count == 3)
		{
			wsprintf(buf, "Map\\Stage1.txt");
			DoEngine::MapTool::get_Instance()->Make_Stage(buf);
		}
		else if (Select_Count == 2)
		{
			wsprintf(buf, "Map\\Stage2.txt");
			DoEngine::MapTool::get_Instance()->Make_Stage(buf);
		}
		else if (Select_Count == 1)
		{

		}
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_GAME);
	}


	return false;
}

//Update�Լ�(override)
void TitleScene::Update(float _fETime)
{
	
}

//�� ���� 24ĭ, 2ĭ ���� 12��
//Draw �Լ�(override)
void TitleScene::Draw(HDC hdc)
{	
	m_BlackBG->Draw(0, 0);

	tmp_bit->Draw(Select_x, Select_y);
}

//Release() �Լ�(override)
void TitleScene::Release()
{

}

//�Ҹ���
TitleScene::~TitleScene()
{

}