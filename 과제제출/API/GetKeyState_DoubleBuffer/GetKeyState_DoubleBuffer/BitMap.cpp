#include "BitMap.h"

//생성자
BitMap::BitMap()
{
	curX = 0;
	curY = 0;
}

//비트맵 초기화
void BitMap::Bit_Init(HWND hWnd, int _posx, int _posy)
{
	HDC hdc = GetDC(hWnd);
	curX = _posx;
	curY = _posy;

	//숨겨 그릴 도화지
	HideBackDC = CreateCompatibleDC(hdc);
	HideBitBackDC = CreateCompatibleBitmap(hdc, 1024, 768);
	HideOldDC = (HBITMAP)SelectObject(HideBackDC, HideBitBackDC);
	
	//도화지에 그릴 배경화면(핑크핑크)
	g_BackDC = CreateCompatibleDC(HideBackDC);
	g_btBack = (HBITMAP)LoadImage(NULL, "back.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	g_btOldBack = (HBITMAP)SelectObject(g_BackDC, g_btBack);

	//도화지에 그릴 캐릭터(발암에 나라)
	g_PlayerDC = CreateCompatibleDC(HideBackDC);
	g_btPlayer = (HBITMAP)LoadImage(NULL, "image.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	g_btOldPlayer = (HBITMAP)SelectObject(g_PlayerDC, g_btPlayer);

	GetObject(g_btPlayer, sizeof(g_mapInfo), &g_mapInfo);

	g_size.cx = g_mapInfo.bmWidth;
	g_size.cy = g_mapInfo.bmHeight;

	ReleaseDC(hWnd, hdc);
}

//비트맵 그리기
void BitMap::Bit_Draw(HWND hWnd, int _posx, int _posy, int _shapex, int _shapey)
{
	HDC hdc = GetDC(hWnd);

	//숨겨 그릴 장소에 배경을 그린다.
	BitBlt(HideBackDC, 0, 0, 1024, 768, g_BackDC, 0, 0, SRCCOPY);

	//숨겨 그릴 장소에 캐릭터를 그린다.
	TransparentBlt(HideBackDC, curX + _posx, curX + _posy, g_size.cx / 4, g_size.cy / 4, g_PlayerDC, (g_size.cx / 4) * _shapex, (g_size.cy / 4) * _shapey,
		g_size.cx / 4, g_size.cy / 4, RGB(255, 0, 255));

	//최종적으로 화면에 뿌린다.
	BitBlt(hdc, 0, 0, 1024, 768, HideBackDC, 0, 0, SRCCOPY);
}

//비트맵 지우기
void BitMap::Bit_Release()
{
	//SelectObject(hMemDC, hOldBitMap);
	//DeleteObject(hImage);
	//DeleteDC(hMemDC);
}

//소멸자
BitMap::~BitMap()
{
	Bit_Release();
}