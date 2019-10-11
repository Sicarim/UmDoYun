#include "Animal.h"

//������
Animal::Animal()
{

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
	HDC hdc = GetDC(hWnd);

	m_Dog.Init(hdc, _hInst, IDB_BITMAP1);
	m_Tiger.Init(hdc, _hInst, IDB_BITMAP2);
	m_Duck.Init(hdc, _hInst, IDB_BITMAP3);
	m_Ele.Init(hdc, _hInst, IDB_BITMAP4);
	m_BlackCow.Init(hdc, _hInst, IDB_BITMAP5);
	m_Horse.Init(hdc, _hInst, IDB_BITMAP6);
	m_Cat.Init(hdc, _hInst, IDB_BITMAP7);
	m_Mongkey.Init(hdc, _hInst, IDB_BITMAP8);
	m_Frog.Init(hdc, _hInst, IDB_BITMAP10);
	m_Dak.Init(hdc, _hInst, IDB_BITMAP11);

	//GetDC�� �޾ƿ� DC�� �ݵ�� ������ ���־�� �ϴµ� ReleaseDC�� ���� ������ �Ѵ�.
	ReleaseDC(hWnd, hdc);
}

/*
�׸����� ���� ǥ��(���)�� �ϱ� ���ؼ� hdc�� �ʿ��ϴٴ°� �ٽ� �������
�ֳĸ� DC�� ��¿� �ʿ��� ��� ������ ������ ������ ����ü�̱� �����̴�.
�ᱹ HDC�� DC�� ������ �����ϴ� ������ ����ü�� ��ġ�� �˱� �����̶��� �������
*/
//��� �׸� �׸���
void Animal::All_Draw(HDC hdc)
{
	//x�� ����: 170
	m_Dog.Draw(hdc, 30, 30);
	m_Tiger.Draw(hdc, 200, 30);
	m_Duck.Draw(hdc, 370, 30);
	m_Ele.Draw(hdc, 540, 30);
	m_BlackCow.Draw(hdc, 710, 30);
	m_Horse.Draw(hdc, 30, 300);
	m_Cat.Draw(hdc, 200, 300);
	m_Mongkey.Draw(hdc, 370, 300);
	m_Frog.Draw(hdc, 540, 300);
	m_Dak.Draw(hdc, 710, 300);
}

//�޽��� ����
/*
�޽��� �ڽ��� ���� ������ ���� �޴µ� �ϴ�.
*/
void Animal::Send_Message(HWND hWnd, int _mouseX, int _mouseY)
{
	if (_mouseY > 30 && _mouseY < 280)
	{
		if (_mouseX > 30 && _mouseX < m_Dog.get_Width() + 30)
		{
			(MessageBox(hWnd, "�����", "����", MB_OK));
		}
		else if (_mouseX > 200 && _mouseX < m_Tiger.get_Width() + 200)
		{
			(MessageBox(hWnd, "ȣ����(���� �����)", "����", MB_OK));
		}
		else if (_mouseX > 370 && _mouseX < m_Duck.get_Width() + 370)
		{
			(MessageBox(hWnd, "�������", "����", MB_OK));
		}
		else if (_mouseX > 540 && _mouseX < m_Ele.get_Width() + 540)
		{
			(MessageBox(hWnd, "�ڳ���", "����", MB_OK));
		}
		else if (_mouseX > 710 && _mouseX < m_BlackCow.get_Width() + 710)
		{
			(MessageBox(hWnd, "���", "����", MB_OK));
		}
	}

	if (_mouseY > 200 && _mouseY < 450)
	{
		if (_mouseX > 30 && _mouseX < m_Horse.get_Width() + 30)
		{
			(MessageBox(hWnd, "��(������)", "����", MB_OK));
		}
		else if (_mouseX > 200 && _mouseX < m_Cat.get_Width() + 200)
		{
			(MessageBox(hWnd, "�����(������)", "����", MB_OK));
		}
		else if (_mouseX > 370 && _mouseX < m_Mongkey.get_Width() + 370)
		{
			(MessageBox(hWnd, "������", "����", MB_OK));
		}
		else if (_mouseX > 540 && _mouseX < m_Frog.get_Width() + 540)
		{
			(MessageBox(hWnd, "������", "����", MB_OK));
		}
		else if (_mouseX > 710 && _mouseX < m_Dak.get_Width() + 710)
		{
			(MessageBox(hWnd, "ġŲ", "����", MB_OK));
		}
	}
}

//������
Animal::~Animal()
{

}