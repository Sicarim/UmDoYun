#pragma once
#include "Mecro.h"
#include "Card.h"
#include "Singleton.h"

class GameManager : public Singleton <GameManager>
{
private:
	vector<Card> tmp_card;
	Card black_Card;
	SYSTEMTIME st;

	int RangeCount;

	int x;
	int y;
	int select_One;
	int select_Two;
	int select_Count;
	bool Answer;

public:
	//������
	GameManager();

	void Card_Shffle(); //ī�� ����
	void All_Draw(HDC hdc); //��� �׸� �׸���
	void ID_Check(HWND hWnd, int _mouseX, int _mouseY); //ID Ȯ��
	void Click(HWND hWnd, int _num); //Ŭ���ϱ�
	void StartTimer(HWND hWnd); //�ð� �帣��

	void Answer_Check(int _id); //���� üũ
	void Erase_Card(HWND hWnd); //ī�� �����
	
	//�Ҹ���
	~GameManager();
	
};