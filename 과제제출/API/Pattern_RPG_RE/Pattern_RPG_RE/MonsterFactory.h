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
	//생성자
	MonsterFactory()
	{
		m_Parent = NULL;
	}

	virtual void Make_Monster() = 0; //몬스터 만들기 선언
	virtual void Add_List(MonsterFactory* _List) = 0; //몬스터 추가 선언
	virtual void View() = 0; //몬스터 뷰 선언

	void set_Parent(MonsterFactory* _parent); //부모 탐색
	MonsterFactory* get_Parent(); //부모 리턴

	//소멸자
	virtual ~MonsterFactory()
	{
		Monster_Arr.clear();
	}

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

class Goblin : public MonsterFactory
{
private:
	vector<MonsterFactory*> List_Goblin;
public:
	Goblin()
	{
		Monster_Arr = MonsterManager::get_Instence()->get_Goblin_List();
	}

	void Make_Monster(); //몬스터 뷰 재정의
	void Add_List(MonsterFactory* _List); //몬스터 추가 재정의
	void View(); //몬스터 뷰 재정의

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
		//오크에 대한 정보를 담는다.
		Monster_Arr = MonsterManager::get_Instence()->get_Ock_List();
	}

	void Make_Monster(); //몬스터 뷰 재정의
	void Add_List(MonsterFactory* _List); //몬스터 추가 재정의
	void View(); //몬스터 뷰 재정의

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
		//오우거에 대한 정보를 담는다.
		Monster_Arr = MonsterManager::get_Instence()->get_Ouger_List();
	}

	void Make_Monster(); //몬스터 뷰 재정의
	void Add_List(MonsterFactory* _List); //몬스터 추가 재정의
	void View(); //몬스터 뷰 재정의

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
		//스켈레톤에 대한 정보를 담는다.
		Monster_Arr = MonsterManager::get_Instence()->get_Skeleton_List();
	}

	void Make_Monster(); //몬스터 뷰 재정의
	void Add_List(MonsterFactory* _List); //몬스터 추가 재정의
	void View(); //몬스터 뷰 재정의

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

	void Make_Monster(); //몬스터 뷰 재정의
	void Add_List(MonsterFactory* _List); //몬스터 추가 재정의
	void View(); //몬스터 뷰 재정의

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

	void Make_Monster(); //몬스터 뷰 재정의
	void Add_List(MonsterFactory* _List); //몬스터 추가 재정의
	void View(); //몬스터 뷰 재정의

	~King()
	{
		List_King.clear();
	}
};

class Monster : public MonsterFactory
{
private:
public:
	Monster() {} //생성자(디폴트)
	Monster(string _Info); //생성자(매개변수)

	void Make_Monster() {} //몬스터 뷰 재정의
	void Add_List(MonsterFactory* _List) {} //몬스터 추가 재정의
	void View(); //몬스터 뷰 재정의

	~Monster();
};