#pragma once
#include "Mecro.h"

class BitMap
{
private:
	HDC HideBackDC; //���� �׸� ���(��ȭ��)�� �غ�
	HBITMAP HideBitBackDC;
	HBITMAP HideOldDC;

	HDC g_PlayerDC, g_BackDC;
	HBITMAP g_btPlayer, g_btBack;
	HBITMAP g_btOldPlayer, g_btOldBack;
	BITMAP g_mapInfo;
	SIZE g_size;

	int curX;
	int curY;

public:
	BitMap(); //������

	void Bit_Init(HWND hWnd, int _posx, int _posy); //��Ʈ�� �ʱ�ȭ
	void Bit_Draw(HWND hWnd, int _posx, int _posy, int _shapex, int _shapey); //��Ʈ�� �׸���
	void Bit_Release(); //��Ʈ�� �����

	~BitMap(); //�Ҹ���
};