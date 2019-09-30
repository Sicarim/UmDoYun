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

	virtual Interface* Create_View(VIEW_SELECT _View_Num) = 0; //뷰 선언.
	virtual CharacterFactory* Create_Char(CLASS_SELECT _SELECT_CLASS) = 0; //캐릭터 선언.
	virtual MonsterFactory* Create_Monster(MONSTER_SELECT _SELECT_MONSTER) = 0; //몬스터 선언.
	virtual WeaponFactory* Create_Weapon(WEAPON_SELECT _SELECT_WEAPON) = 0; //무기 펙토리 선언

	virtual void Main_Loby() = 0; //시작화면 정의.
	virtual void Main_Select_Menu() = 0; //메뉴 선택 화면 정의.
public:
	Game(); //생성자

	virtual void Init(); //초기화 함수
	virtual void Update(); //내용을 담을 함수
	virtual void Release(); //할당 해제

	virtual ~Game() {} //소멸자
};

class RPG_Game : public Game
{
private:
	Player m_Player;
	int iSelect;
public:
	RPG_Game(); //생성자

	virtual Interface* Create_View(VIEW_SELECT _View_Num); //Create_View 재정의
	virtual CharacterFactory* Create_Char(CLASS_SELECT _SELECT_CLASS); //Create_Char 제정의
	virtual MonsterFactory* Create_Monster(MONSTER_SELECT _SELECT_MONSTER); //Create_Monster 재정의.
	virtual WeaponFactory* Create_Weapon(WEAPON_SELECT _SELECT_WEAPON); //무기 펙토리 재정의

	virtual void Main_Loby();
	virtual void Main_Select_Menu();

	void Main_Player_Menu(); //플레이어 메뉴
	void Make_Player_Info(); //플레이어 인포 설정
	void Main_Monster_Menu(); //몬스터 메뉴
	void Main_Weapon_Menu(); //무기 메뉴

	void Player_fun(CLASS_SELECT _class); //플레이어 함수
	void Monster_fun(MONSTER_SELECT _mon); //몬스터 함수
	void Weapon_fun(WEAPON_SELECT _wea); //무기 함수

	void Attack_Test(CharacterFactory* _char);

	~RPG_Game(); //소멸자
};