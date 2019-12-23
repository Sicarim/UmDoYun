#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"
#include "StillWall.h"

class Map
{
private:
	DoEngine::Collider m_MapColl; //�ݶ��̴�
	DoEngine::BitMap* m_pBack; //TitleScene ���ȸ�� ���
	StillWall m_Sill;
	

	int m_wSize;
	int m_hSize;
	string m_sTag;
	
public:
	Map(); //������

	void MakeMap(int _wsize, int _hsize); //�� ����
	void DrawMap(); //�� �׸���

	~Map(); //�Ҹ���
};