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

	//맵 크기만큼 콜라이더를 씌운다.
	m_MapColl.Init_Collider(m_sTag, W_SPACE, H_SPACE, DoEngine::MapTool::get_Instance()->get_wMapSize(), DoEngine::MapTool::get_Instance()->get_hMapSize());

	//블록 번호에 맞게 초기화
	All_InitBlock();
}

//모든 블럭 초기화
void Map::All_InitBlock()
{
	DoEngine::MapTool::get_Instance()->set_MapInfo(6, 14, EGLE_WALL);
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
			//물블록 만들기
			if (DoEngine::MapTool::get_Instance()->get_MapInfo(i, j) == WATER_WALL)
			{
				wsprintf(buf, "WaterWall%d", Water_Count);
				tmp_Water = new WaterWall;
				tmp_Water->set_tag(buf);
				tmp_Water->Init(i, j);
				m_vWater.push_back(tmp_Water);
				Water_Count++;
			}

			//부쉬 블록 만들기
			if (DoEngine::MapTool::get_Instance()->get_MapInfo(i, j) == BUSH_WALL)
			{
				wsprintf(buf, "BushWall%d", Bush_Count);
				tmp_Bush = new BushWall;
				tmp_Bush->set_tag(buf);
				tmp_Bush->Init(i, j);
				m_vBush.push_back(tmp_Bush);
				Bush_Count++;
			}

			//깃발 블럭 만들기
			if (DoEngine::MapTool::get_Instance()->get_MapInfo(i, j) == EGLE_WALL)
			{
				m_Plag = new PlagWall;
				m_Plag->set_tag("PlagWall");
				m_Plag->Init(i, j);
			}
		}
	}
	DoEngine::NodeManager::get_Instance()->add_Neighbors();
	GameManager::get_Instance()->set_BrokenCount(Broken_Count);
	GameManager::get_Instance()->set_StillCount(Still_Count);
	GameManager::get_Instance()->set_WaterCount(Water_Count);
	GameManager::get_Instance()->set_WaterCount(Bush_Count);
	GameManager::get_Instance()->add_WallCollider(); //충돌 콜라이더 생성
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
	m_Plag->Update(_fETime);
}

//Draw 함수(override)
void Map::Draw()
{
	//맵 격자무늬 그리기
	DoEngine::MapTool::get_Instance()->Default_MapDraw(W_SPACE, H_SPACE);

	//각종 블럭 그리기
	for (int i = 0; i < m_vBroken.size(); i++)
	{
		m_vBroken[i]->Draw();
	}

	for (int i = 0; i < m_vStill.size(); i++)
	{
		m_vStill[i]->Draw();
	}

	for (int i = 0; i < m_vWater.size(); i++)
	{
		m_vWater[i]->Draw();
	}
	
	for (int i = 0; i < m_vBush.size(); i++)
	{
		m_vBush[i]->Draw();
	}
	
	m_Plag->Draw();

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
	for (int i = 0; i < m_vBroken.size(); i++)
	{
		m_vBroken[i]->Release();
	}
	m_vBroken.clear();
	m_vStill.clear();
	m_vWater.clear();
	m_vBush.clear();
}

//소멸자
Map::~Map()
{

}