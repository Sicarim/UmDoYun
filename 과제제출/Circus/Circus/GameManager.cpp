#include "GameManager.h"
#include "BitMapManager.h"

//������
GameManager::GameManager()
{
	
}

//���� �ʱ�ȭ
void GameManager::Init()
{
	m_pRect = { 0 };
	m_eRect = { 0 };
	m_gRect = { 0 };
	tmp_Rect = { 0 };
	Max_Health = 3;
	Score = MAX_SCORE;

	GenTime = 0.0f;
	DelayTime = 0.0f;
	GenCheck = false;
	Hit_Check = false;
	End_Check = false;
	End_Mes = false;
	isStart = false;
	m_Fire = BitMapManager::get_Instence()->get_FireCol();
}

//��ŸƮ ��ư ������
void GameManager::Start_Button()
{
	if (GetKeyState(INPUT_S) & 0x8000)
	{
		isStart = true;
	}
}

//ȭ�� �� ������
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

//�浹üũ
void GameManager::Intersec_Check(HWND hWnd, float _dftime)
{
	m_vBonus = BitMapManager::get_Instence()->get_BonusCol();
	m_Ring = BitMapManager::get_Instence()->get_RingCol();
	m_pRect = BitMapManager::get_Instence()->get_pRect();
	m_gRect = BitMapManager::get_Instence()->get_GoalRect();

	Score -= (int)_dftime;

	if (Score < 0)
	{
		Score = 0;
	}

	for (int i = 0; i < m_Ring.size(); i++)
	{
		//�����ߴ�?
		if (IntersectRect(&tmp_Rect, &m_pRect, &m_Ring[i]))
		{
			Hit_Check = true;
			MessageBox(hWnd, "YOU DIE", "YOU DIE", MB_OK);
			Max_Health--;
			BitMapManager::get_Instence()->Delete_Ring();
			m_Ring.clear();
		}
	}

	for (int i = 0; i < m_Fire.size(); i++)
	{
		if (IntersectRect(&tmp_Rect, &m_pRect, &m_Fire[i]))
		{
			Hit_Check = true;
			MessageBox(hWnd, "YOU DIE", "YOU DIE", MB_OK);
			Max_Health--;
			BitMapManager::get_Instence()->Delete_Ring();
		}
	}

	for (int i = 0; i < m_vBonus.size(); i++)
	{
		if (IntersectRect(&tmp_Rect, &m_pRect, &m_vBonus[i]))
		{
			Score += 150;
			BitMapManager::get_Instence()->set_Bonus(true);
			BitMapManager::get_Instence()->Delete_Bonus();
		}
	}

	//�����ߴ�?
	if (IntersectRect(&tmp_Rect, &m_pRect, &m_gRect))
	{
		End_Check = true;
	}
}

//������ ����
void GameManager::Release()
{
	m_pRect = { 0 };
	m_eRect = { 0 };
	tmp_Rect = { 0 };
	Max_Health = 3;

	isStart = false;
	GenCheck = false;
	Hit_Check = false;
	m_Fire.clear();
	m_Ring.clear();
}

//�� üũ ����
void GameManager::set_GenCheck(bool _check)
{
	GenCheck = _check;
}

//�� üũ ����
bool GameManager::get_GenCheck()
{
	return GenCheck;
}

//��� �� ����
int GameManager::get_Health()
{
	return Max_Health;
}

//��Ʈ ���� ����
bool GameManager::get_HitCheck()
{
	return Hit_Check;
}

//��Ʈ ���� ����
void GameManager::set_HitCheck(bool _check)
{
	Hit_Check = _check;
}

//���� ���� ���� ����
bool GameManager::get_EndCheck()
{
	return End_Check;
}

//���� �޼���
void GameManager::set_EndMes(bool _check)
{
	End_Mes = _check;
}

//���� �޼���
bool GameManager::get_EndMes()
{
	return End_Mes;
}

//��ŸƮ ��ư ����
bool GameManager::get_isStart()
{
	return isStart;
}

int GameManager::get_MaxScore()
{
	return Score;
}

//�Ҹ���
GameManager::~GameManager()
{

}