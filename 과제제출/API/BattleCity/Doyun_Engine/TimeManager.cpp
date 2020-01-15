#include "TimeManager.h"

namespace DoEngine
{
	//������
	TimeManager::TimeManager()
	{
		m_bUseFPS = false;
		m_nFPS = 30;

		//�̰��� ���� FPS�� ���Ѵ�
		m_dwLastTime = GetTickCount(); //���� ������ Ÿ���� �޾ƿ´�.
		m_dwCurTime = GetTickCount(); //���� ������ Ÿ���� �޾ƿ´�.
	}

	//�ʱ�ȭ �Լ�
	void TimeManager::Init(bool _usefps, int _fps)
	{
		m_bUseFPS = _usefps;
		m_nFPS = _fps;
	}

	//Update�Լ�
	bool TimeManager::Update()
	{
		//�� �����Ӹ��� ������ TickCount�� �޴´�. -  ������ ƽī��带 �޾ƿ´�.
		m_dwCurTime = GetTickCount();

		if (m_bUseFPS)
		{
			if (m_dwCurTime - m_dwLastTime < 1000 / m_nFPS)
				return false;
		}

		//���� �ð��� �����Ѵ�. ��ƾ�� ���ư� �� ���� ��ƾ������ ƽ ī��Ʈ���� ���̸� üũ�ϱ� ���ؼ� �̴�.
		//1000 �̻��� ���̰� ���� 1���̹Ƿ�  / 1000�ؼ� �ʷ� ȯ��.
		m_fElapseTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;

		//���� Ÿ���� �޴´�.
		//��������� ���� Ÿ���� �ð��� �޴°�.
		m_dwLastTime = m_dwCurTime;

		return true;
	}

	//��� �ð��� ����
	float TimeManager::get_ElipseTime()
	{
		return m_fElapseTime;
	}

	//�Ҹ���
	TimeManager::~TimeManager()
	{

	}
}