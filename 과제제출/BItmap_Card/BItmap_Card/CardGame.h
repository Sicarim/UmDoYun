#pragma once
#include "Mecro.h"

class CardGame
{
private:
	int mouseX;
	int mouseY;

public:
	CardGame(); //������

	void Click_Card(HWND hWnd, int _mouseX, int _mouseY); //ī�� Ŭ��

	~CardGame(); //�Ҹ���

};