#include "Student.h"

//������
Student::Student(int _Num)
{
	Student_Num = 0;
	cout << "�̸��� �Է� �Ͻÿ� : ";
	cin >> Name;
	cout << "3������ ������ �Է��Ͻÿ�" << endl;
	cout << "���� : ";
	cin >> Kor;
	cout << "���� : ";
	cin >> Eng;
	cout << "���� : ";
	cin >> Math;

	Sum = Kor + Eng + Math;
	Avg = (float)Sum / 3;
	Student_Num = _Num;

	if (Avg >= 90)
	{
		Class = 'A';
	}
	else if (Avg >= 80)
	{
		Class = 'B';
	}
	else if (Avg >= 70)
	{
		Class = 'C';
	}
	else if (Avg >= 60)
	{
		Class = 'D';
	}
	else
	{
		Class = 'F';
	}
}

//�л� ���� ����
void Student::set_Student(int _Num)
{
	cout << "�̸��� �Է� �Ͻÿ� : ";
	cin >> Name;
	cout << "3������ ������ �Է��Ͻÿ�" << endl;
	cout << "���� : ";
	cin >> Kor;
	cout << "���� : ";
	cin >> Eng;
	cout << "���� : ";
	cin >> Math;

	Sum = Kor + Eng + Math;
	Avg = (float)Sum / 3;
	Student_Num = _Num;

	if (Avg >= 90)
	{
		Class = 'A';
	}
	else if (Avg >= 80)
	{
		Class = 'B';
	}
	else if (Avg >= 70)
	{
		Class = 'C';
	}
	else if (Avg >= 60)
	{
		Class = 'D';
	}
	else
	{
		Class = 'F';
	}
	return;
}

//�л� ���� ����
void Student::Show_Student()
{
	cout << "----------------------" << endl;
	cout << Student_Num << "�� �л�" << endl;
	cout << "�̸� : " << Name << endl;
	cout << "���� ���� : " << Kor << endl;
	cout << "���� ���� : " << Math << endl;
	cout << "���� ���� : " << Eng << endl;
	cout << "�հ� ���� : " << Sum << "\t ������� : " << Avg << endl;
	cout << "��� : [ " << Class << "]" << endl << endl;
	return;
}

//�Ҹ���
Student::~Student()
{
}