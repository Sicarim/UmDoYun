#include "BitMapManager.h"

/*
	Card Width: 125
	Card Height: 125
*/
BitMapManager::BitMapManager()
{
	m_bit = NULL;
	m_ChessMap.reserve(3);
	m_White_Unit.reserve(6);
	m_Black_Unit.reserve(6);
}

//���� �ʱ�ȭ
void BitMapManager::All_Init(HWND hWnd)
{
	Map_Init(hWnd); //�� ���� �ʱ�ȭ
	Unit_Init(hWnd); //���� �ʱ�ȭ
}

//���� �׸���
void BitMapManager::All_Draw(HWND hWnd)
{
	Map_Draw(hWnd); //�� ��ü �׸���
	//Unit_Draw(hWnd); //Unit All Draw
}

//�� �ʱ�ȭ
void BitMapManager::Map_Init(HWND hWnd)
{
	TCHAR buf[256];

	for (int i = 0; i < 3; i++)
	{
		m_bit = new BitMap;

		wsprintf(buf, "RES//block0%d.bmp", i);
		m_bit->Bit_Init(hWnd, buf);
		m_ChessMap.push_back(*m_bit);
	}
}

//�� �׸���
void BitMapManager::Map_Draw(HWND hWnd)
{
	int Map_Posx = 75, Map_Posy = 75;
	int vec_tmp1 = 0, vec_tmp2 = 1;
	int Change_line = 0;

	for (int i = 1; i <= 64; i++)
	{
		if (i % 2 == 0) //White BitMap(Map) first
		{
			m_ChessMap[vec_tmp1].Bit_Draw(hWnd, Map_Posx, Map_Posy);
		}
		else if(i % 2 == 1) //Black BitMap(Map) second
		{
			m_ChessMap[vec_tmp2].Bit_Draw(hWnd, Map_Posx, Map_Posy);
		}
		Map_Posx += 101;

		//Line Change
		if (i != 0 && i % 8 == 0)
		{
			Change_line++;
			Map_Posx = 75;
			Map_Posy += 101;

			if (Change_line % 2 == 1)
			{
				vec_tmp1 = 1;
				vec_tmp2 = 0;
			}
			else
			{
				vec_tmp1 = 0;	
				vec_tmp2 = 1;
			}
		}
	}
}

//���� ĭ �׸���
void BitMapManager::Select_Draw(HWND hWnd, int _unix, int _uniy)
{	
	m_ChessMap[SELECT].Bit_Draw(hWnd, _unix, _uniy);
}

//ü���� �ʱ�ȭ
void BitMapManager::Unit_Init(HWND hWnd)
{
	/*
	0: Pawn
	1: Knigh 
	2: BIshop
	3: Rook
	4: King
	5: Queen
	->enum ������ ����
	*/

	TCHAR buf[256];

	for (int i = 0; i < 6; i++)
	{
		m_bit = new BitMap;

		wsprintf(buf, "RES//block_b_0%d.bmp", i);
		m_bit->Bit_Init(hWnd, buf);
		m_Black_Unit.push_back(*m_bit);
	}

	for (int i = 0; i < 6; i++)
	{
		m_bit = new BitMap;

		wsprintf(buf, "RES//block_w_0%d.bmp", i);
		m_bit->Bit_Init(hWnd, buf);
		m_White_Unit.push_back(*m_bit);
	}
}

//ü���� �׸���
void BitMapManager::Unit_Draw(HWND hWnd, int _unix, int _uniy, UNIT_CLASS _class, int _num)
{
	if (_num == PLAYER_ONE)
	{
		m_White_Unit[_class].Bit_Draw(hWnd, _unix, _uniy);
	}
	else
	{
		m_Black_Unit[_class].Bit_Draw(hWnd, _unix, _uniy);
	}
}

//������ ���� �ִ°��� �׸���
void BitMapManager::Unit_BlendDraw(HWND hWnd, int _unix, int _uniy)
{
	m_ChessMap[SELECT].Bit_BlendDraw(hWnd, _unix, _uniy);
}

//������ ����
void BitMapManager::Data_Release()
{
	if (m_bit != NULL)
	{
		delete m_bit;
	}
	m_bit = NULL;

	m_ChessMap.clear();
	m_White_Unit.clear();
	m_Black_Unit.clear();
}

BitMapManager::~BitMapManager()
{
	Data_Release();
}