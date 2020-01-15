#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class Interface
{
private:
	MapDraw m_Draw;
public:
	Interface(); //생성자
	void Start_View(); //메인 시작 화면
	void Main_Game_View(); //지뢰찾기 화면
	void Player_Win(); //플레이어가 이겼다!
	void Player_Die(); //플레이어가 죽었다!
	~Interface(); //소멸자

};