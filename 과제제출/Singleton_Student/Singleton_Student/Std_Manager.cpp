#include "Std_Manager.h"

//생성자
Std_Manager::Std_Manager()
{
	m_std.reserve(30);
}

//메인 화면
void Std_Manager::Display()
{
	int iSelect = 0;

	while (true)
	{
		cout << "=========================" << endl;
		cout << "   1.학생 등록" << endl;
		cout << "   2.전체 학생정보 출력" << endl;
		cout << "   3.학생 번호 검색" << endl;
		cout << "   4.학생 이름 검색" << endl;
		cout << "   5.등급별 출력" << endl;
		cout << "   0.종료" << endl;
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
			cout << "잘못 입력 " << endl;
		}
		system("pause"); system("cls");
	}
}

//학생 등록
void Std_Manager::set_Student()
{
	for (int i = 0; i < 30; i++)
	{
		m_std.push_back(*new Student(i + 1));
		return;
	}
	cout << "학생이 전원 등록 되었습니다." << endl;
}

//학생 보기
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

//번호로 학생 찾기
void Std_Manager::Find_Number()
{
	int _find;

	cout << "찾을 학생의번호를 입력 하시오";
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

//이름으로 학생 찾기
void Std_Manager::Find_Name()
{
	string _find;
	int find_num = 0;

	cout << "찾을 학생의이름을 입력 하시오";
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
		cout << "해당 이름의 학생이 없습니다." << endl;
	}
}

//반으로 학생 찾기
void Std_Manager::Find_Class()
{
	int _find = 0;

	cout << "찾을 학생의이름을 입력 하시오";
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

	cout << "총 " << _find << "명" << endl;
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
	cout << "총 " << _find << "명" << endl;
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
	cout << "총 " << _find << "명" << endl;
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
	cout << "총 " << _find << "명" << endl;
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
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl;
}

//소멸자
Std_Manager::~Std_Manager()
{
}