#pragma once
#include "GlobalDefine.h"
#include "Singleton.h"
#include "DoEngine.h"

namespace DoEngine
{
	/**
	* @brief 맵을 제작하는 MapTool
	* @details 2차원 자료구조를 통해 Map을 만든다. 추후 수정 예정
	*/
	class MapTool : public Singleton<MapTool>
	{
	private:
		int m_wSpace, m_hSpace; //맵을 가로, 세로에서 얼마나 띄울 것인가?(맵을 원하는 위치에 그릴수 있다.
		int m_iWidth, m_iHeight; //Map 가로 크기, 세로 크기
		int m_iVal; //첫 생성시 초기화 할것
		BitMap* m_DefaultBlock; //크기를 지정할 디폴트 블럭

		vector<vector<int> > m_MapPos; //이중 벡터 선언 (세로 * 가로)

		HPEN m_MapPen;
		HPEN m_oldMapPen;
		HBRUSH brush_Map;
		HBRUSH brush_oldMap;

	public:
		MapTool(); //생성자(default)

		void Init(int _wSize, int _hSize, string _name, float _wSpace = 0.0f, float _hSpace = 0.0f, int _val = 0); //맵 초기화 후 만들기
		void Default_MapDraw(int _wSpace = 0, int _hSpace = 0); //기본 격자 무늬 그리기

		int get_MapInfo(int _x, int _y); //맵 특정 위치 검사
		void set_MapInfo(int _x, int _y, int _val); //맵 특정 위치에 값 넣기
		int get_wMapSize(); //맵툴 전체 크기(가로)
		int get_hMapSize(); //맵툴 전체 크기(세로)

		~MapTool(); //소멸자
	};
}