#include "MapManager.h"

namespace DoEngine
{
	//������
	MapManager::MapManager()
	{

	}

	//�� �ʱ�ȭ �� �����
	void MapManager::Init(int _wSize, int _hSize, int _wSpace, int _hSpace, int _val)
	{
		//Map ���� ũ��, ���� ũ��
		m_iWidth = _wSize;
		m_iHeight = _hSize;
		//�� ���� ���� ���� ����
		m_wSpace = _wSpace;
		m_hSpace = _hSpace;
		//�ʱ� ��
		m_iVal = _val;

		//2���� ���ͷ� ���� �� �ϼ�(m_iVal)�� �ʱ�ȭ
		m_MapPos.assign(m_iHeight, vector<int>(m_iWidth, m_iVal));
	}

	//�� Ư�� ��ġ �˻�
	int MapManager::get_MapInfo(int _x, int _y)
	{
		return m_MapPos[_y][_x];
	}

	//�� Ư�� ��ġ�� �� �ֱ�
	void MapManager::set_MapInfo(int _x, int _y, int _val)
	{
		m_MapPos[_y][_x] = _val;
	}

	//�Ҹ���
	MapManager::~MapManager()
	{

	}
}
