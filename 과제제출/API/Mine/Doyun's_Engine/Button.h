#pragma once
#include "GlobalDefine.h"
#include "UIObject.h"
#include "BitMap.h"

typedef std::function<bool()> pBoolFunc;
namespace DoEngine
{
	class Button : public DoEngine::UIObject
	{
	private:
		ANCHOR m_anchor; //��Ŀ ����
		POINT m_ptDraw; //���콺 ����Ʈ ����
		RECT m_rcCol; //Rect ���� ����
		BitMap* m_pDefault; //BitMap ����
		pBoolFunc m_pCallBack;

	public:
		Button(); //������

		void Init(int _x, int _y, string _btnImg, pBoolFunc _callback); //�ʱ�ȭ �Լ�
		virtual bool Update(); //Update�Լ�
		virtual void Draw(); //�׸��� �Լ�

		virtual ~Button(); //�Ҹ���
	};

}


