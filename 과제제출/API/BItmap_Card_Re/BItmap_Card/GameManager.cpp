#include "GameManager.h"
#include "BitMapManager.h"
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

//생성자
GameManager::GameManager()
{
	Card_ID = 0;
	select_One = 0;
	select_Two = 0;
	Answer = true;
	c_record[0].ID = 100;
	c_record[1].ID = 100;
}

//카드 섞기
void GameManager::Card_Shuffle()
{
	int Random_ID = 101;
	int temp;
	int rand1 = 0, rand2 = 0;

	for (int i = 0; i < CARDMAX; i++)
	{
		CardShuffle[i] = Random_ID;

		Random_ID++;

		if (i == 9)
		{
			Random_ID = 101;
		}
	}

	for (int i = 0; i < SHUFFLECOUNT; i++)
	{
		rand1 = rand() % 20;
		rand2 = rand() % 20;

		if (rand1 != rand2)
		{
			temp = CardShuffle[rand1];
			CardShuffle[rand1] = CardShuffle[rand2];
			CardShuffle[rand2] = temp;
		}
	}
	/*
	맨 뒤에 인자값을 적으면 무엇을 선택할지, 혹은 범위를 정할수 있다. 만약 적지 않으면 일반적으로 지정된 범위내에서 선택을 하는데, 복사 후 삭제하기 때문에 소멸자를 호출해 버린다.
	소멸자에 DeleteDC를 선언해버려서 보이지 않았던것, 실행할때마다 달라 보였던것은 우연히 같은 숫자가 선택되어 그냥 리턴 시켜버린것!!!!오메 쉬벌!!
	*/
}

void GameManager::ID_Check(HWND hWnd, int _mouseX, int _mouseY)
{
	if (Answer)
	{
		if (_mouseY > 30 && _mouseY < 250)
		{
			if (_mouseX > 30 && _mouseX < BitMapManager::get_Instence()->get_Size() + 30)
			{
				Click(hWnd, 0, 30, 30);
			}
			else if (_mouseX > 150 && _mouseX < BitMapManager::get_Instence()->get_Size() + 150)
			{
				Click(hWnd, 1, 150, 30);
			}
			else if (_mouseX > 270 && _mouseX < BitMapManager::get_Instence()->get_Size() + 270)
			{
				Click(hWnd, 2, 270, 30);
			}
			else if (_mouseX > 390 && _mouseX < BitMapManager::get_Instence()->get_Size() + 390)
			{
				Click(hWnd, 3, 390, 30);
			}
			else if (_mouseX > 510 && _mouseX < BitMapManager::get_Instence()->get_Size() + 510)
			{
				Click(hWnd, 4, 510, 30);
			}
			else if (_mouseX > 630 && _mouseX < BitMapManager::get_Instence()->get_Size() + 630)
			{
				Click(hWnd, 5, 630, 30);
			}
			else if (_mouseX > 750 && _mouseX < BitMapManager::get_Instence()->get_Size() + 750)
			{
				Click(hWnd, 6, 750, 30);
			}
			else if (_mouseX > 870 && _mouseX < BitMapManager::get_Instence()->get_Size() + 870)
			{
				Click(hWnd, 7, 870, 30);
			}
			else if (_mouseX > 990 && _mouseX < BitMapManager::get_Instence()->get_Size() + 990)
			{
				Click(hWnd, 8, 990, 30);
			}
			else if (_mouseX > 1110 && _mouseX < BitMapManager::get_Instence()->get_Size() + 1110)
			{
				Click(hWnd, 9, 1110, 30);
			}
		}

		if (_mouseY > 250 && _mouseY < 470)
		{
			if (_mouseX > 30 && _mouseX < BitMapManager::get_Instence()->get_Size() + 30)
			{
				Click(hWnd, 10, 30, 250);
			}
			else if (_mouseX > 150 && _mouseX < BitMapManager::get_Instence()->get_Size() + 150)
			{
				Click(hWnd, 11, 150, 250);
			}
			else if (_mouseX > 270 && _mouseX < BitMapManager::get_Instence()->get_Size() + 270)
			{
				Click(hWnd, 12, 270, 250);
			}
			else if (_mouseX > 390 && _mouseX < BitMapManager::get_Instence()->get_Size() + 390)
			{
				Click(hWnd, 13, 390, 250);
			}
			else if (_mouseX > 510 && _mouseX < BitMapManager::get_Instence()->get_Size() + 510)
			{
				Click(hWnd, 14, 510, 250);
			}
			else if (_mouseX > 630 && _mouseX < BitMapManager::get_Instence()->get_Size() + 630)
			{
				Click(hWnd, 15, 630, 250);
			}
			else if (_mouseX > 750 && _mouseX < BitMapManager::get_Instence()->get_Size() + 750)
			{
				Click(hWnd, 16, 750, 250);
			}
			else if (_mouseX > 870 && _mouseX < BitMapManager::get_Instence()->get_Size() + 870)
			{
				Click(hWnd, 17, 870, 250);
			}
			else if (_mouseX > 990 && _mouseX < BitMapManager::get_Instence()->get_Size() + 990)
			{
				Click(hWnd, 18,990, 250);
			}
			else if (_mouseX > 1110 && _mouseX < BitMapManager::get_Instence()->get_Size() + 1110)
			{
				Click(hWnd, 19, 1110, 250);
			}
		}
	}
}

void GameManager::Click(HWND hWnd, int _num, int _setX, int _setY)
{
	HDC hdc = GetDC(hWnd);

	BitMapManager::get_Instence()->Maching_Card(hdc, CardShuffle[_num], _setX, _setY);
	set_ID(CardShuffle[_num]);
	Record_Click(hWnd, _setX, _setY);
}

//클릭 기록하기
void GameManager::Record_Click(HWND hWnd, int _setX, int _setY)
{
	if (c_record[0].ID == 100)
	{
		c_record[0].ID = get_ID();
		c_record[0].x = _setX;
		c_record[0].y = _setY;
	}
	else if (c_record[1].ID == 100)
	{
		c_record[1].ID = get_ID();
		c_record[1].x = _setX;
		c_record[1].y = _setY;

		SetTimer(hWnd, 1, 1500, TimeProc);
		Answer = false;
	}
}

void GameManager::Answer_Check(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);

	select_One = c_record[0].ID;
	select_Two = c_record[1].ID;

	if (select_One != select_Two)
	{
		BitMapManager::get_Instence()->BlackCard_Draw(hdc, c_record[0].x, c_record[0].y);
		BitMapManager::get_Instence()->BlackCard_Draw(hdc, c_record[1].x, c_record[1].y);
		c_record[0].ID = 100;
		c_record[1].ID = 100;
	}
	else
	{
		BitMapManager::get_Instence()->BitMap_Erase(hdc, c_record[0].ID, c_record[0].x, c_record[0].y);
		BitMapManager::get_Instence()->BitMap_Erase(hdc, c_record[1].ID, c_record[1].x, c_record[1].y);

		c_record[0].ID = 100;
		c_record[1].ID = 100;
	}
	Answer = true;
	KillTimer(hWnd, 1);
}

//소멸자
GameManager::~GameManager()
{

}
