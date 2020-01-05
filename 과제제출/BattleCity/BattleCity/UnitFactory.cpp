#include "UnitFactory.h"

//생성자
UnitFactory::UnitFactory()
{
	//NULL로 초기화
	m_pUnit = NULL;
	Count = 0;
}

//입맛대로 캐릭터 만들기
DoEngine::Object* UnitFactory::Order_Unit(string _name, int _x, int _y)
{
	//해당 이름으로 유닛 생성
	Create_Unit(_name);
	//Unit이 정상적으로 만들어 졌다면 오브젝트들이 할일을 적어둔다.
	if (m_pUnit != NULL)
	{
		m_pUnit->Init(_x, _y);
		wsprintf(buf, "Tank%d", Count);
		m_pUnit->set_Info(buf);
		Count++;
	}

	return m_pUnit;
}

//소멸자
UnitFactory::~UnitFactory()
{

}