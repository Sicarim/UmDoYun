#pragma once
#include "GlobalDefine.h"

namespace DoEngine
{
	class Scene;
	class InputManager;
	/**
	* @brief ���ӿ� ���Ǵ� Scene���� �����ϴ� Ŭ����
	* @details ���ӿ� ���Ǵ� Scene���� �����ϴ� Ŭ������ ������ ������ ����ϴ� Ŭ�����Դϴ�.
	*/

	class SceneManager
	{
	private:
		bool m_bInit; //�ʱ�ȭ ����
		HWND m_hWnd; //hWnd ����
		vector<Scene*> m_vecScene; //�� ����
		Scene* m_curScene; //���� ��
		Scene* m_lastScene; //������ ��(���� ��?)
		InputManager* m_input; //�Է� ����
		int m_iWinCX; //������ x(����)
		int m_iWinCY; //������ y(����)

		/*
			* ���� ����� ����, SystemManager���� ������ ������.
			* GameManger�� �����ϴ� SceneManager�� �ڴʰ� ������ �ʿ䰡 �ִ�.
		*/
		static SceneManager* s_this; //SceneManager(Singleton) ��ü ����
		SceneManager();

	public:
		//Scene��ü ����
		static SceneManager* get_Instance()
		{
			if (s_this == NULL)
			{
				s_this = new SceneManager();
			}
			return s_this;
		}

		void Init(HWND hWnd, int _wincx, int _wincy); //�ʱ�ȭ �Լ�
		bool Update(); //���������� �����ϴ� Update�Լ�
		void RegistScene(Scene* _reg); //�� ����ϱ�
		void LoadScene(int _sceneindex); //�� �ҷ�����
		void Release(); //���� �Լ�

		~SceneManager(); //�Ҹ���
	};
}