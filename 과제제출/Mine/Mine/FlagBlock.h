#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

class FlagBlock
{
private:
	DoEngine::BitMap* m_pFlag; //깃발 등록
	int Pos_x; //클릭한 x 좌표
	int Pos_y; //클릭한 y 좌표
	bool FlagDraw_Check;

public:
	FlagBlock(); //생성자
	
	void Init(); //초기화 함수
	void Draw(); //그리기(overloading)
	void Draw(int _x, int _y); //그리기(overloading)

	int get_PosX(); //x좌표 리턴
	void set_Posx(int _x); //x값 입력

	int get_PosY(); //Y좌표 리턴
	void set_Posy(int _y); //y값 입력

	bool get_FlagCheck(); //플래그 그리기 체크

	~FlagBlock(); //소멸자
};