#pragma once
#include "Mecro.h"
#include "Singleton.h"

class GameManager : public Singleton<GameManager>
{
private:
	RECT m_pRect;
	RECT m_eRect;
	RECT m_gRect;

	RECT tmp_Rect;
	vector<RECT> m_Fire;
	vector<RECT> m_Ring;

	float DelayTime, StopTime;
	float GenTime; //생성 시간
	bool GenCheck; //몹 리젠 체크
	int Max_Health; //캐릭터 목숨 갯수
	bool Hit_Check; //캐릭터가 데미지를 받았는지 체크
	bool End_Check; //골인 지저 도달
	bool End_Mes;

public:
	GameManager(); //생성자

	void Init(); //게임 초기화
	void FireRing_Generator(float _dftime); //화염 고리 생성기
	void Intersec_Check(HWND hWnd, float _dftime); //충돌체크
	void Release(); //데이터 삭제

	bool get_GenCheck(); //젠 체크 리턴
	void set_GenCheck(bool _check); //젠 체크 갱신
	bool get_HitCheck(); //히트 여부 리턴
	void set_HitCheck(bool _check); //히트 여부 삽입
	bool get_EndCheck(); //골인 지점 도달 리턴
	int get_Health(); //목숨 수 리턴
	void set_EndMes(bool _check); //골인 메세지
	bool get_EndMes(); //골인 메세지


	~GameManager(); //소멸자
};