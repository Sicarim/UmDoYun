#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"
#include "StillWall.h"
#include "BrokenWall.h"

class Map : public DoEngine::Object
{
private:
	TCHAR buf[255];
	int m_wSize;
	int m_hSize;
	int Broken_Count, Water_Count, Bush_Count, Still_Count;
	string m_sTag;

	//�������
	StillWall* tmp_Still;
	BrokenWall* tmp_Broken;
	vector<BrokenWall*> m_vBroken;
	vector<StillWall*> m_vStill;

	DoEngine::Collider m_MapColl; //�ݶ��̴�
	DoEngine::BitMap* m_pBack; //TitleScene ���ȸ�� ���
	
public:
	Map(); //������

	void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(override)
	bool Input(int _state); //Ű�Է�(override)
	void Update(float _fETime); //Update�Լ�(override)
	void Draw(); //Draw �Լ�(override)
	void Draw(int _x, int _y); //Draw �Լ�(override)
	void Release(); //Release() �Լ�(override)

	void All_InitBlock(); //��� �� �ʱ�ȭ

	~Map(); //�Ҹ���
};