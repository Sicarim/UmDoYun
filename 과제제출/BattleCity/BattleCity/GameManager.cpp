#include "GameManager.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "InputManager.h"

//������
GameManager::GameManager()
{
	srand(time(NULL));
}

//�ʱ�ȭ
void GameManager::Init()
{

}

//�� ���
void GameManager::Regist_Scene()
{
	//TitleScene���
	DoEngine::SceneManager::get_Instance()->RegistScene(new TitleScene);
	//GameScene���
	//DoEngine::SceneManager::get_Instance()->RegistScene(new GameScene);
	//EndScene���
	//DoEngine::SceneManager::get_Instance()->RegistScene(new EndScene);
}

//Ű ���
void GameManager::Key_Init()
{
	//Ű ����
	DoEngine::InputManager::get_Instance()->Clear();
	//���۹�ư ���
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_S);
	//���ݹ�ư ���
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_X);
	//����Ű (��)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_LEFT);
	//����Ű (��)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RIGHT);
	//����Ű (��)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_UP);
	//����Ű (�Ʒ�)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_DOWN);
}

//���� �����
vector<DoEngine::Object*> GameManager::Make_Enemy()
{
	//�ӽ� ����
	int tmp_Num = 0;
	DoEngine::Object* tmp_Object = NULL;

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		tmp_Num = rand() % 100;

		if (tmp_Num <= 100)
		{
			tmp_Object = Enemy::get_Instance()->Order_Unit("Tank");
		}
		/*else if (tmp_Num > GENERATE_ENEMY && tmp_Num < GENERATE_ENEMY + 20)
		{
			tmp_Object = Enemy::get_Instance()->Order_Unit("UpTank");
		}*/
		tmp_vEnemy.push_back(tmp_Object);
	}

	return tmp_vEnemy;
}

//�Ҹ���
GameManager::~GameManager()
{

}