#include "InputHandler.h"
#include "InputManager.h"

//생성자
InputHandler::InputHandler()
{
	key_Left = NULL;
	key_Right = NULL;
	key_Up = NULL;
	key_Down = NULL;
}

//명령을 실행할 메서드들
DoEngine::Command* InputHandler::CommandInput()
{
	//왼쪽
	if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_LEFT))
	{
		if (key_Left == NULL)
		{
			key_Left = new DoEngine::LeftCommand;
		}
		return key_Left;
	}
	//오른쪽
	else if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_RIGHT))
	{
		if (key_Right == NULL)
		{
			key_Right = new DoEngine::RightCommand;
		}
		return key_Right;
	}
	//위쪽
	else if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_UP))
	{
		if (key_Up == NULL)
		{
			key_Up = new DoEngine::UpCommand;
		}
		return key_Up;
	}
	//아래쪽
	else if (DoEngine::InputManager::get_Instance()->isKeyPress(VK_DOWN))
	{
		if (key_Down == NULL)
		{
			key_Down = new DoEngine::DownCommand;
		}
		return key_Down;
	}
	//공격 버튼
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

//소멸자
InputHandler::~InputHandler()
{

}