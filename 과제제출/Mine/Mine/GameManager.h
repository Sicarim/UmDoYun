#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h"

using namespace std;

class GameManager : public Singleton<GameManager>
{
private:
	vector<vector<int> > m_MinePos; //이중 벡터 선언
	
	int m_MineX; //Mine X좌표
	int m_MineY; //Mine Y좌표
	bool Trigger;
	int NumTrigger;

	int GameResult;

public:
	GameManager(); //생성자

	void Init(); //맵 배열 선언
	void All_Regist(); //게임 Scene등록
	void Key_Init(); //모든 키 등록
	int Find_Mine(int _thisx, int _thisy); //근처 지뢰의 갯수를 나타낸다

	int get_UnitPos(int _posx, int _posy); //Unit위치 리턴
	int get_UnitX(int _tmp); //행렬의 위치를 반환(x)
	int get_UnitY(int _tmp); //행렬의 위치를 반환(y)

	void set_GameResult(int _result); //게임 결과 가져오기
	int get_GameResult(); //게임 결과 리턴
	bool get_Trigger();
	int get_NumTrigger();

	~GameManager(); //소멸자
};