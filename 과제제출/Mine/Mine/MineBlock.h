#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

class MineBlock
{
private:
	DoEngine::BitMap* m_pMine;
	int Pos_x;
	int Pos_y;

public:
	MineBlock(); //생성자

	void Init(); //초기화
	void Draw(); //그리기(overloading)
	void Draw(int _x, int _y); //그리기(overloading)

	int get_PosX(); //x좌표 리턴
	void set_Posx(int _x); //x값 입력

	int get_PosY(); //Y좌표 리턴
	void set_Posy(int _y); //y값 입력

	~MineBlock(); //소멸자
};