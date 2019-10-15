#include "GameManager.h"
#include "CardManager.h"

//������
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

//ī�� ����
void GameManager::Card_Shffle()
{
	tmp_card = CardManager::get_Instence()->get_Card();
	black_Card = CardManager::get_Instence()->get_BlackCard();
	/*
	�� �ڿ� ���ڰ��� ������ ������ ��������, Ȥ�� ������ ���Ҽ� �ִ�. ���� ���� ������ �Ϲ������� ������ ���������� ������ �ϴµ�, ���� �� �����ϱ� ������ �Ҹ��ڸ� ȣ���� ������.
	�Ҹ��ڿ� DeleteDC�� �����ع����� ������ �ʾҴ���, �����Ҷ����� �޶� ���������� �쿬�� ���� ���ڰ� ���õǾ� �׳� ���� ���ѹ�����!!!!���� ����!!
	*/
}

//��� �׸� �׸���
void GameManager::All_Draw(HDC hdc)
{
	int Count = 1;
	//x�� ����: 170

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

//�ð� �帣��
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

//ī�� �����
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

//�Ҹ���
GameManager::~GameManager()
{
	tmp_card.clear();
}