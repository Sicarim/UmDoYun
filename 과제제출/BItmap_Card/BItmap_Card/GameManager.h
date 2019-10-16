#pragma once
#include "Mecro.h"
#include "Card.h"
#include "Singleton.h"

class GameManager : public Singleton <GameManager>
{
private:
	vector<Card> tmp_card;
	vector<Card> tmp_black;
	int ClickRecord[2] = { 100, 100};

	int x;
	int y;
	int select_One;
	int select_Two;
	bool Answer;

	int Card_ID;

public:
	//������
	GameManager();

	void Card_Shffle(); //ī�� ����
	void All_Draw(HDC hdc); //��� �׸� �׸���
	void ID_Check(HWND hWnd, int _mouseX, int _mouseY); //ID Ȯ��
	void Click(HWND hWnd, int _num); //Ŭ���ϱ�
	void Record_Click(HWND hWnd); //Ŭ�� ����ϱ�

	void Answer_Check(HWND hWnd); //���� üũ
	
	//�Ҹ���
	~GameManager();

	inline int get_ID()
	{
		return Card_ID;
	}

	inline void set_ID(int num)
	{
		Card_ID = num;
	}
};