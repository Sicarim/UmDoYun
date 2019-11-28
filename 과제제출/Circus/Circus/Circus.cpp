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
}

//Update함수
void Circus::Update(HWND hWnd)
{
	m_hWnd = hWnd;

	//매 프레임마다 찍히는 TickCount를 받는다. -  현재의 틱카운드를 받아온다.
	m_dwCurTime = GetTickCount();

	//현재 시간을 저장한다. 루틴이 돌아간 후 이전 루틴에서의 틱 카운트간의 차이를 체크하기 위해서 이다.
	//1000 이상의 차이가 나면 1초이므로  / 1000해서 초로 환산.
	m_fDeltaTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;

	//현재 타임을 받는다.
	//결론적으로 이전 타임의 시간을 받는것.
	m_dwLastTime = m_dwCurTime;

	//캐릭터 컨트롤
	m_Char.Move(hWnd, m_fDeltaTime);


	Char_curX = m_Char.get_charX();
	Char_curY = m_Char.get_charY();
	//적 생성하기
	Generator_Enemy(m_fDeltaTime);
	GameManager::get_Instence()->Intersec_Check(hWnd, m_fDeltaTime); //충돌 체크

	if (GameManager::get_Instence()->get_HitCheck())
	{
		Char_curX -= 500.0f;
		Char_curY = 0.0f;
	}

	Render(Char_curX, Char_curY, m_fDeltaTime);
	Shut_Down(hWnd);
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
			Game_Init(hWnd);
		}
	}
}


//소멸자
Circus::~Circus()
{

}