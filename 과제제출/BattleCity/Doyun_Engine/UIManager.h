#pragma once
#include "GlobalDefine.h"
#include "SingleTon.h"
#include "UIObject.h"

namespace DoEngine
{
	class UIManager : public Singleton<UIManager>
	{
	private:
		vector<DoEngine::UIObject*> m_vecUI; //UI ����
	public:
		UIManager(); //������

		void AddButton(int x, int y, string btnImg, std::function<bool()> callback); //��ư �߰��ϱ�
		void AddLabel(string str, int x, int y, int _r, int _g, int _b, DWORD drawOption); //Label �߰��ϱ�
		void AddText(LPCTSTR _str, int _x, int _y, int _fsize, int _r, int _g, int _b, DWORD _drawOption, LPCTSTR _font); //Text �߰��ϱ�

		void Update(); //Update�� ���
		void Draw(); //UI �׸���(vector�� ��� �״�� �׸���)

		void ReleaseUI(); //UI�����

		~UIManager(); //�Ҹ���
	};
}



