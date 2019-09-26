#include "Monster_List.h"

//생성자(디폴트)
Monster_List::Monster_List()
{
	m_Parent = NULL;
}

//부모 탐색
void Monster_List::set_Parent(Monster_List* _parent)
{
	m_Parent = _parent;
}

//부모 리턴
Monster_List* Monster_List::get_Parent()
{
	return m_Parent;
}

//생성자(디폴트)
Monster::Monster()
{

}

//무기 리스트 보기
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

//무기 추가
void Monster::Add_List(Monster_List* w_List)
{
	w_List->set_Parent(this);
	List_Monster.push_back(w_List);
}

//무기 삭제
void Monster::Remove_List(Monster_List* w_List)
{
	vector<Monster_List*>::iterator remove = find(List_Monster.begin(), List_Monster.end(), w_List);

	if (remove != List_Monster.end())
	{
		List_Monster.erase(remove);
	}
}

//소멸자
Monster::~Monster()
{
	List_Monster.clear();
}

//생성자(디폴트)
Villain::Villain()
{

}

//생성자
Villain::Villain(string Type)
{
	//Monster_List에 등록
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
	cout << "이름 : " << get_Name() << endl;
	cout << "데미지 : " << get_Damege() << "   ";
	cout << "체력 : " << get_Health() << endl;
	cout << "공격 속도 : " << get_Speed() << "   ";
	cout << "골드 : " << get_Gold() << "   ";
	cout << "경험치 : " << get_Exp() << endl;
	cout << endl;
}

Villain::~Villain()
{

}