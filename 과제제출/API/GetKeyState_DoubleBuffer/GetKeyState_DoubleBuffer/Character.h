#pragma once
#include "Mecro.h"

class Character
{
private:
	int curX, curY;
	int ch_dir;
	int jump_count;
	int Chr_Shape;
	bool isJump;
	double Gak;

	float vx;
	float vy;
public:
	Character(); //������

	void Char_Init(HWND hWnd, int _posx, int _posy); //ĳ���� �ʱ�ȭ
	void Char_Draw(HWND hWnd); //ĳ���� �׸���
	void Char_Working(HWND hWnd); //ĳ���� �ȱ�
	void Char_Jump(HWND hWnd); //ĳ���� ����

	~Character(); //�Ҹ���
};