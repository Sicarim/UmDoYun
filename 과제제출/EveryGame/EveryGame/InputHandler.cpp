#include "InputHandler.h"
#include "InputManager.h"

//������
InputHandler::InputHandler()
{
	key_Left = NULL;
	key_Right = NULL;
	key_Up = NULL;
	key_Down = NULL;
}

//����� ������ �޼����
DoEngine::Command* InputHandler::CommandInput()
{
	//���ʹ���Ű�� ������  LeftCommand�� �����Ͽ� �����Ѵ�
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_LEFT))
	{
		if (key_Left == NULL)
		{
			key_Left = new DoEngine::LeftCommand;
		}
		return key_Left;
	}
	//�����ʹ���Ű�� ������  RightCommand�� �����Ͽ� �����Ѵ�
	else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RIGHT))
	{
		if (key_Right == NULL)
		{
			key_Right = new DoEngine::RightCommand;
		}
		return key_Right;
	}
	//���ʹ���Ű�� ������  UpCommand�� �����Ͽ� �����Ѵ�
	else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_UP))
	{
		if (key_Up == NULL)
		{
			key_Up = new DoEngine::UpCommand;
		}
		return key_Up;
	}
	//�Ʒ��ʹ���Ű�� ������  DownCommand�� �����Ͽ� �����Ѵ�
	else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_DOWN))
	{
		if (key_Down == NULL)
		{
			key_Down = new DoEngine::DownCommand;
		}
		return key_Down;
	}

	//���� �Է��� ���ٸ� NULL�� �����Ѵ�.
	return NULL;
}

//�Ҹ���
InputHandler::~InputHandler()
{

}