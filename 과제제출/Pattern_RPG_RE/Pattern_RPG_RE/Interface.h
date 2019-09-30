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
	Interface(); //������
	virtual void Show_View() = 0; //��ƺ��� ��
	virtual void Info_View() = 0; //���� ��
	virtual ~Interface(); //�Ҹ���
};

class Main_Interface : public Interface
{
private:
protected:
public:
	Main_Interface() {} //������
	virtual void Show_View(); //��ƺ��� ��
	virtual void Info_View(); //���� ��
	~Main_Interface() {} //�Ҹ���
};

//���� ���� �������̽�
class Weapon_Interface : public Interface
{
private:
public:
	Weapon_Interface() {} //������
	virtual void Show_View(); //���� ��ƺ��� ��
	virtual void Info_View(); //���� ���� ��
	~Weapon_Interface() {} //�Ҹ���
};

//���� ���� �������̽�
class Monster_Interface : public Interface
{
private:

public:
	Monster_Interface() {} //������
	virtual void Show_View(); //���� ��ƺ��� ��
	virtual void Info_View(); //���� ���� ��
	~Monster_Interface() {} //�Ҹ���
};

class Player_Interface : public Interface
{
private:
public:
	Player_Interface() {}
	virtual void Show_View(); //���� ��ƺ��� ��
	virtual void Info_View(); //���� ���� ��
	~Player_Interface() {}
};