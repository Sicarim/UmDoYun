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
	vector<DoEngine::Object*> m_vCard; //카드 vector

	//카드를 움직일 커맨드 객체 선언
	DoEngine::Command* m_Command;
	InputHandler m_Input;

public:
	CardGame(); //생성자

	void Init(); //게임 초기화
	bool Input(float _fETime); //키 입력
	void Update(float _fETime); //Update함수
	void Draw(); //게임 그리기
	void Release(); //삭제 함수
	void InitBitMap(); //카드 등록

	~CardGame(); //소멸자
};