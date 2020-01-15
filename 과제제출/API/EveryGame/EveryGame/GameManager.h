#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"

/*
	GameManager등록, Game에 관여하는 모든 변수 및 함수를 등록
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
	

	DoEngine::BitMap* Fever_Bit; //FeverEffect 등록
	DoEngine::BitMap* Time_Bar; //Time Bar등록
	DoEngine::BitMap* m_vFeverBar[3]; //FeverVar등록
	DoEngine::BitMap* tmp_Bonus; //Bonus Bit를 담을 임시 객체
	vector<DoEngine::BitMap*> m_vBonus; //보너스 점수 등록(vector)
	DoEngine::BitMap* Load_BackBit; //로딩 Back비트맵
	DoEngine::BitMap* Load_Bit; //로딩 비트맵

	//CardGame
	int Card_Count; //카드 카운트 등록
	int AnswerCount; //정답이면 정답 카운트 등록
	int Bonus_Score; //보너스 점수

	//FlightGame
	bool FlightDestroy;
public:
	GameManager(); //생성자

	void Init(); //초기화 함수
	void Regist_Scene(); //Scene등록
	void Update(float _fETime); //Update
	void All_Draw(); //모든 콜라이더 그리기
	void Key_Init(); //키 등록
	void Release(); //삭제 함수
	
	void ManagerUI_Draw(); //Fever 이펙트 그리기
	void Loading_Draw(); //Fever 이펙트 그리기

	void add_FeverCount(); //Fever게이지 상승

	void set_Score(int _score); //점수 삽입
	int get_Score(); //점수 리턴
	bool get_GameOver(); //게임 오버 리턴
	bool get_isFever(); //Fever여부 리턴
	~GameManager(); //소멸자

	//카드 게임
	void CardGame_Init(); //카드게임 초기화
	void add_BonusScore(); //보너스 점수 리턴
	void add_CardCount(); //카드 횟수 증가
	int get_CardCount(); //카드 횟수 리턴
	DoEngine::BitMap* Bonus_Card();
	vector<DoEngine::BitMap*> get_Bonus();
	void Down_FeverBar(); //FeverBar감소
	void CardGame_Release(); //카드게임 삭제 함수

	//비행기 게임
	void FlightGame_Init(); //비행기 게임 초기화
	void FlightGame_Release(); //비행기 삭제 함수
	void set_Destroy(bool _isDestroy); //비행기 파괴
	bool get_Destroy(); //비행기 파괴 여부리턴
};