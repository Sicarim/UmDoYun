#pragma once
#include "Mecro.h"
#include "BitMap.h"

class Animal
{
private:
	//각종 비트맵 선언
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
	Animal(); //생성자

	void All_Init(HWND hWnd, HINSTANCE _hInst); //모든 그림 초기화
	void All_Draw(HDC hdc); //모든 그림 그리기
	void Send_Message(HWND hWnd, int _mouseX, int _mouseY); //메시지 전송
	
	~Animal(); //소멸자
};
