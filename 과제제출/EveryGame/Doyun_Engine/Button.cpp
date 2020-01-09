#include "Button.h"
#include "ResourcesManager.h"
#include "InputManager.h"

namespace DoEngine
{
	//생성자
	Button::Button()
	{
		//생성시 Default값을 LeftTop으로 설정
		m_anchor = ANCHOR_LT;
	}

	//Update함수
	bool Button::Update()
	{
		//버튼 클릭하면
		if (InputManager::get_Instance()->isKeyUp(VK_LBUTTON))
		{
			//버튼이 눌럿다면?
			if (m_rcCol.isPtin(InputManager::get_Instance()->get_MousePoint()))
			{
				return m_pCallBack();
			}
		}
		return false;
	}

	//초기화 함수
	void Button::Init(int _x, int _y, string _btnImg, pBoolFunc _callback)
	{
		//해당 이름(btnImg)를 가진 비트맵을 가져온다
		m_pDefault = ResourcesManager::get_Instance()->get_Bitmap(_btnImg);
		m_pCallBack = _callback;

		m_ptDraw.x = _x; //마우스 포인트 저장
		m_ptDraw.y = _y; //마우스 포인트 저장

		m_rcCol.left = _x; //Rect 정보 저장
		m_rcCol.top = _y; //Rect 정보 저장
		m_rcCol.right = m_rcCol.left + m_pDefault->get_Width();
		m_rcCol.bottom = m_rcCol.top + m_pDefault->get_Height();
	}

	//그리기 함수
	void Button::Draw()
	{
		m_pDefault->Draw(m_ptDraw);
	}

	//소멸자
	Button::~Button()
	{

	}
}


