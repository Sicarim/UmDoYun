#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

class TitleScene : public DoEngine::Scene
{
private:
	int Select_x;
	int Select_y;
	int Select_Count;
	TCHAR buf[255];
	DoEngine::BitMap* m_BlackBG; //�ƹ��͵� ���� ���� ���ȭ��
	DoEngine::BitMap* tmp_bit;
public:
	TitleScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(override)
	virtual bool Input(float _fETime); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(HDC hdc); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	~TitleScene(); //�Ҹ���
};