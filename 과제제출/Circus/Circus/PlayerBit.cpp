#include "BitMapFactory.h"
#include "BitMapManager.h"
#include "GameManager.h"

//생성자
PlayerBit::PlayerBit()
{
	Player_Rect = { 0 };
}

//BitMap초기화(Override)
void PlayerBit::Bit_Init(HDC hBack, HWND hWnd, float _curx)
{
	TCHAR buf[256];
	EndTime = 0.0f;
	winPos = 0;
	moveX = 0.0f;
	moveY = 0.0f;

	//플레이어
	for (int i = 0; i < 3; i++)
	{
		wsprintf(buf, "RES//player%d.bmp", i);

		PlayerDC[i] = CreateCompatibleDC(hBack);
		bitPlayerDC[i] = (HBITMAP)LoadImage(NULL, buf, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		PlayerOldDC[i] = (HBITMAP)SelectObject(PlayerDC[i], bitPlayerDC[i]);

		GetObject(bitPlayerDC[i], sizeof(playerInfo[i]), &playerInfo[i]);
		pSize[i].cx = playerInfo[i].bmWidth;
		pSize[i].cy = playerInfo[i].bmHeight;
	}

	PlayerDC[3] = CreateCompatibleDC(hBack);
	bitPlayerDC[3] = (HBITMAP)LoadImage(NULL, "RES\\die.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	PlayerOldDC[3] = (HBITMAP)SelectObject(PlayerDC[3], bitPlayerDC[3]);

	GetObject(bitPlayerDC[3], sizeof(playerInfo[3]), &playerInfo[3]);
	pSize[3].cx = playerInfo[3].bmWidth;
	pSize[3].cy = playerInfo[3].bmHeight;

	PlayerDC[4] = CreateCompatibleDC(hBack);
	bitPlayerDC[4] = (HBITMAP)LoadImage(NULL, "RES\\win.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	PlayerOldDC[4] = (HBITMAP)SelectObject(PlayerDC[4], bitPlayerDC[4]);


	PlayerDC[5] = CreateCompatibleDC(hBack);
	bitPlayerDC[5] = (HBITMAP)LoadImage(NULL, "RES\\win2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	PlayerOldDC[5] = (HBITMAP)SelectObject(PlayerDC[5], bitPlayerDC[5]);

	ReleaseDC(hWnd, hBack);
}

//BitMap그리기(Override)
void PlayerBit::Bit_Draw(HDC hback, float _curx, float _cury, float _dftime)
{
	HDC tmp_DC;
	int tmp_iL, tmp_iT, tmp_iR, tmp_iB;

	tmp_iL = 120 + _curx;
	tmp_iT = 500 + _cury;
	tmp_iR = tmp_iL + (pSize[0].cx * 0.8);
	tmp_iB = tmp_iT + (pSize[0].cy * 1.7);

	///////////////충돌 범위 확인하기/////////////////////
	//pBrush = CreateSolidBrush(RGB(0, 200, 0));
	//poBrush = (HBRUSH)SelectObject(hback, pBrush);
	//Rectangle(hback, tmp_iL, tmp_iT, tmp_iR, tmp_iB);
	////////////////////////////////////////////////////

	if (!GameManager::get_Instence()->get_EndCheck())
	{
		moveX = 100 + _curx;
		moveY = 500 + _cury;
		if (abs((int)_curx % 3) == 0)
		{
			tmp_DC = PlayerDC[0];
		}
		else if (abs((int)_curx % 3) == 1)
		{
			tmp_DC = PlayerDC[1];
		}
		else if (abs((int)_curx % 3) == 2)
		{
			tmp_DC = PlayerDC[2];
		}
		if (_cury < 0.0f)
		{
			tmp_DC = PlayerDC[2];
		}
	}

	else
	{
		EndTime += _dftime;
		moveX = 9100;
		moveY = 420;

		if ((int)EndTime % 2 == 0)
		{
			tmp_DC = PlayerDC[4];
			winPos++;
		}
		else
		{
			tmp_DC = PlayerDC[5];
			winPos++;
		}
		Sleep(700);
		if (winPos == 5)
		{
			GameManager::get_Instence()->set_EndMes(true);
		}
	}

	TransparentBlt(hback, moveX, moveY, pSize[0].cx * 1.5, pSize[0].cy * 1.8, tmp_DC, 0, 0, pSize[0].cx, pSize[0].cy, RGB(255, 0, 255));

	Player_Rect = { tmp_iL, tmp_iT , tmp_iR , tmp_iB};
	DeleteObject(pBrush);
}

//렉트 반환(override)
RECT PlayerBit::get_Rect()
{
	return Player_Rect;
}

//소멸자
PlayerBit::~PlayerBit()
{

}