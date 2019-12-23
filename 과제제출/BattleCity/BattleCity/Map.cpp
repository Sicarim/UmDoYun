#include "Map.h"
#include "MapTool.h"

//积己磊
Map::Map()
{
	m_wSize = 0;
	m_hSize = 0;
}

//甘 积己
void Map::MakeMap(int _wsize, int _hsize)
{
	m_sTag = "BackGround";
	m_wSize = _wsize;
	m_hSize = _hsize;

	//m_MapColl.Init_Collider(m_sTag, W_SPACE, H_SPACE, DoEngine::MapTool::get_Instance()->get_wMapSize(), DoEngine::MapTool::get_Instance()->get_hMapSize());

	//m_MapColl.Init_Collider(m_sTag, W_SPACE, H_SPACE, 10, 10);

	DoEngine::MapTool::get_Instance()->Init(_wsize, _hsize, "RES\\block00.bmp", COL_SIZE, COL_SIZE);

	m_Sill.Init();

	/*for (int i = 0; i < _wsize; i++)
	{
		DoEngine::MapTool::get_Instance()->set_MapInfo(i, 0, 1);
		DoEngine::MapTool::get_Instance()->set_MapInfo(i, m_hSize - 1, 1);
	}
	for (int i = 0; i < _hsize; i++)
	{
		DoEngine::MapTool::get_Instance()->set_MapInfo(m_wSize - 1, i, 1);
		DoEngine::MapTool::get_Instance()->set_MapInfo(0, i, 1);
	}*/
}

//甘 弊府扁	
void Map::DrawMap()
{
	//甘 拜磊公刺 弊府扁
	DoEngine::MapTool::get_Instance()->Default_MapDraw(W_SPACE, H_SPACE);
	for (int i = 0; i < m_wSize; i++)
	{
		for (int j = 0; j < m_hSize; j++)
		{
			if (DoEngine::MapTool::get_Instance()->get_MapInfo(i, j) == 1)
			{
				m_Sill.Draw(i, j);
			}
		}
	}
	m_MapColl.Draw_Collider();
}

//家戈磊
Map::~Map()
{

}