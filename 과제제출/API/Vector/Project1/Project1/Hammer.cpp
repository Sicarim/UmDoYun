#include "Hammer.h"

//������
Hammer::Hammer()
{
	Hammer_List.reserve(5);
}

//��� ���� ����
void Hammer::Hammer_Info_Init()
{
	Hammer_List.push_back("�ظ� \t<���ݷ� : 10, ���� : 10 Gold>");
	Hammer_List.push_back("���ε��� �ظ� \t<���ݷ� : 50, ���� : 50 Gold>");
	Hammer_List.push_back("��������  \t<���ݷ� : 110, ���� : 110 Gold>");
	Hammer_List.push_back("õ������ ������ ����� \t<���ݷ� : 170, ���� : 170 Gold>");
	Hammer_List.push_back("�׶���Ʈ �ظ� \t<���ݷ� : 200, ���� : 200 Gold>");
}

//����� ��� ���� 
void Hammer::Show_Hammer()
{
	if (Hammer_List.empty())
	{
		cout << "No Data" << endl;
	}

	else
	{
		for (iter = Hammer_List.begin(); iter != Hammer_List.end(); iter++)
		{
			cout << *iter << endl << endl;
		}
	}

	system("pause");
}

//��� �߰��ϱ�
void Hammer::Hammer_Add()
{
	string tmp_Name = "";
	string Damege = "";
	string Gold = "";
	string newHammer = "";

	cout << "��� �̸� �Է� : ";
	cin >> tmp_Name;
	cout << "���ݷ� �Է� : ";
	cin >> Damege;
	cout << "��� �Է� : ";
	cin >> Gold;

	newHammer = tmp_Name + " \t" + "<���ݷ� : " + Damege + "���� : " + Gold + " Gold>";
	Hammer_List.push_back(newHammer);

	//���� �߰� �� sort �ѹ�(��������)
	sort(Hammer_List.begin(), Hammer_List.end(), greater<string>());
}

//�ڷ� ��� ����
void Hammer::Hammer_All_Delete()
{
	cout << "Warring!!!!!!!!" << endl;
	cout << "�ڷḦ ��� �����մϴ�." << endl;
	Hammer_List.clear();
	system("pause");
}

void Hammer::Hammer_Shop()
{
	int iSelect = 0;
	while (1)
	{
		system("cls");
		cout << "1. ��� ����Ʈ ���� " << endl;
		cout << "2. ��� �߰��ϱ� " << endl;
		cout << "4. �ڷ� ��� ����" << endl;
		cout << "5. ���ư���" << endl;
		cout << "���� : ";

		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Show_Hammer();
			break;
		case 2:
			Hammer_Add();
			break;
		case 3:
			Hammer_All_Delete();
			break;
		case 4:
			return;
		}
	}
}

//�Ҹ���
Hammer::~Hammer()
{

}