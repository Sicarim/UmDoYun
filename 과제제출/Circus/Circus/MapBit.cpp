#include "BitMapFactory.h"
#include "BitMapManager.h"
#include "GameManager.h"

//������
MapBit::MapBit()
{

}

//BitMap�ʱ�ȭ(Override)
void MapBit::Bit_Init(HDC hBack, HWND hWnd, float _curx)
{
	TCHAR buf[256];

	BlackDC = CreateCompatibleDC(hBack);
	bitBlack = CreateCompatibleBitmap(hBack, 10000, 768); // 1024 * 9
	oldbitBlack = (HBITMAP)SelectObject(BlackDC, bitBlack);

	//��ȭ���� �׸� ���ȭ��
	GroundDC = CreateCompatibleDC(hBack);
	bitGroundDC = (HBITMAP)LoadImage(NULL, "RES//back.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	GroundOldDC = (HBITMAP)SelectObject(GroundDC, bitGroundDC);

	//����(��Ŀ�� õ��?) �׸���
	DecoDC = CreateCompatibleDC(hBack);
	bitDecoDC = (HBITMAP)LoadImage(NULL, "RES//back_deco.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	DecoOldDC = (HBITMAP)SelectObject(DecoDC, bitDecoDC);

	//���� �׸���
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

	//���� �� �׸���
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

	//����(����ǥ��)
	font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "�������");
	oldfont = (HFONT)SelectObject(hBack, font);
	SetTextColor(hBack, RGB(255, 255, 255));
	SetBkMode(hBack, TRANSPARENT); //����� ���� ó��

	ReleaseDC(hWnd, hBack);
}

//BitMap�׸���(Override)
void MapBit::Bit_Draw(HDC hBack, float _curx, float _cury, float _dftime)
{	
	TCHAR Miter_Str[256];
	
	BitBlt(hBack, 0, 0, 9999, 900, BlackDC, 0, 0, SRCCOPY);

	//�ʷ� ���ȭ��
	StretchBlt(hBack, 0, 300, GroundSize.cx * 139, GroundSize.cy * 2.5, GroundDC, 0, 0, GroundSize.cx, GroundSize.cy, SRCCOPY);

	//�ڳ���
	for (int i = 1; i < 120; i++)
	{
		if (i % 7 == 0)
		{
			StretchBlt(hBack, 0 + (i * 78), 220, DecoSize.cx * 1.2, DecoSize.cy * 1.2, DecoDC, 0, 0, DecoSize.cx, DecoSize.cy, SRCCOPY);
		}
	}

	//����
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

	//������(����)
	for (int i = 0; i < 10; i++)
	{
		wsprintf(Miter_Str, "%d0", i);
		StretchBlt(hBack, 30 + (i * 1000), 650, MiterSize.cx * 1.5, MiterSize.cy * 1.5, MiterDC, 0, 0, MiterSize.cx, MiterSize.cy, SRCCOPY);
		//DrawText(hBack, "�� ����ϴ� �������� �鸸��Ʈ ��", -1, &rt, DT_CENTER | DT_WORDBREAK);
		TextOut(hBack, 60 + (i * 1000), 655, Miter_Str, strlen(Miter_Str));
	}

	if (GameManager::get_Instence()->get_EndCheck())
	{
		//����
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

//���� ĳ���� ��ġ �ޱ�(override)
void MapBit::set_CurPos(int _curpos)
{
	curPos = _curpos;
}

//��Ʈ ��ȯ(override)
RECT MapBit::get_Rect()
{
	return Map_Rect;
}

//�Ҹ���
MapBit::~MapBit()
{

}