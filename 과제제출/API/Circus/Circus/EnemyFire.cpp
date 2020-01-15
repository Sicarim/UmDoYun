#include "BitMapFactory.h"

//생성자
EnemyFireBit::EnemyFireBit()
{
	Fire_Pos = 0;
}

//BitMap초기화(Override)
void EnemyFireBit::Bit_Init(HDC hBack, HWND hWnd, float _curx)
{
	TCHAR buf[256];
	Fire_Pos = _curx;

	for (int i = 0; i < 2; i++)
	{
		wsprintf(buf, "RES\\front%d.bmp", i);

		EnemyFireDC[i] = CreateCompatibleDC(hBack);
		bitEnemyFireDC[i] = (HBITMAP)LoadImage(NULL, buf, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		OldEnemyFireDC[i] = (HBITMAP)SelectObject(EnemyFireDC[i], bitEnemyFireDC[i]);

		GetObject(bitEnemyFireDC[i], sizeof(EnemyFireInfo[i]), &EnemyFireInfo[i]);
		efSize[i].cx = EnemyFireInfo[i].bmWidth;
		efSize[i].cy = EnemyFireInfo[i].bmHeight;

		tmp_iL = 10 + Fire_Pos;
		tmp_iT = 550;
		tmp_iR = tmp_iL + (efSize[0].cx * 1.0);
		tmp_iB = tmp_iT + (efSize[0].cy * 1.8);
		Fire_Rect = { tmp_iL, tmp_iT, tmp_iR, tmp_iB };
	}
}

//BitMap그리기(Override)
void EnemyFireBit::Bit_Draw(HDC hback, float _curx, float _cury, float _dftime)
{
	///////////////충돌 범위 확인하기////////////////
	//fireBrush = CreateSolidBrush(RGB(255, 255, 255));
	//ofireBrush = (HBRUSH)SelectObject(hback, fireBrush);
	//Rectangle(hback, tmp_iL, tmp_iT, tmp_iR, tmp_iB);
	//////////////////////////////////////////////////

	TransparentBlt(hback, 5 + Fire_Pos, 550, efSize[0].cx * 1.5, efSize[0].cy * 1.8, EnemyFireDC[0], 0, 0, efSize[0].cx, efSize[0].cy, RGB(255, 0, 255));

	DeleteObject(fireBrush);
}

//렉트 반환(override)
RECT EnemyFireBit::get_Rect()
{
	return Fire_Rect;
}

//현재 캐릭터 위치 받기(override)
void EnemyFireBit::set_CurPos(int _curpos)
{
	curPos = _curpos;
}

//소멸자
EnemyFireBit::~EnemyFireBit()
{

}