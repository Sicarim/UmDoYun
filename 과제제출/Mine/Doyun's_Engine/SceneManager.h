#pragma once
#include "GlobalDefine.h"

namespace DoEngine
{
	class Scene;
	class InputManager;
	/**
	* @brief 게임에 사용되는 Scene들을 관리하는 클레스
	* @details 게임에 사용되는 Scene들을 관리하는 클레스로 로직적 메인을 담당하는 클레스입니다.
	*/

	class SceneManager
	{
	private:
		bool m_bInit; //초기화 여부
		HWND m_hWnd; //hWnd 선언
		vector<Scene*> m_vecScene; //씬 모음
		Scene* m_curScene; //현재 씬
		Scene* m_lastScene; //마지막 씬(이전 씬?)
		InputManager* m_input; //입력 관리
		int m_iWinCX; //윈도우 x(넓이)
		int m_iWinCY; //윈도우 y(높이)

		/*
			* 따로 만드는 이유, SystemManager간의 의존성 때문임.
			* GameManger에 의존하는 SceneManager라 뒤늦게 생성할 필요가 있다.
		*/
		static SceneManager* s_this; //SceneManager(Singleton) 객체 선언
		SceneManager();

	public:
		//Scene객체 선언
		static SceneManager* get_Instance()
		{
			if (s_this == NULL)
			{
				s_this = new SceneManager();
			}
			return s_this;
		}

		void Init(HWND hWnd, int _wincx, int _wincy); //초기화 함수
		bool Update(); //지속적으로 갱신하는 Update함수
		void RegistScene(Scene* _reg); //씬 등록하기
		void LoadScene(int _sceneindex); //씬 불러오기
		void Release(); //삭제 함수

		~SceneManager(); //소멸자
	};
}