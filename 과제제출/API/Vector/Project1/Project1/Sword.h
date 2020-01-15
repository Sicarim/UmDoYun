#pragma once
#include "Mecro.h"

class Sword
{
private:
	vector<string> Sword_List;
	vector<string>::iterator iter;
public:
	Sword();
	void Sword_Info_Init(); //소드 정보 기입
	void Show_Sword(); //저장된 소드 보기
	void Sword_Shop(); //소드 상점
	void Sword_Add(); //소드 추가하기
	void Sword_All_Delete(); //소드 삭제하기
	~Sword();
};