#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"

//�Ѿ� Ŭ���� - DoEngine::Object class �� ��� �޴´�.

class Bullet : public DoEngine::Object
{
private:
	DoEngine::BitMap* m_BulletBit;
	DoEngine::Collider m_Coll; 

	float pos_x;
	float pos_y;
public:
	Bullet(); //������

	virtual void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(override)
	virtual bool Input(int _state); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(override)
	virtual void Draw(int _x, int _y); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	~Bullet(); //�Ҹ���
};