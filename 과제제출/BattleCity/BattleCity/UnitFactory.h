#pragma once
#include "GlobalDefine.h"
#include "defines.h"
#include "DoEngine.h"

/*
	���Ͽ��� ���� �߿��� ���� �ϳ��� ĸ��ȭ��� �������� �ٲ�� �κа� �ٲ��� �ʴ� �κ��� �и��ϰ�, �ٲ�� �κ��� ���� �δ°�!
	� Ŭ������ ��ü�� �������� �̸� ���� ���ϴ� ��� ����
*/
class UnitFactory
{
private:
	virtual void Create_Unit(string _name) = 0; //���� ���� ������ private��
protected:
	DoEngine::Object* m_pUnit; //Unit ���� ����
public:
	UnitFactory(); //������
	
	DoEngine::Object* Order_Unit(string _name); //�Ը���� �����
	
	~UnitFactory(); //�Ҹ���
};