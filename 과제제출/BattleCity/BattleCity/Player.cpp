#include "Player.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "Command.h"

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
	curTime = 0.0f;
	DoEngine::BitMap* tmp_bit = NULL;

	//���� ��ġ(���� ��ġ �ʱ�ȭ)
	pos_x = _x;
	pos_y = _y;
	m_vdirection.reserve(ENEMY_KIND);

	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();

	m_vLeft.reserve(ENEMY_KIND);
	m_vRight.reserve(ENEMY_KIND);
	m_vUp.reserve(ENEMY_KIND);
	m_vDown.reserve(ENEMY_KIND);

	//Tag����
	m_sTag = "Player";

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
}

//Ű�Է�(override)
bool Player::Input(int _state)
{
	if (_state == LEFT)
	{
		m_vdirection = m_vLeft;
		pos_x -= curTime * UNIT_SPEED;
	}

	else if (_state == RIGHT)
	{
		m_vdirection = m_vRight;
		pos_x += curTime * UNIT_SPEED;
	}

	else if (_state == UP)
	{
		m_vdirection = m_vUp;
		pos_y -= curTime * UNIT_SPEED;
	}

	else if (_state == DOWN)
	{
		m_vdirection = m_vDown;
		pos_y += curTime * UNIT_SPEED;
	}

	else if (_state == ATTACK)
	{
		//m_Bullet.Init(pos_x, pos_y);
	}

	return false;
}

//Update�Լ�(override)
void Player::Update(float _fETime)
{
	curTime = _fETime;
}

//Draw �Լ�(override)
void Player::Draw()
{
	if (m_vdirection.empty())
	{
		m_vUp[0]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
	}
	else
	{
		m_vdirection[0]->Draw(pos_x, pos_y, COL_SIZE, COL_SIZE);
	}
	
	
	//�ݶ��̴� ���� �׸���
	m_Coll.Draw_Collider(pos_x, pos_y, (m_vDown[1]->get_Width()) * COL_SIZE, (m_vDown[1]->get_Height()) * COL_SIZE);
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