#include "InputManager.h"
#include <algorithm>

namespace DoEngine
{
	InputManager::InputManager()
	{
		m_vecKeyRegist.clear(); //키 코드 clear
	}

	void InputManager::Init(HWND hWnd)
	{
		m_hWnd = hWnd; //hWnd받아온다
	}

	//키가 존재하는지 여부를 검사 
	bool InputManager::isExistKey(int key)
	{
		//키가 있다면 true를 반환
		for (auto iter = m_vecKeyRegist.begin(); iter != m_vecKeyRegist.end(); iter++)
		{
			if ((*iter).keyCode == key)
			{
				return true;
			}
		}
		return false;
	}

	//키값 등록
	void InputManager::RegistKeyCode(int key)
	{
		//만약 키가 있다면 return
		if (isExistKey(key))
		{
			return;
		}
		else
		{
			//키 코드값을 받아 vecter에 삽입
			KEY_INFO code;
			memset(&code, 0, sizeof(KEY_INFO));
			code.keyCode = key;
			m_vecKeyRegist.push_back(code);
		}
	}

	//바뀌는걸 보는 Update함수
	void InputManager::Update()
	{
		//마우스 Point값 받아옴
		::POINT pt;
		GetCursorPos(&pt); //현재 커서를 받는다
		ScreenToClient(m_hWnd, &pt); //	화면의 원점을 기준으로 하는 좌표 lpPoint(pt)를 hWnd의 작업 영역을 기준으로 하는 좌표로 변환한다.
		m_ptMouse.x = pt.x;
		m_ptMouse.y = pt.y;

		//누른 키를 검색해서 키를 눌럿는지 확인한다
		for (auto iter = m_vecKeyRegist.begin(); iter != m_vecKeyRegist.end(); iter++)
		{
			if (GetKeyState((*iter).keyCode) & 0x8000)
			{
				//누르고 있지 않다면
				if ((*iter).KeyPrecce == false)//키 다운
				{
					(*iter).KeyDown = true;
				}
				else
				{
					(*iter).KeyDown = false;
				}

				(*iter).KeyPrecce = true;
				(*iter).keyUp = false;
			}
			else
			{
				if ((*iter).KeyPrecce)//키 업
				{
					(*iter).keyUp = true;
				}
				else
				{
					(*iter).keyUp = false;
				}

				(*iter).KeyDown = false;
				(*iter).KeyPrecce = false;
			}
		}
	}

	//키벡터를 비운다
	void InputManager::Clear()
	{
		m_vecKeyRegist.clear();
	}

	//마우스 포인터를 리턴
	POINT InputManager::get_MousePoint()
	{
		return m_ptMouse;
	}

	//키를 누르고 있다면
	bool InputManager::isKeyPress(int keyCode)
	{
		for (auto iter = m_vecKeyRegist.begin(); iter != m_vecKeyRegist.end(); iter++)
		{
			if ((*iter).keyCode == keyCode)
			{
				return (*iter).KeyPrecce;
			}
		}

		assert(!("isKeyPress keyCode not regist!!"));
		return false;
	}

	//키에 손에 땟다면
	bool InputManager::isKeyUp(int keyCode)
	{
		for (auto iter = m_vecKeyRegist.begin(); iter != m_vecKeyRegist.end(); iter++)
		{
			if ((*iter).keyCode == keyCode)
			{
				return (*iter).keyUp;
			}
		}

		assert(!("isKeyUp keyCode not regist!!"));
		return false;
	}

	//키를 눌렀다면
	bool InputManager::isKeyDown(int keyCode)
	{
		for (auto iter = m_vecKeyRegist.begin(); iter != m_vecKeyRegist.end(); iter++)
		{
			if ((*iter).keyCode == keyCode)
			{
				return (*iter).KeyDown;
			}
		}

		assert(!("isKeyDown keyCode not regist!!"));
		return false;
	}

	InputManager::~InputManager()
	{

	}
}