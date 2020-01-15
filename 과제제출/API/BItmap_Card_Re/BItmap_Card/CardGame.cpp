#include "CardGame.h"
#include "GameManager.h"
#include "BitMapManager.h"

//생성자
CardGame::CardGame()
{
	mouseX = 0;
	mouseY = 0;
}

//게임 초기화
void CardGame::Game_Init(HWND hWnd, HINSTANCE _hInst)
{
	BitMapManager::get_Instence()->All_Init(hWnd, _hInst);
	GameManager::get_Instence()->Card_Shuffle();
}

//카드 클릭
void CardGame::Click_Card(HWND hWnd, int _mouseX, int _mouseY)
{
	mouseX = _mouseX;
	mouseY = _mouseY;

	GameManager::get_Instence()->ID_Check(hWnd, mouseX, mouseY);
}

//게임 메모리 삭제
void CardGame::Release_Game()
{
	GameManager::del_Instence();
	BitMapManager::del_Instence();
}

//소멸자
CardGame::~CardGame()
{

}