#include "Bow.h"

//������
Bow::Bow()
{

}

//���� ���� ����
void Bow::Bow_Info_Init()
{
	Bow_List.push_back("Ȱ \t<���ݷ� : 10, ���� : 10 Gold>");
	Bow_List.push_back("��ȭ ����� \t<���ݷ� : 50, ���� : 50 Gold>");
	Bow_List.push_back("â���� ������ \t<���ݷ� : 110, ���� : 110 Gold>");
	Bow_List.push_back("��ɲ��� Ȱ \t<���ݷ� : 170, ���� : 170 Gold>");
	Bow_List.push_back("Ʈ���� ���þ� \t<���ݷ� : 200, ���� : 200 Gold>");
}

//����� ���� ����
void Bow::Show_Bow()
{
	if (Bow_List.empty())
	{
		cout << "No Data" << endl;
	}

	else
	{
		for (iter = Bow_List.begin(); iter != Bow_List.end(); iter++)
		{
			cout << *iter << endl << endl;
		}
	}

	system("pause");
}

//���� �߰��ϱ�
void Bow::Bow_Add()
{
	string tmp_Name = "";
	string Damege = "";
	string Gold = "";
	string newBow = "";

	cout << "���� �̸� �Է� : ";
	cin >> tmp_Name;
	cout << "���ݷ� �Է� : ";
	cin >> Damege;
	cout << "��� �Է� : ";
	cin >> Gold;

	newBow = tmp_Name + " \t" + "<���ݷ� : " + Damege + "���� : " + Gold + " Gold>";
	Bow_List.push_back(newBow);

	//���� �߰� �� sort �ѹ�(��������)
	sort(Bow_List.begin(), Bow_List.end(), less<string>());
}

//������ ���� ����
void Bow::Bow_All_Delete()
{
	cout << "Warring!!!!!!!!" << endl;
	cout << "�ڷḦ ��� �����մϴ�." << endl;
	Bow_List.clear();
	system("pause");
}

//���� ����
void Bow::Bow_Shop()
{
	int iSelect = 0;
	while (1)
	{
		system("cls");
		cout << "1. ���� ����Ʈ ���� " << endl;
		cout << "2. ���� �߰��ϱ� " << endl;
		cout << "4. �ڷ� ��� ����" << endl;
		cout << "5. ���ư���" << endl;
		cout << "���� : ";

		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Show_Bow();
			break;
		case 2:
			Bow_Add();
			break;
		case 3:
			Bow_All_Delete();
			break;
		case 4:
			return;
		}
	}
}

//�Ҹ���
Bow::~Bow()
{

}