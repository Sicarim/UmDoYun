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
	float Save_Point;

	STATE m_pState;
	STATE isMoving;
public:
	Character(); //������

	void Char_Init(); //ĳ���� �ʱ�ȭ
	void Move(HWND hWnd, float _dftime); //ĳ���� �����̱�
	void Make_SavePoint(); //���̺� ����Ʈ �����

	float get_charX(); //x��ǥ ��ȯ
	float get_charY(); //y��ǥ ��ȯ
	STATE get_isMoving();
	~Character(); //�Ҹ���
};