#include "Character.h"
#include "BitMapManager.h"

//생성자
Character::Character()
{
	KeyX = 0;
	posX = 0;
	posY = 0;
	Jump_Cor = 0;
	jump_count = 0;
	ch_dir = true;
	jump = true;
}

//캐릭터 초기화
void Character::Char_Init(HWND hWnd)
{
	BitMapManager::get_Instence()->Init(hWnd); //캐릭터 초기화
}

//캐릭터 걷기
void Character::Char_Working(HDC hdc, int _keyx)
{
	KeyX = _keyx;
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
		BitMapManager::get_Instence()->Draw(hdc, posX, posY, _keyx); //캐릭터 그리기
	}

	else if (abs(_keyx % 4) == 1)
	{
		posX = 1;
		BitMapManager::get_Instence()->Draw(hdc, posX, posY, _keyx); //캐릭터 그리기
	}

	else if (abs(_keyx % 4) == 2)
	{
		posX = 2;
		BitMapManager::get_Instence()->Draw(hdc, posX, posY, _keyx); //캐릭터 그리기
	}

	else if (abs(_keyx % 4) == 3)
	{
		posX = 3;
		BitMapManager::get_Instence()->Draw(hdc, posX, posY, _keyx); //캐릭터 그리기
	}
}

//캐릭터 점프
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

	if (jump_count <= JUMPMAX)
	{
		Jump_Cor += 5;
		BitMapManager::get_Instence()->Draw(hdc, posX, posY, _chx, -Jump_Cor); //캐릭터 그리기
	}
	else
	{
		Jump_Cor -= 5;
		BitMapManager::get_Instence()->Draw(hdc, posX, posY, _chx, -Jump_Cor); //캐릭터 그리
	}

	if (Jump_Cor == 0)
	{
		jump_count = 0;
		KillTimer(hWnd, 1);
		jump = false;
	}
}

//삭제
void Character::Release()
{
	BitMapManager::del_Instence();
}

//소멸자
Character::~Character()
{
	
}