#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"
#include "StillWall.h"
#include "BrokenWall.h"

class Map : public DoEngine::Object
{
private:
	TCHAR buf[255];
	int m_wSize;
	int m_hSize;
	int Broken_Count, Water_Count, Bush_Count, Still_Count;
	string m_sTag;

	//벽만들기
	StillWall* tmp_Still;
	BrokenWall* tmp_Broken;
	vector<BrokenWall*> m_vBroken;
	vector<StillWall*> m_vStill;

	DoEngine::Collider m_MapColl; //콜라이더
	DoEngine::BitMap* m_pBack; //TitleScene 배경회면 등록
	
public:
	Map(); //생성자

	void Init(int _x = 0, int _y = 0); //초기화(override)
	bool Input(int _state); //키입력(override)
	void Update(float _fETime); //Update함수(override)
	void Draw(); //Draw 함수(override)
	void Draw(int _x, int _y); //Draw 함수(override)
	void Release(); //Release() 함수(override)

	void All_InitBlock(); //모든 블럭 초기화

	~Map(); //소멸자
};