#include "CharacterFactory.h"

//생성자
CharacterFactory::CharacterFactory()
{
	Class_Name = "";
	m_Weapon = NULL;
}

//무기 장착
void CharacterFactory::set_Weapon(WeaponFactory* _weapon)
{
	m_Weapon = _weapon;
}

//무기 리턴
WeaponFactory* CharacterFactory::get_Weapon()
{
	return m_Weapon;
}

//소멸자
CharacterFactory::~CharacterFactory()
{
	
}

//생성자
Knight::Knight()
{
	Class_Name = "Knight";
}

//클래스 이름 재정의(Knight)
string Knight::get_ClassName()
{
	return Class_Name;
}

//무기 장착 여부 재정의
bool Knight::EquipCheck()
{
	Sword* sword = dynamic_cast<Sword*>(get_Weapon());
	Dagger* dagger = dynamic_cast<Dagger*>(get_Weapon());
	Hammer* hammer = dynamic_cast<Hammer*>(get_Weapon());

	if (sword == NULL && dagger == NULL && hammer == NULL)
		return false;

	cout << "--무기--" << endl;

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

//클래스 이름 재정의(Archer)
string Archer::get_ClassName()
{
	return Class_Name;
}

//무기 장착 여부 재정의
bool Archer::EquipCheck()
{
	Bow* bow = dynamic_cast<Bow*>(get_Weapon());
	Gun* gun = dynamic_cast<Gun*>(get_Weapon());

	if (bow == NULL && gun == NULL)
		return false;

	cout << "--무기--" << endl;

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

//클래스 이름 재정의(Wizard)
string Wizard::get_ClassName()
{
	return Class_Name;
}

//무기 장착 여부 재정의
bool Wizard::EquipCheck()
{
	Bow* bow = dynamic_cast<Bow*>(get_Weapon());

	if (bow == NULL)
		return false;

	cout << "--무기--" << endl;

	return bow->Attack();
}

Wizard::~Wizard()
{

}
