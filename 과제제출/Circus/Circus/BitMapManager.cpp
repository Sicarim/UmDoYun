#include "BitMapManager.h"
#include "GameManager.h"

//생성자
BitMapManager::BitMapManager()
{
	srand(time(NULL));
}

//초기화
void BitMapManager::All_Init(HWND hWnd)
{
	m_BitFac = NULL;
	m_playerBit = NULL;
	m_MapBit = NULL;
	hBackDC = NULL;
	hBitBackDC = NULL;
	hOldDC = NULL;
	BonusCount = 0;

	m_FireBit.reserve(10);
	Ring_collider.reserve(100);

	m_pRect = { 0 };
	m_eRect = { 0 };
	m_GoalRect = { 0 };

	bitGenCheck = false;

	HDC hdc = GetDC(hWnd);

	//숨겨 그릴 도화지
	hBackDC = CreateCompatibleDC(hdc);
	hBitBackDC = CreateCompatibleBitmap(hdc, 10000, 768); // 1024 * 9
	hOldDC = (HBITMAP)SelectObject(hBackDC, hBitBackDC);

	GetObject(hBitBackDC, sizeof(BackMapInfo), &BackMapInfo);
	BackSize.cx = BackMapInfo.bmWidth;
	BackSize.cy = BackMapInfo.bmHeight;

	
	Make_SelectView(hBackDC, hWnd);
	Make_BackGround(hBackDC, hWnd);
	Make_Player(hBackDC, hWnd);
	Make_FireEnemy(hBackDC, hWnd);
	Make_Object(hBackDC, hWnd);
}

//화염 고리 만들기
void BitMapManager::Make_FireRing(HWND hWnd, float _curx)
{
	int Random = rand() % 100;
	bitGenCheck = GameManager::get_Instence()->get_GenCheck();

	if (bitGenCheck)
	{
		GameManager::get_Instence()->set_GenCheck(false);
		Make_FrontEnemy(hBackDC, hWnd, _curx);
		Make_BackEnemy(hBackDC, hWnd, _curx);

		if (Random < GENPROB)
		{
			Make_Bonus(hBackDC, hWnd, _curx);
		}
		//MessageBox(hWnd, "생성!", "생성", MB_OK);
	}
}

//그리기
void BitMapManager::All_Draw(HWND hWnd, float _curx, float _cury, float _dftime)
{
	HDC hdc = GetDC(hWnd);

	//순서 주의!
	BackGround_Draw(hBackDC, _curx, _cury, _dftime); //배경화면
	FrontEnemy_Draw(hBackDC, _curx, _cury, _dftime); //화염 고리(앞부분)
	Player_Draw(hBackDC, _curx, _cury, _dftime); //플레이어
	BackEnemy_Draw(hBackDC, _curx, _cury, _dftime); //화염 고리(뒷부분)
	FireEnemy_Draw(hBackDC, _curx, _cury); //불 항아리

	//전체적으로 그리기
	if (_curx < GROUNDMAX)
	{
		Object_Draw(hBackDC, _curx, _cury, _dftime); //오브젝트
		TransparentBlt(hdc, 0, 0, 1024, 768, hBackDC, 0 + _curx, 0, 1024, 768, RGB(255, 0, 255));
	}
	else
	{
		Object_Draw(hBackDC, GROUNDMAX, _cury, _dftime); //오브젝트
		TransparentBlt(hdc, 0, 0, 1024, 768, hBackDC, GROUNDMAX, 0, 1024, 768, RGB(255, 0, 255));
	}
}

//적 그리기
void BitMapManager::FrontEnemy_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime)
{
	if (!GameManager::get_Instence()->get_EndCheck())
	{
		if (!m_FrontRingBit.empty())
		{
			for (int i = 0; i < m_FrontRingBit.size(); i++)
			{
				m_FrontRingBit[i]->Bit_Draw(_hBackDC, _curx, _cury, RING_SPEED);
			}

			Ring_collider.resize(m_FrontRingBit.size());
			for (int i = 0; i < Ring_collider.size(); i++)
			{
				Ring_collider[i] = m_FrontRingBit[i]->get_Rect();
			}
		}
		if (!m_Bonus.empty())
		{
			for (int i = 0; i < m_Bonus.size(); i++)
			{
				m_Bonus[i]->Bit_Draw(_hBackDC, _curx, _cury, RING_SPEED);
			}

			Bonus_collider.resize(m_Bonus.size());
			for (int i = 0; i < Bonus_collider.size(); i++)
			{
				Bonus_collider[i] = m_Bonus[i]->get_Rect();
			}
		}
	}
}

//시작화면 그리기
void BitMapManager::First_Draw(HWND hWnd, float _curx, float _cury, float _dftime)
{
	HDC hdc = GetDC(hWnd);
	SelectView_Draw(hBackDC, _curx, _cury, _dftime); //시작화면
	TransparentBlt(hdc, 0, 0, 1024, 768, hBackDC, 0, 0, 1024, 768, RGB(255, 0, 255));
}

//배경화면 만들기
void BitMapManager::Make_BackGround(HDC _hBackDC, HWND hWnd)
{
	//배경 초기화
	m_BitFac = new MapBit;
	m_BitFac->Bit_Init(_hBackDC, hWnd);
	m_MapBit = m_BitFac;
}

//플레이어 만들기
void BitMapManager::Make_Player(HDC _hBackDC, HWND hWnd)
{
	//캐릭터 초기화
	m_BitFac = new PlayerBit;
	m_BitFac->Bit_Init(_hBackDC, hWnd);
	m_playerBit = m_BitFac;
}

