#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "GlobalDefine.h"

class Tank : public DoEngine::Object
{
private:
	TCHAR buf[256];
	int pos_x; //위치 선언(x)(시작 위치, 앞으로 움직이게 될 위치)
	int pos_y; //위치 선언(y)(시작 위치, 앞으로 움직이게 될 위치)
	int m_wSize, m_hSize;
	float curTime;
	bool is_Destroy;
	float Boom_Time;
	bool Fire, isRun;
	float fire_time;
	int Tank_Look;

	vector<string> m_vColl;
	//장갑차 비트맵 선언
	vector<DoEngine::BitMap*> m_vLeft; //왼쪽
	vector<DoEngine::BitMap*> m_vRight; //오른쪽
	vector<DoEngine::BitMap*> m_vUp; //위로
	vector<DoEngine::BitMap*> m_vDown; //아래로
	vector<DoEngine::BitMap*> m_vdirection; //방향을 담을 벡터
	DoEngine::Collider m_Coll;
	
public:
	Tank(); //생성자

	virtual void Init(int _x = 0, int _y = 0); //초기화(override)
	virtual bool Input(int _state); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(); //Draw 함수(override)
	virtual void Draw(int _x, int _y); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	void Add_Coll(); //충돌시킬 종류들을 모아둔다

	virtual ~Tank(); //소멸자
};