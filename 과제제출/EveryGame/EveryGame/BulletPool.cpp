#include "BulletPool.h"
#include "GameManager.h"

//������
BulletPool::BulletPool()
{
	m_vStandPool.clear();
	m_vBulletPool.clear();
	/*
		���� �ð����� StandPool���� BulletPool�� �̵��Ѵ�.
		������ ����ϴ°��� BulletPool
		���� ���ǿ� ���ϸ� �ٽ� StanPool�� ���ư���.
	*/
}

//�ʱ�ȭ
void BulletPool::Init()
{
	curTime = 0.0f;
	//Bullet 100�� �����
	for (int i = 0; i < 100; i++)
	{
		int UpDown = rand() % 380 + 1;
		int LeftRight = (rand() % 500) + 90;
		m_Bullet = new Bullet;

		if (i % 4 == 0)
		{
			//������ ����
			m_Bullet->Init(UpDown, 110);
		}
		else if (i % 4 == 1)
		{
			//���ʿ��� ����
			m_Bullet->Init(20, LeftRight);
		}
		else if (i % 4 == 2)
		{
			//�Ʒ��ʿ��� ����
			m_Bullet->Init(UpDown, 570);
		}
		else if (i % 4 == 3)
		{
			//�����ʿ��� ����
			m_Bullet->Init(390, LeftRight);
		}
		m_Bullet->set_Birth(i);
		m_vStandPool.push_back(m_Bullet);
	}
}

//�Է� �ޱ�
bool BulletPool::Input(float _fETime)
{
	return false;
}

//Update
void BulletPool::Update(float _fETime)
{
	curTime += _fETime;

	if (curTime > 0.5f)
	{
		get_Data();
		curTime = 0.0f;
	}
	
	if (m_vBulletPool.size() != 0)
	{
		for (int i = 0; i < m_vBulletPool.size(); i++)
		{
			m_vBulletPool[i]->Update(_fETime);
			if (!m_vBulletPool[i]->Input())
			{
				Return_Data(i);
			}
		}
	}

	if (GameManager::get_Instance()->get_Destroy())
	{
		for (int i = 0; i < m_vBulletPool.size(); i++)
		{
			m_vBulletPool[i]->Release();
		}
		m_vBulletPool.clear();
		Init();
	}
}

//�׸���
void BulletPool::Draw()
{
	if (m_vBulletPool.size() != 0)
	{
		for (int i = 0; i < m_vBulletPool.size(); i++)
		{
			m_vBulletPool[i]->Draw();
		}
	}
}

//�����ϱ�
void BulletPool::Release()
{
	curTime = 0.0f;
	for (auto iter = m_vStandPool.begin(); iter != m_vStandPool.end(); iter++)
	{
		(*iter)->Release();
	}
	for (int i = 0; i < m_vBulletPool.size(); i++)
	{
		m_vBulletPool[i]->Release();
	}
	m_vStandPool.clear();
	m_vBulletPool.clear();
}

//������ ������
void BulletPool::get_Data()
{
	Bullet* tmp_Data = m_vStandPool.front();
	m_vStandPool.pop_front();
	m_vBulletPool.push_back(tmp_Data);
}

//������ �ٽ� ����ֱ�
void BulletPool::Return_Data(int _num)
{
	Bullet* tmp_Data = m_vBulletPool[_num];
	m_vStandPool.push_back(tmp_Data);
	//�ν����� ����Ʈ �߻��ϰ� ����

	m_vBulletPool.erase(m_vBulletPool.begin() + _num);
}

//�Ҹ���
BulletPool::~BulletPool()
{

}