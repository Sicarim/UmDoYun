#include "Object.h"

namespace DoEngine
{
	//������
	Object::Object()
	{
		m_sTag = "";
		m_sName = "";
		vec_Trait.clear();
	}

	//�±׿� �̸� �Է�
	void Object::set_Info(string _tag, string _name)
	{
		m_sTag = _tag;
		m_sName = _name;
	}

	//Tag ����
	string Object::get_Tag()
	{
		return m_sTag;
	}

	//�̸� �Է�
	string Object::get_Name()
	{
		return m_sName;
	}

	//�Ҹ���
	Object::~Object()
	{

	}
}