#include "Dagger.h"

//������
Dagger::Dagger()
{
	Dagger_List.reserve(5);
}

//��� ���� ����
void Dagger::Dagger_Info_Init()
{
	Dagger_List.push_back("�ܰ� \t<���ݷ� : 10, ���� : 10 Gold>");
	Dagger_List.push_back("�ϻ����� �λ� \t<���ݷ� : 50, ���� : 50 Gold>");
	Dagger_List.push_back("���� �θ��� �ܰ� \t<���ݷ� : 110, ���� : 110 Gold>");
	Dagger_List.push_back("��̴ܰ� \t<���ݷ� : 170, ���� : 170 Gold>");
	Dagger_List.push_back("����Ŀ�� \t<���ݷ� : 200, ���� : 200 Gold>");
}

//����� ��� ���� 
void Dagger::Show_Dagger()
{
	if (Dagger_List.empty())
	{
		cout << "No Data" << endl;
	}

	else
	{
		for (iter = Dagger_List.begin(); iter != Dagger_List.end(); iter++)
		{
			cout << *iter << endl << endl;
		}
	}

	system("pause");
}

//��� �߰��ϱ�
void Dagger::Dagger_Add()
{
	string tmp_Name = "";
	string Damege = "";
	string Gold = "";
	string newDagger = "";

	cout << "��� �̸� �Է� : ";
	cin >> tmp_Name;
	cout << "���ݷ� �Է� : ";
	cin >> Damege;
	cout << "��� �Է� : ";
	cin >> Gold;

	newDagger = tmp_Name + " \t" + "<���ݷ� : " + Damege + "���� : " + Gold + " Gold>";
	Dagger_List.push_back(newDagger);

	//���� �߰� �� sort �ѹ�(��������)
	sort(Dagger_List.begin(), Dagger_List.end(), greater<string>());
}

//�ڷ� ��� ����
void Dagger::Dagger_All_Delete()
{
	cout << "Warring!!!!!!!!" << endl;
	cout << "�ڷḦ ��� �����մϴ�." << endl;
	Dagger_List.clear();
	system("pause");
}


void Dagger::Dagger_Shop()
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
			Show_Dagger();
			break;
		case 2:
			Dagger_Add();
			break;
		case 3:
			Dagger_All_Delete();
			break;
		case 4:
			return;
		}
	}
}

//�Ҹ���
Dagger::~Dagger()
{
}