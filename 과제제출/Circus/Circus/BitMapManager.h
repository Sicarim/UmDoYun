#pragma once
#include "Mecro.h"
#include "Singleton.h"
#include "BitMapFactory.h"

class BitMapManager : public Singleton <BitMapManager>
{
private:
	BitMapFactory* m_BitFac;

	BitMapFactory* m_playerBit;
	BitMapFactory* m_MapBit;
	BitMapFactory* m_ObjectBit;
	BitMapFactory* m_First;
	vector<BitMapFactory*> m_FrontRingBit;
	vector<BitMapFactory*> m_BackRingBit;
	vector<BitMapFactory*> m_FireBit;
	vector<BitMapFactory*> m_Bonus;

	vector<RECT> Fire_collider;
	vector<RECT> Ring_collider;
	vector<RECT> Bonus_collider;

	HDC hBackDC; //���� �׸� ���(��ȭ��)�� �غ�
	HBITMAP hBitBackDC;
	HBITMAP hOldDC;

	BITMAP BackMapInfo;
	SIZE BackSize;

	RECT m_pRect;
	RECT m_eRect;
	RECT m_GoalRect;

	int BonusCount;
	bool bitGenCheck;
public:
	BitMapManager(); //������
	
	void All_Init(HWND hWnd); //�ʱ�ȭ
	void Make_FireRing(HWND hWnd, float _curx); //ȭ�� �� �����
	void All_Draw(HWND hWnd, float _curx, float _cury, float _dftime); //�׸���
	void First_Draw(HWND hWnd, float _curx, float _cury, float _dftime); //����ȭ�� �׸���

	void Make_BackGround(HDC _hBackDC, HWND hWnd); //���ȭ�� �����
	void Make_Player(HDC _hBackDC, HWND hWnd); //�÷��̾� �����
	void Make_FrontEnemy(HDC _hBackDC, HWND hWnd, float _curx); //��(�պκ�) �����
	void Make_BackEnemy(HDC _hBackDC, HWND hWnd, float _curx); //��(�޺κ�) �����
	void Make_FireEnemy(HDC _hBackDC, HWND hWnd); //��(���̾�~) �����
	void Make_Object(HDC _hBackDC, HWND hWnd); //������Ʈ �����
	void Make_SelectView(HDC _hBackDC, HWND hWnd); //����ȭ�� �����
	void Make_Bonus(HDC _hBackDC, HWND hWnd, float _curx); //���ʽ� �ָӴ� �����

	void BackGround_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //���ȭ�� �׸���
	void Player_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //�÷��̾� �׸���
	void FrontEnemy_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //��(�պκ�) �׸���
	void BackEnemy_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //��(�޺κ�) �׸���
	void FireEnemy_Draw(HDC _hBackDC, float _curx, float _cury); //��(���̾�) �׸���
	void Object_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //������Ʈ �׸���
	void SelectView_Draw(HDC _hBackDC, float _curx, float _cury, float _dftime); //����ȭ�� �׸���

	void Delete_Ring(); //�� ����
	RECT get_pRect(); //�÷��̾� ���� ����
	vector<RECT> get_FireCol(); //Fire�ݶ��̴� ����
	vector<RECT> get_RingCol(); //Ring�ݶ��̴� ����
	RECT get_GoalRect(); //������ ��Ʈ ��ȯ
	vector<RECT> get_BonusCol(); //���ʽ� �ݶ��̴� ��ȯ


	void Release(); //������ ����

	~BitMapManager(); //�Ҹ���
};