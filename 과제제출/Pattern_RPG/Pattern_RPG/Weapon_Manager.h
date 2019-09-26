#pragma once
#include "Mecro.h"
#include "Singleton.h"

class Weapon_Manager : public Singleton<Weapon_Manager>
{
private:
	//각종 무기 리스트
	vector<string> Bow_List;
	vector<string> Dagger_List;
	vector<string> Gun_List;
	vector<string> Sword_List;
	vector<string> Wand_List;
	vector<string> Hammer_List;

	string m_stmp;
	ifstream Weapon_Info; //정보 불러오기
public:
	Weapon_Manager(); //생성자

	void Weapon_Init(); //무기 정보 불러오기
	void Create_Weapon_Info(string _Weapon_Name); //무기 리스트 불러오기
	void ViewTest();

	inline vector<string> get_Bow_List()
	{
		return Bow_List;
	}

	inline vector<string> get_Dagger_List()
	{
		return Dagger_List;
	}

	inline vector<string> get_Gun_List()
	{
		return Gun_List;
	}

	inline vector<string> get_Sword_List()
	{
		return Sword_List;
	}

	inline vector<string> get_Wand_List()
	{
		return Wand_List;
	}

	inline vector<string> get_Hammer_List()
	{
		return Hammer_List;
	}

	~Weapon_Manager(); //소멸자
};