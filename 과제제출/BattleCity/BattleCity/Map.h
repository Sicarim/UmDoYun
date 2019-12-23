#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "defines.h"
#include "StillWall.h"

class Map
{
private:
	DoEngine::Collider m_MapColl; //콜라이더
	DoEngine::BitMap* m_pBack; //TitleScene 배경회면 등록
	StillWall m_Sill;
	

	int m_wSize;
	int m_hSize;
	string m_sTag;
	
public:
	Map(); //생성자

	void MakeMap(int _wsize, int _hsize); //맵 생성
	void DrawMap(); //맵 그리기

	~Map(); //소멸자
};