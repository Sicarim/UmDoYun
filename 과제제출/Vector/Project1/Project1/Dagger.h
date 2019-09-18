#pragma once
#include "Mecro.h"

class Dagger
{
private:
	vector<string> Dagger_List;
	vector<string>::iterator iter;
public:
	Dagger(); 
	void Dagger_Info_Init(); //대거 정보 기입
	void Show_Dagger(); //저장된 대거 보기
	void Dagger_Shop(); //대거상점
	void Dagger_Add(); //대거 추가하기
	void Dagger_All_Delete(); //자료 모두 삭제
	~Dagger();
};