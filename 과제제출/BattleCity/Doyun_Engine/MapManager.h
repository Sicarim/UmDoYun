#pragma once
#include "GlobalDefine.h"
#include "Singleton.h"

namespace DoEngine
{
	class MapManager : public Singleton<MapManager>
	{
	private:
		int m_wSpace, m_hSpace; //���� ����, ���ο��� �󸶳� ��� ���ΰ�?(���� ���ϴ� ��ġ�� �׸��� �ִ�.
		int m_iWidth, m_iHeight; //Map ���� ũ��, ���� ũ��
		int m_iVal; //ù ������ �ʱ�ȭ �Ұ�
		vector<vector<int> > m_MapPos; //���� ���� ���� (���� * ����)

	public:
		MapManager(); //������(default)

		void Init(int _wSize, int _hSize, int _wSpace, int _hSpace, int _val = 0); //�� �ʱ�ȭ �� �����
		int get_MapInfo(int _x, int _y); //�� Ư�� ��ġ �˻�
		void set_MapInfo(int _x, int _y, int _val); //�� Ư�� ��ġ�� �� �ֱ�

		~MapManager(); //�Ҹ���
	};
}