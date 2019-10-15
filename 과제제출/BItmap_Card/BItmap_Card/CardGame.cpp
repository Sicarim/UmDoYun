#include "CardGame.h"
#include "GameManager.h"
#include "CardManager.h"

//생성자
CardGame::CardGame()
{
	mouseX = 0;
	mouseY = 0;
}

//카드 클릭
void CardGame::Click_Card(HWND hWnd, int _mouseX, int _mouseY)
{
	mouseX = _mouseX;
	mouseY = _mouseY;

	GameManager::get_Instence()->ID_Check(hWnd, mouseX, mouseY);
}

//소멸자
CardGame::~CardGame()
{

}