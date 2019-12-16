#include "Label.h"
#include "ResourcesManager.h"

namespace DoEngine
{
	//생성자
	Label::Label()
	{
	}

	//초기화 함수
	void Label::Init(string _str, int _x, int _y, DWORD _drawOption)
	{
		//글자(font)의 크기를 구하는 함수
		::SIZE size;
		GetTextExtentPoint32(ResourcesManager::get_Instance()->get_BackDC(), _str.c_str(), _str.length(), &size);
		set_Pos(_x, _y, _x + size.cx, _y + size.cy);

		m_strPrint = _str;
		m_dwDrawOption = _drawOption;
	}

	//그리기 함수
	void Label::Draw()
	{
		DrawText(ResourcesManager::get_Instance()->get_BackDC(), m_strPrint.c_str(), m_strPrint.length(),
			&m_rcPos.ToWinRECT(), m_dwDrawOption);
	}

	//소멸자
	Label::~Label()
	{
	}
}