#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "POINT.h"
#include "FlagBlock.h"
#include "MineBlock.h"

/*
* @brief ���� ���� ȭ�� 
* @details ������ �����ϴ� Scene
*/

struct DeleteBlock
{
	int Click_x;
	int Click_y;
};

class GameScene : public DoEngine::Scene
{
private:
	int Count; //Ŭ�� ī��Ʈ
	int Answer_Count; //���� ����
	int Mine_Count; //���� ���� ����
	float Cur_Sec; //GameScene������ �ð� ����(��)
	float Cur_Min; //GameScene������ �ð� ����(��)
	float Time;
	bool Click_Check; //Ŭ�� üũ
	bool Die;
	bool Flag_Check;
	bool Flag_InputCheck;
	int Hint_Num;

	TCHAR tmp_Time[256]; //�ð� ǥ��
	TCHAR tmp_Count[256]; //�ð� ǥ��

	DoEngine::POINT m_Lclick; //��Ŭ�� ��ǥ
	DoEngine::POINT m_Rclick; //��Ŭ�� ��ǥ
	DoEngine::BitMap* m_pBackDC; //���ȭ�� ���

	DoEngine::BitMap* tmp_Block;

	FlagBlock* tmp_Flag; //��� ����
	MineBlock* tmp_Mine; //���� ����

	vector<DoEngine::BitMap*> m_vBlock; //�� ���
	vector<DeleteBlock> m_DelClick; //�� ���� ��
	vector<MineBlock*> m_vMines; //���� ��
	vector<FlagBlock*> m_vFlags; //��� ��
	
public:
	GameScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ(override)
	virtual bool Input(float _fETime); //Ű �Է�(override)
	virtual void Update(float _fETime); //Update(override)
	virtual void Draw(HDC hdc); //Draw�Լ�(Override)
	virtual void Release(); //Release()�Լ� (override)s

	void Draw_Number(int _x, int _y); //���� �׸���
	void All_Draw(); //��� Ǯ���� �����ϰ� �׸���
	void Draw_FullBlock(); //Ǯ�� �׸���
	void Draw_Remove(int This_X, int This_Y); //��ó ������ ���ö����� �����
	void Draw_Block(int _x, int _y, DoEngine::BitMap* _bmp); //�� �׸���
	void Hint_Block(); //��Ʈ �� �׸��� 

	~GameScene(); //�Ҹ���
};