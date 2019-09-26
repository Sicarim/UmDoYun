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
	Weapon_List();//������(����Ʈ)

	virtual void View() = 0;
	virtual void Add_List(Weapon_List* w_List) = 0; //���� �߰�
	virtual void Remove_List(Weapon_List* w_List) = 0; //���� ����

	void set_Parent(Weapon_List* _parent); //�θ� Ž��
	Weapon_List* get_Parent(); //�θ� ����

	virtual ~Weapon_List(){}

	//Inline �Լ�//
	 //���� �̸� ��ȯ
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
	Weapon();//������(����Ʈ)

	void View() override; //���� ����Ʈ ����
	void Add_List(Weapon_List* w_List)  override; //���� �߰�
	void Remove_List(Weapon_List* w_List) override; //���� ����

	~Weapon(); //�Ҹ���
};

class Item : public Weapon_List
{
private:
	
public:
	Item(); //������(����Ʈ)
	Item(string Type); //������(�Ű�����)

	void View() override;
	void Add_List(Weapon_List* w_List) {}
	void Remove_List(Weapon_List* w_List) {}

	~Item(); //�Ҹ���
};


















//class Dagger : public Weapon_List
//{
//public:
//	void View() = 0;
//	void Add_List(Weapon_List* w_List); //���� �߰�
//	void Remove_List(Weapon_List* w_List); //���� ����
//};
//
//class Gun : public Weapon_List
//{
//public:
//	void View() = 0;
//	void Add_List(Weapon_List* w_List); //���� �߰�
//	void Remove_List(Weapon_List* w_List); //���� ����
//};
//
//class Sword : public Weapon_List
//{
//public:
//	void View() = 0;
//	void Add_List(Weapon_List* w_List); //���� �߰�
//	void Remove_List(Weapon_List* w_List); //���� ����
//};
//
//class Wand : public Weapon_List
//{
//public:
//	void View() = 0;
//	void Add_List(Weapon_List* w_List); //���� �߰�
//	void Remove_List(Weapon_List* w_List); //���� ����
//};
//
//class Hammer : public Weapon_List
//{
//public:
//	void View() = 0;
//	void Add_List(Weapon_List* w_List); //���� �߰�
//	void Remove_List(Weapon_List* w_List); //���� ����
//
//};