#include "FlightGame.h"
#include "UIManager.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//생성자
FlightGame::FlightGame()
{

}

//게임 초기화
void FlightGame::Init()
{
	//GameManager에서 초기화를 실행
	GameManager::get_Instance()->Init();
	GameManager::get_Instance()->FlightGame_Init();
	curTime = 0.0f;
	//비행기와 StarPool, BulletPool을 초기화
	m_Flight.Init(FLIGHT_X, FLIGHT_Y);
	m_BackGroundColl.Init_Collider("BackGround", 0, 90, 410, 520);
	m_BulletPool.Init();
	m_StarPool.Init();
}

//키 입력
bool FlightGame::Input(float _fETime)
{
	//Flight
	m_Command = m_Input.CommandInput();

	if (m_Command)
	{
		m_Command->excute(m_Flight);
	}

	return false;
}

//Update함수
void FlightGame::Update(float _fETime)
{
	curTime += _fETime;
	GameManager::get_Instance()->Update(_fETime);
	//Star
	m_StarPool.Update(_fETime);
	//Bullet
	m_BulletPool.Update(_fETime);
	//Fight
	m_Flight.Update(_fETime);

	//점수 표기
	wsprintf(Flight_Score, "%d", GameManager::get_Instance()->get_Score());
	m_Text.Init(Flight_Score, 180, 0, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");
}

//그리기
void FlightGame::Draw()
{
	//BackGround
	m_BackGroundColl.Draw_Collider();
	//배경화면
	m_Text.Draw();
	//StarPool그리기
	m_StarPool.Draw();
	//BulletPool 그리기
	m_BulletPool.Draw();
	//Flight
	m_Flight.Draw();
	//UI Effect
	GameManager::get_Instance()->ManagerUI_Draw();
}

//삭제 함수
void FlightGame::Release()
{
	Flight_Count = 0;
	curTime = 0.0f;
	m_StarPool.Release();
	m_BulletPool.Release();
	GameManager::get_Instance()->Release();
	GameManager::get_Instance()->FlightGame_Release();
}

//소멸자
FlightGame::~FlightGame()
{

}