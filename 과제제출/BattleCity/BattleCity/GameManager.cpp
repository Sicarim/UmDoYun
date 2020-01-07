#include "GameManager.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "LoseEndScene.h"
#include "WinScene.h"
#include "InputManager.h"
#include "ColliderManager.h"
#include "StageScene.h"

//생성자
GameManager::GameManager()
{
	
}

//초기화
void GameManager::Init()
{
	Health_Count = 0;
	Enemy_Count = 0;
	WinAndLose = START;
	UpTank_Count = 0;
	Tank_Count = 0;
	NextStage = 1;
	Destroy_Count = 0;
	PlayerDie = false;
	Bullet_Count = 0;
}

//씬 등록
void GameManager::Regist_Scene()
{
	//TitleScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new TitleScene);
	//StageScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new StageScene);
	//GameScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new GameScene);
	//LoseEndScene등록
	DoEngine::SceneManager::get_Instance()->RegistScene(new WinScene);
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
	//엔터키
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RETURN);
}

//몬스터 만들기
vector<DoEngine::Object*> GameManager::Make_Enemy()
{
	tmp_vEnemy.clear();
	UpTank_Count = 0;
	Tank_Count = 0;
	//임시 변수
	int tmp_Num = 0;
	int Random = 0;
	DoEngine::Object* tmp_Object = NULL;

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		tmp_Num = rand() % 100;
		Random = rand() % 3;

		if (tmp_Num < 50)
		{
			tmp_Object = Enemy::get_Instance()->Order_Unit("Tank", Random * 6, 0);
			Tank_Count++;
		}
		else
		{
			tmp_Object = Enemy::get_Instance()->Order_Unit("UpTank", Random * 6, 0);
			UpTank_Count++;
		}
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

//탄알에 번호를 매긴다.
int GameManager::BulletCount()
{
	Bullet_Count++;
	return Bullet_Count;
}

//스테이지가 재실행 될때 초기화한다
void GameManager::Release()
{
	Health_Count = 0;
	Enemy_Count = 0;
	WinAndLose = START;
	UpTank_Count = 0;
	Tank_Count = 0;
	Destroy_Count = 0;
	PlayerDie = false;
	Bullet_Count = 0;
	m_vColl.clear();
	Enemy::get_Instance()->Clear_Data();
}

//충돌할 콜라이더 등록
void GameManager::add_WallCollider()
{
	m_vColl.push_back("PlagWall");

	//부서지는 벽 등록
	for (int i = 0; i < Broken_Count; i++)
	{
		wsprintf(buf, "BrokenWall%d", i);
		m_vColl.push_back((string)buf);
	}

	//강철 벽 등록
	for (int i = 0; i < Still_Count; i++)
	{
		wsprintf(buf, "StiilWall%d", i);
		m_vColl.push_back((string)buf);
	}
}

//콜라이더 모음 리턴
vector<string> GameManager::get_m_vColl()
{
	return m_vColl;
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

//물 블록 리턴
int GameManager::get_WaterCount()
{
	return Water_Count;
}

//적 갯수 저장
void GameManager::set_HealthCount(int _num)
{
	Health_Count = _num;
}

//적 갯수 리턴
int GameManager::get_HealthCount()
{
	return Health_Count;
}

//현재 맵에 있는 적의 갯수 저장
void GameManager::set_EnemyCount(int _num)
{
	Enemy_Count += _num;
}

//현재 맵에 있는 적의 갯수 리턴
int GameManager::get_EnemyCount()
{
	return Enemy_Count;
}

//게임에서 승리
void GameManager::Game_Win()
{
	WinAndLose = WIN;
}

//게임에서 패배
void GameManager::Game_Lose()
{
	WinAndLose = LOSE;
}

void GameManager::Game_Start()
{
	WinAndLose = START;
}

//게임 승패여부 리턴
int GameManager::get_WinAndLose()
{
	return WinAndLose;
}

//Tank갯수 저장
void GameManager::set_Tank(int _num)
{
	Tank_Count = _num;
}

//Tank 갯수 리턴
int GameManager::get_Tank()
{
	return Tank_Count;
}

//UpTank갯수 저장
void GameManager::set_UpTank(int _num)
{
	UpTank_Count = _num;
}

//UpTank갯수 리턴
int GameManager::get_UpTank()
{
	return UpTank_Count;
}

//씬 넘기기
void GameManager::ScenePlus()
{
	NextStage++;
}

//다음 스테이지 리턴
int GameManager::get_NextStage()
{
	return NextStage;
}

//부서진 적 갯수 저장
void GameManager::add_Destroy()
{
	Destroy_Count++;

	if (Destroy_Count == MAX_ENEMY)
	{
		WinAndLose = WIN;
	}
}

//플레이어 죽음
void GameManager::set_PlayerDie(bool _die)
{
	PlayerDie = _die;
}

//플레이어 죽음
bool GameManager::get_PlayerDie()
{
	return PlayerDie;
}

//소멸자
GameManager::~GameManager()
{

}