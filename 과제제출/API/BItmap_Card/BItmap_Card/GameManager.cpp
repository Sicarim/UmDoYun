#include "GameManager.h"
#include "CardManager.h"
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

//������
GameManager::GameManager()
{
	x = 30;
	y = 30;

	Card_ID = 0;
	select_One = 0;
	select_Two = 0;
	Answer = true;
}

//ī�� ����
void GameManager::Card_Shffle()
{
	tmp_card = CardManager::get_Instence()->get_Card();
	tmp_black = CardManager::get_Instence()->get_BlackCard();
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
		tmp_black[i].Draw(hdc);
		
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
	if (Answer)
	{
		if (_mouseY > 30 && _mouseY < 250)
		{
			if (_mouseX > 30 && _mouseX < tmp_card[0].get_Width() + 30)
			{
				Click(hWnd, 0);
			}
			else if (_mouseX > 150 && _mouseX < tmp_card[1].get_Width() + 150)
			{
				Click(hWnd, 1);
			}
			else if (_mouseX > 270 && _mouseX < tmp_card[2].get_Width() + 270)
			{
				Click(hWnd, 2);
			}
			else if (_mouseX > 390 && _mouseX < tmp_card[3].get_Width() + 390)
			{
				Click(hWnd, 3);
			}
			else if (_mouseX > 510 && _mouseX < tmp_card[4].get_Width() + 510)
			{
				Click(hWnd, 4);
			}
			else if (_mouseX > 630 && _mouseX < tmp_card[5].get_Width() + 630)
			{
				Click(hWnd, 5);
			}
			else if (_mouseX > 750 && _mouseX < tmp_card[6].get_Width() + 750)
			{
				Click(hWnd, 6);
			}
			else if (_mouseX > 870 && _mouseX < tmp_card[7].get_Width() + 870)
			{
				Click(hWnd, 7);
			}
			else if (_mouseX > 990 && _mouseX < tmp_card[8].get_Width() + 990)
			{
				Click(hWnd, 8);
			}
			else if (_mouseX > 1110 && _mouseX < tmp_card[9].get_Width() + 1110)
			{
				Click(hWnd, 9);
			}
		}

		if (_mouseY > 250 && _mouseY < 470)
		{
			if (_mouseX > 30 && _mouseX < tmp_card[10].get_Width() + 30)
			{
				Click(hWnd, 10);
			}
			else if (_mouseX > 150 && _mouseX < tmp_card[11].get_Width() + 150)
			{
				Click(hWnd, 11);
			}
			else if (_mouseX > 270 && _mouseX < tmp_card[12].get_Width() + 270)
			{
				Click(hWnd, 12);
			}
			else if (_mouseX > 390 && _mouseX < tmp_card[13].get_Width() + 390)
			{
				Click(hWnd, 13);
			}
			else if (_mouseX > 510 && _mouseX < tmp_card[14].get_Width() + 510)
			{
				Click(hWnd, 14);
			}
			else if (_mouseX > 630 && _mouseX < tmp_card[15].get_Width() + 630)
			{
				Click(hWnd, 15);
			}
			else if (_mouseX > 750 && _mouseX < tmp_card[16].get_Width() + 750)
			{
				Click(hWnd, 16);
			}
			else if (_mouseX > 870 && _mouseX < tmp_card[17].get_Width() + 870)
			{
				Click(hWnd, 17);
			}
			else if (_mouseX > 990 && _mouseX < tmp_card[18].get_Width() + 990)
			{
				Click(hWnd, 18);
			}
			else if (_mouseX > 1110 && _mouseX < tmp_card[19].get_Width() + 1110)
			{
				Click(hWnd, 19);
			}
		}
	}
}

void GameManager::Click(HWND hWnd, int _num)
{
	HDC hdc = GetDC(hWnd);

	if (tmp_card[_num].get_ChangeEnable())
	{
		tmp_card[_num].Draw(hdc);
		set_ID(_num);
		Record_Click(hWnd);
	}
}

//Ŭ�� ����ϱ�
void GameManager::Record_Click(HWND hWnd)
{
	if (ClickRecord[0] == 100)
	{
		ClickRecord[0] = get_ID();
	}
	else if (ClickRecord[1] == 100)
	{
		ClickRecord[1] = get_ID();
		SetTimer(hWnd, 1, 1500, TimeProc);
		Answer = false;
	}
}

void GameManager::Answer_Check(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	select_One = tmp_card[ClickRecord[0]].get_Number();
	select_Two = tmp_card[ClickRecord[1]].get_Number();

	if (select_One != select_Two)
	{
		tmp_black[ClickRecord[0]].Draw(hdc);
		tmp_black[ClickRecord[1]].Draw(hdc);
		ClickRecord[0] = 100;
		ClickRecord[1] = 100;
	}
	else
	{
		tmp_card[ClickRecord[0]].Erase(hdc);
		tmp_card[ClickRecord[1]].Erase(hdc);

		tmp_card[ClickRecord[0]].set_ChangeEnable(false);
		tmp_card[ClickRecord[1]].set_ChangeEnable(false);
		ClickRecord[0] = 100;
		ClickRecord[1] = 100;
	}
	Answer = true;
	KillTimer(hWnd, 1);
}

//�Ҹ���
GameManager::~GameManager()
{
	tmp_card.clear();
	tmp_black.clear();
}
