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
	ifstream Monster_Info; //���� �ҷ�����
public:
	MonsterManager(); //������ 

	void Monster_Init(); //���� ���� �ҷ�����
	void Create_Monster_Info(string _Weapon_Name); //���� ����Ʈ �ҷ�����
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

	~MonsterManager(); //�Ҹ���
};