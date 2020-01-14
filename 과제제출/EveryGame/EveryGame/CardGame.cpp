#include "CardGame.h"
#include "UIManager.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//생성자
CardGame::CardGame()
{

}

//게임 초기화
void CardGame::Init()
{
	//카드Vector를 MAX_CARD(100장)만큼 미리 공간을 잡는다.
	m_vCard.reserve(MAX_CARD);
	//CardGame Class를 초기화한다.
	GameManager::get_Instance()->CardGame_Init();
	Card_Count = 0;
	InitBitMap(); //카드 등록
}

//키 입력
bool CardGame::Input(float _fETime)
{
	//Card
	m_Command = m_Input.CommandInput();
	//m_Card의 동작을 호출한다
	if (m_Command)
	{
		//m_Command의 정해진 행동을 호출한다(m_vCard[CardCount]) Command패턴을 활용
		m_Command->excute(*m_vCard[Card_Count]);
	}

	return false;
}

//Update함수
void CardGame::Update(float _fETime)
{
	//GameManager의 Update문을 실행
	GameManager::get_Instance()->Update(_fETime);

	//화면에 점수를 지속적으로 등록한다.
	wsprintf(Card_Score, "%d", GameManager::get_Instance()->get_Score());
	m_Text.Init(Card_Score, 180, 0, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	//현재 가장 위에 올라가있는 카드를 Update한다
	Card_Count = GameManager::get_Instance()->get_CardCount();
	m_vCard[Card_Count]->Update(_fETime);
}

//그리기
void CardGame::Draw()
{	
	//배경화면
	m_Text.Draw();
	//카드
	m_vCard[Card_Count]->Draw();
	//UI Effect
	GameManager::get_Instance()->ManagerUI_Draw();
}

//삭제 함수
void CardGame::Release()
{
	m_vCard.clear();
	Card_Count = 0;
	GameManager::get_Instance()->CardGame_Release();
}

//카드 등록
void CardGame::InitBitMap()
{
	//랜덤으로 카드 담기
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

//소멸자
CardGame::~CardGame()
{

}