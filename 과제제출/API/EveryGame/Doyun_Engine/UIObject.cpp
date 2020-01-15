#include "UIObject.h"

namespace DoEngine
{
	//생성자
	UIObject::UIObject()
	{
	}

	//오브젝트 위치 입력
	void UIObject::set_Pos(int left, int top, int right, int bottom)
	{
		m_rcPos.Set(left, top, right, bottom);
	}

	//소멸자
	UIObject::~UIObject()
	{
	}
}