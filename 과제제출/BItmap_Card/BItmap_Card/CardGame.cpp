#include "CardGame.h"
#include "GameManager.h"
#include "CardManager.h"

//������
CardGame::CardGame()
{
	mouseX = 0;
	mouseY = 0;
}

//ī�� Ŭ��
void CardGame::Click_Card(HWND hWnd, int _mouseX, int _mouseY)
{
	mouseX = _mouseX;
	mouseY = _mouseY;

	GameManager::get_Instence()->ID_Check(hWnd, mouseX, mouseY);
}

//�Ҹ���
CardGame::~CardGame()
{

}