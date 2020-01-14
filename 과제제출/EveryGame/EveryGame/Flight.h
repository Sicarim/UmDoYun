#pragma once
#include "DoEngine.h"
#include "defines.h"

class Flight : public DoEngine::Object
{
private:
	int pos_x, pos_y;
	int size_x, size_y;
	string m_Tag;
	float curTime, sumTime;
	bool isDestroy;
	TCHAR buf[255];

	DoEngine::Collider m_Coll;
	vector<string> m_vColl;
	DoEngine::BitMap* Flight_Bit; //����� �׸� BItMap ��ü
	DoEngine::BitMap* Flight_Boom[3]; //����� ����
public:
	Flight(); //������

	virtual void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)(override)
	virtual bool Input(int _state = 0); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(overloding)(override)
	virtual void Draw(int _x, int _y); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	virtual ~Flight(); //�Ҹ���
};