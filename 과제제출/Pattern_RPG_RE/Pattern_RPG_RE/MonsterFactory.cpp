#include "MonsterFactory.h"
#include "MapDraw.h"

//부모 탐색
void MonsterFactory::set_Parent(MonsterFactory* _parent)
{
	m_Parent = _parent;
}

//부모 탐색
MonsterFactory* MonsterFactory::get_Parent()
{
	return m_Parent;
}

///////고블린 클래스//////
//몬스터 뷰 재정의
void Goblin::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* Goblin_Monster = new Monster((*iter));
		Add_List(Goblin_Monster);
	}
}

//몬스터 추가 재정의
void Goblin::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_Goblin.push_back(_List);
}

//몬스터 뷰 재정의
void Goblin::View()
{
	vector<MonsterFactory*>::iterator begin = List_Goblin.begin();
	vector<MonsterFactory*>::iterator end = List_Goblin.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

///////오크 클래스//////
 //몬스터 뷰 재정의
void Ock::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* Ock_Monster = new Monster((*iter));
		Add_List(Ock_Monster);
	}
}

//몬스터 추가 재정의
void Ock::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_Ock.push_back(_List);
}

void Ock::View()
{
	vector<MonsterFactory*>::iterator begin = List_Ock.begin();
	vector<MonsterFactory*>::iterator end = List_Ock.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//오우거
//몬스터 뷰 재정의
void Ouger::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* Ouger_Monster = new Monster((*iter));
		Add_List(Ouger_Monster);
	}
}

//몬스터 추가 재정의
void Ouger::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_Ouger.push_back(_List);
}

//몬스터 뷰 재정의
void Ouger::View()
{
	vector<MonsterFactory*>::iterator begin = List_Ouger.begin();
	vector<MonsterFactory*>::iterator end = List_Ouger.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//스켈리톤
//몬스터 뷰 재정의
void Skeleton::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* Skeleton_Monster = new Monster((*iter));
		Add_List(Skeleton_Monster);
	}
}

//몬스터 추가 재정의
void Skeleton::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_Skeleton.push_back(_List);
}

//몬스터 뷰 재정의
void Skeleton::View()
{
	vector<MonsterFactory*>::iterator begin = List_Skeleton.begin();
	vector<MonsterFactory*>::iterator end = List_Skeleton.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//동물
 //몬스터 뷰 재정의
void Animal::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* Animal_Monster = new Monster((*iter));
		Add_List(Animal_Monster);
	}
}

//몬스터 추가 재정의
void Animal::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_Animal.push_back(_List);
}

//몬스터 뷰 재정의
void Animal::View()
{
	vector<MonsterFactory*>::iterator begin = List_Animal.begin();
	vector<MonsterFactory*>::iterator end = List_Animal.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//킹!
 //몬스터 뷰 재정의
void King::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* King_Monster = new Monster((*iter));
		Add_List(King_Monster);
	}
}

//몬스터 추가 재정의
void King::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_King.push_back(_List);
}

//몬스터 뷰 재정의
void King::View()
{
	vector<MonsterFactory*>::iterator begin = List_King.begin();
	vector<MonsterFactory*>::iterator end = List_King.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}


//생성자(매개변수)
Monster::Monster(string _Info)
{
	char tmp_str[200];

	strcpy(tmp_str, _Info.c_str());

	system("cls");
	char* ptr = strtok(tmp_str, " ");
	m_Name = ptr;
	ptr = strtok(NULL, " ");
	m_Damege = ptr;
	ptr = strtok(NULL, " ");
	m_Health = ptr;
	ptr = strtok(NULL, " ");
	m_Speed = ptr;
	ptr = strtok(NULL, " ");
	m_Gold = ptr;
	ptr = strtok(NULL, " ");
	m_Exp = ptr;
	ptr = strtok(NULL, " ");
}

//몬스터 뷰 재정의
void Monster::View()
{
	cout << "이름 : " << get_Name() << endl;
	cout << "데미지 : " << get_Damege() << "   ";
	cout << "체력 : " << get_Health() << endl;
	cout << "공격 속도 : " << get_Speed() << "   ";
	cout << "골드 : " << get_Gold() << "   ";
	cout << "경험치 : " << get_Exp() << endl;
	cout << endl;
}

//소멸자
Monster::~Monster()
{

}