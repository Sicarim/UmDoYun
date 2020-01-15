#pragma once
#include "Mecro.h"
#include "WeaponFactory.h"

class CharacterFactory
{
private:
	WeaponFactory* m_Weapon;
protected:
	string Class_Name ;
	WeaponFactory* get_Weapon(); //무기 리턴
public:
	CharacterFactory(); //생성자

	virtual string get_ClassName() = 0; //클래스 이름 반환
	virtual bool EquipCheck() = 0; //무기 장착 여부 선언
	void set_Weapon(WeaponFactory* _waepon); //무기 장착

	virtual ~CharacterFactory(); //소멸자
};

class Knight : public CharacterFactory
{
private:
protected:
public:
	Knight(); //생성자

	virtual string get_ClassName(); //클래스 이름 재정의(Knight)
	virtual bool EquipCheck(); //무기 장착 여부 재정의

	virtual ~Knight(); //소멸자
};

class Archer : public CharacterFactory
{
private:
protected:
public:
	Archer();

	virtual string get_ClassName(); //클래스 이름 재정의(Archer)
	virtual bool EquipCheck(); //무기 장착 여부 재정의

	virtual ~Archer();
};

class Wizard : public CharacterFactory
{
private:
protected:
public:
	Wizard();

	virtual string get_ClassName(); //클래스 이름 재정의(Wizard)
	virtual bool EquipCheck(); //무기 장착 여부 재정의

	virtual ~Wizard();
};