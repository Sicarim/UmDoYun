#include "YellowStar.h"
#include "GameManager.h"

//생성자
YellowStar::YellowStar()
{
	//오른쪽에서 생성된다.
}

//초기화(시작 위치 초기화 가능)(override)
void YellowStar::Init(int _x, int _y)
{
	YellowStar_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameStar1.bmp");
	m_tag = "YellowStar";
	pos_x = _x;
	pos_y = _y;
	size_x = YellowStar_Bit->get_Width();
	size_y = YellowStar_Bit->get_Height();
	curTime = 0.0f;
	isDestroy = false;
	Random = rand() % 10 + 1;

	//움직일 방향을 랜덤으로 지정
	if (Random % 2 == 0)
	{
		Birth_dir = 1;
	}
	else
	{
		Birth_dir = -1;
	}
}

//키입력(override)
bool YellowStar::Input(int _state)
{
	if (isDestroy)
	{
		return false;
	}
	/*
		Fever상태가 아닐 시 느리게 이동하며,
		Fever상태라면 좀 더 빠르게 이동한다.
	*/
	else
	{
		if (!GameManager::get_Instance()->get_isFever())
		{
			pos_x -= curTime * STAR_SPEED;
			pos_y += 0.3 * Random * Birth_dir;
		}
		else
		{
			pos_x -= curTime * FSTAR_SPEED;
			pos_y += 0.3 * Random * Birth_dir;
		}
	}
}

//Update함수(override)
void YellowStar::Update(float _fETime)
{
	m_Coll.Init_Collider(m_tag, pos_x, pos_y, size_x, size_y);
	curTime = _fETime;

	/*
		Flight라는 이름을 가진 Collider에 충돌하면 파괴된다.
		파괴되면서 점수와 Fever카운트를 증가시킨다
	*/
	if (m_Coll.isCollider("Flight"))
	{
		isDestroy = true;
		GameManager::get_Instance()->set_Score(YELLOW_SCORE);
		GameManager::get_Instance()->add_FeverCount();
	}

	//벽에 닿으면 파괴
	if (m_Coll.get_Collider("BackGround").top > pos_y || m_Coll.get_Collider("BackGround").bottom < pos_y + size_y || m_Coll.get_Collider("BackGround").left > pos_x)
	{
		isDestroy = true;
	}
}

//Draw 함수(overloding)(override)
void YellowStar::Draw()
{
	//파괴되지 않는다면 그림과 콜라이더를 그린다.
	if (!isDestroy)
	{
		YellowStar_Bit->Draw(pos_x, pos_y);
		m_Coll.Draw_Collider();
	}
}

//Draw 함수(override)
void YellowStar::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void YellowStar::Release()
{
}

//소멸자
YellowStar::~YellowStar()
{

}