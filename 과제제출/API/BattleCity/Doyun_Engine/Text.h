#pragma once
#include "GlobalDefine.h"
#include "UIObject.h"

namespace DoEngine
{
	/*
	* @brief Text�� �߰��ϴ� Ŭ����
	* @details ��Ʈ, ���� ó������ ����ϴ� Ŭ�����̴�.
	*/

	/*
	* TRANSPARENT: ����� ����ó��
	*/

	class Text : public DoEngine::UIObject
	{
	private:
		HFONT m_Font; //��Ʈ ����
		HFONT m_oldFont; //��Ʈ ����

		DWORD m_dwDrawOption; //�׸��� �ɼ�
		LPCTSTR m_strPrint; //����� ����
		LPCTSTR m_fontTypeFace; //���� ��Ʈ ����

		int m_fontx, m_fonty;
		int RGB_R, RGB_G, RGB_B;
		int m_size;

	public:
		Text(); //������

		void Init(LPCTSTR _str, int _x, int _y, int _fsize, int _r, int _g, int _b, DWORD _drawOption, LPCTSTR _font); //�ʱ�ȭ �Լ�
		virtual void Draw(); //�׸��� �Լ�(����)

		virtual bool Update() { return false; } //Update�Լ�

		virtual ~Text(); //�Ҹ���
	};
}
