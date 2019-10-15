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

	~CardGame(); //소멸자

};