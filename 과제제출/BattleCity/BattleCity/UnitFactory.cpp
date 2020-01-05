#include "UnitFactory.h"

//������
UnitFactory::UnitFactory()
{
	//NULL�� �ʱ�ȭ
	m_pUnit = NULL;
	Count = 0;
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
		wsprintf(buf, "Tank%d", Count);
		m_pUnit->set_Info(buf);
		Count++;
	}

	return m_pUnit;
}

//�Ҹ���
UnitFactory::~UnitFactory()
{

}