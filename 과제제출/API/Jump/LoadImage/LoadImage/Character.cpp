#include "Character.h"
#include "BitMapManager.h"

//������
Character::Character()
{
	posX = 0;
	posY = 0;
	Jump_Cor = 0;
	jump_count = 0;
	ch_dir = true;
	jump = true;
	//Gak = 2 * M_PI / 100;
	Gak = 2 * 3.141592 / 100;

	vx = 0.0f;
	vy = 0.0f;	
}

//ĳ���� �ʱ�ȭ
void Character::Char_Init(HWND hWnd)
{
	BitMapManager::get_Instence()->Init(hWnd); //ĳ���� �ʱ�ȭ
}

//ĳ���� �ȱ�
void Character::Char_Working(HDC hdc, int _keyx)
{
	if (ch_dir)
	{
		posY = 3;
	}

	else if (!ch_dir)
	{
		posY = 2;
	}

	if (abs(_keyx % 4) == 0)
	{
		posX = 0;
		BitMapManager::get_Instence()->Draw(hdc, posX, posY, _keyx); //ĳ���� �׸���
	}

	else if (abs(_keyx % 4) == 1)
	{
		posX = 1;
		BitMapManager::get_Instence()->Draw(hdc, posX, posY, _keyx); //ĳ���� �׸���
	}

	else if (abs(_keyx % 4) == 2)
	{
		posX = 2;
		BitMapManager::get_Instence()->Draw(hdc, posX, posY, _keyx); //ĳ���� �׸���
	}

	else if (abs(_keyx % 4) == 3)
	{
		posX = 3;
		BitMapManager::get_Instence()->Draw(hdc, posX, posY, _keyx); //ĳ���� �׸���
	}
}

//ĳ���� ����
void Character::Char_Jump(HWND hWnd, int _chx)
{
	HDC hdc = GetDC(hWnd);
	jump_count++;
	jump = true;

	if (ch_dir)
	{
		posY = 3;
	}

	else if (!ch_dir)
	{
		posY = 2;
	}

	Jump_Cor += 1;
	vx = -cos(jump_count * Gak);
	vy = -sin(jump_count * Gak);

	BitMapManager::get_Instence()->Draw(hdc, posX, posY, _chx + vx, JUMPPOWER * vy);


	if (jump_count == JUMPMAX)
	{
		jump_count = 0;
		KillTimer(hWnd, 1);
		jump = false;
	}
}

//����
void Character::Release()
{
	BitMapManager::del_Instence();
}

//�Ҹ���
Character::~Character()
{
	
}