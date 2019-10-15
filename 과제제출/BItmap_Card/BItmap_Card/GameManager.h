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
	//생성자
	GameManager();

	void Card_Shffle(); //카드 섞기
	void All_Draw(HDC hdc); //모든 그림 그리기
	void ID_Check(HWND hWnd, int _mouseX, int _mouseY); //ID 확인
	void Click(HWND hWnd, int _num); //클릭하기
	void StartTimer(HWND hWnd); //시간 흐르기

	void Answer_Check(int _id); //정답 체크
	void Erase_Card(HWND hWnd); //카드 지우기
	
	//소멸자
	~GameManager();
	
};