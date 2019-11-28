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
}

//Update�Լ�
void Circus::Update(HWND hWnd)
{
	m_hWnd = hWnd;

	//�� �����Ӹ��� ������ TickCount�� �޴´�. -  ������ ƽī��带 �޾ƿ´�.
	m_dwCurTime = GetTickCount();

	//���� �ð��� �����Ѵ�. ��ƾ�� ���ư� �� ���� ��ƾ������ ƽ ī��Ʈ���� ���̸� üũ�ϱ� ���ؼ� �̴�.
	//1000 �̻��� ���̰� ���� 1���̹Ƿ�  / 1000�ؼ� �ʷ� ȯ��.
	m_fDeltaTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;

	//���� Ÿ���� �޴´�.
	//��������� ���� Ÿ���� �ð��� �޴°�.
	m_dwLastTime = m_dwCurTime;

	//ĳ���� ��Ʈ��
	m_Char.Move(hWnd, m_fDeltaTime);


	Char_curX = m_Char.get_charX();
	Char_curY = m_Char.get_charY();
	//�� �����ϱ�
	Generator_Enemy(m_fDeltaTime);
	GameManager::get_Instence()->Intersec_Check(hWnd, m_fDeltaTime); //�浹 üũ

	if (GameManager::get_Instence()->get_HitCheck())
	{
		Char_curX -= 500.0f;
		Char_curY = 0.0f;
	}

	Render(Char_curX, Char_curY, m_fDeltaTime);
	Shut_Down(hWnd);
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
			Game_Init(hWnd);
		}
	}
}


//�Ҹ���
Circus::~Circus()
{

}