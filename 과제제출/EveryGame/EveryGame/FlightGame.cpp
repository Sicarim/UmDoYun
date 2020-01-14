#include "FlightGame.h"
#include "UIManager.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//������
FlightGame::FlightGame()
{

}

//���� �ʱ�ȭ
void FlightGame::Init()
{
	//GameManager���� �ʱ�ȭ�� ����
	GameManager::get_Instance()->Init();
	GameManager::get_Instance()->FlightGame_Init();
	curTime = 0.0f;
	//������ StarPool, BulletPool�� �ʱ�ȭ
	m_Flight.Init(FLIGHT_X, FLIGHT_Y);
	m_BackGroundColl.Init_Collider("BackGround", 0, 90, 410, 520);
	m_BulletPool.Init();
	m_StarPool.Init();
}

//Ű �Է�
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

//Update�Լ�
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

	//���� ǥ��
	wsprintf(Flight_Score, "%d", GameManager::get_Instance()->get_Score());
	m_Text.Init(Flight_Score, 180, 0, 50, 255, 255, 255, TRANSPARENT, "���� ���");
}

//�׸���
void FlightGame::Draw()
{
	//BackGround
	m_BackGroundColl.Draw_Collider();
	//���ȭ��
	m_Text.Draw();
	//StarPool�׸���
	m_StarPool.Draw();
	//BulletPool �׸���
	m_BulletPool.Draw();
	//Flight
	m_Flight.Draw();
	//UI Effect
	GameManager::get_Instance()->ManagerUI_Draw();
}

//���� �Լ�
void FlightGame::Release()
{
	Flight_Count = 0;
	curTime = 0.0f;
	m_StarPool.Release();
	m_BulletPool.Release();
	GameManager::get_Instance()->Release();
	GameManager::get_Instance()->FlightGame_Release();
}

//�Ҹ���
FlightGame::~FlightGame()
{

}