#pragma once
#include "GlobalDefine.h"
#include "UIObject.h"

namespace DoEngine
{
	/*
	* @brief Text를 추가하는 클래스
	* @details 폰트, 투명 처리등을 담당하는 클래스이다.
	*/

	/*
	* TRANSPARENT: 배경을 투명처리
	*/

	class Text : public DoEngine::UIObject
	{
	private:
		HFONT m_Font; //폰트 선언
		HFONT m_oldFont; //폰트 연결

		DWORD m_dwDrawOption; //그리기 옵션
		LPCTSTR m_strPrint; //출력할 글자
		LPCTSTR m_fontTypeFace; //글자 폰트 지정

		int m_fontx, m_fonty;
		int RGB_R, RGB_G, RGB_B;
		int m_size;

	public:
		Text(); //생성자

		void Init(LPCTSTR _str, int _x, int _y, int _fsize, int _r, int _g, int _b, DWORD _drawOption, LPCTSTR _font); //초기화 함수
		virtual void Draw(); //그리기 함수(글자)

		virtual bool Update() { return false; } //Update함수

		virtual ~Text(); //소멸자
	};
}
