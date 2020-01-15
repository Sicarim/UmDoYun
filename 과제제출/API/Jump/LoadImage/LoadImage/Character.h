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
	Character(); //������

	void Char_Init(HWND hWnd); //ĳ���� �ʱ�ȭ
	void Char_Working(HDC hdc, int _keyx); //ĳ���� �ȱ�
	void Char_Jump(HWND hWnd, int _chx); //ĳ���� ����
	void Release(); //����

	~Character(); //�Ҹ���

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