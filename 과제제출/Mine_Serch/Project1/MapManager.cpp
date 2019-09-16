#include "MapManager.h"
#include "MapDraw.h"

MapManager* MapManager::m_hInstence = NULL;

//������
MapManager::MapManager()
{
	MapSize = NULL;
	//���� ��ġ �ʱ�ȭ
	Hide_Mine_X = 0;
	Hide_Mine_Y = 0;
	Answer_Count = 0;
}

//�� �ʱ�ȭ�ϱ� - 2�����迭�� �����Ҵ��� ��, ���ڸ� �������� ����
void MapManager::Map_Reset()
{
	Answer_Count = 0;

	if (MapSize != NULL)
	{
		for (int i = 0; i < MINE_HEIGHT; i++)
		{
			if (MapSize[i] != NULL)
			{
				delete[] MapSize[i];
				MapSize[i] = NULL;
			}
		}

		delete[] MapSize;
		MapSize = NULL;
	}

	MapSize = new int* [MINE_HEIGHT]; //�����Ҵ�(2���� �迭)
	memset(MapSize, 0, sizeof(int) * MINE_HEIGHT); //���� ���� 0���� �ʱ�ȭ

	for (int i = 0; i < MINE_HEIGHT; i++)
	{
		MapSize[i] = NULL;
	}

	for (int i = 0; i < MINE_HEIGHT; i++)
	{
		MapSize[i] = new int[MINE_WIDTH];
		memset(MapSize[i], 0, sizeof(int) * MINE_WIDTH); //���� ���� 0���� �ʱ�ȭ
	}
}

//���� ���� �ٽ� �׸���
void MapManager::Re_Draw_Cross(int iBefore_X, int iBefore_Y)
{
	if (iBefore_X == 0 && iBefore_Y == 0)
	{
		MapDraw::DrawPoint("��", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X == 0 && iBefore_Y == LIMIT_DOWN)
	{
		MapDraw::DrawPoint("��", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X == LIMIT_RIGHT + 1 && iBefore_Y == LIMIT_UP)
	{
		MapDraw::DrawPoint("��", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X == LIMIT_RIGHT + 1 && iBefore_Y == LIMIT_DOWN)
	{
		MapDraw::DrawPoint("��", iBefore_X, iBefore_Y);
	}

	else if (iBefore_Y == 0 && iBefore_X > 0 && iBefore_X < LIMIT_RIGHT + 1)
	{
		MapDraw::DrawPoint("��", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X == 0 && iBefore_Y > 0)
	{
		MapDraw::DrawPoint("��", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X == LIMIT_RIGHT + 1 && iBefore_Y > LIMIT_UP && iBefore_Y < LIMIT_DOWN)
	{
		MapDraw::DrawPoint("��", iBefore_X, iBefore_Y);
	}

	else if (iBefore_Y == LIMIT_DOWN && iBefore_X > 0 && iBefore_X < LIMIT_RIGHT + 1)
	{
		MapDraw::DrawPoint("��", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X >= LIMIT_LEFT && iBefore_X <= LIMIT_RIGHT && iBefore_Y >= LIMIT_UP && iBefore_Y <= LIMIT_DOWN)
	{
		MapDraw::DrawPoint("��", iBefore_X, iBefore_Y);
	}
}

//�ʿ� ������ ��ġ.
void MapManager::Mine_InIt()
{
	for (int i = 0; i < MINE_COUNT; i++)
	{
		Hide_Mine_X = rand() % 20;
		Hide_Mine_Y = rand() % 20;

		Draw_Object(Hide_Mine_Y, Hide_Mine_X, OBJECT_CHECK_MINE);
	}
}

//���� ��ǥ�� ������Ʈ�� Ȯ��
int MapManager::Check_Map(int This_X, int This_Y)
{
	return MapSize[This_Y][This_X];
}

//���� ��ǥ�� �ش� ������Ʈ�� �׸���. �� �����̶�� ANSWER�� �ִ´�.
void MapManager::Draw_Object(int This_X, int This_Y, OBJECT_CHECK Number)
{
	if (Number == OBJECT_CHECK_PLAG)
	{
		if (MapSize[This_Y][This_X] == OBJECT_CHECK_MINE)
		{
			MapSize[This_Y][This_X] = OBJECT_CHECK_ANSWER;
			Answer_Count++;
		}
		else if (MapSize[This_Y][This_X] == OBJECT_CHECK_ANSWER)
		{
			MapSize[This_Y][This_X] = OBJECT_CHECK_MINE;
			Answer_Count--;
		}
		else if (MapSize[This_Y][This_X] == OBJECT_CHECK_NULL)
		{
			MapSize[This_Y][This_X] = OBJECT_CHECK_PLAG;
		}
		else
		{
			MapSize[This_Y][This_X] = OBJECT_CHECK_NULL;
		}
	}
	else
	{
		MapSize[This_Y][This_X] = Number;
	}
}

//���� ã��, ��ó ������ ������ ��Ÿ����.
void MapManager::Draw_Mine_Count(int Count, int This_X, int This_Y)
{
	if (Count == 0)
	{

	}
	else if (Count == 1)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("��", This_X, This_Y);
	}

	else if (Count == 2)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("��", This_X, This_Y);
	}
	else if (Count == 3)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("��", This_X, This_Y);
	}
	else if (Count == 4)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("��", This_X, This_Y);
	}
	else if (Count == 5)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("��", This_X, This_Y);
	}
	else if (Count == 6)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("��", This_X, This_Y);
	}
	else if (Count == 7)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("��", This_X, This_Y);
	}
	else if (Count == 8)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("��", This_X, This_Y);
	}
}

