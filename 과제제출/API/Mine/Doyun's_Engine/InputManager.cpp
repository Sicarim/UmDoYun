#include "InputManager.h"
#include <algorithm>

namespace DoEngine
{
	InputManager::InputManager()
	{
		m_vecKeyRegist.clear(); //Ű �ڵ� clear
	}

	void InputManager::Init(HWND hWnd)
	{
		m_hWnd = hWnd; //hWnd�޾ƿ´�
	}

	//Ű�� �����ϴ��� ���θ� �˻� 
	bool InputManager::isExistKey(int key)
	{
		//Ű�� �ִٸ� true�� ��ȯ
		for (auto iter = m_vecKeyRegist.begin(); iter != m_vecKeyRegist.end(); iter++)
		{
			if ((*iter).keyCode == key)
			{
				return true;
			}
		}
		return false;
	}

	//Ű�� ���
	void InputManager::RegistKeyCode(int key)
	{
		//���� Ű�� �ִٸ� return
		if (isExistKey(key))
		{
			return;
		}
		else
		{
			//Ű �ڵ尪�� �޾� vecter�� ����
			KEY_INFO code;
			memset(&code, 0, sizeof(KEY_INFO));
			code.keyCode = key;
			m_vecKeyRegist.push_back(code);
		}
	}

	//�ٲ�°� ���� Update�Լ�
	void InputManager::Update()
	{
		//���콺 Point�� �޾ƿ�
		::POINT pt;
		GetCursorPos(&pt); //���� Ŀ���� �޴´�
		ScreenToClient(m_hWnd, &pt); //	ȭ���� ������ �������� �ϴ� ��ǥ lpPoint(pt)�� hWnd�� �۾� ������ �������� �ϴ� ��ǥ�� ��ȯ�Ѵ�.
		m_ptMouse.x = pt.x;
		m_ptMouse.y = pt.y;

		//���� Ű�� �˻��ؼ� Ű�� �������� Ȯ���Ѵ�
		for (auto iter = m_vecKeyRegist.begin(); iter != m_vecKeyRegist.end(); iter++)
		{
			if (GetKeyState((*iter).keyCode) & 0x8000)
			{
				//������ ���� �ʴٸ�
				if ((*iter).KeyPrecce == false)//Ű �ٿ�
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
				if ((*iter).KeyPrecce)//Ű ��
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

	//Ű���͸� ����
	void InputManager::Clear()
	{
		m_vecKeyRegist.clear();
	}

	//���콺 �����͸� ����
	POINT InputManager::get_MousePoint()
	{
		return m_ptMouse;
	}

	//Ű�� ������ �ִٸ�
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

	//Ű�� �տ� ���ٸ�
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

	//Ű�� �����ٸ�
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