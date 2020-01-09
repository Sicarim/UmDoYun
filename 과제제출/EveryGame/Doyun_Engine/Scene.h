#pragma once
#include "GlobalDefine.h"

namespace DoEngine
{
	/**
	* @brief 게임에 사용되는 Scene들의 부모 클래스
	* @details 게임에 사용되는 Scene들의 부모 클래스(중요!!!).Scene구현해야 하는 항목을 순수 가상 함수로 가지고 있음
	*/

	class Scene
	{
	public:
		Scene(); //생성자

		virtual void Init(HWND hWnd) = 0; //초기화
		virtual bool Input(float _fETime) = 0; //키입력
		virtual void Update(float _fETime) = 0; //Update함수
		virtual void Draw(HDC hdc) = 0; //Draw 함수
		virtual void Release() = 0; //Release() 함수

		virtual ~Scene(); //소멸자
	};
}

