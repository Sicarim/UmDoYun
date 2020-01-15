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
		ANCHOR m_anchor; //앵커 설정
		POINT m_ptDraw; //마우스 포인트 저장
		RECT m_rcCol; //Rect 정보 저장
		BitMap* m_pDefault; //BitMap 저장
		pBoolFunc m_pCallBack;

	public:
		Button(); //생성자

		void Init(int _x, int _y, string _btnImg, pBoolFunc _callback); //초기화 함수
		virtual bool Update(); //Update함수
		virtual void Draw(); //그리기 함수

		virtual ~Button(); //소멸자
	};

}


