#include "Circus.h"
#include "BitMapManager.h"
#include "GameManager.h"

//생성자
Circus::Circus()
{
	
}

/*
	IntersectRect(&rcRect, &m_SelectRect, &tmp_UnitRect)
	1번째 인자: 교집합을 저장할 렉트 주소
	2,3 번째 인자: 교집합을 구할 렉트 주소 
*/

//게임 초기화
void Circus::Game_Init(HWND hWnd)
{
	Init();
	BitMapManager::get_Instence()->All_Init(hWnd); //비트맵 초기화
	GameManager::get_Instence()->Init(); //게임 초기화
}

//설정 초기화
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

//Update함수
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

//게임 시작화면
void Circus::Game_Start()
{
	Save_Time += m_fDeltaTime;

	if (!start)
	{
		BitMapManager::get_Instence()->First_Draw(m_hWnd, 0, 0, Save_Time);
	}
	else
	{
		//캐릭터 컨트롤
		m_Char.Move(m_hWnd, m_fDeltaTime);

		//적 생성하기
		Generator_Enemy(m_fDeltaTime);
		GameManager::get_Instence()->Intersec_Check(m_hWnd, Save_Time); //충돌 체크

		Char_curX = m_Char.get_charX();
		Char_curY = m_Char.get_charY();

		Render(Char_curX, Char_curY, m_fDeltaTime);
		Shut_Down(m_hWnd);
	}
}

//적 생성하기
void Circus::Generator_Enemy(float _dftime)
{
	GameManager::get_Instence()->FireRing_Generator(_dftime);
	BitMapManager::get_Instence()->Make_FireRing(m_hWnd, Char_curX);
}

//그리기 함수
void Circus::Render(float _curx, float _cury, float _dftime)
{
	HDC hdc = GetDC(m_hWnd);
	p_test += _dftime;

	BitMapManager::get_Instence()->All_Draw(m_hWnd, _curx, _cury, p_test * 100);
	GameManager::get_Instence()->set_HitCheck(false);
	ReleaseDC(m_hWnd, hdc);
}

//게임 종료
void Circus::Shut_Down(HWND hWnd)
{
	bool ReGame = false;
	start = false;

	if (GameManager::get_Instence()->get_EndMes())
	{
		MessageBox(hWnd, "골인 하셨습니다!!", "골인", MB_OK);
		ReGame = true;
	}

	if (GameManager::get_Instence()->get_Health() <= 0)
	{
		MessageBox(hWnd, "당신은 죽으셨습니다.", "YOU DIE", MB_OK);
		ReGame = true;
	}

	if (ReGame)
	{
		if (MessageBox(hWnd, "게임을 다시 시작하겠습니까?", "게임 종료!", MB_YESNO) == IDNO)
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


//소멸자
Circus::~Circus()
{

}