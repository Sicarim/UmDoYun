#include "WeaponFactory.h"
#include "MapDraw.h"

//�θ� Ž��
void WeaponFactory::set_Parent(WeaponFactory* _parent)
{
	m_Parent = _parent;
}

//�θ� Ž��
WeaponFactory* WeaponFactory::get_Parent()
{
	return m_Parent;
}

///////���� Ŭ����//////
//���� �� ������
void Bow::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Bow_Weapon = new Weapon((*iter));
		Add_List(Bow_Weapon);
	}
}

//���� �߰� ������
void Bow::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Bow.push_back(_List);
}

//���� �� ������
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

//���� ������
bool Bow::Attack()
{
	cout << "Ȱ ����!!!!" << endl << endl;

	return true;
}

///////��� Ŭ����//////
 //���� �� ������
void Dagger::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Dagger_Weapon = new Weapon((*iter));
		Add_List(Dagger_Weapon);
	}
}

//���� �߰� ������
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

//���� ������
bool Dagger::Attack()
{
	cout << "��� ����!!!!" << endl << endl;

	return true;
}

//��
//���� �� ������
void Gun::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Gun_Weapon = new Weapon((*iter));
		Add_List(Gun_Weapon);
	}
}

//���� �߰� ������
void Gun::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Gun.push_back(_List);
}

//���� �� ������
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

//���� ������
bool Gun::Attack()
{
	cout << "�� ����!!!!" << endl << endl;

	return true;
}

//Sword
//���� �� ������
void Sword::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Sword_Weapon = new Weapon((*iter));
		Add_List(Sword_Weapon);
	}
}

//���� �߰� ������
void Sword::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Sword.push_back(_List);
}

//���� �� ������
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

//���� ������
bool Sword::Attack()
{
	cout << "�� ����!!!!" << endl << endl;

	return true;
}

//Wand
 //���� �� ������
void Wand::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Wand_Weapon = new Weapon((*iter));
		Add_List(Wand_Weapon);
	}
}

//���� �߰� ������
void Wand::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Wand.push_back(_List);
}


//���� �� ������
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

//���� ������
bool Wand::Attack()
{
	cout << "�ϵ� ����!!!!" << endl << endl;

	return true;
}

//Hammer
 //���� �� ������
void Hammer::Make_Weapon()
{
	for (auto iter = Weapon_Arr.begin(); iter != Weapon_Arr.end(); iter++)
	{
		WeaponFactory* Hammer_Weapon = new Weapon((*iter));
		Add_List(Hammer_Weapon);
	}
}

//���� �߰� ������
void Hammer::Add_List(WeaponFactory* _List)
{
	_List->set_Parent(this);
	List_Hammer.push_back(_List);
}

//���� �� ������
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

//���� ������
bool Hammer::Attack()
{
	cout << "�ظ� ����!!!!" << endl << endl;

	return true;
}

//������(�Ű�����)
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

//���� �� ������
void Weapon::View()
{
	cout << "Ÿ�� : " << get_Type() << endl;
	cout << "�̸� : " << get_Name() << "   ";
	cout << "������ : " << get_Damege() << endl;
	cout << "���� �ӵ� : " << get_Speed() << "   ";
	cout << endl;
}

//�Ҹ���
Weapon::~Weapon()
{

}