#include "UnitFactory.h"

//������
UnitFactory::UnitFactory()
{
	//NULL�� �ʱ�ȭ
	m_pUnit = NULL;
	TankCount = 0;
	UpTankCount = 0;
}

//�Ը���� ĳ���� �����
DoEngine::Object* UnitFactory::Order_Unit(string _name, int _x, int _y)
{
	//�ش� �̸����� ���� ����
	Create_Unit(_name);
	//Unit�� ���������� ����� ���ٸ� ������Ʈ���� ������ ����д�.
	if (m_pUnit != NULL)
	{
		m_pUnit->Init(_x, _y);

		if (_name == "Tank")
		{
			wsprintf(buf, "Tank%d", TankCount);
			TankCount++;
		}
		else
		{
			wsprintf(buf, "UpTank%d", UpTankCount);
			UpTankCount++;
		}
		m_pUnit->set_Info(buf);
	}

	return m_pUnit;
}

void UnitFactory::Release()
{
	TankCount = 0;
	UpTankCount = 0;
}

//�Ҹ���
UnitFactory::~UnitFactory()
{

}