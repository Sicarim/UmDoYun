#include "UIObject.h"

namespace DoEngine
{
	//������
	UIObject::UIObject()
	{
	}

	//������Ʈ ��ġ �Է�
	void UIObject::set_Pos(int left, int top, int right, int bottom)
	{
		m_rcPos.Set(left, top, right, bottom);
	}

	//�Ҹ���
	UIObject::~UIObject()
	{
	}
}