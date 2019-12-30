#include "TitleScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "AIManager.h"
#include "MapTool.h"

//생성자
TitleScene::TitleScene()
{

}

//초기화(override)
void TitleScene::Init(HWND hWnd)
{
	m_Command = NULL;
	//검정색 배경화면 만들기
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);
	//키 등록
	GameManager::get_Instance()->Key_Init();
	//콜라이더 범위 그리기
	GameManager::get_Instance()->All_Draw();
	//맵 만들기
	m_Map.Init(W_COUNT + 1, H_COUNT);
	//플레이어 만들기
	m_pPlayer.Init(4, 13);
	//적 초기화하기
	AIManager::get_Instance()->Init();

	/*m_vEnemy.clear();
	m_vEnemy.reserve(MAX_ENEMY);*/
	//적 만들기
	//m_vEnemy = GameManager::get_Instance()->Make_Enemy();
}

//키입력(override)
bool TitleScene::Input(float _fETime)
{
	//종료
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	//Player
	m_Command = m_Input.CommandInput();

	if (m_Command)
	{
		m_Command->excute(m_pPlayer);
	}

	//Enemy
	AIManager::get_Instance()->Input();

	return false;
}

//Update함수(override)
void TitleScene::Update(float _fETime)
{
	//Enemy
	AIManager::get_Instance()->Update(_fETime);
	//Player
	m_pPlayer.Update(_fETime);
	//Map
	m_Map.Update(_fETime); //맵을 지속적으로 Update
}

//블럭 갯수 24칸, 2칸 기준 12블럭
//Draw 함수(override)
void TitleScene::Draw(HDC hdc)
{
	m_BlackBG->Draw(0, 0);
	//배경화면 그리기
	m_Map.Draw();

	AIManager::get_Instance()->Draw();
	m_pPlayer.Draw();
}

//Release() 함수(override)
void TitleScene::Release()
{

}

//소멸자
TitleScene::~TitleScene()
{

}