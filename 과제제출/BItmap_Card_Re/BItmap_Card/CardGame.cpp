#include "CardGame.h"
#include "GameManager.h"
#include "BitMapManager.h"

//������
CardGame::CardGame()
{
	mouseX = 0;
	mouseY = 0;
}

//���� �ʱ�ȭ
void CardGame::Game_Init(HWND hWnd, HINSTANCE _hInst)
{
	BitMapManager::get_Instence()->All_Init(hWnd, _hInst);
	GameManager::get_Instence()->Card_Shuffle();
}

//ī�� Ŭ��
void CardGame::Click_Card(HWND hWnd, int _mouseX, int _mouseY)
{
	mouseX = _mouseX;
	mouseY = _mouseY;

	GameManager::get_Instence()->ID_Check(hWnd, mouseX, mouseY);
}

//���� �޸� ����
void CardGame::Release_Game()
{
	GameManager::del_Instence();
	BitMapManager::del_Instence();
}

//�Ҹ���
CardGame::~CardGame()
{

}