#pragma once
#include "Mecro.h"

class Dagger
{
private:
	vector<string> Dagger_List;
	vector<string>::iterator iter;
public:
	Dagger(); 
	void Dagger_Info_Init(); //��� ���� ����
	void Show_Dagger(); //����� ��� ����
	void Dagger_Shop(); //��Ż���
	void Dagger_Add(); //��� �߰��ϱ�
	void Dagger_All_Delete(); //�ڷ� ��� ����
	~Dagger();
};