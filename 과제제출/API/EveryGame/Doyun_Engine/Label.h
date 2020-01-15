#pragma once
#include "GlobalDefine.h"
#include "UIObject.h"

namespace DoEngine
{
	/**
	* @brief Text를 관리 출력하는 클래스
	* @details Text를 관리 출력하는 클래스
	*/

	class Label : public DoEngine::UIObject
	{
	private:
		DWORD m_dwDrawOption; //그리기 옵션
		string m_strPrint; //출력할 글자

	public:
		Label(); //생성자

		void Init(string str, int x, int y, DWORD drawOption); //초기화 함수
		virtual void Draw(); //그리기 함수

		virtual bool Update() { return false; } //Update함수

		virtual ~Label(); //소멸자
	};

}


