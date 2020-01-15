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
	//생성자
	GameManager();

	void Card_Shffle(); //카드 섞기
	void All_Draw(HDC hdc); //모든 그림 그리기
	void ID_Check(HWND hWnd, int _mouseX, int _mouseY); //ID 확인
	void Click(HWND hWnd, int _num); //클릭하기
	void Record_Click(HWND hWnd); //클릭 기록하기

	void Answer_Check(HWND hWnd); //정답 체크
	
	//소멸자
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