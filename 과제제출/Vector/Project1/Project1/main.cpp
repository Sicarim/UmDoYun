#include "Mecro.h"
#include "Dagger.h"
#include "Sword.h"
#include "Hammer.h"
#include "Bow.h"

int main()
{
	Dagger m_Dagger;
	Bow m_Bow;
	Sword m_Sword;
	Hammer m_Hammer;

	int iSelect = 0;
	m_Dagger.Dagger_Info_Init();
	m_Bow.Bow_Info_Init();
	m_Hammer.Hammer_Info_Init();
	m_Sword.Sword_Info_Init();

	while (1)
	{
		system("cls");
		cout << "Welcome to Weapon_Shop!!!" << endl;
		cout << " 1. Dagger" << endl;
		cout << " 2. Bow" << endl;
		cout << " 3. Sword" << endl;
		cout << " 4. Hammer" << endl;
		cout << " 5. 종료" << endl;
		cout << "선택 : ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			m_Dagger.Dagger_Shop();
			break;
		case 2:
			m_Bow.Bow_Shop();
			break;
		case 3:
			m_Sword.Sword_Shop();
			break;
		case 4:
			m_Hammer.Hammer_Shop();
			break;
		case 5:
			return 0;
		}
	}
}