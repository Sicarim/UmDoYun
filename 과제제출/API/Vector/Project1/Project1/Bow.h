#pragma once
#include "Mecro.h"

class Bow
{
private:
	vector<string> Bow_List;
	vector<string>::iterator iter;
public:
	Bow();
	void Bow_Info_Init(); //���� ���� ����
	void Show_Bow(); //����� ���� ����
	void Bow_Shop(); //���� ����
	void Bow_Add(); //���� �߰��ϱ�
	void Bow_All_Delete(); //������ ���� ����
	~Bow();
};