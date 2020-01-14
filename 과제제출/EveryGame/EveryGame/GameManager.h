#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"

/*
	GameManager���, Game�� �����ϴ� ��� ���� �� �Լ��� ���
*/
class GameManager : public Singleton<GameManager>
{
private:
	TCHAR buf[255];
	int TotalScore;
	int FeverAlpa;
	int UltraAlpa;
	int FeverCount;

	float curTime;
	float FeverTime;
	float FeverPuple_Count, FeverRed_Count, FeverYellow_Count;

	bool isUltr, isFever, isGameOver;
	

	DoEngine::BitMap* Fever_Bit; //FeverEffect ���
	DoEngine::BitMap* Time_Bar; //Time Bar���
	DoEngine::BitMap* m_vFeverBar[3]; //FeverVar���
	DoEngine::BitMap* tmp_Bonus; //Bonus Bit�� ���� �ӽ� ��ü
	vector<DoEngine::BitMap*> m_vBonus; //���ʽ� ���� ���(vector)
	DoEngine::BitMap* Load_BackBit; //�ε� Back��Ʈ��
	DoEngine::BitMap* Load_Bit; //�ε� ��Ʈ��

	//CardGame
	int Card_Count; //ī�� ī��Ʈ ���
	int AnswerCount; //�����̸� ���� ī��Ʈ ���
	int Bonus_Score; //���ʽ� ����

	//FlightGame
	bool FlightDestroy;
public:
	GameManager(); //������

	void Init(); //�ʱ�ȭ �Լ�
	void Regist_Scene(); //Scene���
	void Update(float _fETime); //Update
	void All_Draw(); //��� �ݶ��̴� �׸���
	void Key_Init(); //Ű ���
	void Release(); //���� �Լ�
	
	void ManagerUI_Draw(); //Fever ����Ʈ �׸���
	void Loading_Draw(); //Fever ����Ʈ �׸���

	void add_FeverCount(); //Fever������ ���

	void set_Score(int _score); //���� ����
	int get_Score(); //���� ����
	bool get_GameOver(); //���� ���� ����
	bool get_isFever(); //Fever���� ����
	~GameManager(); //�Ҹ���

	//ī�� ����
	void CardGame_Init(); //ī����� �ʱ�ȭ
	void add_BonusScore(); //���ʽ� ���� ����
	void add_CardCount(); //ī�� Ƚ�� ����
	int get_CardCount(); //ī�� Ƚ�� ����
	DoEngine::BitMap* Bonus_Card();
	vector<DoEngine::BitMap*> get_Bonus();
	void Down_FeverBar(); //FeverBar����
	void CardGame_Release(); //ī����� ���� �Լ�

	//����� ����
	void FlightGame_Init(); //����� ���� �ʱ�ȭ
	void FlightGame_Release(); //����� ���� �Լ�
	void set_Destroy(bool _isDestroy); //����� �ı�
	bool get_Destroy(); //����� �ı� ���θ���
};