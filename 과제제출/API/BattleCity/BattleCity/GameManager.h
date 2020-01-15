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
	int Bullet_Count;
	bool PlayerDie;
	TCHAR buf[255];
	int UpTank_Count, Tank_Count;

	vector<string> m_vColl; //충돌 처리할 오브젝트들의 목록
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
	int BulletCount(); //탄알에 번호를 매긴다.
	void add_WallCollider(); //충돌할 콜라이더 등록
	void Release(); //스테이지가 재실행 될때 초기화한다

	vector<string> get_m_vColl(); //콜라이더 모음 리턴

	void set_BrokenCount(int _count); //파괴되는 블록 갯수 삽입
	void set_WaterCount(int _count); //물 블록 갯수 삽입
	void set_BushCount(int _count); //부쉬 블럭 갯수 삽입
	void set_StillCount(int _count); //강철 블럭 갯수 삽입

	int get_WaterCount(); //물 블록 리턴

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

	~GameManager(); //소멸자
};