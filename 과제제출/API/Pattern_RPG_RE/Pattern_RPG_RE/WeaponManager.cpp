#include "WeaponManager.h"

//持失切 
WeaponManager::WeaponManager()
{

}

void WeaponManager::Weapon_Init()
{
	Create_Weapon_Info("List_Bow.txt");
	Create_Weapon_Info("List_Dagger.txt");
	Create_Weapon_Info("List_Gun.txt");
	Create_Weapon_Info("List_Sword.txt");
	Create_Weapon_Info("List_Wand.txt");
	Create_Weapon_Info("List_Hammer.txt");
}

void WeaponManager::Create_Weapon_Info(string _WeaponName)
{
	Weapon_Info.open(_WeaponName);

	if (!Weapon_Info.is_open())
	{
		cout << "No Data File!!!" << endl;
	}

	else
	{
		while (!Weapon_Info.eof())
		{
			getline(Weapon_Info, m_stmp);

			if (_WeaponName == "List_Bow.txt")
			{
				Bow_List.push_back(m_stmp);
			}
			else if (_WeaponName == "List_Dagger.txt")
			{
				Dagger_List.push_back(m_stmp);
			}
			else if (_WeaponName == "List_Gun.txt")
			{
				Gun_List.push_back(m_stmp);
			}
			else if (_WeaponName == "List_Sword.txt")
			{
				Sword_List.push_back(m_stmp);
			}
			else if (_WeaponName == "List_Wand.txt")
			{
				Wand_List.push_back(m_stmp);
			}
			else if (_WeaponName == "List_Hammer.txt")
			{
				Hammer_List.push_back(m_stmp);
			}
		}
		Weapon_Info.close();
	}
}

//社瑚切
WeaponManager::~WeaponManager()
{
	Bow_List.clear();
	Dagger_List.clear();
	Gun_List.clear();
	Sword_List.clear();
	Wand_List.clear();
	Hammer_List.clear();
}