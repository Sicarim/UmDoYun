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
		//일정 시간이 지나면 get_Data를 실행
		get_Data();
		curTime = 0.0f;
	}
	
	//BulletPool이 NULL이 아니면 StarPool의 객체를 순차적으로 Update한다
	if (m_vBulletPool.size() != 0)
	{
		for (int i = 0; i < m_vBulletPool.size(); i++)
		{
			m_vBulletPool[i]->Update(_fETime);
			//만약 파괴된다면
			if (!m_vBulletPool[i]->Input())
			{
				//ReturnData를 실행
				Return_Data(i);
			}
		}
	}

	//비행기가 파괴되면 현재 화면에 나와있는 모든 탄알을 삭제한다.
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
	//BulletPool의 사이즈가 0이 아니라면
	if (m_vBulletPool.size() != 0)
	{
		//순차적으로 BulletPool의 객체를 그린다.
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
	//100개의 Star를 넣어논 StandPool에서 맨앞의 객체를 임시객체에 담는다
	Bullet* tmp_Data = m_vStandPool.front();
	//꺼낸 후, StandPool의 첫 객체를 삭제한다.
	m_vStandPool.pop_front();
	//정말로 사용될 Pool(BulletPool)에 넣는다.
	m_vBulletPool.push_back(tmp_Data);
}

//데이터 다시 집어넣기
void BulletPool::Return_Data(int _num)
{
	//파괴될 Bullet을 임시 객체에 담는다.
	Bullet* tmp_Data = m_vBulletPool[_num];
	//StandPool에 다시 넣는다.
	m_vStandPool.push_back(tmp_Data);
	//해당 Bullet을 삭제한다.
	m_vBulletPool.erase(m_vBulletPool.begin() + _num);
}

//소멸자
BulletPool::~BulletPool()
{

}