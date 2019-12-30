#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "InputHandler.h"
#include "Node.h"
#include "defines.h"

//적을 관리하는 AIManager, 적의 행동을 관할한다.
class AIManager : public Singleton<AIManager>
{
private:
	vector<DoEngine::Object*> m_vEnemy; //몬스터 저장

	//적을 움직을 커맨드 객체 선언
	DoEngine::Command* tmp_Command;
	vector<DoEngine::Command*> Enemy_behavior;
	DoEngine::Command* m_Command;
	InputHandler m_Input;
public:
	AIManager(); //생성자

	void Init(); //길찾기 초기화
	bool Input(); //키입력
	void Update(float _fETime); //Update함수
	void Draw(); //Draw 함수
	void Release(); //Release() 함수
	void Find_Way(); //길찾기

	~AIManager(); //소멸자
};