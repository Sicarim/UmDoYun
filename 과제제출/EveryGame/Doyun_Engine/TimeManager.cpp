#include "TimeManager.h"

namespace DoEngine
{
	//생성자
	TimeManager::TimeManager()
	{
		m_bUseFPS = false;
		m_nFPS = 30;

		//이것을 통해 FPS를 구한다
		m_dwLastTime = GetTickCount(); //현재 윈도우 타임을 받아온다.
		m_dwCurTime = GetTickCount(); //현재 윈도우 타임을 받아온다.
	}

	//초기화 함수
	void TimeManager::Init(bool _usefps, int _fps)
	{
		m_bUseFPS = _usefps;
		m_nFPS = _fps;
	}

	//Update함수
	bool TimeManager::Update()
	{
		//매 프레임마다 찍히는 TickCount를 받는다. -  현재의 틱카운드를 받아온다.
		m_dwCurTime = GetTickCount();

		if (m_bUseFPS)
		{
			if (m_dwCurTime - m_dwLastTime < 1000 / m_nFPS)
				return false;
		}

		//현재 시간을 저장한다. 루틴이 돌아간 후 이전 루틴에서의 틱 카운트간의 차이를 체크하기 위해서 이다.
		//1000 이상의 차이가 나면 1초이므로  / 1000해서 초로 환산.
		m_fElapseTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;

		//현재 타임을 받는다.
		//결론적으로 이전 타임의 시간을 받는것.
		m_dwLastTime = m_dwCurTime;

		return true;
	}

	//경과 시간을 리턴
	float TimeManager::get_ElipseTime()
	{
		return m_fElapseTime;
	}

	//소멸자
	TimeManager::~TimeManager()
	{

	}
}