#pragma once
#include "Mecro.h"

class MapManager
{
private:
	static MapManager* m_hInstence;

	int** MapSize; //�� ũ��
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

	MapManager(); //������
	void Map_Reset(); //�� �����ϱ�
	void Re_Draw_Cross(int iBefore_X, int iBefore_Y); //���� ���� �ٽ� �׸���
	void Mine_InIt(); //�ʿ� ������ ��ġ.
	int Check_Map(int This_X, int This_Y); //���� ��ǥ�� ������Ʈ�� Ȯ��
	void Draw_Object(int This_X, int This_Y, OBJECT_CHECK Number); //���� ��ǥ�� ����� �׸���.
	void Draw_Remove(int This_X, int This_Y); //��ó ���ڰ� ���ٸ� ����⸦ ����(����Լ�)
	int Find_Mine(int This_X, int This_Y); //��ó ���� ã��
	void Draw_Mine_Count(int Count, int This_X, int This_Y);//���� ã��, ��ó ������ ������ ��Ÿ����.
	~MapManager(); //�Ҹ���

	inline int get_Answer_Count()
	{
		return Answer_Count;
	}

	void Test_Map(); //�� Ȯ�ο� ��¹�
};