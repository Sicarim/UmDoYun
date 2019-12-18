#include "GameManager.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "InputManager.h"

//생성자
GameManager::GameManager()
{
	srand(time(NULL));
}

//초기화
void GameManager::Init()
{

}

//씬 등록
void GameManager::Regist_Scene()
{
	//TitleScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new TitleScene);
	//GameScene등록
	//DoEngine::SceneManager::get_Instance()->RegistScene(new GameScene);
	//EndScene등록
	//DoEngine::SceneManager::get_Instance()->RegistScene(new EndScene);
}

//키 등록
void GameManager::Key_Init()
{
	//키 비우기
	DoEngine::InputManager::get_Instance()->Clear();
	//시작버튼 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_S);
	//공격버튼 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_X);
	//방향키 (왼)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_LEFT);
	//방향키 (오)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RIGHT);
	//방향키 (위)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_UP);
	//방향키 (아래)
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_DOWN);
}

//몬스터 만들기
vector<DoEngine::Object*> GameManager::Make_Enemy()
{
	//임시 변수
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

//소멸자
GameManager::~GameManager()
{

}