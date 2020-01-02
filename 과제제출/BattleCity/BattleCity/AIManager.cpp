#include "AIManager.h"
#include "GameManager.h"

//생성자
AIManager::AIManager()
{

}

//길찾기 초기화
void AIManager::Init()
{
	Count = 0;
	ReTime = 0.0f;
	m_vEnemy.clear();
	m_vEnemy.reserve(2);
	Enemy_behavior.reserve(5);
	//적 만들기
	m_vEnemy = GameManager::get_Instance()->Make_Enemy();

	//적 행동 모음집 만들기
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

//Update함수
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

//키입력
bool AIManager::Input()
{
	//m_Command = Enemy_behavior[LOOK_DOWN];

	/*if (m_Command)
	{
		m_Command->excute(*m_vEnemy[1]);
	}*/

	return false;
}

//Draw 함수
void AIManager::Draw()
{
	for (int i = 0; i < Count; i++)
	{
		m_vEnemy[i]->Draw();
	}
}


//Release() 함수
void AIManager::Release()
{

}

//길찾기
void AIManager::Find_Way()
{

}


//소멸자
AIManager::~AIManager()
{

}
