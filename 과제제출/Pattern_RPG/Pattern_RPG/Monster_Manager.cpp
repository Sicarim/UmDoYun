#include "Monster_Manager.h"

//持失切 
Monster_Manager::Monster_Manager()
{

}

void Monster_Manager::Monster_Init()
{
	Create_Monster_Info("List_Goblin.txt");
	Create_Monster_Info("List_Ock.txt");
	Create_Monster_Info("List_Ouger.txt");
	Create_Monster_Info("List_Skeleton.txt");
	Create_Monster_Info("List_Animal.txt");
	Create_Monster_Info("List_King.txt");
}

void Monster_Manager::Create_Monster_Info(string _Monster_Name)
{
	Monster_Info.open(_Monster_Name);

	if (!Monster_Info.is_open())
	{
		cout << "No Data File!!!" << endl;
	}

	else
	{
		while (!Monster_Info.eof())
		{
			getline(Monster_Info, m_stmp);

			if (_Monster_Name == "List_Goblin.txt")
			{
				Goblin_List.push_back(m_stmp);
			}
			else if (_Monster_Name == "List_Ock.txt")
			{
				Ock_List.push_back(m_stmp);
			}
			else if (_Monster_Name == "List_Skeleton.txt")
			{
				Skeleton_List.push_back(m_stmp);
			}
			else if (_Monster_Name == "List_Ouger.txt")
			{
				Ouger_List.push_back(m_stmp);
			}
			else if (_Monster_Name == "List_King.txt")
			{
				King_List.push_back(m_stmp);
			}
			else if (_Monster_Name == "List_Animal.txt")
			{
				Animal_List.push_back(m_stmp);
			}
		}
		Monster_Info.close();
	}
}

//社瑚切
Monster_Manager::~Monster_Manager()
{
	Goblin_List.clear();
	Ock_List.clear();
	Ouger_List.clear();
	Skeleton_List.clear();
	Animal_List.clear();
	King_List.clear();
}