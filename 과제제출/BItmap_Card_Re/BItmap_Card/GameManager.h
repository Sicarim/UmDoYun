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
	//생성자
	GameManager();

	void Card_Shuffle(); //카드 섞기
	void ID_Check(HWND hWnd, int _mouseX, int _mouseY); //ID 확인
	void Click(HWND hWnd, int _num, int _setX, int _setY); //클릭하기
	void Record_Click(HWND hWnd, int _setX, int _setY); //클릭 기록하기

	void Answer_Check(HWND hWnd); //정답 체크
	
	//소멸자
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