#include "Player.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "Command.h"
#include "GameManager.h"

//������
Player::Player()
{
	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();
	m_vdirection.clear();

	curTime = 0.0f;
	pos_x = 0.0f;
	pos_y = 0.0f;
}

//�ʱ�ȭ(override)
void Player::Init(int _x, int _y)
{
	//Tag����
	m_sTag = "Player";
	Player_Look = LOOK_UP;
	fire_time = 0.0f;
	curTime = 0.0f;
	DoEngine::BitMap* tmp_bit = NULL;
	Fire = false;
	is_Destroy = false;

	m_vdirection.reserve(ENEMY_KIND);
	m_vLeft.reserve(ENEMY_KIND);
	m_vRight.reserve(ENEMY_KIND);
	m_vUp.reserve(ENEMY_KIND);
	m_vDown.reserve(ENEMY_KIND);

	//ź�� �����
	m_BulletPool.Make_Pool(10);

	//��Ʈ�� ���� �ֱ�
	for (int i = 0; i < ENEMY_KIND; i++)
	{
		wsprintf(buf, "RES\\tank_left_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vLeft.push_back(tmp_bit);

		wsprintf(buf, "RES\\tank_right_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vRight.push_back(tmp_bit);

		wsprintf(buf, "RES\\tank_up_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vUp.push_back(tmp_bit);

		wsprintf(buf, "RES\\tank_down_0%d.bmp", i);
		tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vDown.push_back(tmp_bit);
	}

	//���� ��ġ(���� ��ġ �ʱ�ȭ)
	pos_x = W_SPACE + _x * (m_vDown[1]->get_Width() * OBJECT_COL);
	pos_y = H_SPACE + _y * (m_vDown[1]->get_Height() * OBJECT_COL);
	m_wSize = (m_vDown[1]->get_Width() * OBJECT_COL);
	m_hSize = (m_vDown[1]->get_Height() * OBJECT_COL);
	Add_Coll();
}

//�浹��ų �������� ��Ƶд�
void Player::Add_Coll()
{
	int tmp_Count = 0;
	//�� �±� ���
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		wsprintf(buf, "Tank%d", i);
		m_vColl.push_back((string)buf);
	}

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

//Ű�Է�(override)
bool Player::Input(int _state)
{	
	if (_state == LEFT)
	{
		Player_Look = LOOK_LEFT;
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
		Player_Look = LOOK_RIGHT;
		m_vdirection = m_vRight;


		if (m_Coll.get_Collider("BackGround").right > pos_x + (m_vDown[1]->get_Width())* COL_SIZE)
		{
			if (!m_Coll.isCollider(m_vColl, RIGHT))
			{
				pos_x += curTime * UNIT_SPEED;
			}
		}
	}

	else if (_state == UP)
	{
		Player_Look = LOOK_UP;
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
		Player_Look = LOOK_DOWN;
		m_vdirection = m_vDown;
		
		if (m_Coll.get_Collider("BackGround").bottom > pos_y + (m_vDown[1]->get_Height())* COL_SIZE)
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

			if (Player_Look == LOOK_LEFT)
			{
				tmp_Bullet->Init(pos_x - 20, pos_y + 20);
			}
			else if (Player_Look == LOOK_RIGHT)
			{
				tmp_Bullet->Init(pos_x + 50, pos_y + 20);
			}
			else if (Player_Look == LOOK_UP)
			{
				tmp_Bullet->Init(pos_x + 20, pos_y - 15);
			}
			else if (Player_Look == LOOK_DOWN)
			{
				tmp_Bullet->Init(pos_x + 20, pos_y + 40);
			}

			tmp_Bullet->set_BulletDir(Player_Look);
			Fire = true;
		}
	}
	return false;
}

//Update�Լ�(override)
void Player::Update(float _fETime)
{
	curTime = _fETime;
	if (Fire)
	{
		tmp_Bullet->Update(_fETime);
	}
	//ź�˿� �¾Ҵٸ�...
	if (m_Coll.isCollider("Bullet"))
	{
		is_Destroy = true;
	}
}

//Draw �Լ�(override)
void Player::Draw()
{
	//�׾���?
	if (is_Destroy)
	{
		m_Coll.DeleteCollider();
	}
	else
	{
		//�߻� ��ư Ŭ��
		if (Fire)
		{
			tmp_Bullet->Draw();

			//ź���� �������ٸ�....
			if (!tmp_Bullet->get_FireSave())
			{
				tmp_Bullet->Init(pos_x, pos_y);
				m_BulletPool.Return_Data(tmp_Bullet);
				//delete tmp_Bullet;
				Fire = false;
			}
		}

		//����ϴ� ���⿡ ���� �׸���
		if (m_vdirection.empty())
		{
			m_vUp[0]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
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

		//�ݶ��̴� ���� �׸���
		m_Coll.Init_Collider(m_sTag, pos_x + 10, pos_y + 10, m_vDown[1]->get_Width() * (COL_SIZE - 0.6), m_vDown[1]->get_Height() * (COL_SIZE - 0.6));
		m_Coll.Draw_Collider();
	}
	
}

//Draw �Լ�(override)
void Player::Draw(int _x, int _y)
{
	m_vDown[1]->Draw(_x, _y, 3.0f, 3.0f);
}

//Release() �Լ�(override)
void Player::Release()
{

}

//�Ҹ���
Player::~Player()
{

}