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
	if (Sword_List.empty())
	{
		cout << "No Data" << endl;
	}

	else
	{
		for (iter = Sword_List.begin(); iter != Sword_List.end(); iter++)
		{
			cout << *iter << endl << endl;
		}
	}

	system("pause");
}

//�ҵ� �߰��ϱ�
void Sword::Sword_Add()
{
	string tmp_Name = "";
	string Damege = "";
	string Gold = "";
	string newSword = "";

	cout << "�ҵ� �̸� �Է� : ";
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

//�ڷ� ��� ����
void Sword::Sword_All_Delete()
{
	cout << "Warring!!!!!!!!" << endl;
	cout << "�ڷḦ ��� �����մϴ�." << endl;
	Sword_List.clear();
	system("pause");
}

void Sword::Sword_Shop()
{
	int iSelect = 0;
	while (1)
	{
		system("cls");
		cout << "1. �ҵ� ����Ʈ ���� " << endl;
		cout << "2. �ҵ� �߰��ϱ� " << endl;
		cout << "3. �ڷ� ��� ����" << endl;
		cout << "4. ���ư���" << endl;
		cout << "���� : ";

		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Show_Sword();
			break;
		case 2:
			Sword_Add();
			break;
		case 3:
			Sword_Add();
			break;
		case 4:
			return;
		}
	}
}

//�Ҹ���
Sword::~Sword()
{
}