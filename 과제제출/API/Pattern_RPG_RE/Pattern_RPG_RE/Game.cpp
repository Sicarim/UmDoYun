#include "Game.h"
#include "MapDraw.h"
#include "GameManager.h"
#include "MonsterManager.h"
#include "WeaponManager.h"

//������
Game::Game()
{
	m_Inter = NULL;
	m_Char = NULL;
	m_Monster = NULL;
	m_Weapon = NULL;
}

//�ʱ�ȭ �Լ�
void Game::Init()
{
	MonsterManager::get_Instence()->Monster_Init(); //���� ���� ��������
	WeaponManager::get_Instence()->Weapon_Init(); //���� ���� ��������
}

//������ ���� �Լ�
void Game::Update()
{
	Main_Loby();
}

//�Ҵ� ����
void Game::Release()
{

}

//������
RPG_Game::RPG_Game()
{
	iSelect = 0;
}

void RPG_Game::Main_Loby()
{
	iSelect = 0;

	m_Inter = Create_View(VIEW_SELECT_START);

	while (1)
	{
		m_Inter->Show_View();

		iSelect = MapDraw::MenuSelectCursor(2, 2, 20, 9);
		switch (iSelect)
		{
		case 1:
			Main_Select_Menu();
			break;
		case 2:
			return;
		}
	}
}

void RPG_Game::Main_Select_Menu()
{
	iSelect = 0;

	Make_Player_Info();
	while (1)
	{
		m_Inter = Create_View(VIEW_SELECT_START);
		m_Inter->Info_View();
		iSelect = MapDraw::MenuSelectCursor(4, 2, 20, 9);

		switch (iSelect)
		{
		case 1:
			Main_Player_Menu();
			break;
		case 2:
			Main_Monster_Menu();
			break;
		case 3:
			Main_Weapon_Menu();
			break;
		case 4:
			return;
		}
	}
}

//�÷��̾� ���� ����
void RPG_Game::Make_Player_Info()
{
	iSelect = 0;

	//�÷��̾� �̸� ����
	GameManager::get_Instence()->Make_Name();

	//�÷��̾� ���� ���ϱ�
	m_Inter = Create_View(VIEW_SELECT_PLAYER);

	while (1)
	{
		m_Inter->Show_View();
		iSelect = MapDraw::MenuSelectCursor(3, 2, 18, 9);

		switch (iSelect)
		{
		case 1:
			Player_fun(CLASS_KNIGHT);
			return;
		case 2:
			Player_fun(CLASS_ARCHER);
			return;
		case 3:
			Player_fun(CLASS_WIZARD);
			return;
		}
	}
}

//�÷��̾� �Լ�
void RPG_Game::Player_fun(CLASS_SELECT _class)
{
	string tmp_Name = "";
	string tmp_class = "";

	m_Char = Create_Char(_class);
	tmp_class = m_Char->get_ClassName();
	GameManager::get_Instence()->Make_Class(tmp_class);
}

//�÷��̾� �޴�
void RPG_Game::Main_Player_Menu()
{
	m_Inter = Create_View(VIEW_SELECT_PLAYER);
	m_Inter->Info_View();
	system("pause");
}

//���� �޴�
void RPG_Game::Main_Monster_Menu()
{	
	while (1)
	{
		m_Inter = Create_View(VIEW_SELECT_MONSTER);
		m_Inter->Show_View();

		iSelect = MapDraw::MenuSelectCursor(7, 2, 18, 9);

		switch (iSelect)
		{
		case 1:
			Monster_fun(MONSTER_GOBLIN);
			break;
		case 2:
			Monster_fun(MONSTER_OCK);
			break;
		case 3:
			Monster_fun(MONSTER_OUGER);
			break;
		case 4:
			Monster_fun(MONSTER_SKELETON);
			break;
		case 5:
			Monster_fun(MONSTER_ANIMAL);
			break;
		case 6:
			Monster_fun(MONSTER_KING);
			break;
		case 7:
			return;
		}
		system("pause");
	}
}

