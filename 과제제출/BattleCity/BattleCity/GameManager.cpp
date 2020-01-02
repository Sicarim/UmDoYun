#include "GameManager.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "InputManager.h"
#include "ColliderManager.h"

//������
GameManager::GameManager()
{
	
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
	//���� ����
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_ESCAPE);
}

//���� �����
vector<DoEngine::Object*> GameManager::Make_Enemy()
{
	//�ӽ� ����
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

//�ı��Ǵ� ��� ����
int GameManager::get_BrokenCount()
{
	return Broken_Count;
}

//�� ��� ����
int GameManager::get_WaterCount()
{
	return Water_Count;
}

//�ν� �� ����
int GameManager::get_BushCount()
{
	return Bush_Count;
}

//��ö �� ����
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

//�Ҹ���
GameManager::~GameManager()
{

}