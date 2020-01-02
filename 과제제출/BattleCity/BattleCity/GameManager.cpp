#include "GameManager.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "InputManager.h"
#include "ColliderManager.h"

//생성자
GameManager::GameManager()
{
	
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
	//게임 종료
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_ESCAPE);
}

//몬스터 만들기
vector<DoEngine::Object*> GameManager::Make_Enemy()
{
	//임시 변수
	int tmp_Num = 0;
	int Random = 0;
	DoEngine::Object* tmp_Object = NULL;

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		tmp_Num = rand() % 100;
		Random = rand() % 3;

		if (tmp_Num <= 100)
		{
			tmp_Object = Enemy::get_Instance()->Order_Unit("Tank", Random * 6, 0);
		}
		/*else if (tmp_Num > GENERATE_ENEMY && tmp_Num < GENERATE_ENEMY + 20)
		{
			tmp_Object = Enemy::get_Instance()->Order_Unit("UpTank");
		}*/
		tmp_vEnemy.push_back(tmp_Object);
	}

	return tmp_vEnemy;
}

//탄알 방향 저장
void GameManager::set_BulletDir(int _dir)
{
	Bullet_dir = _dir;
}

//탄알 방향 리턴
int GameManager::get_BulletDir()
{
	return Bullet_dir;
}

//모든 콜라이더 그리기
void GameManager::All_Draw()
{
	//그림을 끄려면 false, 아니면 True
	//DoEngine::ColliderManager::get_Instance()->set_DrawCollider(false);
	DoEngine::ColliderManager::get_Instance()->set_DrawCollider(true);
}

//파괴되는 블록 갯수 삽입
void GameManager::set_BrokenCount(int _count)
{
	Broken_Count = _count;
}

//물 블록 갯수 삽입
void GameManager::set_WaterCount(int _count)
{
	Water_Count = _count;
}

//부쉬 블럭 갯수 삽입
void GameManager::set_BushCount(int _count)
{
	Bush_Count = _count;
}

//강철 블럭 갯수 삽입
void GameManager::set_StillCount(int _count)
{
	Still_Count = _count;
}

//파괴되는 블록 리턴
int GameManager::get_BrokenCount()
{
	return Broken_Count;
}

//물 블록 리턴
int GameManager::get_WaterCount()
{
	return Water_Count;
}

//부쉬 블럭 리턴
int GameManager::get_BushCount()
{
	return Bush_Count;
}

//강철 블럭 리턴
int GameManager::get_StillCount()
{
	return Still_Count;
}


void GameManager::set_CurrentX(int _x, int _rx)
{
	test_x = _x;
	Real_x = _rx;
}

void GameManager::set_CurrentY(int _y, int _ry)
{
	test_y = _y;
	Real_y = _ry;
}

int GameManager::get_CurrentX()
{
	return test_x;
}

int GameManager::get_CurrentY()
{
	return test_y;
}


int GameManager::get_RealX()
{
	return Real_x;
}

int GameManager::get_RealY()
{
	return Real_y;
}

//소멸자
GameManager::~GameManager()
{

}