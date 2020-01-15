#pragma once
#include "GlobalDefine.h"
#include "POINT.h"
#include "Singleton.h"

namespace DoEngine
{
	/**
	* @brief ������ Input�� ����ϴ� Ŭ����
	* @details Ű�Է��� ����ϴ� Ŭ����. RegistKeyCode�� ����� isKeyPress , isKeyUp , isKeyDown �Լ��� ���¸� ����
	*/

	class InputManager : public Singleton<InputManager>
	{
		struct KEY_INFO
		{
		public:
			int keyCode; //Ű �ڵ� ����
			bool KeyPrecce; //������ �ִ��� ���θ� Ȯ���ϴµ�
			bool keyUp; //Ű���� ���� ���°�?
			bool KeyDown; //Ű�� �����°�?
		};

	private:
		HWND m_hWnd;
		DoEngine::POINT m_ptMouse; //���콺 ����Ʈ
		std::vector<InputManager::KEY_INFO>	m_vecKeyRegist; //Ű���

	public:
		InputManager(); //������

		bool isExistKey(int key); //Ű�� �����ϴ��� ���θ� �˻� 
		void RegistKeyCode(int key); //Ű�� ���

		void Init(HWND hWnd); //�ʱ�ȭ
		void Update(); //�ٲ�°� ���� Update�Լ�
		void Clear(); //����

		DoEngine::POINT get_MousePoint(); //���콺 Point����
		bool isKeyPress(int keyCode); //Ű�� ������ �ִ�
		bool isKeyUp(int keyCode); //Ű�� ���� ����
		bool isKeyDown(int keyCode); //Ű�� ������

		~InputManager(); //�Ҹ���
	};
}


