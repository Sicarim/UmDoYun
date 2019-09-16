#include "Player.h"
#include "MapDraw.h"
#include "MapManager.h"

Player::Player()
{
	First_X = 0;
	First_Y = 0;
	My_sCursor = "▲";
	My_sPlag = "¶";
}

//플레이어 초기화
void Player::Player_Init(int This_X, int This_Y)
{
	First_X = This_X;
	First_Y = This_Y;
}

//커서 움직이기
void Player::Move_Check()
{
	if (MapManager::get_Instence()->Check_Map(First_X, First_Y) == OBJECT_CHECK_NULL || 
		MapManager::get_Instence()->Check_Map(First_X, First_Y) == OBJECT_CHECK_MINE ||
		MapManager::get_Instence()->Check_Map(First_X, First_Y) == OBJECT_CHECK_END)
	{
		MapDraw::ErasePoint(First_X, First_Y);
		if (MapManager::get_Instence()->Check_Map(First_X, First_Y) != OBJECT_CHECK_END)
		{
			MapManager::get_Instence()->Re_Draw_Cross(First_X, First_Y);
		}
		
	}
}

//움직인 커서 다시 그리기
void Player::Re_Draw()
{
	if (MapManager::get_Instence()->Check_Map(First_X, First_Y) == OBJECT_CHECK_NULL || MapManager::get_Instence()->Check_Map(First_X, First_Y) == OBJECT_CHECK_MINE || MapManager::get_Instence()->Check_Map(First_X, First_Y) == OBJECT_CHECK_END)
	{
		MapDraw::DrawPoint(My_sCursor, First_X, First_Y);
	}
}

//깃발 그리기
void Player::Input_Plag()
{
	MapDraw::DrawPoint(My_sPlag, First_X, First_Y);
}

//마인 찾기.
int Player::Serch_Mine()
{
	//MapDraw::DrawPoint(My_sCursor, First_X, First_Y);

	while (1)
	{
		if (kbhit())
		{
			char ch = getch();

			switch (ch)
			{
			case UP:
				if (First_Y != LIMIT_UP)
				{
					Move_Check();
					First_Y -= 1;
					Re_Draw();
				}
				break;
			case DOWN:
				if (First_Y != LIMIT_DOWN)
				{
					Move_Check();
					First_Y += 1;
					Re_Draw();
				}
				break;
			case LEFT:
				if (First_X != LIMIT_LEFT)
				{
					Move_Check();
					First_X -= 1;
					Re_Draw();
				}
				break;
			case RIGHT:
				if (First_X <= LIMIT_RIGHT)
				{
					Move_Check();
					First_X += 1;
					Re_Draw();
				}
				break;
			case CLICK:
				return OBJECT_CHECK_CLICK;
			case PLAG:
				Input_Plag();
				return OBJECT_CHECK_PLAG;
			}
		}
	}
}

int Player::get_First_X()
{
	return First_X;
}

int Player::get_First_Y()
{
	return First_Y;
}

Player::~Player()
{

}