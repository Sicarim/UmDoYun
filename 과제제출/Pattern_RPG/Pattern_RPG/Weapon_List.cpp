#include "Weapon_List.h"

//생성자(디폴트)
Weapon_List::Weapon_List()
{
	m_Parent = NULL;
}

//부모 탐색
void Weapon_List::set_Parent(Weapon_List* _parent)
{
	m_Parent = _parent;
}

//부모 리턴
Weapon_List* Weapon_List::get_Parent()
{
	return m_Parent;
}

//생성자(디폴트)
Weapon::Weapon()
{

}

//무기 리스트 보기
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

//무기 추가
void Weapon::Add_List(Weapon_List* w_List)
{
	w_List->set_Parent(this);
	List_Weapon.push_back(w_List);
}

//무기 삭제
void Weapon::Remove_List(Weapon_List* w_List)
{
	vector<Weapon_List*>::iterator remove = find(List_Weapon.begin(), List_Weapon.end(), w_List);

	if (remove != List_Weapon.end())
	{
		List_Weapon.erase(remove);
	}
}

//소멸자
Weapon::~Weapon()
{
	List_Weapon.clear();
}

//생성자(디폴트)
Item::Item()
{

}

//생성자
Item::Item(string Type)
{
	//Weapon_List에 등록
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
	cout << "타입 : " << get_Type() << endl;
	cout << "이름 : " << get_Name() << endl;
	cout << "데미지 : " << get_Damege() << endl;
	cout << "골드 : " << get_Gold() << endl;
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