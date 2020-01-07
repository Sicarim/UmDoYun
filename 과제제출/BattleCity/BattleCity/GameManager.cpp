#include "GameManager.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "LoseEndScene.h"
#include "WinScene.h"
#include "InputManager.h"
#include "ColliderManager.h"
#include "StageScene.h"

//������
GameManager::GameManager()
{
	
}

//�ʱ�ȭ
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

//�� ���
void GameManager::Regist_Scene()
{
	//TitleScene���
	DoEngine::SceneManager::get_Instance()->RegistScene(new TitleScene);
	//StageScene���
	DoEngine::SceneManager::get_Instance()->RegistScene(new StageScene);
	//GameScene���
	DoEngine::SceneManager::get_Instance()->RegistScene(new GameScene);
	//LoseEndScene���
	DoEngine::SceneManager::get_Instance()->RegistScene(new WinScene);
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
	//���� ����
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_ESCAPE);
	//����Ű
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RETURN);
}

//���� �����
vector<DoEngine::Object*> GameManager::Make_Enemy()
{
	tmp_vEnemy.clear();
	UpTank_Count = 0;
	Tank_Count = 0;
	//�ӽ� ����
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

//ź�� ���� ����
void GameManager::set_BulletDir(int _dir)
{
	Bullet_dir = _dir;
}

//ź�� ���� ����
int GameManager::get_BulletDir()
{
	return Bullet_dir;
}

//��� �ݶ��̴� �׸���
void GameManager::All_Draw()
{
	//�׸��� ������ false, �ƴϸ� True
	//DoEngine::ColliderManager::get_Instance()->set_DrawCollider(false);
	DoEngine::ColliderManager::get_Instance()->set_DrawCollider(true);
}

//ź�˿� ��ȣ�� �ű��.
int GameManager::BulletCount()
{
	Bullet_Count++;
	return Bullet_Count;
}

//���������� ����� �ɶ� �ʱ�ȭ�Ѵ�
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

//�浹�� �ݶ��̴� ���
void GameManager::add_WallCollider()
{
	m_vColl.push_back("PlagWall");

	//�μ����� �� ���
	for (int i = 0; i < Broken_Count; i++)
	{
		wsprintf(buf, "BrokenWall%d", i);
		m_vColl.push_back((string)buf);
	}

	//��ö �� ���
	for (int i = 0; i < Still_Count; i++)
	{
		wsprintf(buf, "StiilWall%d", i);
		m_vColl.push_back((string)buf);
	}
}

//�ݶ��̴� ���� ����
vector<string> GameManager::get_m_vColl()
{
	return m_vColl;
}

//�ı��Ǵ� ��� ���� ����
void GameManager::set_BrokenCount(int _count)
{
	Broken_Count = _count;
}

//�� ��� ���� ����
void GameManager::set_WaterCount(int _count)
{
	Water_Count = _count;
}

//�ν� �� ���� ����
void GameManager::set_BushCount(int _count)
{
	Bush_Count = _count;
}

//��ö �� ���� ����
void GameManager::set_StillCount(int _count)
{
	Still_Count = _count;
}

//�� ��� ����
int GameManager::get_WaterCount()
{
	return Water_Count;
}

//�� ���� ����
void GameManager::set_HealthCount(int _num)
{
	Health_Count = _num;
}

//�� ���� ����
int GameManager::get_HealthCount()
{
	return Health_Count;
}

//���� �ʿ� �ִ� ���� ���� ����
void GameManager::set_EnemyCount(int _num)
{
	Enemy_Count += _num;
}

//���� �ʿ� �ִ� ���� ���� ����
int GameManager::get_EnemyCount()
{
	return Enemy_Count;
}

//���ӿ��� �¸�
void GameManager::Game_Win()
{
	WinAndLose = WIN;
}

//���ӿ��� �й�
void GameManager::Game_Lose()
{
	WinAndLose = LOSE;
}

void GameManager::Game_Start()
{
	WinAndLose = START;
}

//���� ���п��� ����
int GameManager::get_WinAndLose()
{
	return WinAndLose;
}

//Tank���� ����
void GameManager::set_Tank(int _num)
{
	Tank_Count = _num;
}

//Tank ���� ����
int GameManager::get_Tank()
{
	return Tank_Count;
}

//UpTank���� ����
void GameManager::set_UpTank(int _num)
{
	UpTank_Count = _num;
}

//UpTank���� ����
int GameManager::get_UpTank()
{
	return UpTank_Count;
}

//�� �ѱ��
void GameManager::ScenePlus()
{
	NextStage++;
}

//���� �������� ����
int GameManager::get_NextStage()
{
	return NextStage;
}

//�μ��� �� ���� ����
void GameManager::add_Destroy()
{
	Destroy_Count++;

	if (Destroy_Count == MAX_ENEMY)
	{
		WinAndLose = WIN;
	}
}

//�÷��̾� ����
void GameManager::set_PlayerDie(bool _die)
{
	PlayerDie = _die;
}

//�÷��̾� ����
bool GameManager::get_PlayerDie()
{
	return PlayerDie;
}

//�Ҹ���
GameManager::~GameManager()
{

}