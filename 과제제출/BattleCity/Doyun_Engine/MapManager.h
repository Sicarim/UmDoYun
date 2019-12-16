#pragma once
#include "GlobalDefine.h"
#include "Singleton.h"

namespace DoEngine
{
	class MapManager : public Singleton<MapManager>
	{
	private:
		int m_wSpace, m_hSpace; //맵을 가로, 세로에서 얼마나 띄울 것인가?(맵을 원하는 위치에 그릴수 있다.
		int m_iWidth, m_iHeight; //Map 가로 크기, 세로 크기
		int m_iVal; //첫 생성시 초기화 할것
		vector<vector<int> > m_MapPos; //이중 벡터 선언 (세로 * 가로)

	public:
		MapManager(); //생성자(default)

		void Init(int _wSize, int _hSize, int _wSpace, int _hSpace, int _val = 0); //맵 초기화 후 만들기
		int get_MapInfo(int _x, int _y); //맵 특정 위치 검사
		void set_MapInfo(int _x, int _y, int _val); //맵 특정 위치에 값 넣기

		~MapManager(); //소멸자
	};
}