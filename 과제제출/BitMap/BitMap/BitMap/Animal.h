#pragma once
#include "Mecro.h"
#include "BitMap.h"

class Animal
{
private:
	//���� ��Ʈ�� ����
	BitMap m_Dog;
	BitMap m_Tiger;
	BitMap m_Duck;
	BitMap m_Ele;
	BitMap m_BlackCow;
	BitMap m_Horse;
	BitMap m_Cat;
	BitMap m_Mongkey;
	BitMap m_Frog;
	BitMap m_Dak;

public:
	Animal(); //������

	void All_Init(HWND hWnd, HINSTANCE _hInst); //��� �׸� �ʱ�ȭ
	void All_Draw(HDC hdc); //��� �׸� �׸���
	void Send_Message(HWND hWnd, int _mouseX, int _mouseY); //�޽��� ����
	
	~Animal(); //�Ҹ���
};
