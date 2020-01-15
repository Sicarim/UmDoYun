#include "Bullet.h"

//생성자
Bullet::Bullet()
{

}

//초기화(시작 위치 초기화 가능)(override)
void Bullet::Init(int _x, int _y)
{
	Bullet_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameBullet.bmp");
	pos_x = _x;
	pos_y = _y;
	size_x = Bullet_Bit->get_Width();
	size_y = Bullet_Bit->get_Height();
	curTime = 0.0f;
	Random = rand() % 10 + 1;
	BirthCount = 0;

	isDestroy = false;
	Birth_dir = rand() % 2;

	//탄알의 방향을 정한다.
	if (Birth_dir == 0)
	{
		Birth_Add = 1;
	}
	else
	{
		Birth_Add = -1;
	}
}

//키입력(override)
bool Bullet::Input(int _state)
{
	//만약 파괴된다면 false를 리턴한다
	if (isDestroy)
	{
		return false;
	}
}

//Update함수(override)
void Bullet::Update(float _fETime)
{
	curTime = _fETime;

	//생성위치에 따라 움직임을 정의
	if (BirthCount == 0)
	{
		//위
		pos_x += 0.1 * Random * Birth_Add;
		pos_y += curTime * BULLET_SPEED;
	}
	else if (BirthCount == 1)
	{
		//왼쪽
		pos_x += curTime * BULLET_SPEED;
		pos_y += 0.1 * Random * Birth_Add;
	}
	else if (BirthCount == 2)
	{
		//아래
		pos_x += 0.1 * Random * Birth_Add;
		pos_y -= curTime * BULLET_SPEED;
	}
	else if (BirthCount == 3)
	{
		//오른쪽
		pos_x -= curTime * BULLET_SPEED;
		pos_y += 0.1 * Random * Birth_Add;
	}
	if (m_Coll.get_Collider("BackGround").top > pos_y || m_Coll.get_Collider("BackGround").bottom < pos_y + size_y || m_Coll.get_Collider("BackGround").left > pos_x || m_Coll.get_Collider("BackGround").right < pos_x + size_y)
	{
		isDestroy = true;
	}
}

//Draw 함수(overloding)(override)
void Bullet::Draw()
{
	if (!isDestroy)
	{
		//탄알을 그릴때 지속적으로 태그 등록
		m_Coll.Init_Collider(m_tag, pos_x, pos_y, size_x * 0.8, size_y * 0.8);
		Bullet_Bit->Draw(pos_x, pos_y, 0.8, 0.8);
		m_Coll.Draw_Collider();
	}
}

//Draw 함수(override)
void Bullet::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void Bullet::Release()
{
	pos_x = 0;
	pos_y = 0;
	curTime = 0.0f;
	isDestroy = false;
	BirthCount = 0;
	Birth_Add = 0;
	m_Coll.DeleteCollider();
}

//생성순서
void Bullet::set_Birth(int _num)
{
	wsprintf(buf, "Bullet%d", _num);
	m_tag = buf;
	BirthCount = _num % 4;
}

//소멸자
Bullet::~Bullet()
{

}