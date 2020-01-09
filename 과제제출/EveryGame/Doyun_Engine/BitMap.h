#pragma once
#include <Windows.h>
#include <string>
#include "POINT.h"
using namespace std;

namespace DoEngine
{
	//������
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
	* @brief ��Ʈ�� Ŭ����
	* @details ��Ŀ(������) �������ִ� ��Ʈ�� ���� Ŭ����
	*/

	class BitMap
	{
	private:
		HDC m_hMemDC; //MemDC����
		HBITMAP m_hBitMap; //BitMap����
		HBITMAP	m_hOldBitmap; //������ ���� oldBit����
		SIZE m_size; //Size
		ANCHOR m_eAnchorType;
		DoEngine::POINTF m_ptAnchor; //float����

	public:
		BitMap(); //������

		void InitBack(HDC hdc, int x, int y); //���� ���۸��� ���� BackDC����
		void Init(HDC hdc, string file_name); //��Ʈ�� �ʱ�ȭ
		void InitBGBit(HDC hdc, int _width, int _height); //���ȭ�� ��Ʈ�� �ʱ�ȭ
		void AdDoustAnchorPoint(int& x, int& y); //��Ŀ ������ ���� ������ġ �ʱ�ȭ
		void DrawBitblt(int x, int y); //BitBlt�� �׸���
		void Draw(int x, int y, float _sizex = 1.0f, float _sizey = 1.0f); //TransparentBIt�� �׸���
		void AlphaDraw(int x, int y, int _blend, float _sizex = 1.0f, float _sizey = 1.0f); //Alpha�� �׸���
		void Draw(DoEngine::POINT pt); //Draw(�����ε�)
		void DrawBack(HDC hdc); //BackDC�� �׸���
		void set_Anchor(ANCHOR type); //��Ŀ�� ����
		void set_AnchorPoint(DoEngine::POINTF pt); //Ŀ���� ��Ŀ�� ����
		HDC GetDC();

		int get_Width(); //hMemDC ���� ����
		int get_Height(); //hMemDC ���� ����

		~BitMap(); //�Ҹ���
	};

}

