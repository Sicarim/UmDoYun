#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

class FlagBlock
{
private:
	DoEngine::BitMap* m_pFlag; //��� ���
	int Pos_x; //Ŭ���� x ��ǥ
	int Pos_y; //Ŭ���� y ��ǥ
	bool FlagDraw_Check;

public:
	FlagBlock(); //������
	
	void Init(); //�ʱ�ȭ �Լ�
	void Draw(); //�׸���(overloading)
	void Draw(int _x, int _y); //�׸���(overloading)

	int get_PosX(); //x��ǥ ����
	void set_Posx(int _x); //x�� �Է�

	int get_PosY(); //Y��ǥ ����
	void set_Posy(int _y); //y�� �Է�

	bool get_FlagCheck(); //�÷��� �׸��� üũ

	~FlagBlock(); //�Ҹ���
};