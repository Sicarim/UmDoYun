#include "TitleScene.h" //TitleScene ����
#include "InputManager.h" //InputManager(Ű ��ϵ�....)����
#include "SceneManager.h" //Scene���� �����Ǳ� ������ SceneManager����
#include "UIManager.h" //UI�� ����ϴϱ�..
#include "ResourcesManager.h" //�׸��� ����� �ϴϱ�
#include "GameManager.h"

//������
TitleScene::TitleScene()
{
	m_fTitleX = MAX_WITDH;
	m_fTitleY = MAX_HEIGHT;
}

//�ʱ�ȭ �Լ�(override)
void TitleScene::Init(HWND hWnd)
{
	//Ű ���
	GameManager::get_Instance()->Key_Init();

	//���ȭ�� ã�� ���� ã�� bmp������ ���ٸ� ���� ����(Init)�Ѵ�
	m_pBack = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\back.bmp");
	//���ڸ� ���´�
	DoEngine::UIManager::get_Instance()->AddText("Mine Serch", 370, 100, 50, 255, 255, 255, TRANSPARENT, "���� ���");
	DoEngine::UIManager::get_Instance()->AddText("Please Press 'S'", 360, 300, 40, 255, 255, 255, TRANSPARENT, "���� ���");
	DoEngine::UIManager::get_Instance()->AddText("Made by Doyun", 400, 400, 20, 255, 255, 0, TRANSPARENT, "���� ���");
	DoEngine::UIManager::get_Instance()->AddText("Using DoEngine", 420, 420, 10, 255, 255, 0, TRANSPARENT, "���� ���");
}

//�� Ű�� �´� ��ɾ� �Է�(override)
bool TitleScene::Input(float _fETime)
{
	//S�� ������ GameScene���� �Ѿ��
	if (DoEngine::InputManager::get_Instance()->isKeyUp(BUTTON_S))
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_GAME);
	}
	//ESC�� ������ ����
	else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	return false;
}

//Update �Լ�(override)
void TitleScene::Update(float _fETime)
{

}

//�׸��� �Լ�(override)
void TitleScene::Draw(HDC hdc)
{
	//0,0�� �׷���
	m_pBack->DrawBitblt(0, 0);
}

//���� �Լ�. DC�� BitMap�� �ƴ� ���� ������ ������� �����ų� �����ϴ� �Լ�(�����Ұ�....)(overrride)
void TitleScene::Release()
{

}

//Ŭ���ϸ� true�� ����(override)s
bool TitleScene::OnClick()
{
	return true;
}


//�Ҹ���
TitleScene::~TitleScene()
{

}