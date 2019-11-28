#include "BitMapFactory.h"
#include "BitMapManager.h"
#include "GameManager.h"

//생성자
MapBit::MapBit()
{

}

//BitMap초기화(Override)
void MapBit::Bit_Init(HDC hBack, HWND hWnd, float _curx)
{
	TCHAR buf[256];

	BlackDC = CreateCompatibleDC(hBack);
	bitBlack = CreateCompatibleBitmap(hBack, 10000, 768); // 1024 * 9
	oldbitBlack = (HBITMAP)SelectObject(BlackDC, bitBlack);

	//도화지에 그릴 배경화면
	GroundDC = CreateCompatibleDC(hBack);
	bitGroundDC = (HBITMAP)LoadImage(NULL, "RES//back.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	GroundOldDC = (HBITMAP)SelectObject(GroundDC, bitGroundDC);

	//데코(서커스 천막?) 그리기
	DecoDC = CreateCompatibleDC(hBack);
	bitDecoDC = (HBITMAP)LoadImage(NULL, "RES//back_deco.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	DecoOldDC = (HBITMAP)SelectObject(DecoDC, bitDecoDC);

	//관중 그리기
	for (int i = 0; i < 2; i++)
	{
		wsprintf(buf, "RES//back_normal%d.bmp", i);

		NormalDC[i] = CreateCompatibleDC(hBack);
		bitNormalDC[i] = (HBITMAP)LoadImage(NULL, buf, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		NormalOldDC[i] = (HBITMAP)SelectObject(NormalDC[i], bitNormalDC[i]);

		//Normal
		GetObject(bitNormalDC[i], sizeof(NormalMapInfo[i]), &NormalMapInfo[i]);
		NormalSize[i].cx = NormalMapInfo[i].bmWidth;
		NormalSize[i].cy = NormalMapInfo[i].bmHeight;
	}

	//미터 판 그리기
	MiterDC = CreateCompatibleDC(hBack);
	bitMiterDC = (HBITMAP)LoadImage(NULL, "RES//miter.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	MiterOldDC = (HBITMAP)SelectObject(MiterDC, bitMiterDC);

	//Miter
	GetObject(bitMiterDC, sizeof(MiterMapInfo), &MiterMapInfo);
	MiterSize.cx = MiterMapInfo.bmWidth;
	MiterSize.cy = MiterMapInfo.bmHeight;


	/*
	size.cx: 67
	size.cy: 183
	*/
	//Ground
	GetObject(bitGroundDC, sizeof(GroundMapInfo), &GroundMapInfo);
	GroundSize.cx = GroundMapInfo.bmWidth;
	GroundSize.cy = GroundMapInfo.bmHeight;

	//Deco
	GetObject(bitDecoDC, sizeof(DecoMapInfo), &DecoMapInfo);
	DecoSize.cx = DecoMapInfo.bmWidth;
	DecoSize.cy = DecoMapInfo.bmHeight;

	//Miter
	GetObject(bitMiterDC, sizeof(MiterMapInfo), &MiterMapInfo);
	MiterSize.cx = MiterMapInfo.bmWidth;
	MiterSize.cy = MiterMapInfo.bmHeight;

	//글자(미터표시)
	font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "맑은고딕");
	oldfont = (HFONT)SelectObject(hBack, font);
	SetTextColor(hBack, RGB(255, 255, 255));
	SetBkMode(hBack, TRANSPARENT); //배경은 투명 처리

	ReleaseDC(hWnd, hBack);
}

//BitMap그리기(Override)
void MapBit::Bit_Draw(HDC hBack, float _curx, float _cury, float _dftime)
{	
	TCHAR Miter_Str[256];
	
	BitBlt(hBack, 0, 0, 9999, 900, BlackDC, 0, 0, SRCCOPY);

	//초록 배경화면
	StretchBlt(hBack, 0, 300, GroundSize.cx * 139, GroundSize.cy * 2.5, GroundDC, 0, 0, GroundSize.cx, GroundSize.cy, SRCCOPY);

	//코끼리
	for (int i = 1; i < 120; i++)
	{
		if (i % 7 == 0)
		{
			StretchBlt(hBack, 0 + (i * 78), 220, DecoSize.cx * 1.2, DecoSize.cy * 1.2, DecoDC, 0, 0, DecoSize.cx, DecoSize.cy, SRCCOPY);
		}
	}

	//관중
	for (int i = 0; i < 120; i++)
	{
		if (i == 0)
		{
			StretchBlt(hBack, 0 + (i * NormalSize[0].cx), 225, NormalSize[0].cx * 1.2, NormalSize[0].cy * 1.2, NormalDC[0], 0, 0, NormalSize[0].cx, NormalSize[0].cy, SRCCOPY);
		}

		if (i % 7 != 0)
		{
			StretchBlt(hBack, 0 + (i * 78), 225, NormalSize[0].cx * 1.2, NormalSize[0].cy * 1.2, NormalDC[0], 0, 0, NormalSize[0].cx, NormalSize[0].cy, SRCCOPY);
		}
	}

	//미터판(길이)
	for (int i = 0; i < 10; i++)
	{
		wsprintf(Miter_Str, "%d0", i);
		StretchBlt(hBack, 30 + (i * 1000), 650, MiterSize.cx * 1.5, MiterSize.cy * 1.5, MiterDC, 0, 0, MiterSize.cx, MiterSize.cy, SRCCOPY);
		//DrawText(hBack, "널 사랑하는 내마음엔 백만볼트 찌릿찌릿", -1, &rt, DT_CENTER | DT_WORDBREAK);
		TextOut(hBack, 60 + (i * 1000), 655, Miter_Str, strlen(Miter_Str));
	}

	if (GameManager::get_Instence()->get_EndCheck())
	{
		//관중
		for (int i = 0; i < 120; i++)
		{
			if (i % 7 != 0)
			{
				if ((int)_dftime % 2 == 0)
				{
					StretchBlt(hBack, 0 + (i * 78), 225, NormalSize[1].cx * 1.2, NormalSize[1].cy * 1.2, NormalDC[1], 0, 0, NormalSize[1].cx, NormalSize[1].cy, SRCCOPY);
				}
				else
				{
					StretchBlt(hBack, 0 + (i * 78), 225, NormalSize[0].cx * 1.2, NormalSize[0].cy * 1.2, NormalDC[0], 0, 0, NormalSize[0].cx, NormalSize[0].cy, SRCCOPY);
				}
			}
		}
	}
}

//현재 캐릭터 위치 받기(override)
void MapBit::set_CurPos(int _curpos)
{
	curPos = _curpos;
}

//렉트 반환(override)
RECT MapBit::get_Rect()
{
	return Map_Rect;
}

//소멸자
MapBit::~MapBit()
{

}