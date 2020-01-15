#include "StarPool.h"
#include "GameManager.h"

//������
StarPool::StarPool()
{
	m_vStandPool.clear();
	m_vStarPool.clear();
	/*
		���� �ð����� StandPool���� StarPool�� �̵��Ѵ�. 
		������ ����ϴ°��� StarPool
		���� ���ǿ� ���ϸ� �ٽ� StanPool�� ���ư���.
	*/
}

//�ʱ�ȭ
void StarPool::Init()
{
	curTime = 0.0f;
	//Star 100�� �����
	for (int i = 0; i < 100; i++)
	{
		int UpDown = rand() % 350;
		int LeftRight = (rand() % 360) + 90;

		if (i % 3 == 0)
		{
			//������ ����
			m_Star = new BlueStar;
			m_Star->Init(UpDown, 110);
		}
		else if (i % 3 == 1)
		{
			//���ʿ��� ����
			m_Star = new GreenStar;
			m_Star->Init(20, LeftRight);
		}
		else if (i % 3 == 2)
		{
			//�����ʿ��� ����
			m_Star = new YellowStar;
			m_Star->Init(390, LeftRight);
		}
		m_vStandPool.push_back(m_Star);
	}
}

//�Է� �ޱ�
bool StarPool::Input(float _fETime)
{
	return false;
}

//Update
void StarPool::Update(float _fETime)
{
	curTime += _fETime;

	if (!GameManager::get_Instance()->get_isFever())
	{
		if (curTime > 0.8f)
		{
			//���� �ð��� ������ get_Data�� ����
			get_Data();
			curTime = 0.0f;
		}
	}
	//BulletPool�� NULL�� �ƴϸ� StarPool�� ��ü�� ���������� Update�Ѵ�
	else
	{
		if (curTime > 0.2f)
		{
			get_Data();
			curTime = 0.0f;
		}
	}
	
	
	if (m_vStarPool.size() != 0)
	{
		for (int i = 0; i < m_vStarPool.size(); i++)
		{
			m_vStarPool[i]->Update(_fETime);
			//���� �ı��ȴٸ�
			if (!m_vStarPool[i]->Input())
			{
				//ReturnData�� ����
				Return_Data(i);
			}
		}
	}
}

//�׸���
void StarPool::Draw()
{
	//BulletPool�� ����� 0�� �ƴ϶��
	if (m_vStarPool.size() != 0)
	{
		//���������� BulletPool�� ��ü�� �׸���.
		for (int i = 0; i < m_vStarPool.size(); i++)
		{
			m_vStarPool[i]->Draw();
		}
	}
}

//�����ϱ�
void StarPool::Release()
{
	curTime = 0.0f;
	for (auto iter = m_vStandPool.begin(); iter != m_vStandPool.end(); iter++)
	{
		(*iter)->Release();
	}
	for (int i = 0; i < m_vStarPool.size(); i++)
	{
		m_vStarPool[i]->Release();
	}
	m_vStandPool.clear();
	m_vStarPool.clear();
}

//������ ������
void StarPool::get_Data()
{
	//100���� Star�� �־�� StandPool���� �Ǿ��� ��ü�� �ӽð�ü�� ��´�
	DoEngine::Object* tmp_Data = m_vStandPool.front();
	//���� ��, StandPool�� ù ��ü�� �����Ѵ�.
	m_vStandPool.pop_front();
	//������ ���� Pool(StarPool)�� �ִ´�.
	m_vStarPool.push_back(tmp_Data);
}	

//������ �ٽ� ����ֱ�
void StarPool::Return_Data(int _num)
{
	//�ı��� Bullet�� �ӽ� ��ü�� ��´�.
	DoEngine::Object* tmp_Data = m_vStarPool[_num];
	//StandPool�� �ٽ� �ִ´�.
	m_vStandPool.push_back(tmp_Data);
	//�ش� Star�� �����Ѵ�.
	m_vStarPool.erase(m_vStarPool.begin() + _num);
}

//�Ҹ���
StarPool::~StarPool()
{

}