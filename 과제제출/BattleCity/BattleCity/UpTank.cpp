#include "UpTank.h"
#include "ResourcesManager.h"
#include "ColliderManager.h"
#include "GameManager.h"
#include "NodeManager.h"
#include "MapTool.h"

//������
UpTank::UpTank()
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

//�ʱ�ȭ(override)
void UpTank::Init(int _x, int _y)
{
	beforHit = false;
	//�ӽ� ��Ʈ�� ����
	DoEngine::BitMap* tmp_bit = NULL;
	UpTank_Look = LOOK_DOWN;

	//��ũ ����
	//m_sTag = buf;
	//���� ��ġ �ʱ�ȭ
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

	//ź�� �����
	m_BulletPool.Make_Pool(10);

	m_vLeft.reserve(ENEMY_KIND);
	m_vRight.reserve(ENEMY_KIND);
	m_vUp.reserve(ENEMY_KIND);
	m_vDown.reserve(ENEMY_KIND);

	//��Ʈ�� ���� �ֱ�
	for (int i = 0; i < ENEMY_KIND + 1; i++)
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

	//���� ��ġ(���� ��ġ �ʱ�ȭ)
	pos_x = W_SPACE + _x * (m_vDown[1]->get_Width() * OBJECT_COL);
	pos_y = H_SPACE + _y * (m_vDown[1]->get_Height() * OBJECT_COL);

	m_wSize = (m_vDown[1]->get_Width() * COL_SIZE);
	m_hSize = (m_vDown[1]->get_Height() * COL_SIZE);
	//���� ������ Ž��
	Fast_Way = m_Astar.Serch_FastWay(birth_x, birth_y, Goal_x, Goal_y);
	Add_Coll();
}

//Update�Լ�(override)
void UpTank::Update(float _fETime)
{
	//ź�˿� �¾Ҵٸ�...
	if (m_Coll.isCollider("Bullet"))
	{
		if (!beforHit)
		{
			m_Coll.DeleteCollider();
			GameManager::get_Instance()->set_EnemyCount(-1);
			GameManager::get_Instance()->add_Destroy();
			beforHit = true;
			is_Destroy = true;
		}
	}

	if (!is_Destroy)
	{
		curTime = _fETime;

		//�Ѿ� �߻�
		if (Fire)
		{
			tmp_Bullet->Update(_fETime);
		}
		//AI����
		Start_AI();
	}
}

