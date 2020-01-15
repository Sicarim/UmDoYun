#include "BitMapFactory.h"

//생성자
BonusBit::BonusBit()
{
	BonusDC = NULL;
	bitBonusDC = NULL;
	oldBonusDC = NULL;
	Bonus_Rect = { 0 };
	posx = 0;
}

//BitMap초기화(Override)
void BonusBit::Bit_Init(HDC hback, HWND hWnd, float _curx)
{
	posx = _curx;
	BonusDC = CreateCompatibleDC(hback);
	bitBonusDC = (HBITMAP)LoadImage(NULL, "RES\\cash.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	oldBonusDC = (HBITMAP)SelectObject(BonusDC, bitBonusDC);

	GetObject(bitBonusDC, sizeof(BonusInfo), &BonusInfo);
	BonusSize.cx = BonusInfo.bmWidth;
	BonusSize.cy = BonusInfo.bmHeight;

	ReleaseDC(hWnd, hback);
}

//BitMap그리기(Override)
void BonusBit::Bit_Draw(HDC hback, float _curx, float _cury, float _dftime)
{
	posx += _dftime;
	int tmp_iL, tmp_iT, tmp_iR, tmp_iB;

	tmp_iL = curPos + BONUSSPACE - posx;
	tmp_iT = BONUS_Y;
	tmp_iR = tmp_iL + (BonusSize.cx * 1.5);
	tmp_iB = tmp_iT + (BonusSize.cy * 1.8);

	////////////충돌 범위 확인하기/////////////////
	//BonusBrush = CreateSolidBrush(RGB(255, 255, 255));
	//oBonusBrush = (HBRUSH)SelectObject(hback, BonusBrush);
	//Rectangle(hback, tmp_iL, tmp_iT, tmp_iR, tmp_iB);
	//////////////////////////////////////////////

	TransparentBlt(hback, curPos + BONUSSPACE - posx, BONUS_Y, BonusSize.cx * 1.5, BonusSize.cy * 1.8, BonusDC, 0, 0, BonusSize.cx, BonusSize.cy, RGB(255, 0, 255));

	Bonus_Rect = { tmp_iL, tmp_iT, tmp_iR, tmp_iB };
	DeleteObject(BonusBrush);
}

//렉트 반환(override)
RECT BonusBit::get_Rect()
{
	return Bonus_Rect;
}

//현재 캐릭터 위치 받기(override)
void BonusBit::set_CurPos(int _curpos)
{
	curPos = _curpos;
}

//소멸자
BonusBit::~BonusBit()
{

}