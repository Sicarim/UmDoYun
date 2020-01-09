#include "BitMap.h"
#include "ResourcesManager.h"

namespace DoEngine
{
	//������
	BitMap::BitMap()
	{
		m_eAnchorType = ANCHOR_LT;
	}

	//���� ���۸��� ���� BackDC����
	void BitMap::InitBack(HDC hdc, int x, int y)
	{
		m_hMemDC = CreateCompatibleDC(hdc);
		m_hBitMap = CreateCompatibleBitmap(hdc, x, y);
		m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);

		m_size.cx = x;
		m_size.cy = y;
	}

	//��Ʈ�� �ʱ�ȭ
	void BitMap::Init(HDC hdc, string file_name)
	{
		m_hMemDC = CreateCompatibleDC(hdc);
		m_hBitMap = (HBITMAP)LoadImage(NULL, file_name.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);

		//������ ���ٸ�
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

	//���ȭ�� ��Ʈ�� �ʱ�ȭ
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

	//��Ŀ ������ ���� ������ġ �ʱ�ȭ
	void BitMap::AdDoustAnchorPoint(int& x, int& y)
	{
		x -= m_size.cx * m_ptAnchor.x;
		y -= m_size.cy * m_ptAnchor.y;
	}

	//BitBlt�� �׸���
	void BitMap::DrawBitblt(int x, int y)
	{
		AdDoustAnchorPoint(x, y);
		BitBlt(ResourcesManager::get_Instance()->get_BackDC(), x, y, m_size.cx, m_size.cy, m_hMemDC, 0, 0, SRCCOPY);
	}

	//TransparentBIt�� �׸���
	void BitMap::Draw(int x, int y, float _sizex, float _sizey)
	{
		AdDoustAnchorPoint(x, y);
		TransparentBlt(ResourcesManager::get_Instance()->get_BackDC(), x, y, m_size.cx * _sizex, m_size.cy * _sizey, m_hMemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
	}

	//Draw(�����ε�)
	void BitMap::Draw(DoEngine::POINT pt)
	{
		Draw(pt.x, pt.y);
	}

	//Alpha�� �׸���
	void BitMap::AlphaDraw(int x, int y, int _blend, float _sizex, float _sizey)
	{
		AdDoustAnchorPoint(x, y);

		//���� �ɼ�
		BLENDFUNCTION _bf;
		_bf.BlendOp = 0;
		_bf.BlendFlags = 0;
		_bf.SourceConstantAlpha = _blend; //<--���İ� �����ϱ�	
		_bf.AlphaFormat = AC_SRC_OVER;

		AlphaBlend(ResourcesManager::get_Instance()->get_BackDC(), x, y, m_size.cx * _sizex, m_size.cy * _sizey, m_hMemDC, 0, 0, m_size.cx, m_size.cy, _bf);
	}

	//BackDC�� �׸���
	void BitMap::DrawBack(HDC hdc)
	{
		BitBlt(hdc, 0, 0, m_size.cx, m_size.cy, m_hMemDC, 0, 0, SRCCOPY);
	}

	//��Ŀ�� ����
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

	//Ŀ���� ��Ŀ�� ����
	void BitMap::set_AnchorPoint(DoEngine::POINTF pt)
	{
		m_eAnchorType = ANCHOR_CUSTOM;
		m_ptAnchor = pt;
	}

	HDC BitMap::GetDC()
	{
		return m_hMemDC;
	}

	//hMemDC ���� ����
	int BitMap::get_Width()
	{
		return m_size.cx;
	}

	//hMemDC ���� ����
	int BitMap::get_Height()
	{
		return m_size.cy;
	}

	//�Ҹ���
	BitMap::~BitMap()
	{
		SelectObject(m_hMemDC, m_hOldBitmap);
		DeleteObject(m_hBitMap);
		DeleteDC(m_hMemDC);
	}
}