#pragma once
#include "Mecro.h"

class Player
{
private:
	int First_X;
	int First_Y;
	string My_sCursor;
	string My_sPlag;
public:
	Player();
	void Player_Init(int This_X, int This_Y); //플레이어 초기화
	int Serch_Mine(); //마인 찾기.
	void Move_Check(); //커서 움직이기 체크
	void Re_Draw(); //움직인 커서 다시 그리기
	void Input_Plag(); //깃발 그리기

	//플레이어가 클릭한 위치
	int get_First_X();
	int get_First_Y();
	~Player();
};