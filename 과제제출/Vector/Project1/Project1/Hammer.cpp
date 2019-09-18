#include "Hammer.h"

//생성자
Hammer::Hammer()
{
	Hammer_List.reserve(5);
}

//대거 정보 기입
void Hammer::Hammer_Info_Init()
{
	Hammer_List.push_back("해머 \t<공격력 : 10, 가격 : 10 Gold>");
	Hammer_List.push_back("보로딘의 해머 \t<공격력 : 50, 가격 : 50 Gold>");
	Hammer_List.push_back("무간지옥  \t<공격력 : 110, 가격 : 110 Gold>");
	Hammer_List.push_back("천방지축 도깨비 방망이 \t<공격력 : 170, 가격 : 170 Gold>");
	Hammer_List.push_back("테라나이트 해머 \t<공격력 : 200, 가격 : 200 Gold>");
}

//저장된 대거 보기 
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

//대거 추가하기
void Hammer::Hammer_Add()
{
	string tmp_Name = "";
	string Damege = "";
	string Gold = "";
	string newHammer = "";

	cout << "대거 이름 입력 : ";
	cin >> tmp_Name;
	cout << "공격력 입력 : ";
	cin >> Damege;
	cout << "골드 입력 : ";
	cin >> Gold;

	newHammer = tmp_Name + " \t" + "<공격력 : " + Damege + "가격 : " + Gold + " Gold>";
	Hammer_List.push_back(newHammer);

	//무기 추가 후 sort 한번(내림차순)
	sort(Hammer_List.begin(), Hammer_List.end(), greater<string>());
}

//자료 모두 삭제
void Hammer::Hammer_All_Delete()
{
	cout << "Warring!!!!!!!!" << endl;
	cout << "자료를 모두 삭제합니다." << endl;
	Hammer_List.clear();
	system("pause");
}

void Hammer::Hammer_Shop()
{
	int iSelect = 0;
	while (1)
	{
		system("cls");
		cout << "1. 헤머 리스트 보기 " << endl;
		cout << "2. 헤머 추가하기 " << endl;
		cout << "4. 자료 모두 삭제" << endl;
		cout << "5. 돌아가기" << endl;
		cout << "선택 : ";

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

//소멸자
Hammer::~Hammer()
{

}