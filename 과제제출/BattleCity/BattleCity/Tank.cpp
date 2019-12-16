#include "Tank.h"
#include "ResourcesManager.h"

//생성자
Tank::Tank()
{
	m_vLeft.clear();
	m_vRight.clear();
	m_vUp.clear();
	m_vDown.clear();

	pos_x = 0;
	pos_y = 0;
}

//초기화(override)
void Tank::Init()
{
	//임시 비트맵 선언
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
}

//키입력(override)
bool Tank::Input(float _fETime)
{
	return false;
}

//Update함수(override)
void Tank::Update(float _fETime)
{

}

//Draw 함수(override)
void Tank::Draw()
{
	m_vDown[1]->Draw(pos_x, pos_y);
}

//Draw 함수(override)
void Tank::Draw(int _x, int _y)
{
	m_vDown[1]->Draw(_x, _y);
}

//Release() 함수(override)
void Tank::Release()
{
}

//소멸자
Tank::~Tank()
{

}