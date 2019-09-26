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
	Monster_List();//������(����Ʈ)

	virtual void View() = 0;
	virtual void Add_List(Monster_List* w_List) = 0; //���� �߰�
	virtual void Remove_List(Monster_List* w_List) = 0; //���� ����

	void set_Parent(Monster_List* _parent); //�θ� Ž��
	Monster_List* get_Parent(); //�θ� ����

	virtual ~Monster_List() {}

	//Inline �Լ�//
	 //���� �̸� ��ȯ
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
	Monster();//������(����Ʈ)

	void View() override; //���� ����Ʈ ����
	void Add_List(Monster_List* w_List)  override; //���� �߰�
	void Remove_List(Monster_List* w_List) override; //���� ����

	~Monster(); //�Ҹ���
};

class Villain : public Monster_List
{
private:

public:
	Villain(); //������(����Ʈ)
	Villain(string Type); //������(�Ű�����)

	void View() override;
	void Add_List(Monster_List* w_List) {}
	void Remove_List(Monster_List* w_List) {}

	~Villain(); //�Ҹ���
};

