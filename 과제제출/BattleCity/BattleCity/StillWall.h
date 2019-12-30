#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"

class StillWall : public DoEngine::Object
{
private:
	DoEngine::BitMap* m_pBlockBit; //TitleScene ���ȸ�� ���
	int m_wSize, m_hSize;
	int m_posx, m_posy;
	string m_tag;
	DoEngine::Collider m_Coll;

public:
	StillWall(); //������

	virtual void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(override)
	virtual bool Input(int _state); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(override)
	virtual void Draw(int _x, int _y); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	void set_tag(string _tag); //�±� ���� 

	~StillWall(); //�Ҹ���
};
