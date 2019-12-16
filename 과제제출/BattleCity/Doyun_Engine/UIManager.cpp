#include "UIManager.h"
#include "ResourcesManager.h"
#include "Button.h"
#include "Label.h"
#include "Text.h"

namespace DoEngine
{
	//������
	UIManager::UIManager()
	{
		//BackGround���� ����, TRANSPARENT�� ������ ������ �̿��Ѵ�
		SetBkMode(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), TRANSPARENT);
	}

	//��ư �߰��ϱ�
	void UIManager::AddButton(int x, int y, string btnImg, std::function<bool()> callback)
	{
		//��ư ���� ��, �ʱ�ȭ
		Button* pNew = new Button();
		pNew->Init(x, y, btnImg, callback);
		//�� ��, Vector�� ����
		m_vecUI.push_back(pNew);
	}

	//Label �߰��ϱ�
	void UIManager::AddLabel(string str, int x, int y, int _r, int _g, int _b, DWORD drawOption)
	{
		Label* pNew = new Label();
		pNew->Init(str, x, y, drawOption);
		m_vecUI.push_back(pNew);
	}

	//Text �߰��ϱ�
	void UIManager::AddText(LPCTSTR _str, int _x, int _y, int _fsize, int _r, int _g, int _b, DWORD _drawOption, LPCTSTR _font)
	{
		Text* pNew = new Text();
		pNew->Init(_str, _x, _y, _fsize, _r, _g, _b, _drawOption, _font);
		m_vecUI.push_back(pNew);
	}

	//Update�� ���
	void UIManager::Update()
	{
		int i = m_vecUI.size();

		for (auto iter = m_vecUI.begin(); iter != m_vecUI.end(); iter++)
		{
			if ((*iter)->Update())
				return;
		}
	}

	//UI �׸���(vector�� ��� �״�� �׸���)
	void UIManager::Draw()
	{
		for (auto iter = m_vecUI.begin(); iter != m_vecUI.end(); iter++)
		{
			(*iter)->Draw();
		}
	}

	//UI�����
	void UIManager::ReleaseUI()
	{
		for (auto iter = m_vecUI.begin(); iter != m_vecUI.end(); iter++)
		{
			SAFE_DELETE((*iter));
		}
		m_vecUI.clear();
	}

	//�Ҹ���
	UIManager::~UIManager()
	{
		for (auto iter = m_vecUI.begin(); iter != m_vecUI.end(); iter++)
		{
			auto del = (*iter);
			SAFE_DELETE(del);
		}
	}
}
