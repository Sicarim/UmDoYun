#include "GameManager.h"
#include "CardManager.h"

//생성자
GameManager::GameManager()
{
	RangeCount = 0;
	x = 30;
	y = 30;

	select_One = 0;
	select_Two = 0;
	select_Count = 0;
	Answer = false;
}

//카드 섞기
void GameManager::Card_Shffle()
{
	tmp_card = CardManager::get_Instence()->get_Card();
	black_Card = CardManager::get_Instence()->get_BlackCard();
	/*
	맨 뒤에 인자값을 적으면 무엇을 선택할지, 혹은 범위를 정할수 있다. 만약 적지 않으면 일반적으로 지정된 범위내에서 선택을 하는데, 복사 후 삭제하기 때문에 소멸자를 호출해 버린다.
	소멸자에 DeleteDC를 선언해버려서 보이지 않았던것, 실행할때마다 달라 보였던것은 우연히 같은 숫자가 선택되어 그냥 리턴 시켜버린것!!!!오메 쉬벌!!
	*/
}

//모든 그림 그리기
void GameManager::All_Draw(HDC hdc)
{
	int Count = 1;
	//x축 간격: 170

	for (int i = 0; i < 20; i++)
	{
		black_Card.Black_Draw(hdc, x, y);
		x += 120;

		if (Count == 10)
		{
			x = 30;
			y = 250;
		}
		Count++;
	}

	Count = 0;
}

void GameManager::ID_Check(HWND hWnd, int _mouseX, int _mouseY)
{
	if (_mouseY > 30 && _mouseY < 250)
	{
		if (_mouseX > 30 && _mouseX < tmp_card[0].get_Width() + 30)
		{
			Click(hWnd, 0);
			Answer_Check(tmp_card[0].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 150 && _mouseX < tmp_card[1].get_Width() + 150)
		{
			Click(hWnd, 1);
			Answer_Check(tmp_card[1].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 270 && _mouseX < tmp_card[2].get_Width() + 270)
		{
			Click(hWnd, 2);
			Answer_Check(tmp_card[2].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 390 && _mouseX < tmp_card[3].get_Width() + 390)
		{
			Click(hWnd, 3);
			Answer_Check(tmp_card[3].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 510 && _mouseX < tmp_card[4].get_Width() + 510)
		{
			Click(hWnd, 4);
			Answer_Check(tmp_card[4].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 630 && _mouseX < tmp_card[5].get_Width() + 630)
		{
			Click(hWnd, 5);
			Answer_Check(tmp_card[5].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 750 && _mouseX < tmp_card[6].get_Width() + 750)
		{
			Click(hWnd, 6);
			Answer_Check(tmp_card[6].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 870 && _mouseX < tmp_card[7].get_Width() + 870)
		{
			Click(hWnd, 7);
			Answer_Check(tmp_card[7].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 990 && _mouseX < tmp_card[8].get_Width() + 990)
		{
			Click(hWnd, 8);
			Answer_Check(tmp_card[8].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 1110 && _mouseX < tmp_card[9].get_Width() + 1110)
		{
			Click(hWnd, 9);
			Answer_Check(tmp_card[9].get_Number());
			Erase_Card(hWnd);
		}
	}

	if (_mouseY > 250 && _mouseY < 470)
	{
		if (_mouseX > 30 && _mouseX < tmp_card[10].get_Width() + 30)
		{
			Click(hWnd, 10);
			Answer_Check(tmp_card[10].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 150 && _mouseX < tmp_card[11].get_Width() + 150)
		{
			Click(hWnd, 11);
			Answer_Check(tmp_card[11].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 270 && _mouseX < tmp_card[12].get_Width() + 270)
		{
			Click(hWnd, 12);
			Answer_Check(tmp_card[12].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 390 && _mouseX < tmp_card[13].get_Width() + 390)
		{
			Click(hWnd, 13);
			Answer_Check(tmp_card[13].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 510 && _mouseX < tmp_card[14].get_Width() + 510)
		{
			Click(hWnd, 14);
			Answer_Check(tmp_card[14].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 630 && _mouseX < tmp_card[15].get_Width() + 630)
		{
			Click(hWnd, 15);
			Answer_Check(tmp_card[15].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 750 && _mouseX < tmp_card[16].get_Width() + 750)
		{
			Click(hWnd, 16);
			Answer_Check(tmp_card[16].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 870 && _mouseX < tmp_card[17].get_Width() + 870)
		{
			Click(hWnd, 17);
			Answer_Check(tmp_card[17].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 990 && _mouseX < tmp_card[18].get_Width() + 990)
		{
			Click(hWnd, 18);
			Answer_Check(tmp_card[18].get_Number());
			Erase_Card(hWnd);
		}
		else if (_mouseX > 1110 && _mouseX < tmp_card[19].get_Width() + 1110)
		{
			Click(hWnd, 19);
			Answer_Check(tmp_card[19].get_Number());
			Erase_Card(hWnd);
		}
	}
}

void GameManager::Click(HWND hWnd, int _num)
{
	HDC hdc = GetDC(hWnd);

	tmp_card[_num].Draw(hdc);
}

//시간 흐르기
void GameManager::StartTimer(HWND hWnd)
{
	//HDC hdc = GetDC(hWnd);

	//SetTimer(hWnd, 1, 3000, NULL);
	//GetLocalTime(&st);

	//if (st.wSecond > 3000)
	//{
	//	black_Card.Black_Draw(hdc, 30, 30);
	//}
}

void GameManager::Answer_Check(int _id)
{
	if (select_Count == 0)
	{
		select_One = _id;
		select_Count++;
	}

	else if (select_Count == 1)
	{
		select_Two = _id;
		select_Count++;
	}
	
	if (select_Count == 2)
	{
		if (select_One == select_Two)
		{
			Answer = true;
		}
		else
		{
			select_One = 0;
			select_Two = 0;
			Answer = false;
		}
		select_Count = 0;
	}
}

//카드 지우기
void GameManager::Erase_Card(HWND hWnd)
{	
	HDC hdc = GetDC(hWnd);

	if (Answer == true)
	{
		for (int i = 0; i < CARDMAX; i++)
		{
			if (select_One == tmp_card[i].get_Number())
			{
				tmp_card[i].Erase(hdc);
			}
		}
		Answer = false;
		select_One = 0;
		select_Two = 0;
	}
}

//소멸자
GameManager::~GameManager()
{
	tmp_card.clear();
}