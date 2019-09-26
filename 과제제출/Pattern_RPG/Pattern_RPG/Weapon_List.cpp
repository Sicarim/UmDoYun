#include "Weapon_List.h"

//������(����Ʈ)
Weapon_List::Weapon_List()
{
	m_Parent = NULL;
}

//�θ� Ž��
void Weapon_List::set_Parent(Weapon_List* _parent)
{
	m_Parent = _parent;
}

//�θ� ����
Weapon_List* Weapon_List::get_Parent()
{
	return m_Parent;
}

//������(����Ʈ)
Weapon::Weapon()
{

}

//���� ����Ʈ ����
void Weapon::View()
{
	vector<Weapon_List*>::iterator begin = List_Weapon.begin();
	vector<Weapon_List*>::iterator end = List_Weapon.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//���� �߰�
void Weapon::Add_List(Weapon_List* w_List)
{
	w_List->set_Parent(this);
	List_Weapon.push_back(w_List);
}

//���� ����
void Weapon::Remove_List(Weapon_List* w_List)
{
	vector<Weapon_List*>::iterator remove = find(List_Weapon.begin(), List_Weapon.end(), w_List);

	if (remove != List_Weapon.end())
	{
		List_Weapon.erase(remove);
	}
}

//�Ҹ���
Weapon::~Weapon()
{
	List_Weapon.clear();
}

//������(����Ʈ)
Item::Item()
{

}

//������
Item::Item(string Type)
{
	//Weapon_List�� ���
	char tmp_str[50];

	strcpy(tmp_str, Type.c_str());

	char* ptr = strtok(tmp_str, " ");

	m_Type = ptr;
	ptr = strtok(NULL, " ");
	m_Name = ptr;
	ptr = strtok(NULL, " ");
	m_Damege = ptr;
	ptr = strtok(NULL, " ");
	m_Gold = ptr;
	ptr = strtok(NULL, " ");

	//m_Type = Type;
}

void Item::View()
{
	cout << "Ÿ�� : " << get_Type() << endl;
	cout << "�̸� : " << get_Name() << endl;
	cout << "������ : " << get_Damege() << endl;
	cout << "��� : " << get_Gold() << endl;
	cout << endl;
}

Item::~Item()
{

}

//template <typename Out>
//void Weapon_List::split(const string& s, char delim, Out result)
//{
//	stringstream ss(s);
//	string item;
//
//	while (getline(ss, item, delim)
//	{
//		*(result++) = item;
//	}
//}
/*
vector<string> split(const string& s, const char delim)
{
	vector<string> elems;
	split(s, delim);
	
	return elems;
}

char tmp_str[50];

	strcpy(tmp_str, Type.c_str());

	char* ptr = strtok(tmp_str, " ");
	while (ptr != NULL)
	{
		cout << ptr << endl;
		ptr = strtok(NULL, " ");
	}



	/*template <typename Out>
	void split(const string &s, char delim, Out result);
*/