#include "UIManager.h"
#include "ResourcesManager.h"
#include "Button.h"
#include "Label.h"
#include "Text.h"

namespace DoEngine
{
	//생성자
	UIManager::UIManager()
	{
		//BackGround색상 지정, TRANSPARENT는 투명한 배경색을 이용한다
		SetBkMode(DoEngine::ResourcesManager::get_Instance()->get_BackDC(), TRANSPARENT);
	}

	//버튼 추가하기
	void UIManager::AddButton(int x, int y, string btnImg, std::function<bool()> callback)
	{
		//버튼 생성 후, 초기화
		Button* pNew = new Button();
		pNew->Init(x, y, btnImg, callback);
		//그 후, Vector에 저장
		m_vecUI.push_back(pNew);
	}

	//Label 추가하기
	void UIManager::AddLabel(string str, int x, int y, int _r, int _g, int _b, DWORD drawOption)
	{
		Label* pNew = new Label();
		pNew->Init(str, x, y, drawOption);
		m_vecUI.push_back(pNew);
	}

	//Text 추가하기
	void UIManager::AddText(LPCTSTR _str, int _x, int _y, int _fsize, int _r, int _g, int _b, DWORD _drawOption, LPCTSTR _font)
	{
		Text* pNew = new Text();
		pNew->Init(_str, _x, _y, _fsize, _r, _g, _b, _drawOption, _font);
		m_vecUI.push_back(pNew);
	}

	//Update문 사용
	void UIManager::Update()
	{
		int i = m_vecUI.size();

		for (auto iter = m_vecUI.begin(); iter != m_vecUI.end(); iter++)
		{
			if ((*iter)->Update())
				return;
		}
	}

	//UI 그리기(vector에 담긴 그대로 그린다)
	void UIManager::Draw()
	{
		for (auto iter = m_vecUI.begin(); iter != m_vecUI.end(); iter++)
		{
			(*iter)->Draw();
		}
	}

	//UI지우기
	void UIManager::ReleaseUI()
	{
		for (auto iter = m_vecUI.begin(); iter != m_vecUI.end(); iter++)
		{
			SAFE_DELETE((*iter));
		}
		m_vecUI.clear();
	}

	//소멸자
	UIManager::~UIManager()
	{
		for (auto iter = m_vecUI.begin(); iter != m_vecUI.end(); iter++)
		{
			auto del = (*iter);
			SAFE_DELETE(del);
		}
	}
}
