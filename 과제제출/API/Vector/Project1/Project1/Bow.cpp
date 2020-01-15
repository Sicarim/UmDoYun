#include "Bow.h"

//생성자
Bow::Bow()
{

}

//보우 정보 기입
void Bow::Bow_Info_Init()
{
	Bow_List.push_back("활 \t<공격력 : 10, 가격 : 10 Gold>");
	Bow_List.push_back("강화 보우건 \t<공격력 : 50, 가격 : 50 Gold>");
	Bow_List.push_back("창성의 구원자 \t<공격력 : 110, 가격 : 110 Gold>");
	Bow_List.push_back("사냥꾼의 활 \t<공격력 : 170, 가격 : 170 Gold>");
	Bow_List.push_back("트라이 스팅어 \t<공격력 : 200, 가격 : 200 Gold>");
}

//저장된 보우 보기
void Bow::Show_Bow()
{
	if (Bow_List.empty())
	{
		cout << "No Data" << endl;
	}

	else
	{
		for (iter = Bow_List.begin(); iter != Bow_List.end(); iter++)
		{
			cout << *iter << endl << endl;
		}
	}

	system("pause");
}

//보우 추가하기
void Bow::Bow_Add()
{
	string tmp_Name = "";
	string Damege = "";
	string Gold = "";
	string newBow = "";

	cout << "보우 이름 입력 : ";
	cin >> tmp_Name;
	cout << "공격력 입력 : ";
	cin >> Damege;
	cout << "골드 입력 : ";
	cin >> Gold;

	newBow = tmp_Name + " \t" + "<공격력 : " + Damege + "가격 : " + Gold + " Gold>";
	Bow_List.push_back(newBow);

	//무기 추가 후 sort 한번(오르차순)
	sort(Bow_List.begin(), Bow_List.end(), less<string>());
}

//데이터 전부 삭제
void Bow::Bow_All_Delete()
{
	cout << "Warring!!!!!!!!" << endl;
	cout << "자료를 모두 삭제합니다." << endl;
	Bow_List.clear();
	system("pause");
}

//보우 상점
void Bow::Bow_Shop()
{
	int iSelect = 0;
	while (1)
	{
		system("cls");
		cout << "1. 보우 리스트 보기 " << endl;
		cout << "2. 보유 추가하기 " << endl;
		cout << "4. 자료 모두 삭제" << endl;
		cout << "5. 돌아가기" << endl;
		cout << "선택 : ";

		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Show_Bow();
			break;
		case 2:
			Bow_Add();
			break;
		case 3:
			Bow_All_Delete();
			break;
		case 4:
			return;
		}
	}
}

//소멸자
Bow::~Bow()
{

}