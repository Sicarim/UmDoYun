#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	/**
	(01/02)
	* @brief ���� ����
	* @details ���¸� �����Ͽ� ������ �ൿ�� �´� �ൿ�� �ϵ��� �Ѵ�.
	*/

	class State
	{
	private:

	public:
		State(); //������

		virtual void Enter() = 0; //���� ���·� ��ȯ
		virtual void Excute() = 0; //���� ��Ȳ���� �� �ൿ
		virtual void Exit() = 0; //���� ��Ȳ���� �Ѿ���� �ؾ��ϴ� �ൿ

		virtual ~State(); //�Ҹ���
	};
}