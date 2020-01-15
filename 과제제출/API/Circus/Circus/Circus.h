#pragma once
#include "Mecro.h"
#include "Character.h"

class Circus
{
private:
	Character m_Char;
	HWND m_hWnd;
	
	STATE isMoving;

	float Char_curX;
	float Char_curY;

	//Ÿ�� üũ��
	DWORD m_dwLastTime; //���� Ÿ��
	DWORD m_dwCurTime; //���� Ÿ��
	float m_fDeltaTime; //Ÿ���� ����/ ���� �ð��� ���� �ð��� ���̸� ���
	float p_test;
	STATE m_pState;

	bool start;
	float Save_Time;
public:
	Circus(); //������

	void Game_Init(HWND hWnd); //���� �ʱ�ȭ
	void Init(); //���� �ʱ�ȭ
	void Update(HWND hWnd); //Update�Լ�
	void Game_Start(); //���� ����ȭ��
	void Generator_Enemy(float _dftime); //�� �����ϱ�
	void Render(float _curx, float _cury, float _dftime); //�׸��� �Լ�
	void Shut_Down(HWND hWnd); //���� ����

	~Circus(); //�Ҹ���
};