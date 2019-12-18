#include "UnitFactory.h"

//������
UnitFactory::UnitFactory()
{
	//NULL�� �ʱ�ȭ
	m_pUnit = NULL;
}

//�Ը���� ĳ���� �����
DoEngine::Object* UnitFactory::Order_Unit(string _name)
{
	//�ش� �̸����� ���� ����
	Create_Unit(_name);

	//Unit�� ���������� ����� ���ٸ� ������Ʈ���� ������ ����д�.
	if (m_pUnit != NULL)
	{
		m_pUnit->Init(300, 100);
	}

	return m_pUnit;
}

//�Ҹ���
UnitFactory::~UnitFactory()
{

}