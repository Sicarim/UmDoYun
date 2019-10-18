#pragma once
#include "Mecro.h"
#include "Singleton.h"

struct ClickRecord
{
	int ID;
	int x;
	int y;
};

class GameManager : public Singleton <GameManager>
{
private:
	int CardShuffle[CARDMAX];
	ClickRecord c_record[2];

	int select_One;
	int select_Two;
	bool Answer;

	int Card_ID;

public:
	//������
	GameManager();

	void Card_Shuffle(); //ī�� ����
	void ID_Check(HWND hWnd, int _mouseX, int _mouseY); //ID Ȯ��
	void Click(HWND hWnd, int _num, int _setX, int _setY); //Ŭ���ϱ�
	void Record_Click(HWND hWnd, int _setX, int _setY); //Ŭ�� ����ϱ�

	void Answer_Check(HWND hWnd); //���� üũ
	
	//�Ҹ���
	~GameManager();

	inline int get_ID()
	{
		return Card_ID;
	}

	inline void set_ID(int _ID)
	{
		Card_ID = _ID;
	}
};