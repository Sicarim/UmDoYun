#pragma once
#include "GlobalDefine.h"
#include "Command.h"

namespace DoEngine
{
	/*
		@brief ĳ���� �����ӿ� ���ؼ� �����Ѵ�.
		@details �̵�, ����, �Ѿ� �߻� �� ���� �ൿ�� ���� ������ �ô´�.
	*/

	//�������� �̵��ϱ�
	class LeftCommand : public Command
	{
	private:

	public:
		LeftCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(Object& _actor);

		virtual ~LeftCommand() {} //�Ҹ���
	};

	//���������� �̵��ϱ�
	class RightCommand : public Command
	{
	private:
	public:
		RightCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(Object& _actor);

		virtual ~RightCommand() {} //�Ҹ���
	};

	//���� �̵��ϱ�
	class UpCommand : public Command
	{
	private:
	public:
		UpCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(Object& _actor);

		virtual ~UpCommand() {} //�Ҹ���
	};

	//�Ʒ��� �̵��ϱ�
	class DownCommand : public Command
	{
	private:
	public:
		DownCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(Object& _actor);

		virtual ~DownCommand() {} //�Ҹ���
	};

	//����
	class JumpCommand : public Command
	{
	private:
	public:
		JumpCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(Object& _actor);

		virtual ~JumpCommand() {} //�Ҹ���
	};

	//����
	class AttackCommand : public Command
	{
	private:
	public:
		AttackCommand() {} //������

		//�ൿ�� �����ϴ� �Լ�
		virtual void excute(Object& _actor);

		virtual ~AttackCommand() {} //�Ҹ���
	};
}