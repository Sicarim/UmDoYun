#include "BitMapFactory.h"

#include "BitMapFactory.h"
#include "BitMapManager.h"
#include "GameManager.h"

//생성자
SelectBit::SelectBit()
{
}

//BitMap초기화(Override)
void SelectBit::Bit_Init(HDC hBack, HWND hWnd, float _curx)
{
	TCHAR buf[256];
	posx = 100;
	posy = 100;

	BlackDC = CreateCompatibleDC(hBack);
	bitBlack = CreateCompatibleBitmap(hBack, 1024, 768); // 1024 * 9
	oldbitBlack = (HBITMAP)SelectObject(BlackDC, bitBlack);

	//별 비트
	for (int i = 0; i < 3; i++)
	{
		wsprintf(buf, "RES//star%d.bmp", i);

		StarDC[i] = CreateCompatibleDC(hBack);
		bitStarDC[i] = (HBITMAP)LoadImage(NULL, buf, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		oldStarDC[i] = (HBITMAP)SelectObject(StarDC[i], bitStarDC[i]);

		GetObject(bitStarDC[i], sizeof(StarInfo[i]), &StarInfo[i]);
		StarSize[i].cx = StarInfo[i].bmWidth;
		StarSize[i].cy = StarInfo[i].bmHeight;
	}

	//글자(미터표시)
	selectfont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "맑은고딕");
	oldselectfont = (HFONT)SelectObject(hBack, selectfont);
	SetTextColor(hBack, RGB(255, 255, 255));
	SetBkMode(hBack, TRANSPARENT); //배경은 투명 처리

	ReleaseDC(hWnd, hBack);
}

//BitMap그리기(Override)
void SelectBit::Bit_Draw(HDC hback, float _curx, float _cury, float _dftime)
{
	HDC tmp_DC;
	TCHAR Star_str[256];
	int tmp_Count = 0;
	bool tmp_Check = true;

	BitBlt(hback, 0, 0, 1024, 768, BlackDC, 0, 0, SRCCOPY);

	if (!GameManager::get_Instence()->get_EndCheck())
	{
		if (abs((int)_dftime % 3) == 0)
		{
			tmp_DC = StarDC[0];
		}
		else if (abs((int)_dftime % 3) == 1)
		{
			tmp_DC = StarDC[1];
		}
		else if (abs((int)_dftime % 3) == 2)
		{
			tmp_DC = StarDC[2];
		}
	}

	
	for(int i = 0; i < 16; i++)
	{
		posx = LOGO_X + (i * FB);
		TransparentBlt(hback, posx, LOGO_Y, StarSize[0].cx * 1.5, StarSize[0].cy * 1.8, tmp_DC, 0, 0, StarSize[0].cx, StarSize[0].cy, RGB(255, 0, 255));
	}
	for (int i = 0; i < 6; i++)
	{
		posy = LOGO_Y + (i * FB);
		TransparentBlt(hback, posx, posy, StarSize[0].cx * 1.5, StarSize[0].cy * 1.8, tmp_DC, 0, 0, StarSize[0].cx, StarSize[0].cy, RGB(255, 0, 255));
	}
	for (int i = 0; i < 16; i++)
	{
		posx = LOGO_X + (i * FB);
		TransparentBlt(hback, posx, posy, StarSize[0].cx * 1.5, StarSize[0].cy * 1.8, tmp_DC, 0, 0, StarSize[0].cx, StarSize[0].cy, RGB(255, 0, 255));
	}
	for (int i = 0; i < 6; i++)
	{
		posx = LOGO_X;
		posy = LOGO_Y + (i * FB);
		TransparentBlt(hback, posx, posy, StarSize[0].cx * 1.5, StarSize[0].cy * 1.8, tmp_DC, 0, 0, StarSize[0].cx, StarSize[0].cy, RGB(255, 0, 255));
	}
	

	wsprintf(Star_str, "ⓒ 2019 DOYUN");
	TextOut(hback, STAND, 70, Star_str, strlen(Star_str));
	wsprintf(Star_str, "CIRCUS");
	TextOut(hback, STAND + 30, 220, Star_str, strlen(Star_str));
	wsprintf(Star_str, "CHARING");
	TextOut(hback, STAND + 60, 255, Star_str, strlen(Star_str));
	wsprintf(Star_str, "BY SOFT PRO MAX");
	TextOut(hback, STAND - 15, 400, Star_str, strlen(Star_str));
	wsprintf(Star_str, "PLAYER SELECT");
	TextOut(hback, STAND, 480, Star_str, strlen(Star_str));
	wsprintf(Star_str, "Press the Key 'S'");
	TextOut(hback, STAND, 600, Star_str, strlen(Star_str));
}

//렉트 반환(override)
RECT SelectBit::get_Rect()
{
	return star_Rect;
}

//소멸자
SelectBit::~SelectBit()
{

}