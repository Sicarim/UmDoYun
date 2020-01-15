#pragma once
#include <Windows.h>
#include <string>
#include "POINT.h"
using namespace std;

namespace DoEngine
{
	//기준점
	enum ANCHOR
	{
		ANCHOR_LT,
		ANCHOR_TOP,
		ANCHOR_RT,
		ANCHOR_LEFT,
		ANCHOR_CENTER,
		ANCHOR_RIGHT,
		ANCHOR_LB,
		ANCHOR_BOTTOM,
		ANCHOR_RB,
		ANCHOR_CUSTOM
	};

	/**
	* @brief 비트맵 클레스
	* @details 앵커(기준점) 개념이있는 비트맵 관리 클래스
	*/

	class BitMap
	{
	private:
		HDC m_hMemDC; //MemDC선언
		HBITMAP m_hBitMap; //BitMap선언
		HBITMAP	m_hOldBitmap; //연결을 위한 oldBit선언
		SIZE m_size; //Size
		ANCHOR m_eAnchorType;
		DoEngine::POINTF m_ptAnchor; //float형식

	public:
		BitMap(); //생성자

		void InitBack(HDC hdc, int x, int y); //더블 버퍼링을 위한 BackDC선언
		void Init(HDC hdc, string file_name); //비트맵 초기화
		void InitBGBit(HDC hdc, int _width, int _height); //배경화면 비트맵 초기화
		void AdDoustAnchorPoint(int& x, int& y); //앵커 설정을 위한 시작위치 초기화
		void DrawBitblt(int x, int y); //BitBlt로 그린다
		void Draw(int x, int y, float _sizex = 1.0f, float _sizey = 1.0f); //TransparentBIt로 그린다
		void AlphaDraw(int x, int y, int _blend, float _sizex = 1.0f, float _sizey = 1.0f); //Alpha로 그린다
		void Draw(DoEngine::POINT pt); //Draw(오버로딩)
		void DrawBack(HDC hdc); //BackDC를 그린다
		void set_Anchor(ANCHOR type); //앵커를 설정
		void set_AnchorPoint(DoEngine::POINTF pt); //커스텀 앵커를 설정
		HDC GetDC();

		int get_Width(); //hMemDC 넓이 리턴
		int get_Height(); //hMemDC 높이 리턴

		~BitMap(); //소멸자
	};

}

