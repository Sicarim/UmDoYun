#include "Sword.h"

//������
Sword::Sword()
{

}

//�ҵ� ���� ����
void Sword::Sword_Info_Init()
{
	Sword_List.push_back("�� \t<���ݷ� : 10, ���� : 10 Gold>");
	Sword_List.push_back("��ȭ �� \t<���ݷ� : 50, ���� : 50 Gold>");
	Sword_List.push_back("���� ��ī������ \t<���ݷ� : 110, ���� : 110 Gold>");
	Sword_List.push_back("ī���� ���� \t<���ݷ� : 170, ���� : 170 Gold>");
	Sword_List.push_back("�ֵ��ν��� ���� \t<���ݷ� : 200, ���� : 200 Gold>");
}

//����� �ҵ� ����
void Sword::Show_Sword()
{
	for (iter = Sword_List.begin(); iter != Sword_List.end(); iter++)
	{
		cout << *iter << endl << endl;
	}
	system("pause");
}

//�ҵ� ����
void Sword::Sword_Shop()
{

}

//�ҵ� �߰��ϱ�
void Sword::Sword_Add()
{
	string tmp_Name = "";
	string Damege = "";
	string Gold = "";
	string newSword = "";

	cout << "��� �̸� �Է� : ";
	cin >> tmp_Name;
	cout << "���ݷ� �Է� : ";
	cin >> Damege;
	cout << "��� �Է� : ";
	cin >> Gold;

	newSword = tmp_Name + " \t" + "<���ݷ� : " + Damege + "���� : " + Gold + " Gold>";
	Sword_List.push_back(newSword);

	//���� �߰� �� sort �ѹ�(��������)
	sort(Sword_List.begin(), Sword_List.end(), less<string>());
}

//�ҵ� �˻��ϱ�
void Sword::Sword_Serch()
{

}

//�Ҹ���
Sword::~Sword()
{
}