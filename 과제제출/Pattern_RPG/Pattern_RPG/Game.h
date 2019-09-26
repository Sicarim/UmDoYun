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
	virtual Interface* Create_View(VIEW_SELECT _View_Num) = 0; //뷰를 보여준다.(순수 가상함수)
public:
	Game(); //생성자
	virtual void Release(); //할당 해제

	virtual ~Game() {} //소멸자
};

class RPG_Game : public Game
{
private:
protected:
	virtual Interface* Create_View(VIEW_SELECT _View_Num); //자식에서의 Create_View 구현
public:
	RPG_Game(); //생성자
	void Main_Loby(); //게임 메인 로비 화면
	void Main_Select_Menu(); //메뉴 고르기
	void Main_Monster_Menu(); //몬스터 메뉴
	void Main_Weapon_Menu(); //무기 메뉴
	void Make_Bow_List(); //보우 무기 만들기
	void Make_Dagger_List(); //대거 무기 만들기
	void Make_Gun_List(); //건 무기 만들기
	void Make_Sword_List(); //소드 무기 만들기
	void Make_Wand_List(); //완드 무기 만들기
	void Make_Hammer_List(); //해머 무기 만들기

	void Make_Goblin_List(); //고블린 만들기
	void Make_Ock_List(); //오크 만들기
	void Make_Ouger_List(); //오우거 만들기
	void Make_Skeleton_List(); //스켈레톤 만들기
	void Make_Animal_List(); //동물 만들기
	void Make_King_List(); //왕 만들기
	~RPG_Game(); //소멸자
};