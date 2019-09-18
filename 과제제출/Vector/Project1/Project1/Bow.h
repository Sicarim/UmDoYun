#pragma once
#include "Mecro.h"

class Bow
{
private:
	vector<string> Bow_List;
	vector<string>::iterator iter;
public:
	Bow();
	void Bow_Info_Init(); //보우 정보 기입
	void Show_Bow(); //저장된 보우 보기
	void Bow_Shop(); //보우 상점
	void Bow_Add(); //보우 추가하기
	void Bow_All_Delete(); //데이터 전부 삭제
	~Bow();
};