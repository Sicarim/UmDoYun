#pragma once
#include "Mecro.h"
#include "Card.h"
#include "Singleton.h"

class CardManager : public Singleton <CardManager>
{
private:
	vector<Card> m_Card;
	Card* tmp_card;
	Card* Black_Card;

	int setX;
	int setY;
public:
	//������
	CardManager();

	void All_Init(HWND hWnd, HINSTANCE _hInst); //��� �ʱ�ȭ
	vector<Card> get_Card(); //Card ����
	Card get_BlackCard(); //���� ī�� ����

	//�Ҹ���
	~CardManager();

};