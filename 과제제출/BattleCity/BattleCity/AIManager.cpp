#include "AIManager.h"
#include "GameManager.h"

//������
AIManager::AIManager()
{

}

//��ã�� �ʱ�ȭ
void AIManager::Init()
{
	m_vEnemy.clear();
	m_vEnemy.reserve(MAX_ENEMY);
	Enemy_behavior.reserve(5);
	//�� �����
	m_vEnemy = GameManager::get_Instance()->Make_Enemy();
	
	//�� �ൿ ������ �����
	tmp_Command = new DoEngine::UpCommand;
	Enemy_behavior.push_back(tmp_Command);

	tmp_Command = new DoEngine::LeftCommand;
	Enemy_behavior.push_back(tmp_Command);

	tmp_Command = new DoEngine::RightCommand;
	Enemy_behavior.push_back(tmp_Command);

	tmp_Command = new DoEngine::DownCommand;
	Enemy_behavior.push_back(tmp_Command);

	tmp_Command = new DoEngine::AttackCommand;
	Enemy_behavior.push_back(tmp_Command);

}

//Update�Լ�
void AIManager::Update(float _fETime)
{
	m_vEnemy[1]->Update(_fETime);
}

//Ű�Է�
bool AIManager::Input()
{
	m_Command = Enemy_behavior[LOOK_RIGHT];

	if (m_Command)
	{
		m_Command->excute(*m_vEnemy[1]);
	}
	return false;
}

//Draw �Լ�
void AIManager::Draw()
{
	m_vEnemy[1]->Draw();
}


//Release() �Լ�
void AIManager::Release()
{

}

//��ã��
void AIManager::Find_Way()
{

}


//�Ҹ���
AIManager::~AIManager()
{

}
