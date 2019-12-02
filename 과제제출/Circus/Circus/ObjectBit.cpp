#include "BitMapFactory.h"
#include "BitMapManager.h"
#include "GameManager.h"

//생성자
ObjectBit::ObjectBit()
{
	GoalRect = { 0 };
	Health_Point = 0;
}

//BitMap초기화(Override)
void ObjectBit::Bit_Init(HDC hBack, HWND hWnd, float _curx)
{
	m_Score = 0;
	HealthDC = CreateCompatibleDC(hBack);
	bitHealthDC = (HBITMAP)LoadImage(NULL, "RES\\icon.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	oldHealthDC = (HBITMAP)SelectObject(HealthDC, bitHealthDC);

	GetObject(bitHealthDC, sizeof(HealthInfo), &HealthInfo);
	HealthSize.cx = HealthInfo.bmWidth;
	HealthSize.cy = HealthInfo.bmHeight;

	GoalDC = CreateCompatibleDC(hBack);
	bitGoalDC = (HBITMAP)LoadImage(NULL, "RES\\end.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	oldGoalDC = (HBITMAP)SelectObject(GoalDC, bitGoalDC);

	GetObject(bitGoalDC, sizeof(GoalInfo), &GoalInfo);
	GoalSize.cx = GoalInfo.bmWidth;
	GoalSize.cy = GoalInfo.bmHeight;

	//글자(점수 표시)
	Score = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "맑은고딕");
	oldScore = (HFONT)SelectObject(hBack, Score);
	SetTextColor(hBack, RGB(255, 255, 255));
	SetBkMode(hBack, TRANSPARENT); //배경은 투명 처리

	ReleaseDC(hWnd, hBack);
}

//BitMap그리기(Override)
void ObjectBit::Bit_Draw(HDC hback, float _curx, float _cury, float _dftime)
{
	float tmp_cur = _curx;
	TCHAR Score_Str[256];
	int tmp_iL, tmp_iT, tmp_iR, tmp_iB;

	tmp_iL = 9100;
	tmp_iT = 520;
	tmp_iR = tmp_iL + (GoalSize.cx * 1.5);
	tmp_iB = tmp_iT + (GoalSize.cy * 1.8);

	///////////////충돌 범위 확인하기/////////////////////
	//goalBrush = CreateSolidBrush(RGB(0, 200, 0));
	//ogoalBrush = (HBRUSH)SelectObject(hback, goalBrush);
	//Rectangle(hback, tmp_iL, tmp_iT, tmp_iR, tmp_iB);
	////////////////////////////////////////////////////

	Health_Point = GameManager::get_Instence()->get_Health();
	m_Score = GameManager::get_Instence()->get_MaxScore();

	//목숨 표시
	for (int i = 0; i < Health_Point; i++)
	{
		TransparentBlt(hback, 900 + (i * 30) + _curx, 50, HealthSize.cx * 2, HealthSize.cy * 2, HealthDC, 0, 0, HealthSize.cx, HealthSize.cy, RGB(255, 0, 255));
	}

	//골인 지점 표시
	TransparentBlt(hback, 9100, 520, GoalSize.cx * 1.5, GoalSize.cy * 1.8, GoalDC, 0, 0, GoalSize.cx, GoalSize.cy, RGB(255, 0, 255));
	
	wsprintf(Score_Str, "SCORE: %d", m_Score);
	TextOut(hback, 550 + _curx, 50, Score_Str, strlen(Score_Str));

	wsprintf(Score_Str, "Point: %d", (int)_curx);
	TextOut(hback, 250 + _curx, 50, Score_Str, strlen(Score_Str));

	GoalRect = { tmp_iL, tmp_iT , tmp_iR , tmp_iB };
	DeleteObject(goalBrush);
}

//현재 캐릭터 위치 받기(override)
void ObjectBit::set_CurPos(int _curpos)
{
	curPos = _curpos;
}

//렉트 반환(override)
RECT ObjectBit::get_Rect()
{
	return GoalRect;
}

//소멸자
ObjectBit::~ObjectBit()
{

}