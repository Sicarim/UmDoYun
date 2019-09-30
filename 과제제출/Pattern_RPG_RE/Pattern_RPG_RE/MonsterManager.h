#pragma once
#include "Mecro.h"
#include "Singleton.h"

class MonsterManager : public Singleton<MonsterManager>
{
private:
	vector<string> Goblin_List;
	vector<string> Ock_List;
	vector<string> Ouger_List;
	vector<string> Skeleton_List;
	vector<string> Animal_List;
	vector<string> King_List;

	string m_stmp;
	ifstream Monster_Info; //정보 불러오기
public:
	MonsterManager(); //생성자 

	void Monster_Init(); //몬스터 정보 불러오기
	void Create_Monster_Info(string _Weapon_Name); //몬스터 리스트 불러오기
	void ViewTest();

	inline vector<string> get_Goblin_List()
	{
		return Goblin_List;
	}

	inline vector<string> get_Ock_List()
	{
		return Ock_List;
	}

	inline vector<string> get_Ouger_List()
	{
		return Ouger_List;
	}

	inline vector<string> get_Skeleton_List()
	{
		return Skeleton_List;
	}

	inline vector<string> get_Animal_List()
	{
		return Animal_List;
	}

	inline vector<string> get_King_List()
	{
		return King_List;
	}

	~MonsterManager(); //소멸자
};