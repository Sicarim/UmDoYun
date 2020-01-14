#pragma once
#include "DoEngine.h"
#include "defines.h"

class Bullet : public DoEngine::Object
{
private:
	float pos_x, pos_y;
	int size_x, size_y;
	float curTime;
	int Random, Birth_dir;
	int BirthCount;
	int Birth_Add;
	bool isDestroy;
	string m_tag;
	TCHAR buf[255];

	DoEngine::Collider m_Coll;
	DoEngine::BitMap* Bullet_Bit;
public:
	Bullet(); //������

	virtual void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)(override)
	virtual bool Input(int _state = 0); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(overloding)(override)
	virtual void Draw(int _x, int _y); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)
	void set_Birth(int _num); //��������

	virtual ~Bullet(); //�Ҹ���
};