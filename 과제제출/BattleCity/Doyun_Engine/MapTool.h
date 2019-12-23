#pragma once
#include "GlobalDefine.h"
#include "Singleton.h"
#include "DoEngine.h"

namespace DoEngine
{
	/**
	* @brief ���� �����ϴ� MapTool
	* @details 2���� �ڷᱸ���� ���� Map�� �����. ���� ���� ����
	*/
	class MapTool : public Singleton<MapTool>
	{
	private:
		int m_wSpace, m_hSpace; //���� ����, ���ο��� �󸶳� ��� ���ΰ�?(���� ���ϴ� ��ġ�� �׸��� �ִ�.
		int m_iWidth, m_iHeight; //Map ���� ũ��, ���� ũ��
		int m_iVal; //ù ������ �ʱ�ȭ �Ұ�
		BitMap* m_DefaultBlock; //ũ�⸦ ������ ����Ʈ ��

		vector<vector<int> > m_MapPos; //���� ���� ���� (���� * ����)

		HPEN m_MapPen;
		HPEN m_oldMapPen;
		HBRUSH brush_Map;
		HBRUSH brush_oldMap;

	public:
		MapTool(); //������(default)

		void Init(int _wSize, int _hSize, string _name, float _wSpace = 0.0f, float _hSpace = 0.0f, int _val = 0); //�� �ʱ�ȭ �� �����
		void Default_MapDraw(int _wSpace = 0, int _hSpace = 0); //�⺻ ���� ���� �׸���

		int get_MapInfo(int _x, int _y); //�� Ư�� ��ġ �˻�
		void set_MapInfo(int _x, int _y, int _val); //�� Ư�� ��ġ�� �� �ֱ�
		int get_wMapSize(); //���� ��ü ũ��(����)
		int get_hMapSize(); //���� ��ü ũ��(����)

		~MapTool(); //�Ҹ���
	};
}