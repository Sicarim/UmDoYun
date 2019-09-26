#include "Monster_List.h"

//������(����Ʈ)
Monster_List::Monster_List()
{
	m_Parent = NULL;
}

//�θ� Ž��
void Monster_List::set_Parent(Monster_List* _parent)
{
	m_Parent = _parent;
}

//�θ� ����
Monster_List* Monster_List::get_Parent()
{
	return m_Parent;
}

//������(����Ʈ)
Monster::Monster()
{

}

//���� ����Ʈ ����
void Monster::View()
{
	vector<Monster_List*>::iterator begin = List_Monster.begin();
	vector<Monster_List*>::iterator end = List_Monster.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//���� �߰�
void Monster::Add_List(Monster_List* w_List)
{
	w_List->set_Parent(this);
	List_Monster.push_back(w_List);
}

//���� ����
void Monster::Remove_List(Monster_List* w_List)
{
	vector<Monster_List*>::iterator remove = find(List_Monster.begin(), List_Monster.end(), w_List);

	if (remove != List_Monster.end())
	{
		List_Monster.erase(remove);
	}
}

//�Ҹ���
Monster::~Monster()
{
	List_Monster.clear();
}

//������(����Ʈ)
Villain::Villain()
{

}

//������
Villain::Villain(string Type)
{
	//Monster_List�� ���
	char tmp_str[200];

	strcpy(tmp_str, Type.c_str());

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

	//m_Type = Type;
}

void Villain::View()
{
	cout << "�̸� : " << get_Name() << endl;
	cout << "������ : " << get_Damege() << "   ";
	cout << "ü�� : " << get_Health() << endl;
	cout << "���� �ӵ� : " << get_Speed() << "   ";
	cout << "��� : " << get_Gold() << "   ";
	cout << "����ġ : " << get_Exp() << endl;
	cout << endl;
}

Villain::~Villain()
{

}