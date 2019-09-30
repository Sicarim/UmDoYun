#include "Mecro.h"
#include "MonsterManager.h"

class MonsterFactory
{
protected:
	MonsterFactory* m_Parent;
	vector<string> Monster_Arr;

	string m_Name;
	string m_Damege;
	string m_Health;
	string m_Speed;
	string m_Gold;
	string m_Exp;
	
public:
	//������
	MonsterFactory()
	{
		m_Parent = NULL;
	}

	virtual void Make_Monster() = 0; //���� ����� ����
	virtual void Add_List(MonsterFactory* _List) = 0; //���� �߰� ����
	virtual void View() = 0; //���� �� ����

	void set_Parent(MonsterFactory* _parent); //�θ� Ž��
	MonsterFactory* get_Parent(); //�θ� ����

	//�Ҹ���
	virtual ~MonsterFactory()
	{
		Monster_Arr.clear();
	}

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

class Goblin : public MonsterFactory
{
private:
	vector<MonsterFactory*> List_Goblin;
public:
	Goblin()
	{
		Monster_Arr = MonsterManager::get_Instence()->get_Goblin_List();
	}

	void Make_Monster(); //���� �� ������
	void Add_List(MonsterFactory* _List); //���� �߰� ������
	void View(); //���� �� ������

	~Goblin()
	{
		List_Goblin.clear();
	}
};

class Ock : public MonsterFactory
{
private:
	vector<MonsterFactory*> List_Ock;
public:
	Ock()
	{
		//��ũ�� ���� ������ ��´�.
		Monster_Arr = MonsterManager::get_Instence()->get_Ock_List();
	}

	void Make_Monster(); //���� �� ������
	void Add_List(MonsterFactory* _List); //���� �߰� ������
	void View(); //���� �� ������

	~Ock()
	{
		List_Ock.clear();
	}
};

class Ouger : public MonsterFactory
{
private:
	vector<MonsterFactory*> List_Ouger;
public:
	Ouger()
	{
		//����ſ� ���� ������ ��´�.
		Monster_Arr = MonsterManager::get_Instence()->get_Ouger_List();
	}

	void Make_Monster(); //���� �� ������
	void Add_List(MonsterFactory* _List); //���� �߰� ������
	void View(); //���� �� ������

	~Ouger()
	{
		List_Ouger.clear();
	}
};

class Skeleton : public MonsterFactory
{
private:
	vector<MonsterFactory*> List_Skeleton;
public:
	Skeleton()
	{
		//���̷��濡 ���� ������ ��´�.
		Monster_Arr = MonsterManager::get_Instence()->get_Skeleton_List();
	}

	void Make_Monster(); //���� �� ������
	void Add_List(MonsterFactory* _List); //���� �߰� ������
	void View(); //���� �� ������

	~Skeleton()
	{
		List_Skeleton.clear();
	}
};

class Animal : public MonsterFactory
{
private:
	vector<MonsterFactory*> List_Animal;
public:
	Animal()
	{
		Monster_Arr = MonsterManager::get_Instence()->get_Animal_List();
	}

	void Make_Monster(); //���� �� ������
	void Add_List(MonsterFactory* _List); //���� �߰� ������
	void View(); //���� �� ������

	~Animal()
	{
		List_Animal.clear();
	}
};

class King : public MonsterFactory
{
private:
	vector<MonsterFactory*> List_King;
public:
	King()
	{
		Monster_Arr = MonsterManager::get_Instence()->get_King_List();
	}

	void Make_Monster(); //���� �� ������
	void Add_List(MonsterFactory* _List); //���� �߰� ������
	void View(); //���� �� ������

	~King()
	{
		List_King.clear();
	}
};

class Monster : public MonsterFactory
{
private:
public:
	Monster() {} //������(����Ʈ)
	Monster(string _Info); //������(�Ű�����)

	void Make_Monster() {} //���� �� ������
	void Add_List(MonsterFactory* _List) {} //���� �߰� ������
	void View(); //���� �� ������

	~Monster();
};