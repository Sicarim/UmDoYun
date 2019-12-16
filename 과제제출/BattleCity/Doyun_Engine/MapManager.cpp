#include "MapManager.h"

namespace DoEngine
{
	//생성자
	MapManager::MapManager()
	{

	}

	//맵 초기화 후 만들기
	void MapManager::Init(int _wSize, int _hSize, int _wSpace, int _hSpace, int _val)
	{
		//Map 가로 크기, 세로 크기
		m_iWidth = _wSize;
		m_iHeight = _hSize;
		//맵 가로 세로 사이 간격
		m_wSpace = _wSpace;
		m_hSpace = _hSpace;
		//초기 값
		m_iVal = _val;

		//2차원 벡터로 만든 맵 완성(m_iVal)로 초기화
		m_MapPos.assign(m_iHeight, vector<int>(m_iWidth, m_iVal));
	}

	//맵 특정 위치 검사
	int MapManager::get_MapInfo(int _x, int _y)
	{
		return m_MapPos[_y][_x];
	}

	//맵 특정 위치에 값 넣기
	void MapManager::set_MapInfo(int _x, int _y, int _val)
	{
		m_MapPos[_y][_x] = _val;
	}

	//소멸자
	MapManager::~MapManager()
	{

	}
}
