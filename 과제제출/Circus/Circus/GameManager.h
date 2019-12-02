#pragma once
#include "Mecro.h"
#include "Singleton.h"

class GameManager : public Singleton<GameManager>
{
private:
	RECT m_pRect;
	RECT m_eRect;
	RECT m_gRect;

	RECT tmp_Rect;
	vector<RECT> m_Fire;
	vector<RECT> m_Ring;
	vector<RECT> m_vBonus;

	float DelayTime, StopTime;
	float GenTime; //���� �ð�
	bool GenCheck; //�� ���� üũ
	int Max_Health; //ĳ���� ��� ����
	bool Hit_Check; //ĳ���Ͱ� �������� �޾Ҵ��� üũ
	bool End_Check; //���� ���� ����
	bool End_Mes;
	bool isStart;
	int Score;
public:
	GameManager(); //������

	void Init(); //���� �ʱ�ȭ
	void Start_Button(); //��ŸƮ ��ư ������
	void FireRing_Generator(float _dftime); //ȭ�� �� ������
	void Intersec_Check(HWND hWnd, float _dftime); //�浹üũ
	void Release(); //������ ����

	bool get_GenCheck(); //�� üũ ����
	void set_GenCheck(bool _check); //�� üũ ����
	bool get_HitCheck(); //��Ʈ ���� ����
	void set_HitCheck(bool _check); //��Ʈ ���� ����
	bool get_EndCheck(); //���� ���� ���� ����
	int get_Health(); //��� �� ����
	void set_EndMes(bool _check); //���� �޼���
	bool get_EndMes(); //���� �޼���
	bool get_isStart(); //��ŸƮ ��ư ����
	int get_MaxScore(); //���� ����

	~GameManager(); //�Ҹ���
};