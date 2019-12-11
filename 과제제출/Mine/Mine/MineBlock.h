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
	MineBlock(); //������

	void Init(); //�ʱ�ȭ
	void Draw(); //�׸���(overloading)
	void Draw(int _x, int _y); //�׸���(overloading)

	int get_PosX(); //x��ǥ ����
	void set_Posx(int _x); //x�� �Է�

	int get_PosY(); //Y��ǥ ����
	void set_Posy(int _y); //y�� �Է�

	~MineBlock(); //�Ҹ���
};