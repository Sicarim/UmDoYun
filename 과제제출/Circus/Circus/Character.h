#pragma once
#include "Mecro.h"

class Character
{
private:
	float pCur_x; //ĳ���� ������ġ(x)
	float pCur_y; //ĳ���� ������ġ(y)
	float m_fJumpX;
	float m_fJumpY;
	float p_CurJumpTime; //ĳ���� ���� �ð�

	STATE m_pState;
	STATE isMoving;
public:
	Character(); //������

	void Move(HWND hWnd, float _dftime); //ĳ���� �����̱�

	float get_charX(); //x��ǥ ��ȯ
	float get_charY(); //y��ǥ ��ȯ
	STATE get_isMoving();
	~Character(); //�Ҹ���
};