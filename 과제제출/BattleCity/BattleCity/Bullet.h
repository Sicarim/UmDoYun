#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"

//�Ѿ� Ŭ���� - DoEngine::Object class �� ��� �޴´�.

class Bullet : public DoEngine::Object
{
private:
	TCHAR buf[255];
	float pos_x;
	float pos_y;
	float curTime;
	float Fire_Time;
	bool is_Save;
	bool isDestroy;
	int Bullet_dir; //�Ѿ��� �߻��ϴ� ����
	float Boom_Time; //������ �ð�
	
	vector<string> m_vColl; //�浹 ó���� ������Ʈ���� ���
	vector<DoEngine::BitMap*> m_vDestroy; //���� �̹���
	vector<DoEngine::BitMap*> m_vBulletBit;
	DoEngine::Collider m_Coll;
	DoEngine::BitMap* tmp_Bullet;
	DoEngine::BitMap* m_BulletDir;
	
public:
	Bullet(); //������

	virtual void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(override)
	virtual bool Input(int _state); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(override)
	virtual void Draw(int _x, int _y); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	bool get_FireSave(); //ź�� ���̺� ����
	void set_BulletDir(int _dir); //�Ѿ� ���� ����
	int get_BulletDir(); //ź�� ���� ����
	
	void Add_Coll(); //�浹�� ������ ���

	~Bullet(); //�Ҹ���
};