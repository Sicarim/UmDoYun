#pragma once
#include"Mecro.h"
#include "Weapon_Manager.h"

class Weapon_List
{
private:

protected:
	Weapon_List* m_Parent;

	string m_Type;
	string m_Name;
	string m_Damege;
	string m_Gold;
public:
	Weapon_List();//생성자(디폴트)

	virtual void View() = 0;
	virtual void Add_List(Weapon_List* w_List) = 0; //무기 추가
	virtual void Remove_List(Weapon_List* w_List) = 0; //무기 삭제

	void set_Parent(Weapon_List* _parent); //부모 탐색
	Weapon_List* get_Parent(); //부모 리턴

	virtual ~Weapon_List(){}

	//Inline 함수//
	 //무기 이름 반환
	inline string get_Type()
	{
		return m_Type;
	}
	inline string get_Name()
	{
		return m_Name;
	}
	inline string get_Damege()
	{
		return m_Damege;
	}
	inline string get_Gold()
	{
		return m_Gold;
	}
};

class Weapon : public Weapon_List
{
private:
	vector<Weapon_List*> List_Weapon;
public:
	Weapon();//생성자(디폴트)

	void View() override; //무기 리스트 보기
	void Add_List(Weapon_List* w_List)  override; //무기 추가
	void Remove_List(Weapon_List* w_List) override; //무기 삭제

	~Weapon(); //소멸자
};

class Item : public Weapon_List
{
private:
	
public:
	Item(); //생성자(디폴트)
	Item(string Type); //생성자(매개변수)

	void View() override;
	void Add_List(Weapon_List* w_List) {}
	void Remove_List(Weapon_List* w_List) {}

	~Item(); //소멸자
};


















//class Dagger : public Weapon_List
//{
//public:
//	void View() = 0;
//	void Add_List(Weapon_List* w_List); //무기 추가
//	void Remove_List(Weapon_List* w_List); //무기 삭제
//};
//
//class Gun : public Weapon_List
//{
//public:
//	void View() = 0;
//	void Add_List(Weapon_List* w_List); //무기 추가
//	void Remove_List(Weapon_List* w_List); //무기 삭제
//};
//
//class Sword : public Weapon_List
//{
//public:
//	void View() = 0;
//	void Add_List(Weapon_List* w_List); //무기 추가
//	void Remove_List(Weapon_List* w_List); //무기 삭제
//};
//
//class Wand : public Weapon_List
//{
//public:
//	void View() = 0;
//	void Add_List(Weapon_List* w_List); //무기 추가
//	void Remove_List(Weapon_List* w_List); //무기 삭제
//};
//
//class Hammer : public Weapon_List
//{
//public:
//	void View() = 0;
//	void Add_List(Weapon_List* w_List); //무기 추가
//	void Remove_List(Weapon_List* w_List); //무기 삭제
//
//};