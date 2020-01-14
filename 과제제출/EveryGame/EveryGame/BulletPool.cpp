#include "BulletPool.h"
#include "GameManager.h"

//생성자
BulletPool::BulletPool()
{
	m_vStandPool.clear();
	m_vBulletPool.clear();
	/*
		일정 시간마다 StandPool에서 BulletPool로 이동한다.
		실제로 사용하는것은 BulletPool
		일정 조건에 달하면 다시 StanPool로 돌아간다.
	*/
}

//초기화
void BulletPool::Init()
{
	curTime = 0.0f;
	//Bullet 100개 만들기
	for (int i = 0; i < 100; i++)
	{
		int UpDown = rand() % 380 + 1;
		int LeftRight = (rand() % 500) + 90;
		m_Bullet = new Bullet;

		if (i % 4 == 0)
		{
			//위에서 나옴
			m_Bullet->Init(UpDown, 110);
		}
		else if (i % 4 == 1)
		{
			//왼쪽에서 나옴
			m_Bullet->Init(20, LeftRight);
		}
		else if (i % 4 == 2)
		{
			//아랫쪽에서 나옴
			m_Bullet->Init(UpDown, 570);
		}
		else if (i % 4 == 3)
		{
			//오른쪽에서 나옴
			m_Bullet->Init(390, LeftRight);
		}
		m_Bullet->set_Birth(i);
		m_vStandPool.push_back(m_Bullet);
	}
}

//입력 받기
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

//그리기
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

//삭제하기
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

//데이터 꺼내기
void BulletPool::get_Data()
{
	Bullet* tmp_Data = m_vStandPool.front();
	m_vStandPool.pop_front();
	m_vBulletPool.push_back(tmp_Data);
}

//데이터 다시 집어넣기
void BulletPool::Return_Data(int _num)
{
	Bullet* tmp_Data = m_vBulletPool[_num];
	m_vStandPool.push_back(tmp_Data);
	//부숴지는 이펙트 발생하고 삭제

	m_vBulletPool.erase(m_vBulletPool.begin() + _num);
}

//소멸자
BulletPool::~BulletPool()
{

}