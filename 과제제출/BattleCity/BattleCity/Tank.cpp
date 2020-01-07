#include "Tank.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"
#include "GameManager.h"
#include "NodeManager.h"
#include "MapTool.h"

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
	//탄알 태그 등록
	wsprintf(bulletNum, "Bullet%d", GameManager::get_Instance()->BulletCount());

	beforHit = false;
	//임시 비트맵 선언
	DoEngine::BitMap* tmp_bit = NULL;
	Tank_Look = LOOK_DOWN;

	//태크 지정
	//시작 위치 초기화
	birth_x = _x;
	birth_y = _y;
	Goal_x = rand() % 5 + 4;
	Goal_y = 12;
	SumTime = 0.0f;

	
	Current_x = birth_x;
	Current_y = birth_y;
	AICount = 1;
	Fast_Way.clear();
	
	AIStart = false;
	is_Destroy = false;
	Fire = false;
	curTime = 0.0f;

	//탄알 만들기
	m_BulletPool.Make_Pool(10);

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
	Fast_Way = m_Astar.Serch_FastWay(birth_x, birth_y, Goal_x, Goal_y);
	m_vColl = GameManager::get_Instance()->get_m_vColl();
	Add_Coll();
}

//충돌시킬 종류들을 모아둔다
void Tank::Add_Coll()
{
	int tmp_Count = 0;

	//물 벽 등록
	tmp_Count = GameManager::get_Instance()->get_WaterCount();
	for (int i = 0; i < tmp_Count; i++)
	{
		wsprintf(buf, "WaterWall%d", i);
		m_vColl.push_back((string)buf);
	}
}

//Update함수(override)
void Tank::Update(float _fETime)
{
	//탄알에 맞았다면...
	if (m_Coll.isCollider("Bullet1"))
	{
		if (!beforHit)
		{
			m_Coll.DeleteCollider();
			GameManager::get_Instance()->set_EnemyCount(-1);
			GameManager::get_Instance()->add_Destroy();
			beforHit = true;
			is_Destroy = true;
			m_vColl.clear();
			DoEngine::ColliderManager::get_Instance()->Release_Collider(bulletNum);
		}
	}

	if (!is_Destroy)
	{
		curTime = _fETime;

		//총알 발사
		if (Fire)
		{
			tmp_Bullet->Update(_fETime);
		}
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

	else if (_state == ATTACK)
	{
		if (!Fire)
		{
			tmp_Bullet = m_BulletPool.get_Data();
			if (Tank_Look == LOOK_LEFT)
			{
				tmp_Bullet->Init(pos_x - 20, pos_y + 20);
			}
			else if (Tank_Look == LOOK_RIGHT)
			{
				tmp_Bullet->Init(pos_x + 50, pos_y + 20);
			}
			else if (Tank_Look == LOOK_UP)
			{
				tmp_Bullet->Init(pos_x + 20, pos_y - 15);
			}
			else if (Tank_Look == LOOK_DOWN)
			{
				tmp_Bullet->Init(pos_x + 20, pos_y + 40);
			}
			tmp_Bullet->set_Info(bulletNum);
			tmp_Bullet->set_BulletDir(Tank_Look);
			Fire = true;
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
	
	return false;
}

//Draw 함수(override)
void Tank::Draw()
{
	//죽엇나?
	if (!is_Destroy)
	{
		//총알 발사
		if (Fire)
		{
			tmp_Bullet->Draw();
			//탄알이 없어졌다면....
			if (!tmp_Bullet->get_FireSave())
			{
				tmp_Bullet->Init(pos_x, pos_y);
				m_BulletPool.Return_Data(tmp_Bullet);
				Fire = false;
			}
		}

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

		//콜라이더 범위 씌우기
		m_Coll.Init_Collider(m_sTag, pos_x + 5, pos_y + 5, m_vDown[1]->get_Width() * (COL_SIZE - 0.3), m_vDown[1]->get_Height() * (COL_SIZE - 0.3));

		m_Coll.Draw_Collider();
		//Trigger콜라이더 범위 그리기
		m_triColl.Init_Collider(m_sTag, pos_x, pos_y, m_vDown[1]->get_Width() * COL_SIZE, m_vDown[1]->get_Height() * COL_SIZE, 90, 90);
	}
}

//Draw 함수(override)
void Tank::Draw(int _x, int _y)
{

}

//가장 빠른 길을 리턴
vector<DoEngine::Node*> Tank::get_FastWay()
{
	return Fast_Way;
}

//AI 시작
void Tank::Start_AI()
{
	SumTime += curTime;

	//탄알 발사
	if (SumTime > 3.0f)
	{
		Input(ATTACK);
		SumTime = 0.0f;
	}

	/*
		행동 정의 새로하기 길찾기(AStar 문제 였음! 그래도 니잘못!)
	*/
	if (m_triColl.isCollider("Player"))
	{
		int tmp_num;
		tmp_num = m_triColl.get_HitDir();

		if (tmp_num == LEFT)
		{
			Input(LEFT);
		}
		else if (tmp_num == DOWN)
		{
			Input(DOWN);
		}
		else if (tmp_num == UP)
		{
			Input(UP);
		}
		else if (tmp_num == RIGHT)
		{
			Input(RIGHT);
		}
	}

	else
	{
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

	
}

void Tank::set_Coll(string buf)
{
	m_vColl.push_back(buf);
}

//Release() 함수(override)
void Tank::Release()
{
	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();
	m_vdirection.clear();
	Fast_Way.clear();
	m_Coll.Release_Collider();
}

//소멸자
Tank::~Tank()
{

}