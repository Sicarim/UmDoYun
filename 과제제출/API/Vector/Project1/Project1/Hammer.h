#pragma once
#include "Mecro.h"

class Hammer
{
private:
	vector<string> Hammer_List;
	vector<string>::iterator iter;
public:
	Hammer();
	void Hammer_Info_Init(); //�ظ� ���� ����
	void Show_Hammer(); //����� ����� ����
	void Hammer_Shop(); //�ظ� ����
	void Hammer_Add(); //�ظ� �߰��ϱ�
	void Hammer_All_Delete();
	~Hammer();
};