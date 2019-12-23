#pragma once
#include "GlobalDefine.h"
#include "SingleTon.h"
#include "BitMap.h"

using namespace std;

namespace DoEngine
{
	/**
	* @brief DoEngine::BitMapŬ������ �����ϴ� Ŭ����
	* @details DoEngine::BitMapŬ������ �����ϴ� Ŭ���� , ���� DoEngine::BitMap ��ü�� �����Ǵ� ���� �����ְ� ���Ϸε带 ���.
	*/
	class ResourcesManager : public Singleton<ResourcesManager>
	{
	private:
		DoEngine::BitMap* m_pBack; //��Ʈ�� ��ü ����
		map<string, DoEngine::BitMap*>	m_mapBitmap; //��(�ڷᱸ��)������ BitMap����
		DoEngine::BitMap* InitBitmap(std::string strFileName); //Resoureces�� �ش� �׸��� �׸���
		DoEngine::BitMap* InitBackGround(std::string strFileName, int _width, int _height); //�ƹ��͵� ���� ���ȭ�� �����

	public:
		ResourcesManager(); //������

		void InitBack(HDC hdc, int cx, int cy); //������ ũ�⿡ ���߼� BackDC�� ����
		HDC get_BackDC();
		void DrawBack(HDC hdc);
		DoEngine::BitMap* get_Bitmap(std::string strFileName); //vector���� ���� �̸��� ���� bmp������ ã�´� ���ٸ� ���� �����
		DoEngine::BitMap* get_BackGround(std::string strFileName, int _width, int _height); //vector���� ���� �̸��� ���� bmp����(BackGround)�� ã�´� ���ٸ� ���� �����
		

		~ResourcesManager(); //�Ҹ���
	};
}