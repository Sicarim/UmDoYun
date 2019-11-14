#pragma once
#include "Mecro.h"
#include "Singleton.h"

class GameManager : public Singleton<GameManager>
{
private:
public:
	GameManager(); //생성자

	void All_Init(); //전부 초기화
	void All_Release(); //전부 삭제

	~GameManager(); //소멸자
};