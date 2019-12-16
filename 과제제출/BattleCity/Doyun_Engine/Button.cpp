#include "Button.h"
#include "ResourcesManager.h"
#include "InputManager.h"

namespace DoEngine
{
	//������
	Button::Button()
	{
		//������ Default���� LeftTop���� ����
		m_anchor = ANCHOR_LT;
	}

	//Update�Լ�
	bool Button::Update()
	{
		//��ư Ŭ���ϸ�
		if (InputManager::get_Instance()->isKeyUp(VK_LBUTTON))
		{
			//��ư�� �����ٸ�?
			if (m_rcCol.isPtin(InputManager::get_Instance()->get_MousePoint()))
			{
				return m_pCallBack();
			}
		}
		return false;
	}

	//�ʱ�ȭ �Լ�
	void Button::Init(int _x, int _y, string _btnImg, pBoolFunc _callback)
	{
		//�ش� �̸�(btnImg)�� ���� ��Ʈ���� �����´�
		m_pDefault = ResourcesManager::get_Instance()->get_Bitmap(_btnImg);
		m_pCallBack = _callback;

		m_ptDraw.x = _x; //���콺 ����Ʈ ����
		m_ptDraw.y = _y; //���콺 ����Ʈ ����

		m_rcCol.left = _x; //Rect ���� ����
		m_rcCol.top = _y; //Rect ���� ����
		m_rcCol.right = m_rcCol.left + m_pDefault->get_Width();
		m_rcCol.bottom = m_rcCol.top + m_pDefault->get_Height();
	}

	//�׸��� �Լ�
	void Button::Draw()
	{
		m_pDefault->Draw(m_ptDraw);
	}

	//�Ҹ���
	Button::~Button()
	{

	}
}


