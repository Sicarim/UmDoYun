#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "BlueCard.h"
#include "RedCard.h"
#include "GreenCard.h"
#include "YellowCard.h"
#include "InputHandler.h"
#include "Text.h"

class CardGame
{
private:
	int Card_Count;
	TCHAR Card_Score[255];
	
	DoEngine::Object* Color_Card;
	DoEngine::Text m_Text;
	vector<DoEngine::Object*> m_vCard; //ī�� vector

	//ī�带 ������ Ŀ�ǵ� ��ü ����
	DoEngine::Command* m_Command;
	InputHandler m_Input;

public:
	CardGame(); //������

	void Init(); //���� �ʱ�ȭ
	bool Input(float _fETime); //Ű �Է�
	void Update(float _fETime); //Update�Լ�
	void Draw(); //���� �׸���
	void Release(); //���� �Լ�
	void InitBitMap(); //ī�� ���

	~CardGame(); //�Ҹ���
};