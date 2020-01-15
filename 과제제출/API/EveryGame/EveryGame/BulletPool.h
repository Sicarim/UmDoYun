#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "Bullet.h"

/*
	FlightGame에서 사용하는 BulletPool(ObjectPool)
	탄알의 생성, 삭제를 반복하므로 미리 갯수를 정해놓고, 필요하면 꺼내고, 파괴되면 다시 되돌리는 objectPool을 사용
*/
class BulletPool
{
private:
	float curTime;
	Bullet* m_Bullet;

	list<Bullet*> m_vStandPool; //미리 만들어 논후, 대기
	vector<Bullet*> m_vBulletPool; //실제 움직이는 vector
public:
	BulletPool(); //생성자

	void Init(); //초기화
	bool Input(float _fETime); //입력 받기
	void Update(float _fETime); //Update
	void Draw(); //그리기
	void Release(); //삭제하기

	void get_Data(); //데이터 꺼내기
	void Return_Data(int _num); //데이터 다시 집어넣기

	~BulletPool(); //소멸자
};