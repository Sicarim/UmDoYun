#pragma once
#include "Mecro.h"
#include "Student.h"
#include "Singleton_Std.h"

class Std_Manager : public Singleton_Std<Std_Manager>
{
private:
	vector<Student> m_std;
	//Student* m_std[30];
public:
	Std_Manager();
	void Display();
	void set_Student();
	void Show_Student();
	void Find_Number();
	void Find_Name();
	void Find_Class();
	~Std_Manager();
};