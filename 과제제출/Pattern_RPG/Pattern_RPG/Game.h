#pragma once
#include "Mecro.h"
#include "Interface.h"
#include "Weapon_List.h"
#include "Monster_List.h"

class Game
{
private:
	
protected:
	Interface* m_Inter;
	virtual Interface* Create_View(VIEW_SELECT _View_Num) = 0; //�並 �����ش�.(���� �����Լ�)
public:
	Game(); //������
	virtual void Release(); //�Ҵ� ����

	virtual ~Game() {} //�Ҹ���
};

class RPG_Game : public Game
{
private:
protected:
	virtual Interface* Create_View(VIEW_SELECT _View_Num); //�ڽĿ����� Create_View ����
public:
	RPG_Game(); //������
	void Main_Loby(); //���� ���� �κ� ȭ��
	void Main_Select_Menu(); //�޴� ����
	void Main_Monster_Menu(); //���� �޴�
	void Main_Weapon_Menu(); //���� �޴�
	void Make_Bow_List(); //���� ���� �����
	void Make_Dagger_List(); //��� ���� �����
	void Make_Gun_List(); //�� ���� �����
	void Make_Sword_List(); //�ҵ� ���� �����
	void Make_Wand_List(); //�ϵ� ���� �����
	void Make_Hammer_List(); //�ظ� ���� �����

	void Make_Goblin_List(); //��� �����
	void Make_Ock_List(); //��ũ �����
	void Make_Ouger_List(); //����� �����
	void Make_Skeleton_List(); //���̷��� �����
	void Make_Animal_List(); //���� �����
	void Make_King_List(); //�� �����
	~RPG_Game(); //�Ҹ���
};