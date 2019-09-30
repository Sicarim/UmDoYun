#include "WeaponFactory.h"
#include "MapDraw.h"

//부모 탐색
void WeaponFactory::set_Parent(WeaponFactory* _parent)
{
	m_Parent = _parent;
}

//부모 탐색
WeaponFactory* WeaponFactory::get_Parent()
{
	return m_Parent;
}

///////보우 클래스//////
//무기 뷰 재정의
void Bow::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Bow_Weapon = new Weapon((*iter));
		Add_List(Bow_Weapon);
	}
}

//무기 추가 재정의
void Bow::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Bow.push_back(_List);
}

//무기 뷰 재정의
void Bow::View()
{
	vector<WeaponFactory*>::iterator begin = List_Bow.begin();
	vector<WeaponFactory*>::iterator end = List_Bow.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//장착 재정의
bool Bow::Attack()
{
	cout << "활 장착!!!!" << endl << endl;

	return true;
}

///////대거 클래스//////
 //무기 뷰 재정의
void Dagger::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Dagger_Weapon = new Weapon((*iter));
		Add_List(Dagger_Weapon);
	}
}

//무기 추가 재정의
void Dagger::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Dagger.push_back(_List);
}

void Dagger::View()
{
	vector<WeaponFactory*>::iterator begin = List_Dagger.begin();
	vector<WeaponFactory*>::iterator end = List_Dagger.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//장착 재정의
bool Dagger::Attack()
{
	cout << "대거 장착!!!!" << endl << endl;

	return true;
}

//건
//무기 뷰 재정의
void Gun::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Gun_Weapon = new Weapon((*iter));
		Add_List(Gun_Weapon);
	}
}

//무기 추가 재정의
void Gun::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Gun.push_back(_List);
}

//무기 뷰 재정의
void Gun::View()
{
	vector<WeaponFactory*>::iterator begin = List_Gun.begin();
	vector<WeaponFactory*>::iterator end = List_Gun.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//장착 재정의
bool Gun::Attack()
{
	cout << "총 장착!!!!" << endl << endl;

	return true;
}

//Sword
//무기 뷰 재정의
void Sword::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Sword_Weapon = new Weapon((*iter));
		Add_List(Sword_Weapon);
	}
}

//무기 추가 재정의
void Sword::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Sword.push_back(_List);
}

//무기 뷰 재정의
void Sword::View()
{
	vector<WeaponFactory*>::iterator begin = List_Sword.begin();
	vector<WeaponFactory*>::iterator end = List_Sword.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//장착 재정의
bool Sword::Attack()
{
	cout << "검 장착!!!!" << endl << endl;

	return true;
}

//Wand
 //무기 뷰 재정의
void Wand::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Wand_Weapon = new Weapon((*iter));
		Add_List(Wand_Weapon);
	}
}

//무기 추가 재정의
void Wand::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Wand.push_back(_List);
}


//무기 뷰 재정의
void Wand::View()
{
	vector<WeaponFactory*>::iterator begin = List_Wand.begin();
	vector<WeaponFactory*>::iterator end = List_Wand.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//장착 재정의
bool Wand::Attack()
{
	cout << "완드 장착!!!!" << endl << endl;

	return true;
}

//Hammer
 //무기 뷰 재정의
void Hammer::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Hammer_Weapon = new Weapon((*iter));
		Add_List(Hammer_Weapon);
	}
}

//무기 추가 재정의
void Hammer::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Hammer.push_back(_List);
}

//무기 뷰 재정의
void Hammer::View()
{
	vector<WeaponFactory*>::iterator begin = List_Hammer.begin();
	vector<WeaponFactory*>::iterator end = List_Hammer.end();

	while (begin != end)
	{
		(*begin)->View();

		begin++;
	}
}

//장착 재정의
bool Hammer::Attack()
{
	cout << "해머 장착!!!!" << endl << endl;

	return true;
}

//생성자(매개변수)
Weapon::Weapon(string _Info)
{
	char tmp_str[200];

	strcpy(tmp_str, _Info.c_str());

	system("cls");
	char* ptr = strtok(tmp_str, " ");
	m_Type = ptr;
	ptr = strtok(NULL, " ");
	m_Name = ptr;
	ptr = strtok(NULL, " ");
	m_Damege = ptr;
	ptr = strtok(NULL, " ");;
	m_Speed = ptr;
	ptr = strtok(NULL, " ");
}

//무기 뷰 재정의
void Weapon::View()
{
	cout << "타입 : " << get_Type() << endl;
	cout << "이름 : " << get_Name() << "   ";
	cout << "데미지 : " << get_Damege() << endl;
	cout << "공격 속도 : " << get_Speed() << "   ";
	cout << endl;
}

//소멸자
Weapon::~Weapon()
{

}