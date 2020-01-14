#pragma once
#include "DoEngine.h"
#include "defines.h"
#include "FlightInput.h"
#include "Text.h"
#include "Flight.h"
#include "Bullet.h"
#include "BlueStar.h"
#include "GreenStar.h"
#include "YellowStar.h"
#include "StarPool.h"
#include "BulletPool.h"

class FlightGame
{
private:
	int Flight_Count;
	float curTime;
	TCHAR Flight_Score[255];

	DoEngine::Text m_Text;
	Flight m_Flight; //����� ��ü
	Bullet m_Bullet; //�Ѿ� ��ü
	DoEngine::Collider m_BackGroundColl; //��� �ݶ��̴�
	//Star
	StarPool m_StarPool;
	//Bullet
	BulletPool m_BulletPool;

	//����⸦ ������ Ŀ�ǵ� ��ü ����
	DoEngine::Command* m_Command;
	FlightInput m_Input;
public:
	FlightGame(); //������

	void Init(); //���� �ʱ�ȭ
	bool Input(float _fETime); //Ű �Է�
	void Update(float _fETime); //Update�Լ�
	void Draw(); //���� �׸���
	void Release(); //���� �Լ�

	~FlightGame(); //�Ҹ���
};