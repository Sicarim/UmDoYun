#pragma once
#include "Singleton.h"
#include <Windows.h>

namespace DoEngine
{
	/**
	* @brief ���ӿ� ���Ǵ� �ð��� FPS�� ����ϴ� Ŭ����
	* @details scene�� Input Update ������ ���ڷ� �Ѿ�� �귯���ð��� �����ϴ� Ŭ���� FPS���� ����� ����.
	*/

	class TimeManager : public Singleton<TimeManager>
	{
	private:
		bool m_bUseFPS;
		int m_nFPS;
		DWORD m_dwLastTime; //���� �ð�
		DWORD m_dwCurTime; //���� �ð�
		float m_fElapseTime; //��� �ð�

	public:
		TimeManager(); //������

		void Init(bool _usefps, int _fps); //�ʱ�ȭ �Լ�
		bool Update(); //Update�Լ�
		float get_ElipseTime(); //��� �ð��� ����

		~TimeManager(); //�Ҹ���
	};
}

