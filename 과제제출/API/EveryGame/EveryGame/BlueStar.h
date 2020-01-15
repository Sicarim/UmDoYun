#pragma once
#include "DoEngine.h"
#include "defines.h"

/*
	FlightGame���� ����ϴ� BlueStar
*/

class BlueStar : public DoEngine::Object
{
private:
	int size_x, size_y;
	int Fever;
	int Random, Birth_dir;
	float curTime;
	float pos_x, pos_y;
	string m_tag;

	bool isDestroy;

	DoEngine::Collider m_Coll;
	DoEngine::BitMap* BlueStar_Bit;
	
public:
	BlueStar(); //������

	virtual void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)(override)
	virtual bool Input(int _state = 0); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(overloding)(override)
	virtual void Draw(int _x, int _y); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	virtual ~BlueStar(); //�Ҹ���
};