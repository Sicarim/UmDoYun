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
	void Player_Init(int This_X, int This_Y); //�÷��̾� �ʱ�ȭ
	int Serch_Mine(); //���� ã��.
	void Move_Check(); //Ŀ�� �����̱� üũ
	void Re_Draw(); //������ Ŀ�� �ٽ� �׸���
	void Input_Plag(); //��� �׸���

	//�÷��̾ Ŭ���� ��ġ
	int get_First_X();
	int get_First_Y();
	~Player();
};