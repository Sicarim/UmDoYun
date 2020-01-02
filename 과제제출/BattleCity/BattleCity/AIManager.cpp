#include "AIManager.h"
#include "GameManager.h"

//������
AIManager::AIManager()
{

}

//��ã�� �ʱ�ȭ
void AIManager::Init()
{
	Count = 0;
	ReTime = 0.0f;
	m_vEnemy.clear();
	m_vEnemy.reserve(2);
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
	ReTime += _fETime;

	if (ReTime > 3.0f)
	{
		ReTime = 0.0f;
		if (Count < MAX_ENEMY)
		{
			Count++;
		}
	}

	for(int i = 0; i < Count; i++)
	{
		m_vEnemy[i]->Update(_fETime);
	}
}

//Ű�Է�
bool AIManager::Input()
{
	//m_Command = Enemy_behavior[LOOK_DOWN];

	/*if (m_Command)
	{
		m_Command->excute(*m_vEnemy[1]);
	}*/

	return false;
}

//Draw �Լ�
void AIManager::Draw()
{
	for (int i = 0; i < Count; i++)
	{
		m_vEnemy[i]->Draw();
	}
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
