#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "GlobalDefine.h"

class PlayerTank : public DoEngine::Object
{
private:
	TCHAR buf[255];
	//�尩 ��Ʈ�� ����
	vector<DoEngine::BitMap*> m_vLeft; //����
	vector<DoEngine::BitMap*> m_vRight; //������
	vector<DoEngine::BitMap*> m_vUp; //����
	vector<DoEngine::BitMap*> m_vDown; //�Ʒ���

	int pos_x; //��ġ ����(x)(���� ��ġ, ������ �����̰� �� ��ġ)
	int pos_y; //��ġ ����(y)(���� ��ġ, ������ �����̰� �� ��ġ)
public:
	PlayerTank(); //������

	virtual void Init(); //�ʱ�ȭ(override)
	virtual bool Input(float _fETime); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(); //Draw �Լ�(override)
	virtual void Draw(int _x, int _y); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	~PlayerTank(); //�Ҹ���
};