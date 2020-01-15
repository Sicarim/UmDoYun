#pragma once
#include "GlobalDefine.h"
#include "POINT.h"
#include "Singleton.h"

namespace DoEngine
{
	/**
	* @brief 엔진의 Input을 담당하는 클래스
	* @details 키입력을 담당하는 클래스. RegistKeyCode로 등록후 isKeyPress , isKeyUp , isKeyDown 함수로 상태를 검출
	*/

	class InputManager : public Singleton<InputManager>
	{
		struct KEY_INFO
		{
		public:
			int keyCode; //키 코드 지정
			bool KeyPrecce; //누르고 있는지 여부를 확인하는듯
			bool keyUp; //키에서 손을 땟는가?
			bool KeyDown; //키를 눌럿는가?
		};

	private:
		HWND m_hWnd;
		DoEngine::POINT m_ptMouse; //마우스 포인트
		std::vector<InputManager::KEY_INFO>	m_vecKeyRegist; //키등록

	public:
		InputManager(); //생성자

		bool isExistKey(int key); //키가 존재하는지 여부를 검사 
		void RegistKeyCode(int key); //키값 등록

		void Init(HWND hWnd); //초기화
		void Update(); //바뀌는걸 보는 Update함수
		void Clear(); //비우기

		DoEngine::POINT get_MousePoint(); //마우스 Point지정
		bool isKeyPress(int keyCode); //키를 누르고 있다
		bool isKeyUp(int keyCode); //키에 손을 땟다
		bool isKeyDown(int keyCode); //키를 눌럿다

		~InputManager(); //소멸자
	};
}


