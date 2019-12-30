#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "InputHandler.h"
#include "defines.h"
#include "Bullet.h"

class Player : public DoEngine::Object
{
private:
	float pos_x; //위치 선언(x)(시작 위치, 앞으로 움직이게 될 위치)
	float pos_y; //위치 선언(y)(시작 위치, 앞으로 움직이게 될 위치)
	float curTime;
	bool Fire, isRun;
	float fire_time;
	int Player_Look;
	int m_wSize, m_hSize;

	vector<string> m_vColl;
	TCHAR buf[255];
	DoEngine::Collider m_Coll; //콜라이더
	DoEngine::ObjectPool<Bullet> m_BulletPool; //총알 오브젝트 풀 생성
	Bullet* tmp_Bullet;

	//장갑 비트맵 선언
	vector<DoEngine::BitMap*> m_vLeft; //왼쪽
	vector<DoEngine::BitMap*> m_vRight; //오른쪽
	vector<DoEngine::BitMap*> m_vUp; //위로
	vector<DoEngine::BitMap*> m_vDown; //아래로
	vector<DoEngine::BitMap*> m_vdirection; //방향을 담을 벡터
public:
	Player(); //생성자

	virtual void Init(int _x = 0, int _y = 0); //초기화(override)
	virtual bool Input(int _state); //키입력(override)
	virtual void Update(float _fETime); //Update함수(override)
	virtual void Draw(); //Draw 함수(override)
	virtual void Draw(int _x, int _y); //Draw 함수(override)
	virtual void Release(); //Release() 함수(override)

	void Add_Coll(); //충돌시킬 종류들을 모아둔다

	~Player(); //소멸자
};