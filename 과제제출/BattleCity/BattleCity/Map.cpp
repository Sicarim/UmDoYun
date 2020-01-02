#include "Map.h"
#include "MapTool.h"
#include "GameManager.h"
#include "NodeManager.h"

//생성자
Map::Map()
{
	m_wSize = 0;
	m_hSize = 0;
}

//초기화(override)
void Map::Init(int _x, int _y)
{
	m_sTag = "BackGround";
	m_wSize = _x;
	m_hSize = _y;

	//맵 만들기
	DoEngine::MapTool::get_Instance()->Init(_x, _y, "RES\\block00.bmp", COL_SIZE + 0.1f, COL_SIZE + 0.1f, NO_WALL);
	//맵 크기만큼 콜라이더를 씌운다.
	m_MapColl.Init_Collider(m_sTag, W_SPACE, H_SPACE, DoEngine::MapTool::get_Instance()->get_wMapSize(), DoEngine::MapTool::get_Instance()->get_hMapSize());


	//test용
	for (int i = 2; i <= 5; i++)
	{
		DoEngine::MapTool::get_Instance()->set_MapInfo(1, i, BROKEN_WALL);
	}
	for (int i = 2; i <= 5; i++)
	{
		DoEngine::MapTool::get_Instance()->set_MapInfo(3, i, BROKEN_WALL);
	}
	for (int i = 2; i <= 5; i++)
	{
		DoEngine::MapTool::get_Instance()->set_MapInfo(9, i, BROKEN_WALL);
	}
	for (int i = 2; i <= 5; i++)
	{
		DoEngine::MapTool::get_Instance()->set_MapInfo(11, i, BROKEN_WALL);
	}

	for (int i = 9; i <= 12; i++)
	{
		DoEngine::MapTool::get_Instance()->set_MapInfo(1, i, BROKEN_WALL);
	}
	for (int i = 9; i <= 12; i++)
	{
		DoEngine::MapTool::get_Instance()->set_MapInfo(3, i, BROKEN_WALL);
	}
	for (int i = 9; i <= 12; i++)
	{
		DoEngine::MapTool::get_Instance()->set_MapInfo(9, i, BROKEN_WALL);
	}
	for (int i = 9; i <= 12; i++)
	{
		DoEngine::MapTool::get_Instance()->set_MapInfo(11, i, BROKEN_WALL);
	}

	DoEngine::MapTool::get_Instance()->set_MapInfo(0, 7, STILL_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(12, 7, STILL_WALL);

	DoEngine::MapTool::get_Instance()->set_MapInfo(1, 7, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(11, 7, BROKEN_WALL);

	DoEngine::MapTool::get_Instance()->set_MapInfo(5, 6, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(7, 6, BROKEN_WALL);

	DoEngine::MapTool::get_Instance()->set_MapInfo(6, 1, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(6, 2, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(6, 3, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(5, 2, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(7, 2, BROKEN_WALL);

	DoEngine::MapTool::get_Instance()->set_MapInfo(6, 8, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(6, 9, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(6, 10, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(5, 9, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(7, 9, BROKEN_WALL);


	DoEngine::MapTool::get_Instance()->set_MapInfo(5, 13, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(6, 13, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(7, 13, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(5, 14, BROKEN_WALL);
	DoEngine::MapTool::get_Instance()->set_MapInfo(7, 14, BROKEN_WALL);
	
	//블록 번호에 맞게 초기화
	All_InitBlock();
}

//모든 블럭 초기화
void Map::All_InitBlock()
{
	Broken_Count = 0;
	Water_Count = 0;
	Bush_Count = 0;
	Still_Count = 0;
	int Node_Count = 0;

	for (int i = 0; i < m_wSize; i++)
	{
		for (int j = 0; j < m_hSize; j++)
		{
			//노드 정보 삽입
			DoEngine::NodeManager::get_Instance()->Init_Nodes(i, j, Node_Count);
			Node_Count++;
			
			//부서지는 블록 만들기
			if (DoEngine::MapTool::get_Instance()->get_MapInfo(i, j) == BROKEN_WALL)
			{
				wsprintf(buf, "BrokenWall%d", Broken_Count);
				tmp_Broken = new BrokenWall;
				tmp_Broken->set_tag(buf);
				tmp_Broken->Init(i, j);
				m_vBroken.push_back(tmp_Broken);
				Broken_Count++;
			}
			//강철블록 만들기
			if (DoEngine::MapTool::get_Instance()->get_MapInfo(i, j) == STILL_WALL)
			{
				wsprintf(buf, "StiilWall%d", Still_Count);
				tmp_Still = new StillWall;
				tmp_Still->set_tag(buf);
				tmp_Still->Init(i, j);
				m_vStill.push_back(tmp_Still);
				Still_Count++;
			}
		}
	}
	DoEngine::NodeManager::get_Instance()->add_Neighbors();
	GameManager::get_Instance()->set_BrokenCount(Broken_Count);
	GameManager::get_Instance()->set_StillCount(Still_Count);
}

//키입력(override)
bool Map::Input(int _state)
{
	return false;
}

//Update함수(override)
void Map::Update(float _fETime)
{
	for (int i = 0; i < m_vBroken.size(); i++)
	{
		m_vBroken[i]->Update(_fETime);
	}
}

//Draw 함수(override)
void Map::Draw()
{
	//맵 격자무늬 그리기
	DoEngine::MapTool::get_Instance()->Default_MapDraw(W_SPACE, H_SPACE);

	for (int i = 0; i < m_vBroken.size(); i++)
	{
		m_vBroken[i]->Draw();
	}

	for (int i = 0; i < m_vStill.size(); i++)
	{
		m_vStill[i]->Draw();
	}
	

	//전체 맵 범위 그리기
	m_MapColl.Draw_Collider();
}

//Draw 함수(override)
void Map::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void Map::Release()
{

}

//소멸자
Map::~Map()
{

}