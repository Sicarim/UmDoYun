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

	//타임 체크용
	DWORD m_dwLastTime; //이전 타임
	DWORD m_dwCurTime; //현재 타임
	float m_fDeltaTime; //타임을 저장/ 이전 시간과 현재 시간의 차이를 계산
	float p_test;
	STATE m_pState;

	bool start;
	float Save_Time;
public:
	Circus(); //생성자

	void Game_Init(HWND hWnd); //게임 초기화
	void Init(); //설정 초기화
	void Update(HWND hWnd); //Update함수
	void Game_Start(); //게임 시작화면
	void Generator_Enemy(float _dftime); //적 생성하기
	void Render(float _curx, float _cury, float _dftime); //그리기 함수
	void Shut_Down(HWND hWnd); //게임 종료

	~Circus(); //소멸자
};