#include "MapTool.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"

namespace DoEngine
{
	//생성자
	MapTool::MapTool()
	{
		m_DefaultBlock = NULL;
	}

	//맵 초기화 후 만들기
	void MapTool::Init(int _wSize, int _hSize, string _name, float _wSpace, float _hSpace, int _val)
	{
		//디폴트 블록 지정
		m_DefaultBlock = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(_name);

		//Map 가로 크기, 세로 크기
		m_iWidth = _wSize;
		m_iHeight = _hSize;
		//맵 가로 세로 사이 간격
		m_wSpace = m_DefaultBlock->get_Width() * MAP_COL * _wSpace;
		m_hSpace = m_DefaultBlock->get_Height() * MAP_COL * _hSpace;
		//초기 값
		m_iVal = _val;
		//2차원 벡터로 만든 맵 완성(m_iVal)로 초기화
		m_MapPos.assign(m_iWidth, vector<int>(m_iHeight, m_iVal));
	}

	//스테이지 만들기
	void MapTool::Make_Stage(LPCTSTR _name)
	{
		HANDLE hFile = CreateFile(_name, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				DWORD readB;
				ReadFile(hFile, &m_MapPos[i][j], sizeof(int), &readB, NULL);
			}
		}
		CloseHandle(hFile);
	}

	//기본 격자 무늬 그리기(맵간격을 넣어야 한다)
	void MapTool::Default_MapDraw(int _wSpace, int _hSpace)
	{
		if (DoEngine::ColliderManager::get_Instance()->get_DrawCollider())
		{
			//맵툴을 눈에 보여줄 격자 그림
			m_MapPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			m_oldMapPen = (HPEN)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), m_MapPen);
			brush_Map = (HBRUSH)GetStockObject(NULL_BRUSH);
			brush_oldMap = (HBRUSH)SelectObject(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), brush_Map);

			for (int i = 0; i < m_iWidth; i++)
			{
				for (int j = 0; j < m_iHeight; j++)
				{
					Rectangle(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), _wSpace + i * m_wSpace, _hSpace + j * m_hSpace, _wSpace + (i + 1) * m_wSpace, _hSpace + (j + 1) * m_hSpace);
				}
			}
			DeleteObject(m_oldMapPen);
			DeleteObject(brush_oldMap);
		}
	}
	
	//맵 특정 위치 검사
	int MapTool::get_MapInfo(int _x, int _y)
	{
		return m_MapPos[_x][_y];
	}

	//맵 특정 위치에 값 넣기
	void MapTool::set_MapInfo(int _x, int _y, int _val)
	{
		m_MapPos[_x][_y] = _val;
	}

	//맵툴 전체 크기(가로)
	int MapTool::get_wMapSize()
	{
		return m_iWidth * m_wSpace;
	}

	//맵툴 전체 크기(세로)
	int MapTool::get_hMapSize()
	{
		return m_iHeight * m_hSpace;
	}

	//소멸자
	MapTool::~MapTool()
	{

	}
}
