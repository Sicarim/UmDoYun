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
	//왼쪽방향키를 누르면  LeftCommand를 생성하여 리턴한다
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_LEFT))
	{
		if (key_Left == NULL)
		{
			key_Left = new DoEngine::LeftCommand;
		}
		return key_Left;
	}
	//오른쪽방향키를 누르면  RightCommand를 생성하여 리턴한다
	else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RIGHT))
	{
		if (key_Right == NULL)
		{
			key_Right = new DoEngine::RightCommand;
		}
		return key_Right;
	}
	//위쪽방향키를 누르면  UpCommand를 생성하여 리턴한다
	else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_UP))
	{
		if (key_Up == NULL)
		{
			key_Up = new DoEngine::UpCommand;
		}
		return key_Up;
	}
	//아래쪽방향키를 누르면  DownCommand를 생성하여 리턴한다
	else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_DOWN))
	{
		if (key_Down == NULL)
		{
			key_Down = new DoEngine::DownCommand;
		}
		return key_Down;
	}

	//만약 입력이 없다면 NULL을 리턴한다.
	return NULL;
}

//소멸자
InputHandler::~InputHandler()
{

}