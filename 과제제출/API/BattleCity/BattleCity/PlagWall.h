#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"

class PlagWall : public DoEngine::Object
{
private:
	int m_wSize, m_hSize;
	int m_posx, m_posy;
	int Plag_wall;
	bool isDestroy;
	string m_tag;
	TCHAR buf[255];
	TCHAR EnemyBullet[255];

	vector<DoEngine::BitMap*> m_vEgle;
	DoEngine::Collider m_Coll;
public:
	PlagWall(); //������

	void Init(int _x = 0, int _y = 0); //�ʱ�ȭ(override)
	bool Input(int _state); //Ű�Է�(override)
	void Update(float _fETime); //Update�Լ�(override)
	void Draw(); //Draw �Լ�(override)
	void Draw(int _x, int _y); //Draw �Լ�(override)
	void Release(); //Release() �Լ�(override)
	void set_tag(string _tag); //�±� ���� 

	~PlagWall(); //�Ҹ���
};