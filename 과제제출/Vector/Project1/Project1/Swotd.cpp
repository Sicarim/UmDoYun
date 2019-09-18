#include "Sword.h"

//생성자
Sword::Sword()
{

}

//소드 정보 기입
void Sword::Sword_Info_Init()
{
	Sword_List.push_back("검 \t<공격력 : 10, 가격 : 10 Gold>");
	Sword_List.push_back("강화 검 \t<공격력 : 50, 가격 : 50 Gold>");
	Sword_List.push_back("마검 아카폴립스 \t<공격력 : 110, 가격 : 110 Gold>");
	Sword_List.push_back("카인의 저주 \t<공격력 : 170, 가격 : 170 Gold>");
	Sword_List.push_back("솔도로스의 선택 \t<공격력 : 200, 가격 : 200 Gold>");
}

//저장된 소드 보기
void Sword::Show_Sword()
{
	for (iter = Sword_List.begin(); iter != Sword_List.end(); iter++)
	{
		cout << *iter << endl << endl;
	}
	system("pause");
}

//소드 상점
void Sword::Sword_Shop()
{

}

//소드 추가하기
void Sword::Sword_Add()
{
	string tmp_Name = "";
	string Damege = "";
	string Gold = "";
	string newSword = "";

	cout << "대거 이름 입력 : ";
	cin >> tmp_Name;
	cout << "공격력 입력 : ";
	cin >> Damege;
	cout << "골드 입력 : ";
	cin >> Gold;

	newSword = tmp_Name + " \t" + "<공격력 : " + Damege + "가격 : " + Gold + " Gold>";
	Sword_List.push_back(newSword);

	//무기 추가 후 sort 한번(오르차순)
	sort(Sword_List.begin(), Sword_List.end(), less<string>());
}

//소드 검색하기
void Sword::Sword_Serch()
{

}

//소멸자
Sword::~Sword()
{
}