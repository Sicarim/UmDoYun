#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "Enemy.h"

class GameManager : public Singleton<GameManager>
{
private:
	int Bullet_dir;
	int Broken_Count, Water_Count, Bush_Count, Still_Count;
	int Health_Count, Enemy_Count, Destroy_Count;
	int WinAndLose;
	int NextStage;
	bool PlayerDie;

	int UpTank_Count, Tank_Count;

	vector<DoEngine::Object*> tmp_vEnemy; //적 vector
	DoEngine::Object* tmp_Player; //Player Object


public:
	GameManager(); //생성자

	void Init(); //초기화
	void Key_Init(); //키 등록
	void Regist_Scene(); //씬 등록
	vector<DoEngine::Object*> Make_Enemy(); //몬스터 만들기
	void All_Draw(); //모든 콜라이더 그리기
	void set_BulletDir(int _dir); //탄알 방향 저장
	int get_BulletDir(); //탄알 방향 리턴

	void set_BrokenCount(int _count); //파괴되는 블록 갯수 삽입
	void set_WaterCount(int _count); //물 블록 갯수 삽입
	void set_BushCount(int _count); //부쉬 블럭 갯수 삽입
	void set_StillCount(int _count); //강철 블럭 갯수 삽입

	int get_BrokenCount(); //파괴되는 블록 리턴
	int get_WaterCount(); //물 블록 리턴
	int get_BushCount(); //부쉬 블럭 리턴
	int get_StillCount(); //강철 블럭 리턴

	void set_HealthCount(int _num); //적 갯수 저장
	int get_HealthCount(); //적 갯수 리턴

	void set_EnemyCount(int _num); //현재 맵에 있는 적의 갯수 저장
	int get_EnemyCount(); //현재 맵에 있는 적의 갯수 리턴

	void set_Tank(int _num); //Tank갯수 저장
	int get_Tank(); //Tank 갯수 리턴

	void set_UpTank(int _num); //UpTank갯수 저장
	int get_UpTank(); //UpTank갯수 리턴

	void Game_Win(); //게임에서 승리
	void Game_Lose(); //게임에서 패배
	void Game_Start(); //게임 스탑
	int get_WinAndLose(); //게임 승패여부 리턴

	void ScenePlus(); //씬 넘기기
	int get_NextStage(); //다음 스테이지 리턴

	void add_Destroy(); //부서진 적 갯수 저장

	void set_PlayerDie(bool _die); //플레이어 죽음
	bool get_PlayerDie(); //플레이어 죽음



	//test함수
	void set_CurrentX(int _x, int _rx);
	void set_CurrentY(int _y, int _ry);

	int get_CurrentX();
	int get_CurrentY();

	int get_RealX();
	int get_RealY();

	~GameManager(); //소멸자
};