#include "Tank.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"
#include "GameManager.h"
#include "NodeManager.h"

#include "UIManager.h"
#include "TimeManager.h"

//생성자
Tank::Tank()
{
	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();

	pos_x = 0;
	pos_y = 0;
	birth_x = 0;
	birth_y = 0;
}

//초기화(override)
void Tank::Init(int _x, int _y)
{
	int num = rand() % 100;
	//임시 비트맵 선언
	DoEngine::BitMap* tmp_bit = NULL;

	//태크 지정
	wsprintf(buf, "Tank%d", num);
	m_sTag = buf;
	//시작 위치 초기화
	birth_x = _x;
	birth_y = _y;
	Current_x = birth_x;
	Current_y = birth_y;
	AICount = 1;
	Fast_Way.clear();
	
	AIStart = false;
	is_Destroy = false;
	curTime = 0.0f;

	m_vLeft.reserve(ENEMY_KIND);
	m_vRight.reserve(ENEMY_KIND);	
	m_vUp.reserve(ENEMY_KIND);
	m_vDown.reserve(ENEMY_KIND);

	//비트맵 집어 넣기
	for (int i = 0; i < ENEMY_KIND; i++)
	{
		wsprintf(buf, "RES\\e_left_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vLeft.push_back(tmp_bit);

		wsprintf(buf, "RES\\e_right_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vRight.push_back(tmp_bit);

		wsprintf(buf, "RES\\e_up_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vUp.push_back(tmp_bit);

		wsprintf(buf, "RES\\e_down_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vDown.push_back(tmp_bit);
	}

	//시작 위치(생성 위치 초기화)
	pos_x = W_SPACE + _x * (m_vDown[1]->get_Width() * OBJECT_COL);
	pos_y = H_SPACE + _y * (m_vDown[1]->get_Height() * OBJECT_COL);

	m_wSize = (m_vDown[1]->get_Width() * COL_SIZE);
	m_hSize = (m_vDown[1]->get_Height() * COL_SIZE);
	//가장 빠른길 탐색
	Fast_Way = m_Astar.Serch_FastWay(birth_x, birth_y, 5, 12);
}

//Update함수(override)
void Tank::Update(float _fETime)
{
	curTime = _fETime;

	//탄알에 맞았다면...
	if (m_Coll.isCollider("Bullet"))
	{
		is_Destroy = true;
	}

	if (!is_Destroy)
	{
		//AI시작
		Start_AI();
	}
}

//키입력(override)
bool Tank::Input(int _state)
{
	//왼쪽
	if (_state == LEFT)
	{
		Tank_Look = LOOK_LEFT;
		m_vdirection = m_vLeft;

		if (m_Coll.get_Collider("BackGround").left < pos_x)
		{
			if (!m_Coll.isCollider(m_vColl, LEFT))
			{
				pos_x -= curTime * UNIT_SPEED;
			}
		}
	}

	else if (_state == RIGHT)
	{
		Tank_Look = LOOK_RIGHT;
		m_vdirection = m_vRight;

		if (m_Coll.get_Collider("BackGround").right > pos_x + (m_vDown[1]->get_Width()) * COL_SIZE)
		{
			if (!m_Coll.isCollider(m_vColl, RIGHT))
			{
				pos_x += curTime * UNIT_SPEED;
			}
		}
	}

	else if (_state == UP)
	{
		Tank_Look = LOOK_UP;
		m_vdirection = m_vUp;
		if (m_Coll.get_Collider("BackGround").top < pos_y)
		{
			if (!m_Coll.isCollider(m_vColl, UP))
			{
				pos_y -= curTime * UNIT_SPEED;
			}
		}
	}

	else if (_state == DOWN)
	{
		Tank_Look = LOOK_DOWN;
		m_vdirection = m_vDown;

		if (m_Coll.get_Collider("BackGround").bottom > pos_y + (m_vDown[1]->get_Height()) * COL_SIZE)
		{
			if (!m_Coll.isCollider(m_vColl, DOWN))
			{
				pos_y += curTime * UNIT_SPEED;
			}
		}
	}
	

	testx = m_vDown[1]->get_Width() * OBJECT_COL;
	testy = m_vDown[1]->get_Height() * OBJECT_COL;

	if (birth_x == 0 && birth_y == 0)
	{
		Current_x = floor((pos_x - 100) / testx);
		Current_y = floor((pos_y - 7) / testy);
	}
	else
	{
		Current_x = floor((pos_x - 40) / testx);
		Current_y = floor((pos_y - 6) / testy);
	}

	GameManager::get_Instance()->set_CurrentX(Current_x, pos_x);
	GameManager::get_Instance()->set_CurrentY(Current_y, pos_y);
	
	return false;
}

//Draw 함수(override)
void Tank::Draw()
{	
	if (is_Destroy)
	{
		m_Coll.DeleteCollider();
	}
	else
	{
		//출발하는 방향에 따라 그리기
		if (m_vdirection.empty())
		{
			m_vDown[0]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
		}

		else
		{
			if ((int)pos_x % 20 >= 0 && (int)pos_x % 20 <= 9)
			{
				m_vdirection[0]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
			}
			else if ((int)pos_x % 20 >= 10 && (int)pos_x % 20 <= 19)
			{
				m_vdirection[1]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
			}

			if ((int)pos_y % 20 >= 0 && (int)pos_y % 20 <= 9)
			{
				m_vdirection[0]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
			}
			else if ((int)pos_y % 20 >= 10 && (int)pos_y % 20 <= 19)
			{
				m_vdirection[1]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
			}
		}

		m_Coll.Init_Collider(m_sTag, pos_x, pos_y, m_vDown[1]->get_Width() * COL_SIZE, m_vDown[1]->get_Height() * COL_SIZE);
		m_Coll.Draw_Collider();
	}
	
	//m_vDown[1]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);

	//if (pos_x == 0 && pos_y == 0)
	//{
	//	m_vDown[1]->Draw(W_SPACE + pos_x, H_SPACE + pos_y, COL_SIZE, COL_SIZE);
	//	//Tank 범위 입력
	//	//m_Coll.Init_Collider(m_sTag, pos_x, pos_y, m_vDown[1]->get_Width() * COL_SIZE, m_vDown[1]->get_Height() * COL_SIZE);
	//}
	//else if (pos_x == 0 && pos_y != 0)
	//{
	//	m_vDown[1]->Draw(W_SPACE + pos_x, H_SPACE + pos_y * m_hSize, COL_SIZE, COL_SIZE);
	//	//Tank 범위 입력
	//	//m_Coll.Init_Collider(m_sTag, pos_x, pos_y, m_vDown[1]->get_Width() * COL_SIZE, m_vDown[1]->get_Height() * COL_SIZE);
	//}
	//else if (pos_x != 0 && pos_y == 0)
	//{
	//	m_vDown[1]->Draw(W_SPACE + pos_x * m_wSize, H_SPACE + pos_y, COL_SIZE, COL_SIZE);
	//	//Tank 범위 입력
	//	//m_Coll.Init_Collider(m_sTag, pos_x, pos_y, m_vDown[1]->get_Width() * COL_SIZE, m_vDown[1]->get_Height() * COL_SIZE);
	//}
	//else
	//{
	//	m_vDown[1]->Draw(W_SPACE + pos_x * m_wSize, H_SPACE + pos_y * m_hSize, COL_SIZE, COL_SIZE);
	//	//Tank 범위 입력
	//	//m_Coll.Init_Collider(m_sTag, pos_x, pos_y, m_vDown[1]->get_Width() * COL_SIZE, m_vDown[1]->get_Height() * COL_SIZE);
	//}
}

//Draw 함수(override)
void Tank::Draw(int _x, int _y)
{

}

//충돌시킬 종류들을 모아둔다
void Tank::Add_Coll()
{
	int tmp_Count = 0;
	//적 등록
	m_vColl.push_back("Enemy");

	//부서지는 벽 등록
	tmp_Count = GameManager::get_Instance()->get_BrokenCount();
	for (int i = 0; i < tmp_Count; i++)
	{
		wsprintf(buf, "BrokenWall%d", i);
		m_vColl.push_back((string)buf);
	}

	//강철 벽 등록
	tmp_Count = GameManager::get_Instance()->get_StillCount();
	for (int i = 0; i < tmp_Count; i++)
	{
		wsprintf(buf, "StiilWall%d", i);
		m_vColl.push_back((string)buf);
	}
}

//가장 빠른 길을 리턴
vector<DoEngine::Node*> Tank::get_FastWay()
{
	return Fast_Way;
}

//AI 시작
void Tank::Start_AI()
{
	/*
		행동 정의 새로하기 길찾기(AStar 문제 없음! 니잘못!)
	*/
	if (Fast_Way.size() == AICount)
	{
		return;
	}

	if (Current_x < Fast_Way[AICount]->get_NodeX() && (int)Current_y == Fast_Way[AICount]->get_NodeY())
	{
		Input(RIGHT);
	}

	else if (Current_x > Fast_Way[AICount]->get_NodeX() && (int)Current_y == Fast_Way[AICount]->get_NodeY())
	{
		Input(LEFT);
	}

	else if (Current_y > Fast_Way[AICount]->get_NodeY() && (int)Current_x == Fast_Way[AICount]->get_NodeX())
	{
		Input(UP);
	}

	else if (Current_y < Fast_Way[AICount]->get_NodeY() && (int)Current_x == Fast_Way[AICount]->get_NodeX())
	{
		Input(DOWN);
	}

	else 
	{
		AICount++;
	}
}

//Release() 함수(override)
void Tank::Release()
{

}

//소멸자
Tank::~Tank()
{

}