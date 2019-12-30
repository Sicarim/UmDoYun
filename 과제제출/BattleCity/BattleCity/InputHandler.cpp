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
	//����
	if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_LEFT))
	{
		if (key_Left == NULL)
		{
			key_Left = new DoEngine::LeftCommand;
		}
		return key_Left;
	}
	//������
	else if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_RIGHT))
	{
		if (key_Right == NULL)
		{
			key_Right = new DoEngine::RightCommand;
		}
		return key_Right;
	}
	//����
	else if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_UP))
	{
		if (key_Up == NULL)
		{
			key_Up = new DoEngine::UpCommand;
		}
		return key_Up;
	}
	//�Ʒ���
	else if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_DOWN))
	{
		if (key_Down == NULL)
		{
			key_Down = new DoEngine::DownCommand;
		}
		return key_Down;
	}
	//���� ��ư
	else if (DoEngine::InputManager::get_Instance()->isKeyPress(BUTTON_X))
	{
		if (Key_Attack == NULL)
		{
			Key_Attack = new DoEngine::AttackCommand;
		}
		
		return Key_Attack;
	}

	return NULL;
}

//�Ҹ���
InputHandler::~InputHandler()
{

}