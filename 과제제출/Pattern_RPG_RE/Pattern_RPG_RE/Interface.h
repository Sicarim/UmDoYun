#pragma once
#include "Mecro.h"
#include "MapDraw.h"

class Interface
{
protected:
	MapDraw m_Draw;
	string Name;
	string Class;
	string Weapon;
public:
	Interface(); //생성자
	virtual void Show_View() = 0; //모아보기 뷰
	virtual void Info_View() = 0; //인포 뷰
	virtual ~Interface(); //소멸자
};

class Main_Interface : public Interface
{
private:
protected:
public:
	Main_Interface() {} //생성자
	virtual void Show_View(); //모아보기 뷰
	virtual void Info_View(); //인포 뷰
	~Main_Interface() {} //소멸자
};

//무기 관련 인터페이스
class Weapon_Interface : public Interface
{
private:
public:
	Weapon_Interface() {} //생성자
	virtual void Show_View(); //무기 모아보기 뷰
	virtual void Info_View(); //무기 인포 뷰
	~Weapon_Interface() {} //소멸자
};

//몬스터 관련 인터페이스
class Monster_Interface : public Interface
{
private:

public:
	Monster_Interface() {} //생성자
	virtual void Show_View(); //몬스터 모아보기 뷰
	virtual void Info_View(); //몬스터 인포 뷰
	~Monster_Interface() {} //소멸자
};

class Player_Interface : public Interface
{
private:
public:
	Player_Interface() {}
	virtual void Show_View(); //몬스터 모아보기 뷰
	virtual void Info_View(); //몬스터 인포 뷰
	~Player_Interface() {}
};