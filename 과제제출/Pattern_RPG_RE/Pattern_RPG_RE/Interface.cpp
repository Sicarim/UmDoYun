#include "Interface.h"
#include "GameManager.h"

//������
Interface::Interface()
{
	//system("mode con cols=100 lines=30");
	Name = "";
	Class = "";
	Weapon = "";
}

//���� ���� ȭ��
void Main_Interface::Show_View()
{
	system("cls");
	m_Draw.BoxDraw(START_X, START_Y, WIDTH, HEIGH);
	m_Draw.DrawMidText("�ڡ� Pattern_RPG �١�", 50, 6);
	m_Draw.DrawMidText("1. Game Start", 50, 9);
	m_Draw.DrawMidText("2. Exit", 50, 11);
}

//���� �޴� ȭ��
void Main_Interface::Info_View()
{
	system("cls");
	m_Draw.BoxDraw(START_X, START_Y, WIDTH, HEIGH);
	m_Draw.DrawMidText("�ڡ� MENU �١�", 50, 6);
	m_Draw.DrawMidText("1. Player Info", 50, 9);
	m_Draw.DrawMidText("2. Monster Info", 50, 11);
	m_Draw.DrawMidText("3. Weapon Info", 50, 13);
	m_Draw.DrawMidText("4. Exit", 50, 15);
}

//���� ��ƺ��� ��
void Weapon_Interface::Show_View()
{
	system("cls");
	m_Draw.BoxDraw(START_X, START_Y, WIDTH, HEIGH);
	m_Draw.DrawMidText("�ڡ� Weapon_Interface �١�", 50, 6);
	m_Draw.DrawMidText("1. Bow", 50, 9);
	m_Draw.DrawMidText("2. Dagger", 50, 11);
	m_Draw.DrawMidText("3. Gun", 50, 13);
	m_Draw.DrawMidText("4. Sword", 50, 15);
	m_Draw.DrawMidText("5. Wand", 50, 17);
	m_Draw.DrawMidText("6. Hammer", 50, 19);
	m_Draw.DrawMidText("7. Exit", 50, 21);
}

//���� ���� ��
void Weapon_Interface::Info_View()
{

}

//���� ��ƺ��� ��
void Monster_Interface::Show_View()
{
	system("cls");
	m_Draw.BoxDraw(START_X, START_Y, WIDTH, HEIGH);
	m_Draw.DrawMidText("�ڡ� Monser_Interface �١�", 50, 6);
	m_Draw.DrawMidText("1. Goblin", 50, 9);
	m_Draw.DrawMidText("2. Ock", 50, 11);
	m_Draw.DrawMidText("3. Ouger", 50, 13);
	m_Draw.DrawMidText("4. Skeleton", 50, 15);
	m_Draw.DrawMidText("5. Animal", 50, 17);
	m_Draw.DrawMidText("6. King", 50, 19);
	m_Draw.DrawMidText("7. Exit", 50, 21);
}

//���� ���� ��
void Monster_Interface::Info_View()
{

}

void Player_Interface::Info_View()
{
	Name = GameManager::get_Instence()->get_Name();
	Class = GameManager::get_Instence()->get_Class();
	Weapon = GameManager::get_Instence()->get_Weapon();

	system("cls");
	m_Draw.BoxDraw(START_X, START_Y, WIDTH, HEIGH);
	m_Draw.DrawMidText("== Player Info ==", 50, 6);
	m_Draw.DrawMidText("Name : ", 47, 9);
	m_Draw.DrawMidText(Name, 52, 9);
	m_Draw.DrawMidText("Class : ", 47, 11);
	m_Draw.DrawMidText(Class, 54, 11);
	m_Draw.DrawMidText("Weapon : ", 47, 13);
	m_Draw.DrawMidText(Weapon, 54, 13);
	cout << endl;
}

void Player_Interface::Show_View()
{
	system("cls");
	m_Draw.BoxDraw(START_X, START_Y, WIDTH, HEIGH);
	m_Draw.DrawMidText("������ �����ּ���.", 50, 6);
	m_Draw.DrawMidText("1. ����", 50, 9);
	m_Draw.DrawMidText("2. ��ó", 50, 11);
	m_Draw.DrawMidText("3. ������", 50, 13);

}

//�Ҹ���
Interface::~Interface()
{
}