#pragma once
#include "Mecro.h"
#include "Card.h"
#include "Singleton.h"

class CardManager : public Singleton <CardManager>
{
private:
	vector<Card> m_Card;
	vector<Card> m_black;
	Card* tmp_card;
	Card* Black_Card;

	int setX;
	int setY;
public:
	//생성자
	CardManager();

	void All_Init(HWND hWnd, HINSTANCE _hInst); //모두 초기화
	vector<Card> get_Card(); //Card 리턴
	vector<Card> get_BlackCard(); //검정 카드 리턴

	//소멸자
	~CardManager();

};