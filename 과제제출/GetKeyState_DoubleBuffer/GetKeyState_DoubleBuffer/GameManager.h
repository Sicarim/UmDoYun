#pragma once
#include "Mecro.h"
#include "Singleton.h"

class GameManager : public Singleton<GameManager>
{
private:
public:
	GameManager(); //������

	void All_Init(); //���� �ʱ�ȭ
	void All_Release(); //���� ����

	~GameManager(); //�Ҹ���
};