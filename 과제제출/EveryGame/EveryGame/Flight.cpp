#include "Flight.h"
#include "GameManager.h"

//생성자
Flight::Flight()
{

}

//초기화(시작 위치 초기화 가능)(override)
void Flight::Init(int _x, int _y)
{
	pos_x = _x;
	pos_y = _y;
	curTime = 0.0f;
	sumTime = 0.0f;
	m_Tag = "Flight";
	isDestroy = false;

	//비행기 그릴 BItMap 객체
	Flight_Bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\FlightGameFlight.bmp");
	Flight_Boom[0] = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\explosion1.bmp");
	Flight_Boom[1] = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\explosion2.bmp");
	Flight_Boom[2] = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\explosion3.bmp");
	size_x = Flight_Bit->get_Width();
	size_y = Flight_Bit->get_Height();

	for (int i = 0; i < 100; i++)
	{
		wsprintf(buf, "Bullet%d", i);
		m_vColl.push_back(buf);
	}
	
}

//키입력(override)
bool Flight::Input(int _state)
{
	if (!isDestroy)
	{
		if (_state == LEFT)
		{
			if (m_Coll.get_Collider("BackGround").left < pos_x)
			{
				pos_x -= curTime * FLIGHT_SPEED;
			}
		}

		else if (_state == RIGHT)
		{
			if (m_Coll.get_Collider("BackGround").right > pos_x + size_x)
			{
				pos_x += curTime * FLIGHT_SPEED;

			}
		}

		else if (_state == UP)
		{
			if (m_Coll.get_Collider("BackGround").top < pos_y)
			{
				pos_y -= curTime * FLIGHT_SPEED;
			}
		}

		else if (_state == DOWN)
		{
			if (m_Coll.get_Collider("BackGround").bottom > pos_y + size_y)
			{
				pos_y += curTime * FLIGHT_SPEED;
			}
		}
	}
	return false;
}

//Update함수(override)
void Flight::Update(float _fETime)
{
	curTime = _fETime;

	if (m_Coll.isCollider(m_vColl))
	{
		isDestroy = true;
	}
	else
	{
		m_Coll.Init_Collider(m_Tag, pos_x + 25, pos_y + 20, size_x - 50, size_y - 40);
	}
}

//Draw 함수(overloding)(override)
void Flight::Draw()
{
	if (!isDestroy)
	{
		GameManager::get_Instance()->set_Destroy(isDestroy);
		Flight_Bit->Draw(pos_x, pos_y);
		m_Coll.Draw_Collider();
	}
	else
	{
		GameManager::get_Instance()->set_Destroy(isDestroy);
		sumTime += curTime;

		if (sumTime < 0.2f)
		{
			Flight_Boom[0]->Draw(pos_x, pos_y);
		}
		else if (sumTime >= 0.2f && sumTime < 0.4f)
		{
			Flight_Boom[1]->Draw(pos_x, pos_y);
		}
		else if (sumTime >= 0.4f && sumTime < 0.6f)
		{
			Flight_Boom[2]->Draw(pos_x, pos_y);
			isDestroy = false;
			pos_x = FLIGHT_X;
			pos_y = FLIGHT_Y;
			m_Coll.Init_Collider(m_Tag, pos_x + 25, pos_y + 20, size_x - 50, size_y - 40);
			sumTime = 0.0f;
		}
	}	
}

//Draw 함수(override)
void Flight::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void Flight::Release()
{
	pos_x = 0;
	pos_y = 0;
	curTime = 0.0f;
	sumTime = 0.0f;
	size_x = 0;
	size_y = 0;
	m_vColl.clear();
}

//소멸자
Flight::~Flight()
{

}