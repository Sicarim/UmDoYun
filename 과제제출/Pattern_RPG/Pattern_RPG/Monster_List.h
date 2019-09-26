#pragma once
#include"Mecro.h"
#include "Monster_Manager.h"

class Monster_List
{
private:

protected:
	Monster_List* m_Parent;

	string m_Name;
	string m_Damege;
	string m_Health;
	string m_Speed;
	string m_Gold;
	string m_Exp;

public:
	Monster_List();//생성자(디폴트)

	virtual void View() = 0;
	virtual void Add_List(Monster_List* w_List) = 0; //무기 추가
	virtual void Remove_List(Monster_List* w_List) = 0; //무기 삭제

	void set_Parent(Monster_List* _parent); //부모 탐색
	Monster_List* get_Parent(); //부모 리턴

	virtual ~Monster_List() {}

	//Inline 함수//
	 //몬스터 이름 반환
	inline string get_Name()
	{
		return m_Name;
	}

	inline string get_Damege()
	{
		return m_Damege;
	}
	inline string get_Health()
	{
		return m_Health;
	}
	inline string get_Speed()
	{
		return m_Speed;
	}
	inline string get_Gold()
	{
		return m_Gold;
	}
	inline string get_Exp()
	{
		return m_Exp;
	}
};

class Monster : public Monster_List
{
private:
	vector<Monster_List*> List_Monster;
public:
	Monster();//생성자(디폴트)

	void View() override; //무기 리스트 보기
	void Add_List(Monster_List* w_List)  override; //무기 추가
	void Remove_List(Monster_List* w_List) override; //무기 삭제

	~Monster(); //소멸자
};

class Villain : public Monster_List
{
private:

public:
	Villain(); //생성자(디폴트)
	Villain(string Type); //생성자(매개변수)

	void View() override;
	void Add_List(Monster_List* w_List) {}
	void Remove_List(Monster_List* w_List) {}

	~Villain(); //소멸자
};

