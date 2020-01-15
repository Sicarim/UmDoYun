#pragma once
#include "Mecro.h"

class Character
{
private:
	int Jump_Cor;
	int posX, posY;
	
	bool ch_dir;
	int jump_count;
	bool jump;
	double Gak;

	float vx;
	float vy;
public:
	Character(); //생성자

	void Char_Init(HWND hWnd); //캐릭터 초기화
	void Char_Working(HDC hdc, int _keyx); //캐릭터 걷기
	void Char_Jump(HWND hWnd, int _chx); //캐릭터 점프
	void Release(); //삭제

	~Character(); //소멸자

	inline void set_direction(bool _dir)
	{
		ch_dir = _dir;
	}

	inline void set_Jump(bool _isjump)
	{
		jump = _isjump;
	}

	inline bool get_Jump()
	{
		return jump;
	}
};