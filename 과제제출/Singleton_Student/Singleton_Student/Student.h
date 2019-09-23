#pragma once
#include "Mecro.h"

class Student
{
private:
	string Name;
	int Kor, Eng, Math, Sum;
	float Avg;
	int Student_Num;
	char Class;
public:
	Student() {}
	Student(int _Num);
	void set_Student(int _Num); //�л� ���� ����
	void Show_Student(); //�ϻ� ���� ����
	~Student();

	inline int get_Num()
	{
		return Student_Num;
	}

	inline string get_Name()
	{
		return Name;
	}

	inline char get_Class()
	{
		return Class;
	}
};