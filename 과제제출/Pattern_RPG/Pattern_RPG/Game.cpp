#include "Game.h"
#include "MapDraw.h"
#include "Weapon_Manager.h"
#include "Monster_Manager.h"

//생성자
Game::Game()
{
	m_Inter = NULL;
}

void Game::Release()
{

}

//생성자
RPG_Game::RPG_Game()
{

}

//게임 메인 로비 화면
void RPG_Game::Main_Loby()
{
	int iSelect = 0;

	while (1)
	{
		m_Inter = Create_View(VIEW_SELECT_START);
		m_Inter->Show_View();
		iSelect = MapDraw::MenuSelectCursor(2, 2, 20, 9);

		switch (iSelect)
		{
		case 1:
			Main_Select_Menu();
			break;
		case 2:
			return ;
		}
	}
}

//메뉴 고르기
void RPG_Game::Main_Select_Menu()
{
	int iSelect = 0;
	
	while (1) 
	{
		m_Inter = Create_View(VIEW_SELECT_START);
		m_Inter->Info_View();
		iSelect = MapDraw::MenuSelectCursor(3, 2, 20, 9);

		switch (iSelect)
		{
		case 1:
			Main_Monster_Menu();
			break;
		case 2:
			Main_Weapon_Menu();
			break;
		case 3:
			return;
		}
	}
}

//고블린 만들기
void RPG_Game::Make_Goblin_List()
{
	vector<string> arr = Monster_Manager::get_Instence()->get_Goblin_List();
	system("cls");

	Monster_List* Goblin = new Monster();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Monster_List* Goblin_Villain = new Villain((*iter));
		Goblin->Add_List(Goblin_Villain);
	}
	Goblin->View();
	system("pause");
}

//오크 만들기
void RPG_Game::Make_Ock_List()
{
	vector<string> arr = Monster_Manager::get_Instence()->get_Ock_List();
	system("cls");

	Monster_List* Ock = new Monster();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Monster_List* Ock_Villain = new Villain((*iter));
		Ock->Add_List(Ock_Villain);
	}
	Ock->View();
	system("pause");
}

//오우거 만들기
void RPG_Game::Make_Ouger_List()
{
	vector<string> arr = Monster_Manager::get_Instence()->get_Ouger_List();
	system("cls");

	Monster_List* Ouger = new Monster();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Monster_List* Ouger_Villain = new Villain((*iter));
		Ouger->Add_List(Ouger_Villain);
	}
	Ouger->View();
	system("pause");
}

//스켈레톤 만들기
void RPG_Game::Make_Skeleton_List()
{
	vector<string> arr = Monster_Manager::get_Instence()->get_Skeleton_List();
	system("cls");

	Monster_List* Skeleton = new Monster();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Monster_List* Skeleton_Villain = new Villain((*iter));
		Skeleton->Add_List(Skeleton_Villain);
	}
	Skeleton->View();
	system("pause");
}

//동물만들기
void RPG_Game::Make_Animal_List()
{
	vector<string> arr = Monster_Manager::get_Instence()->get_Animal_List();
	system("cls");

	Monster_List* Animal = new Monster();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Monster_List* Animal_Villain = new Villain((*iter));
		Animal->Add_List(Animal_Villain);
	}
	Animal->View();
	system("pause");
}

//왕 만들기
void RPG_Game::Make_King_List()
{
	vector<string> arr = Monster_Manager::get_Instence()->get_King_List();
	system("cls");

	Monster_List* King = new Monster();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Monster_List* King_Villain = new Villain((*iter));
		King->Add_List(King_Villain);
	}
	King->View();
	system("pause");
}

