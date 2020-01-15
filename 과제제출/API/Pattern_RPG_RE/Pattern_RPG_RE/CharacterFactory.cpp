#include "CharacterFactory.h"

//������
CharacterFactory::CharacterFactory()
{
	Class_Name = "";
	m_Weapon = NULL;
}

//���� ����
void CharacterFactory::set_Weapon(WeaponFactory* _weapon)
{
	m_Weapon = _weapon;
}

//���� ����
WeaponFactory* CharacterFactory::get_Weapon()
{
	return m_Weapon;
}

//�Ҹ���
CharacterFactory::~CharacterFactory()
{
	
}

//������
Knight::Knight()
{
	Class_Name = "Knight";
}

//Ŭ���� �̸� ������(Knight)
string Knight::get_ClassName()
{
	return Class_Name;
}

//���� ���� ���� ������
bool Knight::EquipCheck()
{
	Sword* sword = dynamic_cast<Sword*>(get_Weapon());
	Dagger* dagger = dynamic_cast<Dagger*>(get_Weapon());
	Hammer* hammer = dynamic_cast<Hammer*>(get_Weapon());

	if (sword == NULL && dagger == NULL && hammer == NULL)
		return false;

	cout << "--����--" << endl;

	if (sword != NULL)
	{
		return sword->Attack();
	}
	else if (dagger != NULL)
	{
		return dagger->Attack();
	}
	else if (hammer != NULL)
	{
		return hammer->Attack();
	}
	
}


Knight::~Knight()
{

}
Archer::Archer()
{
	Class_Name = "Archer";
}

//Ŭ���� �̸� ������(Archer)
string Archer::get_ClassName()
{
	return Class_Name;
}

//���� ���� ���� ������
bool Archer::EquipCheck()
{
	Bow* bow = dynamic_cast<Bow*>(get_Weapon());
	Gun* gun = dynamic_cast<Gun*>(get_Weapon());

	if (bow == NULL && gun == NULL)
		return false;

	cout << "--����--" << endl;

	if (bow != NULL)
	{
		return bow->Attack();
	}
	else if (gun != NULL)
	{
		return gun->Attack();
	}
}

Archer::~Archer()
{

}

Wizard::Wizard()
{
	Class_Name = "Wizard";
}

//Ŭ���� �̸� ������(Wizard)
string Wizard::get_ClassName()
{
	return Class_Name;
}

//���� ���� ���� ������
bool Wizard::EquipCheck()
{
	Bow* bow = dynamic_cast<Bow*>(get_Weapon());

	if (bow == NULL)
		return false;

	cout << "--����--" << endl;

	return bow->Attack();
}

Wizard::~Wizard()
{

}
