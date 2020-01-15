#pragma once
#include "Mecro.h"
#include "WeaponFactory.h"

class CharacterFactory
{
private:
	WeaponFactory* m_Weapon;
protected:
	string Class_Name ;
	WeaponFactory* get_Weapon(); //���� ����
public:
	CharacterFactory(); //������

	virtual string get_ClassName() = 0; //Ŭ���� �̸� ��ȯ
	virtual bool EquipCheck() = 0; //���� ���� ���� ����
	void set_Weapon(WeaponFactory* _waepon); //���� ����

	virtual ~CharacterFactory(); //�Ҹ���
};

class Knight : public CharacterFactory
{
private:
protected:
public:
	Knight(); //������

	virtual string get_ClassName(); //Ŭ���� �̸� ������(Knight)
	virtual bool EquipCheck(); //���� ���� ���� ������

	virtual ~Knight(); //�Ҹ���
};

class Archer : public CharacterFactory
{
private:
protected:
public:
	Archer();

	virtual string get_ClassName(); //Ŭ���� �̸� ������(Archer)
	virtual bool EquipCheck(); //���� ���� ���� ������

	virtual ~Archer();
};

class Wizard : public CharacterFactory
{
private:
protected:
public:
	Wizard();

	virtual string get_ClassName(); //Ŭ���� �̸� ������(Wizard)
	virtual bool EquipCheck(); //���� ���� ���� ������

	virtual ~Wizard();
};