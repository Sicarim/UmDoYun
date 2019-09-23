#include "Std_Manager.h"

//������
Std_Manager::Std_Manager()
{
	m_std.reserve(30);
}

//���� ȭ��
void Std_Manager::Display()
{
	int iSelect = 0;

	while (true)
	{
		cout << "=========================" << endl;
		cout << "   1.�л� ���" << endl;
		cout << "   2.��ü �л����� ���" << endl;
		cout << "   3.�л� ��ȣ �˻�" << endl;
		cout << "   4.�л� �̸� �˻�" << endl;
		cout << "   5.��޺� ���" << endl;
		cout << "   0.����" << endl;
		cout << "=========================" << endl;
		cin >> iSelect;

		switch (iSelect) 
		{
		case 1:
			set_Student();
			break;
		case 2:
			Show_Student();
			break;
		case 3:
			Find_Number();
			break;
		case 4:
			Find_Name();
			break;
		case 5:
			Find_Class();
			break;
		case 0:
			return;
		default:
			cout << "�߸� �Է� " << endl;
		}
		system("pause"); system("cls");
	}
}

//�л� ���
void Std_Manager::set_Student()
{
	for (int i = 0; i < 30; i++)
	{
		m_std.push_back(*new Student(i + 1));
		return;
	}
	cout << "�л��� ���� ��� �Ǿ����ϴ�." << endl;
}

//�л� ����
void Std_Manager::Show_Student()
{
	for (auto iter = m_std.begin(); iter != m_std.end(); iter++)
	{
		if (iter->get_Num() != 0)
		{
			iter->Show_Student();
		}
		else
		{
			return;
		}
	}
}

//��ȣ�� �л� ã��
void Std_Manager::Find_Number()
{
	int _find;

	cout << "ã�� �л��ǹ�ȣ�� �Է� �Ͻÿ�";
	cin >> _find;

	for (auto iter = m_std.begin(); iter != m_std.end(); iter++)
	{
		if (iter->get_Num() == _find)
		{
			iter->Show_Student();
			return;
		}
	}
}

//�̸����� �л� ã��
void Std_Manager::Find_Name()
{
	string _find;
	int find_num = 0;

	cout << "ã�� �л����̸��� �Է� �Ͻÿ�";
	cin >> _find;

	for (auto iter = m_std.begin(); iter != m_std.end(); iter++)
	{
		if (iter->get_Name() == _find)
		{
			iter->Show_Student();
			find_num++;
		}
	}

	if (find_num == 0)
	{
		cout << "�ش� �̸��� �л��� �����ϴ�." << endl;
	}
}

//������ �л� ã��
void Std_Manager::Find_Class()
{
	int _find = 0;

	cout << "ã�� �л����̸��� �Է� �Ͻÿ�";
	cin >> _find;

	cout << "========= [ A ] =========" << endl;
	for (auto iter = m_std.begin(); iter != m_std.end(); iter++)
	{
		if (iter->get_Class() == 'A')
		{
			iter->Show_Student();
			_find++;
		}
	}

	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl << endl << endl;
	_find = 0;


	cout << "========= [ B ] =========" << endl;
	for (auto iter = m_std.begin(); iter != m_std.end(); iter++)
	{
		if (iter->get_Class() == 'B')
		{
			iter->Show_Student();
			_find++;
		}
	}
	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl;
	_find = 0;


	cout << "========= [ C ] =========" << endl;
	for (auto iter = m_std.begin(); iter != m_std.end(); iter++)
	{
		if (iter->get_Class() == 'C')
		{
			iter->Show_Student();
			_find++;
		}
	}
	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl;
	_find = 0;


	cout << "========= [ D ] =========" << endl;
	for (auto iter = m_std.begin(); iter != m_std.end(); iter++)
	{
		if (iter->get_Class() == 'D')
		{
			iter->Show_Student();
			_find++;
		}
	}
	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl;
	_find = 0;


	cout << "========= [ F ] =========" << endl;
	for (auto iter = m_std.begin(); iter != m_std.end(); iter++)
	{
		if (iter->get_Class() == 'F')
		{
			iter->Show_Student();
			_find++;
		}
	}
	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl;
}

//�Ҹ���
Std_Manager::~Std_Manager()
{
}