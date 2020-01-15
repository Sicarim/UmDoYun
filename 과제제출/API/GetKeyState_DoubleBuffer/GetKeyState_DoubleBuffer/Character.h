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
	Character(); //생성자

	void Char_Init(HWND hWnd, int _posx, int _posy); //캐릭터 초기화
	void Char_Draw(HWND hWnd); //캐릭터 그리기
	void Char_Working(HWND hWnd); //캐릭터 걷기
	void Char_Jump(HWND hWnd); //캐릭터 점프

	~Character(); //소멸자
};