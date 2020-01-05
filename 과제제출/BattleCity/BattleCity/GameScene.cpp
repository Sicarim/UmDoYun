#include "GameScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "AIManager.h"
#include "MapTool.h"
#include "UIManager.h"

//생성자
GameScene::GameScene()
{

}

//초기화(override)
void GameScene::Init(HWND hWnd)
{
	//몬스터 갯수 초기화
	Health_Count = MAX_ENEMY;

	tmp_Count = 0;
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (i < 10)
		{
			Health[i].posx = 960;
			Health[i].posy = 50 + tmp_Count * 30;
			tmp_Count++;
		}
		else
		{
			Health[i].posx = 990;
			Health[i].posy = 50 + tmp_Count * 30;
			tmp_Count++;
		}
		if (i == 9)
		{
			tmp_Count = 0;
		}
	}

	m_Command = NULL;
	//검정색 배경화면 만들기
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);
	//키 등록
	GameManager::get_Instance()->Key_Init();
	//콜라이더 범위 그리기
	GameManager::get_Instance()->All_Draw();
	//맵 만들기
	m_Map.Init(W_COUNT, H_COUNT);
	//플레이어 만들기
	m_pPlayer.Init(4, 13);
	//몬스터 갯수
	m_EnemyHealth = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\enemy_icon.bmp");
	m_tmpBlock = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\block08.bmp");
	//적 초기화하기
	AIManager::get_Instance()->Init();
}

//키입력(override)
bool GameScene::Input(float _fETime)
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
void GameScene::Update(float _fETime)
{
	//Enemy
	AIManager::get_Instance()->Update(_fETime);
	//Map
	m_Map.Update(_fETime); //맵을 지속적으로 Update
	//Player
	m_pPlayer.Update(_fETime);

	/*wsprintf(buf, "Grid x: %d", GameManager::get_Instance()->get_CurrentX());
	DoEngine::UIManager::get_Instance()->AddText(buf, 0, 0, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");

	wsprintf(buf2, "Grid y: %d", GameManager::get_Instance()->get_CurrentY());
	DoEngine::UIManager::get_Instance()->AddText(buf2, 0, 60, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");

	wsprintf(buf3, "Real x: %d", GameManager::get_Instance()->get_RealX());
	DoEngine::UIManager::get_Instance()->AddText(buf3, 0, 120, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");

	wsprintf(buf4, "Real y: %d", GameManager::get_Instance()->get_RealY());
	DoEngine::UIManager::get_Instance()->AddText(buf4, 0, 180, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");*/
}

//블럭 갯수 24칸, 2칸 기준 12블럭
//Draw 함수(override)
void GameScene::Draw(HDC hdc)
{
	//배경화면 그리기
	m_BlackBG->Draw(0, 0);

	//배경 블럭 그리기(왼쪽)
	for (int i = 0; i < 15; i++)
	{
		m_tmpBlock->Draw(0, 10 + i * 50, OBJECT_COL, OBJECT_COL);
	}

	//배경 블럭 그리기(오른쪽)
	for (int i = 0; i < 15; i++)
	{
		m_tmpBlock->Draw(955, 10 + i * 50, OBJECT_COL, OBJECT_COL);
	}

	//몬스터 목숨 카운트
	for (int i = 0; i < Health_Count - GameManager::get_Instance()->get_HealthCount(); i++)
	{
		m_EnemyHealth->Draw(Health[i].posx, Health[i].posy, 1.5, 1.5);
	}

	//플레이어 그리기
	m_pPlayer.Draw();
	//맵 만들기
	m_Map.Draw();
	//적 그리기
	AIManager::get_Instance()->Draw();
}

//Release() 함수(override)
void GameScene::Release()
{

}

//소멸자
GameScene::~GameScene()
{

}