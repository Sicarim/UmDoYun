#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "InputHandler.h"
#include "defines.h"
#include "Bullet.h"

class Player : public DoEngine::Object
{
private:
	TCHAR buf[255];
	DoEngine::Collider m_Coll; //�ݶ��̴�
	DoEngine::ObjectPool<Bullet> m_BulletPool; //�Ѿ� ������Ʈ Ǯ ����
	Bullet* tmp_Bullet;

	//�尩 ��Ʈ�� ����
	vector<DoEngine::BitMap*> m_vLeft; //����
	vector<DoEngine::BitMap*> m_vRight; //������
	vector<DoEngine::BitMap*> m_vUp; //����
	vector<DoEngine::BitMap*> m_vDown; //�Ʒ���
	vector<DoEngine::BitMap*> m_vdirection; //������ ���� ����

	float pos_x; //��ġ ����(x)(���� ��ġ, ������ �����̰� �� ��ġ)
	float pos_y; //��ġ ����(y)(���� ��ġ, ������ �����̰� �� ��ġ)
	float curTime;
	bool Fire;
	float fire_time;

public:
	Player(); //������

	virtual void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(override)
	virtual bool Input(int _state); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(override)
	virtual void Draw(int _x, int _y); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	~Player(); //�Ҹ���
};