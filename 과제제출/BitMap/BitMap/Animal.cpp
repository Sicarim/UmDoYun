#include "Animal.h"
#include "BitMapManager.h"

//������
Animal::Animal()
{
	x = 30;
	y = 30;
}

//��� �׸� �ʱ�ȭ
/*
������ �ڵ� ������ �����ϰ�, ���α׷��� �ν��Ͻ� �ĺ��ڸ� �Ѱ� �޴´�.
���� ������, ���� ���α׷����� ���ư��� �����ε�
Init�� ������ �ڵ鷯, ���α׷� �ν��Ͻ� �ĺ��ڰ� ���ٴ°Ϳ� ����(HWND, HIMSTAME)
*/

/*
���� HWND�� ����ϴ°��� ���� ������ â���� �Ͼ�� ���ε��ϴ�.

�ᱹ HINSTANCE�� ���α׷� ��ü�� �ڵ��̸�, HWND�� ���α׷����� ������â�� ��ȣ�ΰͰ���.
�׷� HINSTANCE�� ���α׷��� �ϳ���� ������ �ϳ���, HWND�� �������� �ɼ� �ִ°��ֳ�?
�����带 ������ �ν��ٽ����� Ȥ�� �޶�����? �ƴѰ�? ���� ���α׷��̴ϱ�..?
*/
void Animal::All_Init(HWND hWnd, HINSTANCE _hInst)
{
	//GetDC�� DC�� ������ �ڵ� ������ ���� �޾� �´�. 
	//HDC hdc = GetDC(hWnd);

	//GetDC�� �޾ƿ� DC�� �ݵ�� ������ ���־�� �ϴµ� ReleaseDC�� ���� ������ �Ѵ�.
	//ReleaseDC(hWnd, hdc);
}

/*
�׸����� ���� ǥ��(���)�� �ϱ� ���ؼ� hdc�� �ʿ��ϴٴ°� �ٽ� �������
�ֳĸ� DC�� ��¿� �ʿ��� ��� ������ ������ ������ ����ü�̱� �����̴�.
�ᱹ HDC�� DC�� ������ �����ϴ� ������ ����ü�� ��ġ�� �˱� �����̶��� �������
*/
//��� �׸� �׸���
void Animal::All_Draw(HDC hdc)
{
	int Count = 1;
	bit = BitMapManager::get_Instence()->get_Bit();
	//x�� ����: 170

	for (auto iter = bit.begin(); iter != bit.end(); iter++)
	{				
		if(Count == 5)
		{
			(*iter).Draw(hdc, x, y);
			y = 300;
			x = 30;
			Count = 0;
		}
		(*iter).Draw(hdc, x, y);
		x += 170;
		Count++;
	}
}

//�޽��� ����
/*
�޽��� �ڽ��� ���� ������ ���� �޴µ� �ϴ�.
*/
void Animal::Send_Message(HWND hWnd, int _mouseX, int _mouseY)
{
	if (_mouseY > 30 && _mouseY < 280)
	{
		if (_mouseX > 30 && _mouseX < bit[0].get_Width() + 30)
		{
			(MessageBox(hWnd, "�����", "����", MB_OK));
		}
		else if (_mouseX > 200 && _mouseX < bit[1].get_Width() + 200)
		{
			(MessageBox(hWnd, "ȣ����(���� �����)", "����", MB_OK));
		}
		else if (_mouseX > 370 && _mouseX < bit[2].get_Width() + 370)
		{
			(MessageBox(hWnd, "�������", "����", MB_OK));
		}
		else if (_mouseX > 540 && _mouseX < bit[3].get_Width() + 540)
		{
			(MessageBox(hWnd, "�ڳ���", "����", MB_OK));
		}
		else if (_mouseX > 710 && _mouseX < bit[4].get_Width() + 710)
		{
			(MessageBox(hWnd, "���", "����", MB_OK));
		}
	}

	if (_mouseY > 200 && _mouseY < 450)
	{
		if (_mouseX > 30 && _mouseX < bit[5].get_Width() + 30)
		{
			(MessageBox(hWnd, "��(������)", "����", MB_OK));
		}
		else if (_mouseX > 200 && _mouseX < bit[6].get_Width() + 200)
		{
			(MessageBox(hWnd, "�����(������)", "����", MB_OK));
		}
		else if (_mouseX > 370 && _mouseX < bit[7].get_Width() + 370)
		{
			(MessageBox(hWnd, "������", "����", MB_OK));
		}
		else if (_mouseX > 540 && _mouseX < bit[8].get_Width() + 540)
		{
			(MessageBox(hWnd, "������", "����", MB_OK));
		}
		else if (_mouseX > 710 && _mouseX < bit[9].get_Width() + 710)
		{
			(MessageBox(hWnd, "ġŲ", "����", MB_OK));
		}
	}
}

//������
Animal::~Animal()
{

}