//적 만들기
void BitMapManager::Make_FrontEnemy(HDC _hBackDC, HWND hWnd, float _curx)
{
	m_BitFac = new EnemyFrontBit;
	m_BitFac->Bit_Init(_hBackDC, hWnd);
	m_BitFac->set_CurPos(_curx);
	m_FrontRingBit.push_back(m_BitFac);
}

//보너스 주머니 만들기
void BitMapManager::Make_Bonus(HDC _hBackDC, HWND hWnd, float _curx)
{
	m_BitFac = new BonusBit;
	m_BitFac->Bit_Init(_hBackDC, hWnd);
	m_BitFac->set_CurPos(_curx);
	m_Bonus.push_back(m_BitFac);
}

//적 만들기
void BitMapManager::Make_BackEnemy(HDC _hBackDC, HWND hWnd, float _curx)
{
	m_BitFac = new EnemyBackBit;
	m_BitFac->Bit_Init(_hBackDC, hWnd);
	m_BitFac->set_CurPos(_curx);
	m_BackRingBit.push_back(m_BitFac);
}

//적(파이어~) 만들기
void BitMapManager::Make_FireEnemy(HDC _hBackDC, HWND hWnd)
{
	int tmp = 1;

	for (int i = 0; i < 11; i++)
	{
		m_BitFac = new EnemyFireBit;
		if (i == 10)
		{
			m_BitFac->Bit_Init(_hBackDC, hWnd, 9000);
		}
		else
		{
			m_BitFac->Bit_Init(_hBackDC, hWnd, tmp * 800);
		}
		
		m_FireBit.push_back(m_BitFac);
		Fire_collider.push_back(m_BitFac->get_Rect());
		tmp++;
	}
}

//시작화면 만들기
void BitMapManager::Make_SelectView(HDC _hBackDC, HWND hWnd)
{
	m_BitFac = new SelectBit;
	m_BitFac->Bit_Init(_hBackDC, hWnd);
	m_First = m_BitFac;
}

//배경화면 그리기
void BitMapManager::BackGround_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime)
{
	m_MapBit->Bit_Draw(_hBackDC, _curx, _cury, _dftime);
}

//오브젝트 만들기
void BitMapManager::Make_Object(HDC _hBackDC, HWND hWnd)
{
	m_BitFac = new ObjectBit;
	m_BitFac->Bit_Init(_hBackDC, hWnd);
	m_ObjectBit = m_BitFac;
}

//플레이어 그리기
void BitMapManager::Player_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime)
{
	m_playerBit->Bit_Draw(_hBackDC, _curx, _cury, _dftime);
}

//적 그리기
void BitMapManager::BackEnemy_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime)
{
	if (!GameManager::get_Instence()->get_EndCheck())
	{
		if (!m_BackRingBit.empty())
		{
			for (int i = 0; i < m_BackRingBit.size(); i++)
			{
				m_BackRingBit[i]->Bit_Draw(_hBackDC, _curx, _cury, RING_SPEED);
			}
		}
	}
}

//적(파이어) 그리기
void BitMapManager::FireEnemy_Draw(HDC _hBackDC, float _curx, float _cury)
{
	for (int i = 0; i < 11; i++)
	{
		m_FireBit[i]->Bit_Draw(_hBackDC);
	}
}

//오브젝트 그리기
void BitMapManager::Object_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime)
{
	m_ObjectBit->Bit_Draw(_hBackDC, _curx, _cury, _dftime);
}

//시작화면 그리기
void BitMapManager::SelectView_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime)
{
	m_First->Bit_Draw(_hBackDC, _curx, _cury, _dftime);
}

//플레이어 렉트 리턴
RECT BitMapManager::get_pRect()
{
	m_pRect = m_playerBit->get_Rect();
	return m_pRect;
}

//Fire콜라이더 리턴
vector<RECT> BitMapManager::get_FireCol()
{
	return Fire_collider;
}

//Ring콜라이더 리턴
vector<RECT> BitMapManager::get_RingCol()
{
	return Ring_collider;
}

//보너스 콜라이더 반환
vector<RECT> BitMapManager::get_BonusCol()
{
	return Bonus_collider;
}


//골지점 렉트 반환
RECT BitMapManager::get_GoalRect()
{
	m_GoalRect = m_ObjectBit->get_Rect();
	return m_GoalRect;
}

//링 삭제
void BitMapManager::Delete_Ring()
{
	m_FrontRingBit.clear();
	m_BackRingBit.clear();
	m_Bonus.clear();
	Fire_collider.clear();
	Bonus_collider.clear();
}

//데이터 삭제
void BitMapManager::Release()
{
	if (m_BitFac != NULL)
	{
		delete m_BitFac;
	}
	if (m_playerBit != NULL)
	{
		delete m_playerBit;
	}
	if (m_MapBit != NULL)
	{
		delete m_MapBit;
	}

	m_FrontRingBit.clear();
	m_BackRingBit.clear();
	m_FireBit.clear();
	m_Bonus.clear();
	Fire_collider.clear();
	Ring_collider.clear();

	m_ObjectBit = NULL;
	m_MapBit = NULL;
	m_playerBit = NULL;
	m_BitFac = NULL;
	bitGenCheck = false;

	hBackDC = NULL;
	hBitBackDC = NULL;
	hOldDC = NULL;
}

//소멸자
BitMapManager::~BitMapManager()
{
	Release();
}