#pragma once
#include "Mecro.h"

class CardGame
{
private:
	int mouseX;
	int mouseY;

public:
	CardGame(); //생성자

	void Click_Card(HWND hWnd, int _mouseX, int _mouseY); //카드 클릭
	void Game_Init(HWND hWnd, HINSTANCE _hInst); //게임 초기화
	void Release_Game(); //게임 메모리 삭제

	~CardGame(); //소멸자
};