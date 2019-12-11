#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

using namespace std;

class GameManager : public Singleton<GameManager>
{
private:
	vector<vector<int> > m_MinePos; //���� ���� ����
	
	int m_MineX; //Mine X��ǥ
	int m_MineY; //Mine Y��ǥ
	bool Trigger;
	int NumTrigger;

	int GameResult;

public:
	GameManager(); //������

	void Init(); //�� �迭 ����
	void All_Regist(); //���� Scene���
	void Key_Init(); //��� Ű ���
	int Find_Mine(int _thisx, int _thisy); //��ó ������ ������ ��Ÿ����

	int get_UnitPos(int _posx, int _posy); //Unit��ġ ����
	int get_UnitX(int _tmp); //����� ��ġ�� ��ȯ(x)
	int get_UnitY(int _tmp); //����� ��ġ�� ��ȯ(y)

	void set_GameResult(int _result); //���� ��� ��������
	int get_GameResult(); //���� ��� ����
	bool get_Trigger();
	int get_NumTrigger();

	~GameManager(); //�Ҹ���
};