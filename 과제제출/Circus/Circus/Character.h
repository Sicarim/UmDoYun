#pragma once
#include "Mecro.h"

class Character
{
private:
	float pCur_x; //캐릭터 현재위치(x)
	float pCur_y; //캐릭터 현재위치(y)
	float m_fJumpX;
	float m_fJumpY;
	float p_CurJumpTime; //캐릭터 점프 시간

	STATE m_pState;
	STATE isMoving;
public:
	Character(); //생성자

	void Move(HWND hWnd, float _dftime); //캐릭터 움직이기

	float get_charX(); //x좌표 반환
	float get_charY(); //y좌표 반환
	STATE get_isMoving();
	~Character(); //소멸자
};