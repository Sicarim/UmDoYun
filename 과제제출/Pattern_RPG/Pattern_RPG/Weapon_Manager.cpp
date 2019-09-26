#include "Weapon_Manager.h"

//생성자
Weapon_Manager::Weapon_Manager()
{
	m_stmp = "";
}

//무기 정보 불러오기
void Weapon_Manager::Weapon_Init()
{
	Create_Weapon_Info("List_Bow.txt");
	Create_Weapon_Info("List_Dagger.txt");
	Create_Weapon_Info("List_Gun.txt");
	Create_Weapon_Info("List_Sword.txt");
	Create_Weapon_Info("List_Wand.txt");
	Create_Weapon_Info("List_Hammer.txt");
}

//무기 리스트 불러오기
void Weapon_Manager::Create_Weapon_Info(string _Weapon_Name)
{
	Weapon_Info.open(_Weapon_Name);

	if (!Weapon_Info.is_open())
	{
		cout << "No Data File!!!" << endl;
	}
	else
	{
		while (!Weapon_Info.eof())
		{
			getline(Weapon_Info, m_stmp);

			if (_Weapon_Name == "List_Bow.txt")
			{
				Bow_List.push_back(m_stmp);
			}
			else if (_Weapon_Name == "List_Dagger.txt")
			{
				Dagger_List.push_back(m_stmp);
			}
			else if (_Weapon_Name == "List_Gun.txt")
			{
				Gun_List.push_back(m_stmp);
			}
			else if (_Weapon_Name == "List_Sword.txt")
			{
				Sword_List.push_back(m_stmp);
			}
			else if (_Weapon_Name == "List_Wand.txt")
			{
				Wand_List.push_back(m_stmp);
			}
			else if (_Weapon_Name == "List_Hammer.txt")
			{
				Hammer_List.push_back(m_stmp);
			}
		}
		Weapon_Info.close();
	}
}

void Weapon_Manager::ViewTest()
{
	system("cls");
	for (auto iter = Hammer_List.begin(); iter != Hammer_List.end(); iter++)
	{
		cout << *iter << endl;
	}
}

//소멸자
Weapon_Manager::~Weapon_Manager()
{
	Bow_List.clear();
	Dagger_List.clear();
	Gun_List.clear();
	Sword_List.clear();
	Wand_List.clear();
	Hammer_List.clear();
}