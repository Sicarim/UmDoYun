#pragma once
#include "Singleton.h"
#include <Windows.h>

namespace DoEngine
{
	/**
	* @brief 게임에 사용되는 시간과 FPS를 담당하는 클래스
	* @details scene의 Input Update 에서의 인자로 넘어가는 흘러간시간을 관리하는 클레스 FPS조절 기능을 가짐.
	*/

	class TimeManager : public Singleton<TimeManager>
	{
	private:
		bool m_bUseFPS;
		int m_nFPS;
		DWORD m_dwLastTime; //이전 시간
		DWORD m_dwCurTime; //현재 시간
		float m_fElapseTime; //경과 시간

	public:
		TimeManager(); //생성자

		void Init(bool _usefps, int _fps); //초기화 함수
		bool Update(); //Update함수
		float get_ElipseTime(); //경과 시간을 리턴

		~TimeManager(); //소멸자
	};
}

