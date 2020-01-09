#include "Label.h"
#include "ResourcesManager.h"

namespace DoEngine
{
	//������
	Label::Label()
	{
	}

	//�ʱ�ȭ �Լ�
	void Label::Init(string _str, int _x, int _y, DWORD _drawOption)
	{
		//����(font)�� ũ�⸦ ���ϴ� �Լ�
		::SIZE size;
		GetTextExtentPoint32(ResourcesManager::get_Instance()->get_BackDC(), _str.c_str(), _str.length(), &size);
		set_Pos(_x, _y, _x + size.cx, _y + size.cy);

		m_strPrint = _str;
		m_dwDrawOption = _drawOption;
	}

	//�׸��� �Լ�
	void Label::Draw()
	{
		DrawText(ResourcesManager::get_Instance()->get_BackDC(), m_strPrint.c_str(), m_strPrint.length(),
			&m_rcPos.ToWinRECT(), m_dwDrawOption);
	}

	//�Ҹ���
	Label::~Label()
	{
	}
}