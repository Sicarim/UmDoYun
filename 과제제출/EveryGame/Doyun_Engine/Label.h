#pragma once
#include "GlobalDefine.h"
#include "UIObject.h"

namespace DoEngine
{
	/**
	* @brief Text�� ���� ����ϴ� Ŭ����
	* @details Text�� ���� ����ϴ� Ŭ����
	*/

	class Label : public DoEngine::UIObject
	{
	private:
		DWORD m_dwDrawOption; //�׸��� �ɼ�
		string m_strPrint; //����� ����

	public:
		Label(); //������

		void Init(string str, int x, int y, DWORD drawOption); //�ʱ�ȭ �Լ�
		virtual void Draw(); //�׸��� �Լ�

		virtual bool Update() { return false; } //Update�Լ�

		virtual ~Label(); //�Ҹ���
	};

}


