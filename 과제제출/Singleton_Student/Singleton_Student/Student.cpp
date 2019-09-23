#include "Student.h"

//생성자
Student::Student(int _Num)
{
	Student_Num = 0;
	cout << "이름을 입력 하시오 : ";
	cin >> Name;
	cout << "3과목의 점수를 입력하시오" << endl;
	cout << "국어 : ";
	cin >> Kor;
	cout << "영어 : ";
	cin >> Eng;
	cout << "수학 : ";
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

//학생 정보 기입
void Student::set_Student(int _Num)
{
	cout << "이름을 입력 하시오 : ";
	cin >> Name;
	cout << "3과목의 점수를 입력하시오" << endl;
	cout << "국어 : ";
	cin >> Kor;
	cout << "영어 : ";
	cin >> Eng;
	cout << "수학 : ";
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

//학생 정보 보기
void Student::Show_Student()
{
	cout << "----------------------" << endl;
	cout << Student_Num << "번 학생" << endl;
	cout << "이름 : " << Name << endl;
	cout << "국어 점수 : " << Kor << endl;
	cout << "수학 점수 : " << Math << endl;
	cout << "영어 점수 : " << Eng << endl;
	cout << "합계 점수 : " << Sum << "\t 평균점수 : " << Avg << endl;
	cout << "등급 : [ " << Class << "]" << endl << endl;
	return;
}

//소멸자
Student::~Student()
{
}