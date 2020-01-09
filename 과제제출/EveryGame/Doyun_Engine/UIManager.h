#pragma once
#include "GlobalDefine.h"
#include "SingleTon.h"
#include "UIObject.h"

namespace DoEngine
{
	class UIManager : public Singleton<UIManager>
	{
	private:
		vector<DoEngine::UIObject*> m_vecUI; //UI 벡터
	public:
		UIManager(); //생성자

		void AddButton(int x, int y, string btnImg, std::function<bool()> callback); //버튼 추가하기
		void AddLabel(string str, int x, int y, int _r, int _g, int _b, DWORD drawOption); //Label 추가하기
		void AddText(LPCTSTR _str, int _x, int _y, int _fsize, int _r, int _g, int _b, DWORD _drawOption, LPCTSTR _font); //Text 추가하기

		void Update(); //Update문 사용
		void Draw(); //UI 그리기(vector에 담긴 그대로 그린다)

		void ReleaseUI(); //UI지우기

		~UIManager(); //소멸자
	};
}



