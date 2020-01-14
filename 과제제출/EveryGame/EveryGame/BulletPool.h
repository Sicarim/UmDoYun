#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "Bullet.h"

class BulletPool
{
private:
	float curTime;
	Bullet* m_Bullet;

	list<Bullet*> m_vStandPool; //�̸� ����� ����, ���
	vector<Bullet*> m_vBulletPool; //���� �����̴� vector
public:
	BulletPool(); //������

	void Init(); //�ʱ�ȭ
	bool Input(float _fETime); //�Է� �ޱ�
	void Update(float _fETime); //Update
	void Draw(); //�׸���
	void Release(); //�����ϱ�

	void get_Data(); //������ ������
	void Return_Data(int _num); //������ �ٽ� ����ֱ�

	~BulletPool(); //�Ҹ���
};