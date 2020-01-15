#include "MapManager.h"
#include "MapDraw.h"

MapManager* MapManager::m_hInstence = NULL;

//생성자
MapManager::MapManager()
{
	MapSize = NULL;
	//지뢰 위치 초기화
	Hide_Mine_X = 0;
	Hide_Mine_Y = 0;
	Answer_Count = 0;
}

//맵 초기화하기 - 2차원배열을 동적할당한 뒤, 지뢰를 랜덤으로 투하
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

	MapSize = new int* [MINE_HEIGHT]; //동적할당(2차원 배열)
	memset(MapSize, 0, sizeof(int) * MINE_HEIGHT); //맵을 전부 0으로 초기화

	for (int i = 0; i < MINE_HEIGHT; i++)
	{
		MapSize[i] = NULL;
	}

	for (int i = 0; i < MINE_HEIGHT; i++)
	{
		MapSize[i] = new int[MINE_WIDTH];
		memset(MapSize[i], 0, sizeof(int) * MINE_WIDTH); //맵을 전부 0으로 초기화
	}
}

//격자 무늬 다시 그리기
void MapManager::Re_Draw_Cross(int iBefore_X, int iBefore_Y)
{
	if (iBefore_X == 0 && iBefore_Y == 0)
	{
		MapDraw::DrawPoint("┌", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X == 0 && iBefore_Y == LIMIT_DOWN)
	{
		MapDraw::DrawPoint("└", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X == LIMIT_RIGHT + 1 && iBefore_Y == LIMIT_UP)
	{
		MapDraw::DrawPoint("┐", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X == LIMIT_RIGHT + 1 && iBefore_Y == LIMIT_DOWN)
	{
		MapDraw::DrawPoint("┘", iBefore_X, iBefore_Y);
	}

	else if (iBefore_Y == 0 && iBefore_X > 0 && iBefore_X < LIMIT_RIGHT + 1)
	{
		MapDraw::DrawPoint("┬", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X == 0 && iBefore_Y > 0)
	{
		MapDraw::DrawPoint("├", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X == LIMIT_RIGHT + 1 && iBefore_Y > LIMIT_UP && iBefore_Y < LIMIT_DOWN)
	{
		MapDraw::DrawPoint("┤", iBefore_X, iBefore_Y);
	}

	else if (iBefore_Y == LIMIT_DOWN && iBefore_X > 0 && iBefore_X < LIMIT_RIGHT + 1)
	{
		MapDraw::DrawPoint("┴", iBefore_X, iBefore_Y);
	}

	else if (iBefore_X >= LIMIT_LEFT && iBefore_X <= LIMIT_RIGHT && iBefore_Y >= LIMIT_UP && iBefore_Y <= LIMIT_DOWN)
	{
		MapDraw::DrawPoint("┼", iBefore_X, iBefore_Y);
	}
}

//맵에 마인을 설치.
void MapManager::Mine_InIt()
{
	for (int i = 0; i < MINE_COUNT; i++)
	{
		Hide_Mine_X = rand() % 20;
		Hide_Mine_Y = rand() % 20;

		Draw_Object(Hide_Mine_Y, Hide_Mine_X, OBJECT_CHECK_MINE);
	}
}

//현재 좌표의 오브젝트를 확인
int MapManager::Check_Map(int This_X, int This_Y)
{
	return MapSize[This_Y][This_X];
}

//현재 좌표의 해당 오브젝트를 그린다. 단 정답이라면 ANSWER을 넣는다.
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

//지뢰 찾기, 근처 지뢰의 갯수를 나타낸다.
void MapManager::Draw_Mine_Count(int Count, int This_X, int This_Y)
{
	if (Count == 0)
	{

	}
	else if (Count == 1)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("①", This_X, This_Y);
	}

	else if (Count == 2)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("②", This_X, This_Y);
	}
	else if (Count == 3)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("③", This_X, This_Y);
	}
	else if (Count == 4)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("④", This_X, This_Y);
	}
	else if (Count == 5)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("⑤", This_X, This_Y);
	}
	else if (Count == 6)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("⑥", This_X, This_Y);
	}
	else if (Count == 7)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("⑦", This_X, This_Y);
	}
	else if (Count == 8)
	{
		Draw_Object(This_X, This_Y, OBJECT_CHECK_COUNT);
		MapDraw::DrawPoint("⑧", This_X, This_Y);
	}
}

//근처 지뢰가 없다면 지우기를 시작(재귀함수)
void MapManager::Draw_Remove(int This_X, int This_Y)
{
	int Mine_Cnt = 0;

	//정해진 맵안에서만 인식
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

//근처 지뢰 찾기
int MapManager::Find_Mine(int This_X, int This_Y)
{
	int Mine_Num = 0;
	
	if (Check_Map(This_X, This_Y) != OBJECT_CHECK_MINE)
	{
		//왼쪽
		if (This_X - 1 >= 0 && Check_Map(This_X - 1, This_Y) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//오른쪽
		if (This_X + 1 < WIDTH && Check_Map(This_X + 1, This_Y) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//위
		if (This_Y - 1 >= 0 && Check_Map(This_X, This_Y - 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//아래
		if (This_Y + 1 < HEIGHT && Check_Map(This_X, This_Y + 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//왼쪽 위
		if (This_X - 1 >= 0 && This_Y - 1 >= 0 && Check_Map(This_X - 1, This_Y - 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//오른쪽 위
		if (This_X + 1 < WIDTH && This_Y - 1 >= 0 && Check_Map(This_X + 1, This_Y - 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//왼쪽 아래
		if (This_X - 1 >= 0 && This_Y + 1 < HEIGHT && Check_Map(This_X - 1, This_Y + 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
		//오른쪽 아래
		if (This_X + 1 < HEIGHT && This_Y + 1 < HEIGHT && Check_Map(This_X + 1, This_Y + 1) == OBJECT_CHECK_MINE)
		{
			Mine_Num++;
		}
	}

	return Mine_Num;
}

//맵 확인용 출력문
void MapManager::Test_Map()
{
	//맵확인용 테스트
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

//소멸자
MapManager::~MapManager()
{
	//동적할당 삭제
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