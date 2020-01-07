#pragma once
#include "DoEngine.h"
#include "Astar.h"
#include "defines.h"
#include "GlobalDefine.h"
#include "Bullet.h"


class UpTank : public DoEngine::Object
{
private:
	TCHAR buf[256];
	TCHAR bulletNum[255];
	int pos_x; //��ġ ����(x)(���� ��ġ, ������ �����̰� �� ��ġ)
	int pos_y; //��ġ ����(y)(���� ��ġ, ������ �����̰� �� ��ġ)
	int birth_x, birth_y; //���� ��ġ
	int Goal_x, Goal_y; //�� ��ġ
	int Current_x, Current_y; //���� ��ġ

	int m_wSize, m_hSize;
	float curTime;
	bool is_Destroy;
	bool Fire, isRun;
	float fire_time;
	int UpTank_Look;
	bool beforHit;

	bool AIStart;
	int AICount;
	float SumTime;

	vector<string> m_vColl;
	DoEngine::TriggerCollider m_triColl; //Ʈ���� �ݶ��̴�
	//�尩�� ��Ʈ�� ����
	vector<DoEngine::BitMap*> m_vLeft; //����
	vector<DoEngine::BitMap*> m_vRight; //������
	vector<DoEngine::BitMap*> m_vUp; //����
	vector<DoEngine::BitMap*> m_vDown; //�Ʒ���
	vector<DoEngine::BitMap*> m_vdirection; //������ ���� ����
	DoEngine::ObjectPool<Bullet> m_BulletPool; //�Ѿ� ������Ʈ Ǯ ����
	Bullet* tmp_Bullet;

	DoEngine::Collider m_Coll;
	DoEngine::AStar m_Astar;
	vector<DoEngine::Node*> Fast_Way;

	int testx, testy;
public:
	UpTank(); //������

	virtual void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(override)
	virtual bool Input(int _state); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(override)
	virtual void Draw(int _x, int _y); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	void Add_Coll(); //�浹��ų �������� ��Ƶд�
	void Start_AI(); //AI ����
	void set_Coll(string buf);
	vector<DoEngine::Node*> get_FastWay(); //���� ���� ���� ����

	virtual ~UpTank(); //�Ҹ���
};