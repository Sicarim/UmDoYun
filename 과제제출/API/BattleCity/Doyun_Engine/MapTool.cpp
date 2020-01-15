#include "MapTool.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"

namespace DoEngine
{
	//������
	MapTool::MapTool()
	{
		m_DefaultBlock = NULL;
	}

	//�� �ʱ�ȭ �� �����
	void MapTool::Init(int _wSize, int _hSize, string _name, float _wSpace, float _hSpace, int _val)
	{
		//����Ʈ ��� ����
		m_DefaultBlock = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(_name);

		//Map ���� ũ��, ���� ũ��
		m_iWidth = _wSize;
		m_iHeight = _hSize;
		//�� ���� ���� ���� ����
		m_wSpace = m_DefaultBlock->get_Width() * MAP_COL * _wSpace;
		m_hSpace = m_DefaultBlock->get_Height() * MAP_COL * _hSpace;
		//�ʱ� ��
		m_iVal = _val;
		//2���� ���ͷ� ���� �� �ϼ�(m_iVal)�� �ʱ�ȭ
		m_MapPos.assign(m_iWidth, vector<int>(m_iHeight, m_iVal));
	}

	//�������� �����
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

	//�⺻ ���� ���� �׸���(�ʰ����� �־�� �Ѵ�)
	void MapTool::Default_MapDraw(int _wSpace, int _hSpace)
	{
		if (DoEngine::ColliderManager::get_Instance()->get_DrawCollider())
		{
			//������ ���� ������ ���� �׸�
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
	
	//�� Ư�� ��ġ �˻�
	int MapTool::get_MapInfo(int _x, int _y)
	{
		return m_MapPos[_x][_y];
	}

	//�� Ư�� ��ġ�� �� �ֱ�
	void MapTool::set_MapInfo(int _x, int _y, int _val)
	{
		m_MapPos[_x][_y] = _val;
	}

	//���� ��ü ũ��(����)
	int MapTool::get_wMapSize()
	{
		return m_iWidth * m_wSpace;
	}

	//���� ��ü ũ��(����)
	int MapTool::get_hMapSize()
	{
		return m_iHeight * m_hSpace;
	}

	//�Ҹ���
	MapTool::~MapTool()
	{

	}
}
