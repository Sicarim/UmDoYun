#include "CardManager.h"

//생성자
CardManager::CardManager()
{
	srand(time(NULL));
	m_Card.reserve(CARDMAX);
	setX = 30;
	setY = 30;
}

//모두 초기화
void CardManager::All_Init(HWND hWnd, HINSTANCE _hInst)
{
	HDC hdc = GetDC(hWnd);
	int bit_id = 101;

	for (int i = 0; i < CARDMAX; i++)
	{
		tmp_card = new Card;
		tmp_card->Init(hdc, _hInst, bit_id);
		m_Card.push_back(*tmp_card);
		bit_id++;

		if (i == 9)
		{
			bit_id = 101;
		}
	}

	//카드섞기
	random_shuffle(m_Card.begin(), m_Card.end());

	for (int i = 0; i < CARDMAX; i++)
	{
		m_Card[i].Range_Init(setX, setY);

		setX += 120;

		if (i == 9)
		{
			setX = 30;
			setY = 250;
		}
	}
	setX = 30;
	setY = 30;

	Black_Card = new Card;
	Black_Card->Init(hdc, _hInst, 111);
	Black_Card->Range_Init(setX, setY);
}

//Card 리턴
vector<Card> CardManager::get_Card()
{
	return m_Card;
}

//Black_Card 리턴
Card CardManager::get_BlackCard()
{
	return *Black_Card;
}

//소멸자
CardManager::~CardManager()
{
	m_Card.clear();

	if (tmp_card != NULL)
	{
		delete tmp_card;
	}
	tmp_card = NULL;
}