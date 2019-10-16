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
	//������
	CardManager();

	void All_Init(HWND hWnd, HINSTANCE _hInst); //��� �ʱ�ȭ
	vector<Card> get_Card(); //Card ����
	vector<Card> get_BlackCard(); //���� ī�� ����

	//�Ҹ���
	~CardManager();

};