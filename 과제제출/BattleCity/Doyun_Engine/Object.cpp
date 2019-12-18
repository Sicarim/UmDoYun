#include "Object.h"

namespace DoEngine
{
	//생성자
	Object::Object()
	{
		m_sTag = "";
		m_sName = "";
		vec_Trait.clear();
	}

	//태그와 이름 입력
	void Object::set_Info(string _tag, string _name)
	{
		m_sTag = _tag;
		m_sName = _name;
	}

	//Tag 리턴
	string Object::get_Tag()
	{
		return m_sTag;
	}

	//이름 입력
	string Object::get_Name()
	{
		return m_sName;
	}

	//소멸자
	Object::~Object()
	{

	}
}