//몬스터 메뉴
void RPG_Game::Main_Monster_Menu()
{
	int iSelect = 0;
	m_Inter = Create_View(VIEW_SELECT_MONSTER);
	Monster_Manager::get_Instence()->Monster_Init(); //정보 가져오기

	while (1)
	{
		m_Inter->Show_View();
		iSelect = MapDraw::MenuSelectCursor(7, 2, 20, 9);
		
		switch (iSelect)
		{
		case 1:
			Make_Goblin_List();
			break;
		case 2:
			Make_Ock_List();
			break;
		case 3:
			Make_Ouger_List();
			break;
		case 4:
			Make_Skeleton_List();
			break;
		case 5:
			Make_Animal_List();
			break;
		case 6:
			Make_King_List();
			break;
		case 7:
			return;
		}
	}
}

//보우 무기 만들기
void RPG_Game::Make_Bow_List()
{
	vector<string> arr = Weapon_Manager::get_Instence()->get_Bow_List();
	system("cls");

	Weapon_List* Bow = new Weapon();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Weapon_List* Bow_Item = new Item((*iter));
		Bow->Add_List(Bow_Item);
	}
	Bow->View();
	system("pause");
}

//대거 무기 만들기
void RPG_Game::Make_Dagger_List()
{
	vector<string> arr = Weapon_Manager::get_Instence()->get_Dagger_List();
	system("cls");

	Weapon_List* Dagger = new Weapon();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Weapon_List* Dagger_Item = new Item((*iter));
		Dagger->Add_List(Dagger_Item);
	}
	Dagger->View();
	system("pause");
}

//건 무기 만들기
void RPG_Game::Make_Gun_List()
{
	vector<string> arr = Weapon_Manager::get_Instence()->get_Gun_List();
	system("cls");

	Weapon_List* Gun = new Weapon();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Weapon_List* Gun_Item = new Item((*iter));
		Gun->Add_List(Gun_Item);
	}
	Gun->View();
	system("pause");
}

//소드 무기 만들기
void RPG_Game::Make_Sword_List()
{
	vector<string> arr = Weapon_Manager::get_Instence()->get_Sword_List();
	system("cls");

	Weapon_List* Sword = new Weapon();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Weapon_List* Sword_Item = new Item((*iter));
		Sword->Add_List(Sword_Item);
	}
	Sword->View();
	system("pause");
}

//완드 무기 만들기
void RPG_Game::Make_Wand_List()
{
	vector<string> arr = Weapon_Manager::get_Instence()->get_Wand_List();
	system("cls");

	Weapon_List* Wand = new Weapon();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Weapon_List* Wand_Item = new Item((*iter));
		Wand->Add_List(Wand_Item);
	}
	Wand->View();
	system("pause");
}

//해머 무기 만들기
void RPG_Game::Make_Hammer_List()
{
	vector<string> arr = Weapon_Manager::get_Instence()->get_Hammer_List();
	system("cls");

	Weapon_List* Hammer = new Weapon();

	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		Weapon_List* Hammer_Item = new Item((*iter));
		Hammer->Add_List(Hammer_Item);
	}
	Hammer->View();
	system("pause");
}

//무기 메뉴
void RPG_Game::Main_Weapon_Menu()
{
	int iSelect = 0;
	m_Inter = Create_View(VIEW_SELECT_WEAPON);
	Weapon_Manager::get_Instence()->Weapon_Init(); //무기 정보 가져오기

	while (1)
	{
		m_Inter->Show_View();
		iSelect = MapDraw::MenuSelectCursor(7, 2, 20, 9);

		switch (iSelect)
		{
		case 1:
			Make_Bow_List();
			break;
		case 2:
			Make_Dagger_List();
			break;
		case 3:
			Make_Gun_List();
			break;
		case 4:
			Make_Sword_List();
			break;
		case 5:
			Make_Wand_List();
			break;
		case 6:
			Make_Hammer_List();
			break;
		case 7:
			return;
		}
	}
}

Interface* RPG_Game::Create_View(VIEW_SELECT _View_Num)
{
	switch (_View_Num)
	{
	case VIEW_SELECT_START:
		return new Main_Interface;
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

//소멸자
RPG_Game::~RPG_Game()
{
	delete m_Inter;
}