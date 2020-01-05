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
	DoEngine::BitMap* m_BlackBG; //아무것도 없는 검은 배경화면
	DoEngine::BitMap* tmp_bit;
public:
	TitleScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(override)
	virtual bool Input(float _fETime); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(HDC hdc); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	~TitleScene(); //소멸자
};