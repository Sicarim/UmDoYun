#include "StarPool.h"
#include "GameManager.h"

//생성자
StarPool::StarPool()
{
	m_vStandPool.clear();
	m_vStarPool.clear();
	/*
		일정 시간마다 StandPool에서 StarPool로 이동한다. 
		실제로 사용하는것은 StarPool
		일정 조건에 달하면 다시 StanPool로 돌아간다.
	*/
}

//초기화
void StarPool::Init()
{
	curTime = 0.0f;
	//Star 100개 만들기
	for (int i = 0; i < 100; i++)
	{
		int UpDown = rand() % 350;
		int LeftRight = (rand() % 360) + 90;

		if (i % 3 == 0)
		{
			//위에서 나옴
			m_Star = new BlueStar;
			m_Star->Init(UpDown, 110);
		}
		else if (i % 3 == 1)
		{
			//왼쪽에서 나옴
			m_Star = new GreenStar;
			m_Star->Init(20, LeftRight);
		}
		else if (i % 3 == 2)
		{
			//오른쪽에서 나옴
			m_Star = new YellowStar;
			m_Star->Init(390, LeftRight);
		}
		m_vStandPool.push_back(m_Star);
	}
}

//입력 받기
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
			//일정 시간이 지나면 get_Data를 실행
			get_Data();
			curTime = 0.0f;
		}
	}
	//BulletPool이 NULL이 아니면 StarPool의 객체를 순차적으로 Update한다
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
			//만약 파괴된다면
			if (!m_vStarPool[i]->Input())
			{
				//ReturnData를 실행
				Return_Data(i);
			}
		}
	}
}

//그리기
void StarPool::Draw()
{
	//BulletPool의 사이즈가 0이 아니라면
	if (m_vStarPool.size() != 0)
	{
		//순차적으로 BulletPool의 객체를 그린다.
		for (int i = 0; i < m_vStarPool.size(); i++)
		{
			m_vStarPool[i]->Draw();
		}
	}
}

//삭제하기
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

//데이터 꺼내기
void StarPool::get_Data()
{
	//100개의 Star를 넣어논 StandPool에서 맨앞의 객체를 임시객체에 담는다
	DoEngine::Object* tmp_Data = m_vStandPool.front();
	//꺼낸 후, StandPool의 첫 객체를 삭제한다.
	m_vStandPool.pop_front();
	//정말로 사용될 Pool(StarPool)에 넣는다.
	m_vStarPool.push_back(tmp_Data);
}	

//데이터 다시 집어넣기
void StarPool::Return_Data(int _num)
{
	//파괴될 Bullet을 임시 객체에 담는다.
	DoEngine::Object* tmp_Data = m_vStarPool[_num];
	//StandPool에 다시 넣는다.
	m_vStandPool.push_back(tmp_Data);
	//해당 Star을 삭제한다.
	m_vStarPool.erase(m_vStarPool.begin() + _num);
}

//소멸자
StarPool::~StarPool()
{

}