//���� �Լ�
void RPG_Game::Monster_fun(MONSTER_SELECT _mon)
{
	m_Monster = Create_Monster(_mon);
	m_Monster->Make_Monster();
	m_Monster->View();
}

//���� �޴�
//ĳ���Ϳ� ����°ͱ��� �Բ� ����Ұ�!!!!!
void RPG_Game::Main_Weapon_Menu()
{
	while (1)
	{
		m_Inter = Create_View(VIEW_SELECT_WEAPON);
		m_Inter->Show_View();

		iSelect = MapDraw::MenuSelectCursor(7, 2, 18, 9);

		switch (iSelect)
		{
		case 1:
			Weapon_fun(WEAPON_BOW);
			break;
		case 2:
			Weapon_fun(WEAPON_DAGGER);
			break;
		case 3:
			Weapon_fun(WEAPON_GUN);
			break;
		case 4:
			Weapon_fun(WEAPON_SWORD);
			break;
		case 5:
			Weapon_fun(WEAPON_WAND);
			break;
		case 6:
			Weapon_fun(WEAPON_HAMMER);
			break;
		case 7:
			return;
		}
		system("pause");
	}
}

//���� �Լ�
void RPG_Game::Weapon_fun(WEAPON_SELECT _wea)
{
	m_Weapon = Create_Weapon(_wea);
	m_Weapon->Make_Weapon();
	m_Weapon->View();
	GameManager::get_Instence()->Make_Weapon(_wea);
	system("pause");

	system("cls");
	m_Char->set_Weapon(m_Weapon);
	Attack_Test(m_Char);
}

void RPG_Game::Attack_Test(CharacterFactory* _char)
{
	if (!_char->EquipCheck())
		cout << "���� ���� ����!" << endl;
}


//�̷������� ���������� new�� �ع����� ��� �޸𸮸� ��ƸԴ°� �ƴѰ�?? (�����Ұ�)
//m_Inter�� ������ �����°��ΰ� ���� ������ �Ҵ��ϴ� ���ΰ�, �Ƹ� ���� �Ҵ��ϴ°Ű�����.....
Interface* RPG_Game::Create_View(VIEW_SELECT _View_Num)
{
	switch (_View_Num)
	{
	case VIEW_SELECT_START:
		return new Main_Interface;
	case VIEW_SELECT_PLAYER:
		return new Player_Interface;
	case VIEW_SELECT_MONSTER:
		return new Monster_Interface;
	case VIEW_SELECT_WEAPON:
		return new Weapon_Interface;
	case VIEW_SELECT_END:
		break;
	default:
		break;
	}
}

CharacterFactory* RPG_Game::Create_Char(CLASS_SELECT _SELECT_CLASS)
{
	switch (_SELECT_CLASS)
	{
	case CLASS_KNIGHT:
		return new Knight;
	case CLASS_ARCHER:
		return new Archer;
	case CLASS_WIZARD:
		return new Wizard;
	default:
		break;
	}
}

//Create_Monster ������.
MonsterFactory* RPG_Game::Create_Monster(MONSTER_SELECT _SELECT_MONSTER)
{
	switch (_SELECT_MONSTER)
	{
	case MONSTER_GOBLIN:
		return new Goblin;
	case MONSTER_OCK:
		return new Ock;
	case MONSTER_OUGER:
		return new Ouger;
	case MONSTER_SKELETON:
		return new Skeleton;
	case MONSTER_ANIMAL:
		return new Animal;
	case MONSTER_KING:
		return new King;
	default:
		break;
	}
}

//���� ���丮 ������
WeaponFactory* RPG_Game::Create_Weapon(WEAPON_SELECT _SELECT_WEAPON)
{
	switch (_SELECT_WEAPON)
	{
	case WEAPON_BOW:
		return new Bow;
	case WEAPON_DAGGER:
		return new Dagger;
	case WEAPON_GUN:
		return new Gun;
	case WEAPON_SWORD:
		return new Sword;
	case WEAPON_WAND:
		return new Wand;
	case WEAPON_HAMMER:
		return new Hammer;
	default:
		break;
	}
}

//�Ҹ���
RPG_Game::~RPG_Game()
{
	delete m_Inter;
}