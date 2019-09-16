#pragma once
#include "Mecro.h"

class MapManager
{
private:
	static MapManager* m_hInstence;

	int** MapSize; //맵 크기
	int Hide_Mine_X;
	int Hide_Mine_Y;
	int Answer_Count;
	
public:
	static MapManager* get_Instence()
	{
		if (m_hInstence == NULL)
		{
			m_hInstence = new MapManager();
		}
		return m_hInstence;
	}

	static void del_Instence()
	{
		if (m_hInstence != NULL)
		{
			delete m_hInstence;
			m_hInstence = NULL;
		}
		m_hInstence = NULL;
	}

	MapManager(); //생성자
	void Map_Reset(); //맵 리셋하기
	void Re_Draw_Cross(int iBefore_X, int iBefore_Y); //격자 무늬 다시 그리기
	void Mine_InIt(); //맵에 마인을 설치.
	int Check_Map(int This_X, int This_Y); //현재 좌표의 오브젝트를 확인
	void Draw_Object(int This_X, int This_Y, OBJECT_CHECK Number); //현재 좌표의 깃발을 그린다.
	void Draw_Remove(int This_X, int This_Y); //근처 지뢰가 없다면 지우기를 시작(재귀함수)
	int Find_Mine(int This_X, int This_Y); //근처 지뢰 찾기
	void Draw_Mine_Count(int Count, int This_X, int This_Y);//지뢰 찾기, 근처 지뢰의 갯수를 나타낸다.
	~MapManager(); //소멸자

	inline int get_Answer_Count()
	{
		return Answer_Count;
	}

	void Test_Map(); //맵 확인용 출력문
};