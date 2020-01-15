#pragma once
#include "Mecro.h"
#include "Interface.h"
#include "Player.h"
#include "CharacterFactory.h"
#include "MonsterFactory.h"
#include "WeaponFactory.h"


class Game
{
private:
protected:
	Interface* m_Inter;
	CharacterFactory* m_Char;
	MonsterFactory* m_Monster;
	WeaponFactory* m_Weapon;

	virtual Interface* Create_View(VIEW_SELECT _View_Num) = 0; //�� ����.
	virtual CharacterFactory* Create_Char(CLASS_SELECT _SELECT_CLASS) = 0; //ĳ���� ����.
	virtual MonsterFactory* Create_Monster(MONSTER_SELECT _SELECT_MONSTER) = 0; //���� ����.
	virtual WeaponFactory* Create_Weapon(WEAPON_SELECT _SELECT_WEAPON) = 0; //���� ���丮 ����

	virtual void Main_Loby() = 0; //����ȭ�� ����.
	virtual void Main_Select_Menu() = 0; //�޴� ���� ȭ�� ����.
public:
	Game(); //������

	virtual void Init(); //�ʱ�ȭ �Լ�
	virtual void Update(); //������ ���� �Լ�
	virtual void Release(); //�Ҵ� ����

	virtual ~Game() {} //�Ҹ���
};

class RPG_Game : public Game
{
private:
	Player m_Player;
	int iSelect;
public:
	RPG_Game(); //������

	virtual Interface* Create_View(VIEW_SELECT _View_Num); //Create_View ������
	virtual CharacterFactory* Create_Char(CLASS_SELECT _SELECT_CLASS); //Create_Char ������
	virtual MonsterFactory* Create_Monster(MONSTER_SELECT _SELECT_MONSTER); //Create_Monster ������.
	virtual WeaponFactory* Create_Weapon(WEAPON_SELECT _SELECT_WEAPON); //���� ���丮 ������

	virtual void Main_Loby();
	virtual void Main_Select_Menu();

	void Main_Player_Menu(); //�÷��̾� �޴�
	void Make_Player_Info(); //�÷��̾� ���� ����
	void Main_Monster_Menu(); //���� �޴�
	void Main_Weapon_Menu(); //���� �޴�

	void Player_fun(CLASS_SELECT _class); //�÷��̾� �Լ�
	void Monster_fun(MONSTER_SELECT _mon); //���� �Լ�
	void Weapon_fun(WEAPON_SELECT _wea); //���� �Լ�

	void Attack_Test(CharacterFactory* _char);

	~RPG_Game(); //�Ҹ���
};