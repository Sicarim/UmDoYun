#include "BitMap.h"
#include "ResourcesManager.h"

namespace DoEngine
{
	//생성자
	BitMap::BitMap()
	{
		m_eAnchorType = ANCHOR_LT;
	}

	//더블 버퍼링을 위한 BackDC선언
	void BitMap::InitBack(HDC hdc, int x, int y)
	{
		m_hMemDC = CreateCompatibleDC(hdc);
		m_hBitMap = CreateCompatibleBitmap(hdc, x, y);
		m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);

		m_size.cx = x;
		m_size.cy = y;
	}

	//비트맵 초기화
	void BitMap::Init(HDC hdc, string file_name)
	{
		m_hMemDC = CreateCompatibleDC(hdc);
		m_hBitMap = (HBITMAP)LoadImage(NULL, file_name.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);

		//파일이 없다면
		if (m_hBitMap == NULL)
		{
			MessageBox(NULL, file_name.c_str(), "File Not Find", MB_OK);
			return;
		}

		m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);

		BITMAP bmp_info;
		GetObject(m_hBitMap, sizeof(bmp_info), &bmp_info);
		m_size.cx = (int)bmp_info.bmWidth;
		m_size.cy = (int)bmp_info.bmHeight;
	}

	//배경화면 비트맵 초기화
	void BitMap::InitBGBit(HDC hdc, int _width, int _height)
	{
		m_hMemDC = CreateCompatibleDC(hdc);
		m_hBitMap = CreateCompatibleBitmap(hdc, _width, _height);

		m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);

		BITMAP bmp_info;
		GetObject(m_hBitMap, sizeof(bmp_info), &bmp_info);
		m_size.cx = (int)bmp_info.bmWidth;
		m_size.cy = (int)bmp_info.bmHeight;
	}

	//앵커 설정을 위한 시작위치 초기화
	void BitMap::AdDoustAnchorPoint(int& x, int& y)
	{
		x -= m_size.cx * m_ptAnchor.x;
		y -= m_size.cy * m_ptAnchor.y;
	}

	//BitBlt로 그린다
	void BitMap::DrawBitblt(int x, int y)
	{
		AdDoustAnchorPoint(x, y);
		BitBlt(ResourcesManager::get_Instance()->get_BackDC(), x, y, m_size.cx, m_size.cy, m_hMemDC, 0, 0, SRCCOPY);
	}

	//TransparentBIt로 그린다
	void BitMap::Draw(int x, int y, float _sizex, float _sizey)
	{
		AdDoustAnchorPoint(x, y);
		TransparentBlt(ResourcesManager::get_Instance()->get_BackDC(), x, y, m_size.cx * _sizex, m_size.cy * _sizey, m_hMemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
	}

	//Draw(오버로딩)
	void BitMap::Draw(DoEngine::POINT pt)
	{
		Draw(pt.x, pt.y);
	}

	//Alpha로 그린다
	void BitMap::AlphaDraw(int x, int y, int _blend, float _sizex, float _sizey)
	{
		AdDoustAnchorPoint(x, y);

		//블랜딩 옵션
		BLENDFUNCTION _bf;
		_bf.BlendOp = 0;
		_bf.BlendFlags = 0;
		_bf.SourceConstantAlpha = _blend; //<--알파값 조절하기	
		_bf.AlphaFormat = AC_SRC_OVER;

		AlphaBlend(ResourcesManager::get_Instance()->get_BackDC(), x, y, m_size.cx * _sizex, m_size.cy * _sizey, m_hMemDC, 0, 0, m_size.cx, m_size.cy, _bf);
	}

	//BackDC를 그린다
	void BitMap::DrawBack(HDC hdc)
	{
		BitBlt(hdc, 0, 0, m_size.cx, m_size.cy, m_hMemDC, 0, 0, SRCCOPY);
	}

	//앵커를 설정
	void BitMap::set_Anchor(ANCHOR type)
	{
		m_eAnchorType = type;
		switch (m_eAnchorType)
		{
		case ANCHOR_LT:
			m_ptAnchor.x = 0.0f;
			m_ptAnchor.y = 0.0f;
			break;
		case ANCHOR_TOP:
			m_ptAnchor.x = 0.5f;
			m_ptAnchor.y = 0.0f;
			break;
		case ANCHOR_RT:
			m_ptAnchor.x = 1.0f;
			m_ptAnchor.y = 0.0f;
			break;
		case ANCHOR_LEFT:
			m_ptAnchor.x = 0.0f;
			m_ptAnchor.y = 0.5f;
			break;
		case ANCHOR_CENTER:
			m_ptAnchor.x = 0.5f;
			m_ptAnchor.y = 0.5f;
			break;
		case ANCHOR_RIGHT:
			m_ptAnchor.x = 1.0f;
			m_ptAnchor.y = 0.5f;
			break;
		case ANCHOR_LB:
			m_ptAnchor.x = 0.0f;
			m_ptAnchor.y = 1.0f;
			break;
		case ANCHOR_BOTTOM:
			m_ptAnchor.x = 0.5f;
			m_ptAnchor.y = 1.0f;
			break;
		case ANCHOR_RB:
			m_ptAnchor.x = 1.0f;
			m_ptAnchor.y = 1.0f;
			break;
		}
	}

	//커스텀 앵커를 설정
	void BitMap::set_AnchorPoint(DoEngine::POINTF pt)
	{
		m_eAnchorType = ANCHOR_CUSTOM;
		m_ptAnchor = pt;
	}

	HDC BitMap::GetDC()
	{
		return m_hMemDC;
	}

	//hMemDC 넓이 리턴
	int BitMap::get_Width()
	{
		return m_size.cx;
	}

	//hMemDC 높이 리턴
	int BitMap::get_Height()
	{
		return m_size.cy;
	}

	//소멸자
	BitMap::~BitMap()
	{
		SelectObject(m_hMemDC, m_hOldBitmap);
		DeleteObject(m_hBitMap);
		DeleteDC(m_hMemDC);
	}
}