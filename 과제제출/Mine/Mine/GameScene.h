#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "POINT.h"
#include "FlagBlock.h"
#include "MineBlock.h"

/*
* @brief 게임 진행 화면 
* @details 게임을 진행하는 Scene
*/

struct DeleteBlock
{
	int Click_x;
	int Click_y;
};

class GameScene : public DoEngine::Scene
{
private:
	int Count; //클릭 카운트
	int Answer_Count; //정답 갯수
	int Mine_Count; //누른 마인 갯수
	float Cur_Sec; //GameScene에서의 시간 저장(초)
	float Cur_Min; //GameScene에서의 시간 저장(분)
	float Time;
	bool Click_Check; //클릭 체크
	bool Die;
	bool Flag_Check;
	bool Flag_InputCheck;
	int Hint_Num;

	TCHAR tmp_Time[256]; //시간 표시
	TCHAR tmp_Count[256]; //시간 표시

	DoEngine::POINT m_Lclick; //좌클릭 좌표
	DoEngine::POINT m_Rclick; //우클릭 좌표
	DoEngine::BitMap* m_pBackDC; //배경화면 등록

	DoEngine::BitMap* tmp_Block;

	FlagBlock* tmp_Flag; //깃발 선언
	MineBlock* tmp_Mine; //지뢰 선언

	vector<DoEngine::BitMap*> m_vBlock; //블럭 등록
	vector<DeleteBlock> m_DelClick; //블럭 삭제 블럭
	vector<MineBlock*> m_vMines; //마인 블럭
	vector<FlagBlock*> m_vFlags; //깃발 블럭
	
public:
	GameScene(); //생성자

	virtual void Init(HWND hWnd); //초기화(override)
	virtual bool Input(float _fETime); //키 입력(override)
	virtual void Update(float _fETime); //Update(override)
	virtual void Draw(HDC hdc); //Draw함수(Override)
	virtual void Release(); //Release()함수 (override)s

	void Draw_Number(int _x, int _y); //숫자 그리기
	void All_Draw(); //모든 풀블럭을 제외하고 그리기
	void Draw_FullBlock(); //풀블럭 그리기
	void Draw_Remove(int This_X, int This_Y); //근처 마인이 나올때까지 지우기
	void Draw_Block(int _x, int _y, DoEngine::BitMap* _bmp); //블럭 그리기
	void Hint_Block(); //힌트 블럭 그리기 

	~GameScene(); //소멸자
};