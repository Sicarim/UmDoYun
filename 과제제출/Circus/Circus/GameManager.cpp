#include "GameManager.h"
#include "BitMapManager.h"

//생성자
GameManager::GameManager()
{
	
}

//게임 초기화
void GameManager::Init()
{
	m_pRect = { 0 };
	m_eRect = { 0 };
	m_gRect = { 0 };
	tmp_Rect = { 0 };
	Max_Health = 3;

	GenTime = 0.0f;
	DelayTime = 0.0f;
	GenCheck = false;
	Hit_Check = false;
	End_Check = false;
	End_Mes = false;
	m_Fire = BitMapManager::get_Instence()->get_FireCol();
}

//화염 고리 생성기
void GameManager::FireRing_Generator(float _dftime)
{
	GenTime += _dftime;

	if (GenTime >= GEN_TIME)
	{
		GenTime = 0.0f;
		GenCheck = true;
	}
	else
	{
		GenCheck = false;
	}
}

//충돌체크
void GameManager::Intersec_Check(HWND hWnd, float _dftime)
{
	m_Ring = BitMapManager::get_Instence()->get_RingCol();
	m_pRect = BitMapManager::get_Instence()->get_pRect();
	m_gRect = BitMapManager::get_Instence()->get_GoalRect();

	for (int i = 0; i < m_Ring.size(); i++)
	{
		//층돌했니?
		if (IntersectRect(&tmp_Rect, &m_pRect, &m_Ring[i]))
		{
			Hit_Check = true;
			MessageBox(hWnd, "YOU DIE", "YOU DIE", MB_OK);
			Max_Health--;
		}
	}

	for (int i = 0; i < m_Fire.size(); i++)
	{
		if (IntersectRect(&tmp_Rect, &m_pRect, &m_Fire[i]))
		{
			Hit_Check = true;
			MessageBox(hWnd, "YOU DIE", "YOU DIE", MB_OK);
			Max_Health--;
		}
	}

	//층돌했니?
	if (IntersectRect(&tmp_Rect, &m_pRect, &m_gRect))
	{
		End_Check = true;
	}
}

//데이터 삭제
void GameManager::Release()
{
	m_pRect = { 0 };
	m_eRect = { 0 };
	tmp_Rect = { 0 };
	Max_Health = 3;

	GenCheck = false;
	Hit_Check = false;
	m_Fire.clear();
	m_Ring.clear();
}

//젠 체크 갱신
void GameManager::set_GenCheck(bool _check)
{
	GenCheck = _check;
}

//젠 체크 리턴
bool GameManager::get_GenCheck()
{
	return GenCheck;
}

//목숨 수 리턴
int GameManager::get_Health()
{
	return Max_Health;
}

//히트 여부 리턴
bool GameManager::get_HitCheck()
{
	return Hit_Check;
}

//히트 여부 삽입
void GameManager::set_HitCheck(bool _check)
{
	Hit_Check = _check;
}

//골인 지점 도달 리턴
bool GameManager::get_EndCheck()
{
	return End_Check;
}

//골인 메세지
void GameManager::set_EndMes(bool _check)
{
	End_Mes = _check;
}

//골인 메세지
bool GameManager::get_EndMes()
{
	return End_Mes;
}

//소멸자
GameManager::~GameManager()
{

}