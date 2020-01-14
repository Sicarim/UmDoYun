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
		//���� �ð��� ������ get_Data�� ����
		get_Data();
		curTime = 0.0f;
	}
	
	//BulletPool�� NULL�� �ƴϸ� StarPool�� ��ü�� ���������� Update�Ѵ�
	if (m_vBulletPool.size() != 0)
	{
		for (int i = 0; i < m_vBulletPool.size(); i++)
		{
			m_vBulletPool[i]->Update(_fETime);
			//���� �ı��ȴٸ�
			if (!m_vBulletPool[i]->Input())
			{
				//ReturnData�� ����
				Return_Data(i);
			}
		}
	}

	//����Ⱑ �ı��Ǹ� ���� ȭ�鿡 �����ִ� ��� ź���� �����Ѵ�.
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
	//BulletPool�� ����� 0�� �ƴ϶��
	if (m_vBulletPool.size() != 0)
	{
		//���������� BulletPool�� ��ü�� �׸���.
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
	//100���� Star�� �־�� StandPool���� �Ǿ��� ��ü�� �ӽð�ü�� ��´�
	Bullet* tmp_Data = m_vStandPool.front();
	//���� ��, StandPool�� ù ��ü�� �����Ѵ�.
	m_vStandPool.pop_front();
	//������ ���� Pool(BulletPool)�� �ִ´�.
	m_vBulletPool.push_back(tmp_Data);
}

//������ �ٽ� ����ֱ�
void BulletPool::Return_Data(int _num)
{
	//�ı��� Bullet�� �ӽ� ��ü�� ��´�.
	Bullet* tmp_Data = m_vBulletPool[_num];
	//StandPool�� �ٽ� �ִ´�.
	m_vStandPool.push_back(tmp_Data);
	//�ش� Bullet�� �����Ѵ�.
	m_vBulletPool.erase(m_vBulletPool.begin() + _num);
}

//�Ҹ���
BulletPool::~BulletPool()
{

}