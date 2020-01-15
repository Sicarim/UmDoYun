#pragma once
#include "Mecro.h"
#include "WeaponManager.h"

class WeaponFactory
{
protected:
	WeaponFactory* m_Parent;
	vector<string> Weapon_Arr;

	string m_Type;
	string m_Name;
	string m_Damege;
	string m_Speed;
public:
	//생성자
	WeaponFactory()
	{
		m_Parent = NULL;
	}

	virtual void Make_Weapon() = 0; //무기 만들기 선언
	virtual void Add_List(WeaponFactory* _List) = 0; //무기 추가 선언
	virtual bool Attack() = 0; //장착 선언
	virtual void View() = 0; //무기 뷰 선언

	void set_Parent(WeaponFactory* _parent); //부모 탐색
	WeaponFactory* get_Parent(); //부모 리턴

	//소멸자
	virtual ~WeaponFactory()
	{
		Weapon_Arr.clear();
	}

	//Inline 함수//

	inline string get_Type()
	{
		return m_Type;
	}

	 //무기 이름 반환
	inline string get_Name()
	{
		return m_Name;
	}

	inline string get_Damege()
	{
		return m_Damege;
	}

	inline string get_Speed()
	{
		return m_Speed;
	}
};

class Bow : public WeaponFactory
{
private:
	vector<WeaponFactory*> List_Bow;
public:
	Bow()
	{
		Weapon_Arr = WeaponManager::get_Instence()->get_Bow_List();
	}

	void Make_Weapon(); //무기 뷰 재정의
	void Add_List(WeaponFactory* _List); //무기 추가 재정의
	virtual bool Attack(); //장착 재정의
	void View(); //무기 뷰 재정의

	~Bow()
	{
		List_Bow.clear();
	}
};

class Dagger : public WeaponFactory
{
private:
	vector<WeaponFactory*> List_Dagger;
public:
	Dagger()
	{
		Weapon_Arr = WeaponManager::get_Instence()->get_Dagger_List();
	}

	void Make_Weapon(); //무기 뷰 재정의
	void Add_List(WeaponFactory* _List); //무기 추가 재정의
	virtual bool Attack(); //장착 재정의
	void View(); //무기 뷰 재정의

	~Dagger()
	{
		List_Dagger.clear();
	}
};

class Gun : public WeaponFactory
{
private:
	vector<WeaponFactory*> List_Gun;
public:
	Gun()
	{
		Weapon_Arr = WeaponManager::get_Instence()->get_Gun_List();
	}

	void Make_Weapon(); //무기 뷰 재정의
	void Add_List(WeaponFactory* _List); //무기 추가 재정의
	virtual bool Attack(); //장착 재정의
	void View(); //무기 뷰 재정의

	~Gun()
	{
		List_Gun.clear();
	}
};

class Sword : public WeaponFactory
{
private:
	vector<WeaponFactory*> List_Sword;
public:
	Sword()
	{
		Weapon_Arr = WeaponManager::get_Instence()->get_Sword_List();
	}

	void Make_Weapon(); //무기 뷰 재정의
	void Add_List(WeaponFactory* _List); //무기 추가 재정의
	virtual bool Attack(); //장착 재정의
	void View(); //무기 뷰 재정의

	~Sword()
	{
		List_Sword.clear();
	}
};

class Wand : public WeaponFactory
{
private:
	vector<WeaponFactory*> List_Wand;
public:
	Wand()
	{
		Weapon_Arr = WeaponManager::get_Instence()->get_Wand_List();
	}

	void Make_Weapon(); //무기 뷰 재정의
	void Add_List(WeaponFactory* _List); //무기 추가 재정의
	virtual bool Attack(); //장착 재정의
	void View(); //무기 뷰 재정의

	~Wand()
	{
		List_Wand.clear();
	}
};

class Hammer : public WeaponFactory
{
private:
	vector<WeaponFactory*> List_Hammer;
public:
	Hammer()
	{
		Weapon_Arr = WeaponManager::get_Instence()->get_Hammer_List();
	}

	void Make_Weapon(); //무기 뷰 재정의
	void Add_List(WeaponFactory* _List); //무기 추가 재정의
	virtual bool Attack(); //장착 재정의
	void View(); //무기 뷰 재정의

	~Hammer()
	{
		List_Hammer.clear();
	}
};

class Weapon : public WeaponFactory
{
private:
public:
	Weapon() {} //생성자(디폴트)
	Weapon(string _Info); //생성자(매개변수)

	void Make_Weapon() {} //무기 뷰 재정의
	void Add_List(WeaponFactory* _List) {} //무기 추가 재정의
	virtual bool Attack() { return false; } //장착 재정의
	void View(); //무기 뷰 재정의

	~Weapon();
};