//Ű�Է�(override)
bool UpTank::Input(int _state)
{
	//����
	if (_state == LEFT)
	{
		UpTank_Look = LOOK_LEFT;
		m_vdirection = m_vLeft;

		if (m_Coll.get_Collider("BackGround").left < pos_x)
		{
			if (!m_Coll.isCollider(m_vColl, LEFT))
			{
				pos_x -= curTime * (UNIT_SPEED + 40);
			}
		}
	}

	else if (_state == RIGHT)
	{
		UpTank_Look = LOOK_RIGHT;
		m_vdirection = m_vRight;

		if (m_Coll.get_Collider("BackGround").right > pos_x + (m_vDown[1]->get_Width()) * COL_SIZE)
		{
			if (!m_Coll.isCollider(m_vColl, RIGHT))
			{
				pos_x += curTime * (UNIT_SPEED + 40);
			}
		}
	}

	else if (_state == UP)
	{
		UpTank_Look = LOOK_UP;
		m_vdirection = m_vUp;
		if (m_Coll.get_Collider("BackGround").top < pos_y)
		{
			if (!m_Coll.isCollider(m_vColl, UP))
			{
				pos_y -= curTime * (UNIT_SPEED + 40);
			}
		}
	}

	else if (_state == DOWN)
	{
		UpTank_Look = LOOK_DOWN;
		m_vdirection = m_vDown;

		if (m_Coll.get_Collider("BackGround").bottom > pos_y + (m_vDown[1]->get_Height()) * COL_SIZE)
		{
			if (!m_Coll.isCollider(m_vColl, DOWN))
			{
				pos_y += curTime * (UNIT_SPEED + 40);
			}
		}
	}

	else if (_state == ATTACK)
	{
		if (!Fire)
		{
			tmp_Bullet = m_BulletPool.get_Data();
			if (UpTank_Look == LOOK_LEFT)
			{
				tmp_Bullet->Init(pos_x - 20, pos_y + 20);
			}
			else if (UpTank_Look == LOOK_RIGHT)
			{
				tmp_Bullet->Init(pos_x + 50, pos_y + 20);
			}
			else if (UpTank_Look == LOOK_UP)
			{
				tmp_Bullet->Init(pos_x + 20, pos_y - 15);
			}
			else if (UpTank_Look == LOOK_DOWN)
			{
				tmp_Bullet->Init(pos_x + 20, pos_y + 40);
			}

			tmp_Bullet->set_BulletDir(UpTank_Look);
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

	GameManager::get_Instance()->set_CurrentX(Current_x, pos_x);
	GameManager::get_Instance()->set_CurrentY(Current_y, pos_y);

	return false;
}

//Draw �Լ�(override)
void UpTank::Draw()
{
	

	//�׾���?
	if (!is_Destroy)
	{
		//�Ѿ� �߻�
		if (Fire)
		{
			tmp_Bullet->Draw();
			//ź���� �������ٸ�....
			if (!tmp_Bullet->get_FireSave())
			{
				tmp_Bullet->Init(pos_x, pos_y);
				m_BulletPool.Return_Data(tmp_Bullet);
				Fire = false;
			}
		}

		//����ϴ� ���⿡ ���� �׸���
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
				m_vdirection[2]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
			}

			if ((int)pos_y % 20 >= 0 && (int)pos_y % 20 <= 9)
			{
				m_vdirection[0]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
			}
			else if ((int)pos_y % 20 >= 10 && (int)pos_y % 20 <= 19)
			{
				m_vdirection[2]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
			}
		}

		//�ݶ��̴� ���� �����
		m_Coll.Init_Collider(m_sTag, pos_x + 10, pos_y + 10, m_vDown[1]->get_Width() * (COL_SIZE - 0.7), m_vDown[1]->get_Height() * (COL_SIZE - 0.7));
		//Trigger�ݶ��̴� ���� �׸���
		m_triColl.Init_Collider(m_sTag, pos_x, pos_y, m_vDown[1]->get_Width() * COL_SIZE, m_vDown[1]->get_Height() * COL_SIZE, 90, 90);
		m_Coll.Draw_Collider();
	}
}

//Draw �Լ�(override)
void UpTank::Draw(int _x, int _y)
{

}

//�浹��ų �������� ��Ƶд�
void UpTank::Add_Coll()
{
	int tmp_Count = 0;

	//�μ����� �� ���
	tmp_Count = GameManager::get_Instance()->get_BrokenCount();
	for (int i = 0; i < tmp_Count; i++)
	{
		wsprintf(buf, "BrokenWall%d", i);
		m_vColl.push_back((string)buf);
	}

	//��ö �� ���
	tmp_Count = GameManager::get_Instance()->get_StillCount();
	for (int i = 0; i < tmp_Count; i++)
	{
		wsprintf(buf, "StiilWall%d", i);
		m_vColl.push_back((string)buf);
	}

	//�� �� ���
	tmp_Count = GameManager::get_Instance()->get_WaterCount();
	for (int i = 0; i < tmp_Count; i++)
	{
		wsprintf(buf, "WaterWall%d", i);
		m_vColl.push_back((string)buf);
	}
}

//���� ���� ���� ����
vector<DoEngine::Node*> UpTank::get_FastWay()
{
	return Fast_Way;
}

//AI ����
void UpTank::Start_AI()
{
	SumTime += curTime;

	//ź�� �߻�
	if (SumTime > 3.0f)
	{
		Input(ATTACK);
		SumTime = 0.0f;
	}

	/*
		�ൿ ���� �����ϱ� ��ã��(AStar ���� ����! �׷��� ���߸�!)
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

void UpTank::set_Coll(string buf)
{
	m_vColl.push_back(buf);
}

//Release() �Լ�(override)
void UpTank::Release()
{
	m_vColl.clear();
	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();
	m_vdirection.clear();
	Fast_Way.clear();
}

//�Ҹ���
UpTank::~UpTank()
{

}