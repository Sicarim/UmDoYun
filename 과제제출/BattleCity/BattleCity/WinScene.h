#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

class WinScene : public DoEngine::Scene
{
private:
	int Tank_Score, UpTank_Score;
	int curStage;
	float curTime;
	int Select_Count;
	TCHAR buf[255];
	TCHAR cTank_S[255];
	TCHAR cTank[255];

	TCHAR cUpTank_S[255];
	TCHAR cUpTank[255];

	TCHAR Total_Score[255];

	DoEngine::BitMap* m_BlackBG; //�ƹ��͵� ���� ���� ���ȭ��

	DoEngine::BitMap* Tank;
	DoEngine::BitMap* UpTank;
public:
	WinScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(override)
	virtual bool Input(float _fETime); //Ű�Է�(override)
	virtual void Update(float _fETime); //Update�Լ�(override)
	virtual void Draw(HDC hdc); //Draw �Լ�(override)
	virtual void Release(); //Release() �Լ�(override)

	~WinScene(); //�Ҹ���
};