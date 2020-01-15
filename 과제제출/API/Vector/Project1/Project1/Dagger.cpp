#include "Dagger.h"

//생성자
Dagger::Dagger()
{
	Dagger_List.reserve(5);
}

//대거 정보 기입
void Dagger::Dagger_Info_Init()
{
	Dagger_List.push_back("단검 \t<공격력 : 10, 가격 : 10 Gold>");
	Dagger_List.push_back("암살자의 인사 \t<공격력 : 50, 가격 : 50 Gold>");
	Dagger_List.push_back("뱀을 부리는 단검 \t<공격력 : 110, 가격 : 110 Gold>");
	Dagger_List.push_back("흑미단검 \t<공격력 : 170, 가격 : 170 Gold>");
	Dagger_List.push_back("윈드커터 \t<공격력 : 200, 가격 : 200 Gold>");
}

//저장된 대거 보기 
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

//대거 추가하기
void Dagger::Dagger_Add()
{
	string tmp_Name = "";
	string Damege = "";
	string Gold = "";
	string newDagger = "";

	cout << "대거 이름 입력 : ";
	cin >> tmp_Name;
	cout << "공격력 입력 : ";
	cin >> Damege;
	cout << "골드 입력 : ";
	cin >> Gold;

	newDagger = tmp_Name + " \t" + "<공격력 : " + Damege + "가격 : " + Gold + " Gold>";
	Dagger_List.push_back(newDagger);

	//무기 추가 후 sort 한번(내림차순)
	sort(Dagger_List.begin(), Dagger_List.end(), greater<string>());
}

//자료 모두 삭제
void Dagger::Dagger_All_Delete()
{
	cout << "Warring!!!!!!!!" << endl;
	cout << "자료를 모두 삭제합니다." << endl;
	Dagger_List.clear();
	system("pause");
}


void Dagger::Dagger_Shop()
{
	int iSelect = 0;
	while (1)
	{
		system("cls");
		cout << "1. 대거 리스트 보기 " << endl;
		cout << "2. 대거 추가하기 " << endl;
		cout << "4. 자료 모두 삭제" << endl;
		cout << "5. 돌아가기" << endl;
		cout << "선택 : ";

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

//소멸자
Dagger::~Dagger()
{
}