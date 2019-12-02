#include "Circus.h"
#include "BitMapManager.h"
#include "GameManager.h"

//������
Circus::Circus()
{
	
}

/*
	IntersectRect(&rcRect, &m_SelectRect, &tmp_UnitRect)
	1��° ����: �������� ������ ��Ʈ �ּ�
	2,3 ��° ����: �������� ���� ��Ʈ �ּ� 
*/

//���� �ʱ�ȭ
void Circus::Game_Init(HWND hWnd)
{
	Init();
	BitMapManager::get_Instence()->All_Init(hWnd); //��Ʈ�� �ʱ�ȭ
	GameManager::get_Instence()->Init(); //���� �ʱ�ȭ
}

//���� �ʱ�ȭ
void Circus::Init()
{
	m_dwLastTime = GetTickCount();
	m_dwCurTime = GetTickCount();
	m_fDeltaTime = 0.0f;
	p_test = 0.0f;
	Char_curX = 0.0f;
	Char_curY = 0.0f;
	start = false;
	Save_Time = 0.0f;
}

//Update�Լ�
void Circus::Update(HWND hWnd)
{
	m_hWnd = hWnd;

	m_dwCurTime = GetTickCount();
	m_fDeltaTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;
	m_dwLastTime = m_dwCurTime;

	GameManager::get_Instence()->Start_Button();
	start = GameManager::get_Instence()->get_isStart();
	Game_Start();
}

//���� ����ȭ��
void Circus::Game_Start()
{
	Save_Time += m_fDeltaTime;

	if (!start)
	{
		BitMapManager::get_Instence()->First_Draw(m_hWnd, 0, 0, Save_Time);
	}
	else
	{
		//ĳ���� ��Ʈ��
		m_Char.Move(m_hWnd, m_fDeltaTime);

		//�� �����ϱ�
		Generator_Enemy(m_fDeltaTime);
		GameManager::get_Instence()->Intersec_Check(m_hWnd, Save_Time); //�浹 üũ

		Char_curX = m_Char.get_charX();
		Char_curY = m_Char.get_charY();

		Render(Char_curX, Char_curY, m_fDeltaTime);
		Shut_Down(m_hWnd);
	}
}

//�� �����ϱ�
void Circus::Generator_Enemy(float _dftime)
{
	GameManager::get_Instence()->FireRing_Generator(_dftime);
	BitMapManager::get_Instence()->Make_FireRing(m_hWnd, Char_curX);
}

//�׸��� �Լ�
void Circus::Render(float _curx, float _cury, float _dftime)
{
	HDC hdc = GetDC(m_hWnd);
	p_test += _dftime;

	BitMapManager::get_Instence()->All_Draw(m_hWnd, _curx, _cury, p_test * 100);
	GameManager::get_Instence()->set_HitCheck(false);
	ReleaseDC(m_hWnd, hdc);
}

//���� ����
void Circus::Shut_Down(HWND hWnd)
{
	bool ReGame = false;
	start = false;

	if (GameManager::get_Instence()->get_EndMes())
	{
		MessageBox(hWnd, "���� �ϼ̽��ϴ�!!", "����", MB_OK);
		ReGame = true;
	}

	if (GameManager::get_Instence()->get_Health() <= 0)
	{
		MessageBox(hWnd, "����� �����̽��ϴ�.", "YOU DIE", MB_OK);
		ReGame = true;
	}

	if (ReGame)
	{
		if (MessageBox(hWnd, "������ �ٽ� �����ϰڽ��ϱ�?", "���� ����!", MB_YESNO) == IDNO)
		{
			DestroyWindow(hWnd);
			GameManager::get_Instence()->Release();
			BitMapManager::get_Instence()->Release();
			GameManager::del_Instence();
			BitMapManager::del_Instence();
		}
		else
		{
			GameManager::get_Instence()->Release();
			BitMapManager::get_Instence()->Release();
			m_Char.Char_Init();
			Game_Init(hWnd);
		}
	}
}


//�Ҹ���
Circus::~Circus()
{

}