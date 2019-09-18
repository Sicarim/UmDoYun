#pragma once
#include "Mecro.h"

class Hammer
{
private:
	vector<string> Hammer_List;
	vector<string>::iterator iter;
public:
	Hammer();
	void Hammer_Info_Init(); //해머 정보 기입
	void Show_Hammer(); //저장된 헤ㅐ머 보기
	void Hammer_Shop(); //해머 상점
	void Hammer_Add(); //해머 추가하기
	void Hammer_All_Delete();
	~Hammer();
};