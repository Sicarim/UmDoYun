#include "BitMapFactory.h"

//생성자
EnemyFrontBit::EnemyFrontBit()
{
	EnemyDC = NULL;
	bitEnemyDC = NULL;
	EnemyOldDC = NULL;
	Front_Rect = { 0 };
	MovePos = 0;
}

//BitMap초기화(Override)
void EnemyFrontBit::Bit_Init(HDC hBack, HWND hWnd, float _curx)
{
	curPos = _curx;
	EnemyDC = CreateCompatibleDC(hBack);
	bitEnemyDC = (HBITMAP)LoadImage(NULL, "RES\\enemy_1b.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	EnemyOldDC = (HBITMAP)SelectObject(EnemyDC, bitEnemyDC);

	GetObject(bitEnemyDC, sizeof(EnemyInfo), &EnemyInfo);
	eSize.cx = EnemyInfo.bmWidth;
	eSize.cy = EnemyInfo.bmHeight;

	ReleaseDC(hWnd, hBack);
}

//BitMap그리기(Override)
void EnemyFrontBit::Bit_Draw(HDC hback, float _curx, float _cury, float _dftime)
{
	MovePos += _dftime;
	int tmp_iL, tmp_iT, tmp_iR, tmp_iB;

	tmp_iL = curPos + PLAYSPACE - MovePos;
	tmp_iT = 525;
	tmp_iR = tmp_iL + (eSize.cx * 1.5);
	tmp_iB = tmp_iT + (eSize.cy * 0.4);
	
	////////////충돌 범위 확인하기/////////////////
	//efBrush = CreateSolidBrush(RGB(255, 255, 255));
	//efoBrush = (HBRUSH)SelectObject(hback, efBrush);
	//Rectangle(hback, tmp_iL, tmp_iT, tmp_iR, tmp_iB);
	//////////////////////////////////////////////

	//BitBlt(hback, 100, 300, 1024, 768, EnemyDC, 0, 0, SRCCOPY);
	TransparentBlt(hback, curPos + PLAYSPACE - MovePos, 325, eSize.cx * 1.5, eSize.cy * 1.8, EnemyDC, 0, 0, eSize.cx, eSize.cy, RGB(255, 0, 255));

	Front_Rect = {tmp_iL, tmp_iT, tmp_iR, tmp_iB};
	DeleteObject(efBrush);
}

//현재 캐릭터 위치 받기(override)
void EnemyFrontBit::set_CurPos(int _curpos)
{
	curPos = _curpos;
}

//렉트 반환(override)
RECT EnemyFrontBit::get_Rect()
{
	return Front_Rect;
}

//소멸자
EnemyFrontBit::~EnemyFrontBit()
{

}