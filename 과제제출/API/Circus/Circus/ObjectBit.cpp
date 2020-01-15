#include "BitMapFactory.h"
#include "BitMapManager.h"
#include "GameManager.h"

//������
ObjectBit::ObjectBit()
{
	GoalRect = { 0 };
	Health_Point = 0;
}

//BitMap�ʱ�ȭ(Override)
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

	//����(���� ǥ��)
	Score = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "�������");
	oldScore = (HFONT)SelectObject(hBack, Score);
	SetTextColor(hBack, RGB(255, 255, 255));
	SetBkMode(hBack, TRANSPARENT); //����� ���� ó��

	ReleaseDC(hWnd, hBack);
}

//BitMap�׸���(Override)
void ObjectBit::Bit_Draw(HDC hback, float _curx, float _cury, float _dftime)
{
	float tmp_cur = _curx;
	TCHAR Score_Str[256];
	int tmp_iL, tmp_iT, tmp_iR, tmp_iB;

	tmp_iL = 9100;
	tmp_iT = 520;
	tmp_iR = tmp_iL + (GoalSize.cx * 1.5);
	tmp_iB = tmp_iT + (GoalSize.cy * 1.8);

	///////////////�浹 ���� Ȯ���ϱ�/////////////////////
	//goalBrush = CreateSolidBrush(RGB(0, 200, 0));
	//ogoalBrush = (HBRUSH)SelectObject(hback, goalBrush);
	//Rectangle(hback, tmp_iL, tmp_iT, tmp_iR, tmp_iB);
	////////////////////////////////////////////////////

	Health_Point = GameManager::get_Instence()->get_Health();
	m_Score = GameManager::get_Instence()->get_MaxScore();

	//��� ǥ��
	for (int i = 0; i < Health_Point; i++)
	{
		TransparentBlt(hback, 900 + (i * 30) + _curx, 50, HealthSize.cx * 2, HealthSize.cy * 2, HealthDC, 0, 0, HealthSize.cx, HealthSize.cy, RGB(255, 0, 255));
	}

	//���� ���� ǥ��
	TransparentBlt(hback, 9100, 520, GoalSize.cx * 1.5, GoalSize.cy * 1.8, GoalDC, 0, 0, GoalSize.cx, GoalSize.cy, RGB(255, 0, 255));
	
	wsprintf(Score_Str, "SCORE: %d", m_Score);
	TextOut(hback, 550 + _curx, 50, Score_Str, strlen(Score_Str));

	wsprintf(Score_Str, "Point: %d", (int)_curx);
	TextOut(hback, 250 + _curx, 50, Score_Str, strlen(Score_Str));

	GoalRect = { tmp_iL, tmp_iT , tmp_iR , tmp_iB };
	DeleteObject(goalBrush);
}

//���� ĳ���� ��ġ �ޱ�(override)
void ObjectBit::set_CurPos(int _curpos)
{
	curPos = _curpos;
}

//��Ʈ ��ȯ(override)
RECT ObjectBit::get_Rect()
{
	return GoalRect;
}

//�Ҹ���
ObjectBit::~ObjectBit()
{

}