#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class Interface
{
private:
	MapDraw m_Draw;
public:
	Interface(); //������
	void Start_View(); //���� ���� ȭ��
	void Main_Game_View(); //����ã�� ȭ��
	void Player_Win(); //�÷��̾ �̰��!
	void Player_Die(); //�÷��̾ �׾���!
	~Interface(); //�Ҹ���

};