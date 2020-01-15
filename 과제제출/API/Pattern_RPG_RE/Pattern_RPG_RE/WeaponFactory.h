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
	//������
	WeaponFactory()
	{
		m_Parent = NULL;
	}

	virtual void Make_Weapon() = 0; //���� ����� ����
	virtual void Add_List(WeaponFactory* _List) = 0; //���� �߰� ����
	virtual bool Attack() = 0; //���� ����
	virtual void View() = 0; //���� �� ����

	void set_Parent(WeaponFactory* _parent); //�θ� Ž��
	WeaponFactory* get_Parent(); //�θ� ����

	//�Ҹ���
	virtual ~WeaponFactory()
	{
		Weapon_Arr.clear();
	}

	//Inline �Լ�//

	inline string get_Type()
	{
		return m_Type;
	}

	 //���� �̸� ��ȯ
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

	void Make_Weapon(); //���� �� ������
	void Add_List(WeaponFactory* _List); //���� �߰� ������
	virtual bool Attack(); //���� ������
	void View(); //���� �� ������

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

	void Make_Weapon(); //���� �� ������
	void Add_List(WeaponFactory* _List); //���� �߰� ������
	virtual bool Attack(); //���� ������
	void View(); //���� �� ������

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

	void Make_Weapon(); //���� �� ������
	void Add_List(WeaponFactory* _List); //���� �߰� ������
	virtual bool Attack(); //���� ������
	void View(); //���� �� ������

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

	void Make_Weapon(); //���� �� ������
	void Add_List(WeaponFactory* _List); //���� �߰� ������
	virtual bool Attack(); //���� ������
	void View(); //���� �� ������

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

	void Make_Weapon(); //���� �� ������
	void Add_List(WeaponFactory* _List); //���� �߰� ������
	virtual bool Attack(); //���� ������
	void View(); //���� �� ������

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

	void Make_Weapon(); //���� �� ������
	void Add_List(WeaponFactory* _List); //���� �߰� ������
	virtual bool Attack(); //���� ������
	void View(); //���� �� ������

	~Hammer()
	{
		List_Hammer.clear();
	}
};

class Weapon : public WeaponFactory
{
private:
public:
	Weapon() {} //������(����Ʈ)
	Weapon(string _Info); //������(�Ű�����)

	void Make_Weapon() {} //���� �� ������
	void Add_List(WeaponFactory* _List) {} //���� �߰� ������
	virtual bool Attack() { return false; } //���� ������
	void View(); //���� �� ������

	~Weapon();
};