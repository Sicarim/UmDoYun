#pragma once
#include "Mecro.h"

class Sword
{
private:
	vector<string> Sword_List;
	vector<string>::iterator iter;
public:
	Sword();
	void Sword_Info_Init(); //�ҵ� ���� ����
	void Show_Sword(); //����� �ҵ� ����
	void Sword_Shop(); //�ҵ� ����
	void Sword_Add(); //�ҵ� �߰��ϱ�
	void Sword_All_Delete(); //�ҵ� �����ϱ�
	~Sword();
};