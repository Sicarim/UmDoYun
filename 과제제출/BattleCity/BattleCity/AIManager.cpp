#include "AIManager.h"
#include "GameManager.h"

//생성자
AIManager::AIManager()
{

}

//길찾기 초기화
void AIManager::Init()
{
	m_vEnemy.clear();
	m_vEnemy.reserve(MAX_ENEMY);
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
	m_vEnemy[1]->Update(_fETime);
}

//키입력
bool AIManager::Input()
{
	m_Command = Enemy_behavior[LOOK_RIGHT];

	if (m_Command)
	{
		m_Command->excute(*m_vEnemy[1]);
	}
	return false;
}

//Draw 함수
void AIManager::Draw()
{
	m_vEnemy[1]->Draw();
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
