#include "Character.h"
#include "BitMapManager.h"
void CALLBACK TimeJump(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
//생성자
Character::Character()
{
	curX = 0;
	curY = 0;
	jump_count = 0;
	ch_dir = DIR_FRONT;
	Chr_Shape = 0;
	Gak = 2 * 3.141592 / 100;
	isJump = false;

	vx = 0.0f;
	vy = 0.0f;
}

//캐릭터 초기화
void Character::Char_Init(HWND hWnd, int _posx, int _posy)
{
	BitMapManager::get_Instence()->Init(hWnd, _posx, _posy); //캐릭터 초기화
}

//캐릭터 그리기
void Character::Char_Draw(HWND hWnd)
{
	BitMapManager::get_Instence()->Draw(hWnd, curX, curY, Chr_Shape, ch_dir);
}

//캐릭터 걷기
void Character::Char_Working(HWND hWnd)
{
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		ch_dir = DIR_LEFT;
		curX -= SPEED;
		if (!isJump)
		{
			if (abs(curX % 4) == 0)
				Chr_Shape = 0;
			else if (abs(curX % 4) == 1)
				Chr_Shape = 1;
			else if (abs(curX % 4) == 2)
				Chr_Shape = 2;
			else if (abs(curX % 4) == 3)
				Chr_Shape = 3;
		}
		
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		ch_dir = DIR_RIGHT;
		curX += SPEED;
		if (!isJump)
		{
			if (abs(curX % 4) == 0)
				Chr_Shape = 0;
			else if (abs(curX % 4) == 1)
				Chr_Shape = 1;
			else if (abs(curX % 4) == 2)
				Chr_Shape = 2;
			else if (abs(curX % 4) == 3)
				Chr_Shape = 3;
		}
	}
	if (GetKeyState(VK_UP) & 0x8000)
	{
		ch_dir = DIR_BACK;
		curY -= SPEED;
		
		if (!isJump)
		{
			if (abs(curY % 4) == 0)
				Chr_Shape = 0;
			else if (abs(curY % 4) == 1)
				Chr_Shape = 1;
			else if (abs(curY % 4) == 2)
				Chr_Shape = 2;
			else if (abs(curY % 4) == 3)
				Chr_Shape = 3;
		}
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		ch_dir = DIR_FRONT;
		curY += SPEED;
		if (!isJump)
		{
			if (abs(curY % 4) == 0)
				Chr_Shape = 0;
			else if (abs(curY % 4) == 1)
				Chr_Shape = 1;
			else if (abs(curY % 4) == 2)
				Chr_Shape = 2;
			else if (abs(curY % 4) == 3)
				Chr_Shape = 3;
		}
	}

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		SetTimer(hWnd, 2, 10, TimeJump);
	}

	InvalidateRect(hWnd, NULL, false);
}

//캐릭터 점프
void Character::Char_Jump(HWND hWnd)
{
	isJump = true;
	jump_count++;
	vx = -cos(jump_count * Gak);
	vy = -sin(jump_count * Gak);

	//curX = curX + vx;
	curY += 5 * vy;
	Chr_Shape = 3;
	if (jump_count == JUMPMAX)
	{
		isJump = false;
		jump_count = 0;
		KillTimer(hWnd, 2);
	}
	InvalidateRect(hWnd, NULL, false);
}

//소멸자
Character::~Character()
{

}