#include "MonsterFactory.h"
#include "MapDraw.h"

//�θ� Ž��
void MonsterFactory::set_Parent(MonsterFactory* _parent)
{
	m_Parent = _parent;
}

//�θ� Ž��
MonsterFactory* MonsterFactory::get_Parent()
{
	return m_Parent;
}

///////��� Ŭ����//////
//���� �� ������
void Goblin::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* Goblin_Monster = new Monster((*iter));
		Add_List(Goblin_Monster);
	}
}

//���� �߰� ������
void Goblin::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_Goblin.push_back(_List);
}

//���� �� ������
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

///////��ũ Ŭ����//////
 //���� �� ������
void Ock::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* Ock_Monster = new Monster((*iter));
		Add_List(Ock_Monster);
	}
}

//���� �߰� ������
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

//�����
//���� �� ������
void Ouger::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* Ouger_Monster = new Monster((*iter));
		Add_List(Ouger_Monster);
	}
}

//���� �߰� ������
void Ouger::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_Ouger.push_back(_List);
}

//���� �� ������
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

//���̸���
//���� �� ������
void Skeleton::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* Skeleton_Monster = new Monster((*iter));
		Add_List(Skeleton_Monster);
	}
}

//���� �߰� ������
void Skeleton::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_Skeleton.push_back(_List);
}

//���� �� ������
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

//����
 //���� �� ������
void Animal::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* Animal_Monster = new Monster((*iter));
		Add_List(Animal_Monster);
	}
}

//���� �߰� ������
void Animal::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_Animal.push_back(_List);
}

//���� �� ������
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

//ŷ!
 //���� �� ������
void King::Make_Monster()
{
	for (auto iter = Monster_Arr.begin(); iter != Monster_Arr.end(); iter++)
	{
		MonsterFactory* King_Monster = new Monster((*iter));
		Add_List(King_Monster);
	}
}

//���� �߰� ������
void King::Add_List(MonsterFactory* _List)
{
	_List->set_Parent(this);
	List_King.push_back(_List);
}

//���� �� ������
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


//������(�Ű�����)
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

//���� �� ������
void Monster::View()
{
	cout << "�̸� : " << get_Name() << endl;
	cout << "������ : " << get_Damege() << "   ";
	cout << "ü�� : " << get_Health() << endl;
	cout << "���� �ӵ� : " << get_Speed() << "   ";
	cout << "��� : " << get_Gold() << "   ";
	cout << "����ġ : " << get_Exp() << endl;
	cout << endl;
}

//�Ҹ���
Monster::~Monster()
{

}