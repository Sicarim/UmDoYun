#include "BlueStar.h"
#include "GameManager.h"

//생성자
BlueStar::BlueStar()
{
	//위쪽에서 생성된다.
}

//초기화(시작 위치 초기화 가능)(override)
void BlueStar::Init(int _x, int _y)
{
	BlueStar_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameStar3.bmp");
	m_tag = "BlueStar";
	pos_x = _x;
	pos_y = _y;
	size_x = BlueStar_Bit->get_Width();
	size_y = BlueStar_Bit->get_Height();
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
bool BlueStar::Input(int _state)
{
	if (isDestroy)
	{
		return false;
	}
	else
	{
		/*
			Fever상태가 아닐 시 느리게 이동하며, 
			Fever상태라면 좀 더 빠르게 이동한다.
		*/
		if (!GameManager::get_Instance()->get_isFever())
		{
			pos_x += 0.3 * Random * Birth_dir;
			pos_y += curTime * STAR_SPEED;
		}
		else
		{
			pos_x += 0.3 * Random * Birth_dir;
			pos_y += curTime * FSTAR_SPEED;
		}
	}
}

//Update함수(override)
void BlueStar::Update(float _fETime)
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
		GameManager::get_Instance()->set_Score(BLUE_SCORE);
		GameManager::get_Instance()->add_FeverCount();
	}

	//벽에 닿으면 파괴
	if (m_Coll.get_Collider("BackGround").top > pos_y || m_Coll.get_Collider("BackGround").bottom < pos_y + size_y || m_Coll.get_Collider("BackGround").left > pos_x || m_Coll.get_Collider("BackGround").right < pos_x + size_y)
	{
		isDestroy = true;
	}
}

//Draw 함수(overloding)(override)
void BlueStar::Draw()
{
	//파괴되지 않는다면 그림과 콜라이더를 그린다.
	if (!isDestroy)
	{
		BlueStar_Bit->Draw(pos_x, pos_y);
		m_Coll.Draw_Collider();
	}
}

//Draw 함수(override)
void BlueStar::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void BlueStar::Release()
{
	isDestroy = false;
}

//소멸자
BlueStar::~BlueStar()
{

}