#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "GlobalDefine.h"

class Tank : public DoEngine::Object
{
private:
	TCHAR buf[256];
	int pos_x; //��ġ ����(x)(���� ��ġ, ������ �����̰� �� ��ġ)
	int pos_y; //��ġ ����(y)(���� ��ġ, ������ �����̰� �� ��ġ)
	int m_wSize, m_hSize;
	float curTime;
	bool is_Destroy;
	float Boom_Time;
	bool Fire, isRun;
	float fire_time;
	int Tank_Look;

	vector<string> m_vColl;
	//�尩�� ��Ʈ�� ����
	vector<DoEngine::BitMap*> m_vLeft; //����
	vector<DoEngine::BitMap*> m_vRight; //������
	vector<DoEngine::BitMap*> m_vUp; //����
	vector<DoEngine::BitMap*> m_vDown; //�Ʒ���
	vector<DoEngine::BitMap*> m_vdirection; //������ ���� ����
	DoEngine::Collider m_Coll;
	
public:
	Tank(); //������

	virtual void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(override)
	virtual bool Input(int _state); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(override)
	virtual void Draw(int _x, int _y); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	void Add_Coll(); //�浹��ų �������� ��Ƶд�

	virtual ~Tank(); //�Ҹ���
};