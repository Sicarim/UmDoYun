#include "MapDraw.h"

//생성자
MapDraw::MapDraw()
{
}

//지우개
void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

//원하는곳에 글자쓰기(특수문자)
void MapDraw::DrawPoint(string str, int x, int y) //두칸을 그려주기때문에 한칸 빼기
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

//중간에 string쓰기
void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

//그냥 string쓰기
void MapDraw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

//격자무늬 그리기
void MapDraw::CrossDraw(int Start_x, int Start_y, int Width, int Height)
{
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		gotoxy(Start_x, Start_y + y);
		if (y == 0)
		{
			cout << "┌";
			for (int x = 1; x < Width - 1; x++)
				cout << "┬";
			cout << "┐";
		}
		else if (y == Height - 1)
		{
			cout << "└";
			for (int x = 1; x < Width - 1; x++)
				cout << "┴";
			cout << "┘";
		}
		else
		{
			cout << "├";
			for (int x = 1; x < Width - 1; x++)
				cout << "┼";
			cout << "┤";
		}
	}
	return;
}

//그냥 박스 그리기
void MapDraw::BoxDraw(int Start_x, int Start_y, int Width, int Height)
{
	for (int y = 0; y < Height; y++)
	{
		gotoxy(Start_x, Start_y + y);
		gotoxy(Start_x, Start_y + y);

		if (y == 0)
		{
			cout << "▤";
			for (int x = 1; x < Width - 1; x++)
				cout << "▤";
			cout << "▤";
		}
		else if (y == Height - 1)
		{
			cout << "▤";
			for (int x = 1; x < Width - 1; x++)
				cout << "▤";
			cout << "▤";
		}
		else
		{
			cout << "▤";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "▤";
		}
	}
	return;
}

//소멸자
MapDraw::~MapDraw()
{
}