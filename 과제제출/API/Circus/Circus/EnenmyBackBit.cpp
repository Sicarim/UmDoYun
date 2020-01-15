#include "BitMapFactory.h"

//������
EnemyBackBit::EnemyBackBit()
{
	EnemyDC = NULL;
	bitEnemyDC = NULL;
	EnemyOldDC = NULL;
	Back_Rect = { 0 };
	
	MovePos = 0;
}

//BitMap�ʱ�ȭ(Override)
void EnemyBackBit::Bit_Init(HDC hBack, HWND hWnd, float _curx)
{
	curPos = _curx;
	EnemyDC = CreateCompatibleDC(hBack);
	bitEnemyDC = (HBITMAP)LoadImage(NULL, "RES\\enemy_1f.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	EnemyOldDC = (HBITMAP)SelectObject(EnemyDC, bitEnemyDC);

	GetObject(bitEnemyDC, sizeof(EnemyInfo), &EnemyInfo);
	eSize.cx = EnemyInfo.bmWidth;
	eSize.cy = EnemyInfo.bmHeight;

	ReleaseDC(hWnd, hBack);
}

//BitMap�׸���(Override)
void EnemyBackBit::Bit_Draw(HDC hback, float _curx, float _cury, float _dftime)
{
	MovePos += _dftime;

	TransparentBlt(hback, (curPos + PLAYSPACE + FB) - MovePos, 325, eSize.cx * 1.5, eSize.cy * 1.8, EnemyDC, 0, 0, eSize.cx, eSize.cy, RGB(255, 0, 255));
}

//���� ĳ���� ��ġ �ޱ�(override)
void EnemyBackBit::set_CurPos(int _curpos)
{
	curPos = _curpos;
}

//��Ʈ ��ȯ(override)
RECT EnemyBackBit::get_Rect()
{
	return Back_Rect;
}

//�Ҹ���
EnemyBackBit::~EnemyBackBit()
{

}