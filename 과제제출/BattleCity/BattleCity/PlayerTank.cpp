#include "PlayerTank.h"
#include "ResourcesManager.h"

//생성자
PlayerTank::PlayerTank()
{
	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();

	pos_x = 0;
	pos_y = 0;
}

//초기화(override)
void PlayerTank::Init()
{
	DoEngine::BitMap* tmp_bit = NULL;

	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();

	m_vLeft.reserve(ENEMY_KIND);
	m_vRight.reserve(ENEMY_KIND);
	m_vUp.reserve(ENEMY_KIND);
	m_vDown.reserve(ENEMY_KIND);

	//비트맵 집어 넣기
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

//키입력(override)
bool PlayerTank::Input(float _fETime)
{
	return false;
}

//Update함수(override)
void PlayerTank::Update(float _fETime)
{

}

//Draw 함수(override)
void PlayerTank::Draw()
{
	
}

//Draw 함수(override)
void PlayerTank::Draw(int _x, int _y)
{
	m_vDown[1]->Draw(_x, _y);
}

//Release() 함수(override)
void PlayerTank::Release()
{

}

//소멸자
PlayerTank::~PlayerTank()
{

}