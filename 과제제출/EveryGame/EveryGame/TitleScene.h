#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

class TitleScene : public DoEngine::Scene
{
private:
	DoEngine::BitMap* Title_Bit; //Ÿ��Ʋ ��Ʈ��
public:
	TitleScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(overrride)
	virtual bool Input(float _fETime); //Ű�Է�(overrride)
	virtual void Update(float _fETime); //Update�Լ�(overrride)
	virtual void Draw(HDC hdc); //Draw �Լ�(overrride)
	virtual void Release(); //Release() �Լ�(overrride)

	virtual ~TitleScene(); //�Ҹ���
};