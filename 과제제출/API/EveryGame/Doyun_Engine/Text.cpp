#include "Text.h"
#include "ResourcesManager.h"

namespace DoEngine
{
	//생성자
	Text::Text()
	{

	}

	/*
		그릴 글자, 글자를 그릴 위치, 글자 크기, 글자 색, 글꼴 모양을 지정
	*/
	void Text::Init(LPCTSTR _str, int _x, int _y, int _fsize, int _r, int _g, int _b, DWORD _drawOption, LPCTSTR _font)
	{
		m_dwDrawOption = _drawOption;
		m_fontTypeFace = _font;
		m_strPrint = _str;

		m_size = _fsize;
		m_fontx = _x;
		m_fonty = _y;

		RGB_R = _r;
		RGB_G = _g;
		RGB_B = _b;
	}

	//글자 그리기
	void Text::Draw()
	{
		m_Font = CreateFont(m_size, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, m_fontTypeFace);
		m_oldFont = (HFONT)SelectObject(ResourcesManager::get_Instance()->get_BackDC(), m_Font);
		SetBkMode(ResourcesManager::get_Instance()->get_BackDC(), m_dwDrawOption); //배경은 투명 처리
		SetTextColor(ResourcesManager::get_Instance()->get_BackDC(), RGB(RGB_R, RGB_G, RGB_B));

		TextOut(ResourcesManager::get_Instance()->get_BackDC(), m_fontx, m_fonty, m_strPrint, strlen(m_strPrint));

		SelectObject(ResourcesManager::get_Instance()->get_BackDC(), m_oldFont);
		DeleteObject(m_Font);
	}

	//소멸자
	Text::~Text()
	{

	}
}