//��ó ���ڰ� ���ٸ� ����⸦ ����(����Լ�)
void MapManager::Draw_Remove(int This_X, int This_Y)
{
	int Mine_Cnt = 0;

	//������ �ʾȿ����� �ν�
	if (This_X >= 0 && This_X - 1 < MINE_WIDTH && This_Y >= 0 && This_Y < MINE_HEIGHT)
	{
		if (Check_Map(This_X, This_Y) == OBJECT_CHECK_NULL)
		{
			Mine_Cnt = Find_Mine(This_X, This_Y);
			if (Mine_Cnt > 0)
			{
				Draw_Mine_Count(Mine_Cnt, This_X, This_Y);
				return;
			}
			else
			{
				MapDraw::DrawPoint(" ", This_X, This_Y);
				Draw_Object(This_X, This_Y, OBJECT_CHECK_END);
			}
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
	Draw_Remove(This_X + 1, This_Y);
	Draw_Remove(This_X - 1, This_Y);
	Draw_Remove(This_X, This_Y + 1);
	Draw_Remove(This_X, This_Y - 1);
}

//��ó ���� ã��
int MapManager::Find_Mine(int This_X, int This_Y)
{
	int Mine_Num = 0;
	
	if (Check_Map(This_X, This_Y) != OBJECT_CHECK_MINE)
	{
		//����
		if (This_X - 1 >= 0 && Check_Map(This_X - 1, This_Y) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//������
		if (This_X + 1 < WIDTH && Check_Map(This_X + 1, This_Y) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//��
		if (This_Y - 1 >= 0 && Check_Map(This_X, This_Y - 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//�Ʒ�
		if (This_Y + 1 < HEIGHT && Check_Map(This_X, This_Y + 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//���� ��
		if (This_X - 1 >= 0 && This_Y - 1 >= 0 && Check_Map(This_X - 1, This_Y - 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//������ ��
		if (This_X + 1 < WIDTH && This_Y - 1 >= 0 && Check_Map(This_X + 1, This_Y - 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//���� �Ʒ�
		if (This_X - 1 >= 0 && This_Y + 1 < HEIGHT && Check_Map(This_X - 1, This_Y + 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//������ �Ʒ�
		if (This_X + 1 < HEIGHT && This_Y + 1 < HEIGHT && Check_Map(This_X + 1, This_Y + 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
	}

	return Mine_Num;
}

//�� Ȯ�ο� ��¹�
void MapManager::Test_Map()
{
	//��Ȯ�ο� �׽�Ʈ
	for (int i = 0; i < MINE_HEIGHT; i++)
	{
		for (int j = 0; j < MINE_WIDTH; j++)
		{
			cout << MapSize[i][j];
		}
		cout << endl;
	}

	system("pause");
}

//�Ҹ���
MapManager::~MapManager()
{
	//�����Ҵ� ����
	for (int i = 0; i < MINE_HEIGHT; ++i)
	{
		if (MapSize[i] != NULL)
		{
			delete[] MapSize[i];
		}
		MapSize[i] = NULL;
	}

	if (MapSize != NULL)
	{
		delete[] MapSize;
	}
	MapSize = NULL;
}