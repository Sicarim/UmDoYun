#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "GlobalDefine.h"

class PlayerTank : public DoEngine::Object
{
private:
	TCHAR buf[255];
	//장갑 비트맵 선언
	vector<DoEngine::BitMap*> m_vLeft; //왼쪽
	vector<DoEngine::BitMap*> m_vRight; //오른쪽
	vector<DoEngine::BitMap*> m_vUp; //위로
	vector<DoEngine::BitMap*> m_vDown; //아래로

	int pos_x; //위치 선언(x)(시작 위치, 앞으로 움직이게 될 위치)
	int pos_y; //위치 선언(y)(시작 위치, 앞으로 움직이게 될 위치)
public:
	PlayerTank(); //생성자

	virtual void Init(); //초기화(override)
	virtual bool Input(float _fETime); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(); //Draw 함수(override)
	virtual void Draw(int _x, int _y); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	~PlayerTank(); //소멸자
};