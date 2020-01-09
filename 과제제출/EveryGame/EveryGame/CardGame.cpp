#include "CardGame.h"
#include "UIManager.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//������
CardGame::CardGame()
{

}

//���� �ʱ�ȭ
void CardGame::Init()
{
	m_vCard.reserve(MAX_CARD);
	GameManager::get_Instance()->CardGame_Init();
	Card_Count = 0;
	InitBitMap(); //ī�� ���
}

//Ű �Է�
bool CardGame::Input(float _fETime)
{
	//Card
	m_Command = m_Input.CommandInput();

	if (m_Command)
	{
		m_Command->excute(*m_vCard[Card_Count]);
	}

	return false;
}

//Update�Լ�
void CardGame::Update(float _fETime)
{
	GameManager::get_Instance()->Update(_fETime);

	wsprintf(Card_Score, "%d", GameManager::get_Instance()->get_Score());
	m_Text.Init(Card_Score, 180, 0, 50, 255, 255, 255, TRANSPARENT, "���� ���");

	Card_Count = GameManager::get_Instance()->get_CardCount();
	m_vCard[Card_Count]->Update(_fETime);
}

//�׸���
void CardGame::Draw()
{	
	//���ȭ��
	m_Text.Draw();
	//ī��
	m_vCard[Card_Count]->Draw();
	//UI Effect
	GameManager::get_Instance()->ManagerUI_Draw();
}

//���� �Լ�
void CardGame::Release()
{
	m_vCard.clear();
	Card_Count = 0;
	GameManager::get_Instance()->CardGame_Release();
}

//ī�� ���
void CardGame::InitBitMap()
{
	//�������� ī�� ���
	int tmp_Rand = 0;
	for (int i = 0; i < MAX_CARD; i++)
	{
		tmp_Rand = rand() % 4;

		if (tmp_Rand == BLUE)
		{
			Color_Card = new BlueCard;
			Color_Card->Init(CARD_X, CARD_Y);
		}
		else if (tmp_Rand == RED)
		{
			Color_Card = new RedCard;
			Color_Card->Init(CARD_X, CARD_Y);
		}
		else if (tmp_Rand == GREEN)
		{
			Color_Card = new GreenCard;
			Color_Card->Init(CARD_X, CARD_Y);
		}
		else if (tmp_Rand == YELLOW)
		{
			Color_Card = new YellowCard;
			Color_Card->Init(CARD_X, CARD_Y);
		}
		m_vCard.push_back(Color_Card);
	}
}

//�Ҹ���
CardGame::~CardGame()
{

}