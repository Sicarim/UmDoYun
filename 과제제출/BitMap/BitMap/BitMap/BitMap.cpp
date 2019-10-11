#include "BitMap.h"

//������
BitMap::BitMap()
{

}

//��Ʈ�� ����
/*
������ �ڵ� ������ �����ϰ�, ���α׷��� �ν��Ͻ� �ĺ��ڸ� �Ѱ� �޴´�.
���� ������, ���� ���α׷����� ���ư��� �����ε�, �׷� �ٸ� �ĺ���(HINSTENCE)�� ���� ����ϴ°��ΰ�?
Init�� ������ �ڵ鷯, ���α׷� �ν��Ͻ� �ĺ��ڰ� ���ٴ°Ϳ� ����(HWND, HIMSTAME)
*/
void BitMap::Init(HDC hdc, HINSTANCE _hInst, int _id)
{
	//Dc�� ������ ������ DC�� �޸𸮻� ����� �ش�.
	//�޸� DC�� �̿��Ͽ� �׸��� �غ� �ϱ� �����̴�.
	MemDC = CreateCompatibleDC(hdc); //�޾ƿ� hdc�� ������ DC�� MemDC�� ������ش�.
	//�޾ƿ� ��Ʈ�� ���̵� ���� �ش� ���α׷�(HINSTANCE0)�� �ҷ��´�. �̸� myBitMap�� �ִ´�.
	myBitmap = LoadBitmap(_hInst, MAKEINTRESOURCE(_id));
	//myBitmap�� ������ DC�� oldBitmap�� ����!(�ݵ�� ������ ���ִ°� ��Ģ�̶� �̷��� ���� ������ �ٽ� �׷����� �ʴ´�.)
	oldBitmap = (HBITMAP)SelectObject(MemDC, myBitmap);

	/*
	�߿�!!!!!!! BITMAPŬ������ �̿��Ͽ� �޾ƿ� Bitmap�� ������ �ҷ��´�!@!!!!!
	*/
	BITMAP bit_Info;

	//GDI������Ʈ�� �ڵ�(myBitMap)���� �޾ƿ´�. ����, ���ۿ� ������ ũ��, ���ۿ� ������ ���Ϲ��� ����ü�� �����͸� �����ش�)
	//GetObject(myBitmap, ->�����ϰ����ϴ� GDI ������Ʈ�� �ڵ�
	//sizeof(bit_Info), ->���ۿ� ������ ������ ũ��
	//&bit_Info); ->������Ʈ�� ������ ���Ϲ��� ����ü�� ������(������ �μ��� NULL�� �ϸ� �ʿ��� ������ ũ�⸦ ����, ���н� 0�� �����Ѵ�.)
	GetObject(myBitmap, sizeof(bit_Info), &bit_Info);

	//������Ʈ�� ����� ����
	size.cx = bit_Info.bmWidth;
	size.cy = bit_Info.bmHeight;
}

void BitMap::Draw(HDC hdc, int x, int y, int _bitsizeW, int _bitsizeH)
{
	/*
	BitBlt: ���� �׷��� �׸�
	StretchBit: ũ�⸦ ���� ����
	6��° �μ� ���� ���� �׷���(���� ������)ũ�⸦ �����Ѵ�.
	*/
	StretchBlt(hdc, x, y, _bitsizeW * size.cx, _bitsizeH * size.cy, MemDC, 0, 0, size.cx, size.cy, SRCCOPY);
}

//�Ҹ���
BitMap::~BitMap()
{
	/*
	GDI������Ʈ�� �޸𸮸� ����ϱ� ������ ��� �� �ݵ�� �����ؾ��Ѵ�.
	�̶� ���������� DC�� ���� ���õǾ��ִ� GDI������Ʈ�� ������ �� ����.
	�׷��� �����ϱ� ���� DC�� ���õ� ��ü�� �����ؾ��Ѵ�.
	*/

	//���� myBitMap�� ���� �Ǿ� �����Ƿ�, ���� ������ ������Ʈ �ڵ�(oldBitMap)�� �����Ѵ�.
	SelectObject(MemDC, oldBitmap);
	//�����آZ���� ����
	DeleteObject(myBitmap);
	//�ʵ� ����
	DeleteDC(MemDC);
}