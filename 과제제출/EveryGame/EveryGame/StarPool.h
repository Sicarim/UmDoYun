#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "BlueStar.h"
#include "GreenStar.h"
#include "YellowStar.h"

class StarPool
{
private:
	float curTime;
	DoEngine::Object* m_Star;

	list<DoEngine::Object*> m_vStandPool; //�̸� ����� ����, ���
	vector<DoEngine::Object*> m_vStarPool; //���� �����̴� vector
public:
	StarPool(); //������

	void Init(); //�ʱ�ȭ
	bool Input(float _fETime); //�Է� �ޱ�
	void Update(float _fETime); //Update
	void Draw(); //�׸���
	void Release(); //�����ϱ�

	void get_Data(); //������ ������
	void Return_Data(int _num); //������ �ٽ� ����ֱ�

	~StarPool(); //�Ҹ���
};