#pragma once
#include "GlobalDefine.h"
#include "SingleTon.h"
#include "BitMap.h"

using namespace std;

namespace DoEngine
{
	/**
	* @brief DoEngine::BitMap클레스를 관리하는 클래스
	* @details DoEngine::BitMap클레스를 관리하는 클래스 , 같은 DoEngine::BitMap 객체가 생성되는 것을 막아주고 파일로드를 담당.
	*/
	class ResourcesManager : public Singleton<ResourcesManager>
	{
	private:
		DoEngine::BitMap* m_pBack; //비트맵 객체 선언
		map<string, DoEngine::BitMap*>	m_mapBitmap; //맵(자료구조)형식의 BitMap선언
		DoEngine::BitMap* InitBitmap(std::string strFileName); //Resoureces에 해당 그림을 그린다
		DoEngine::BitMap* InitBackGround(std::string strFileName, int _width, int _height); //아무것도 없는 배경화면 만들기

	public:
		ResourcesManager(); //생성자

		void InitBack(HDC hdc, int cx, int cy); //윈도우 크기에 맞추서 BackDC를 생성
		HDC get_BackDC();
		void DrawBack(HDC hdc);
		DoEngine::BitMap* get_Bitmap(std::string strFileName); //vector에서 같은 이름을 가진 bmp파일을 찾는다 없다면 새로 만든다
		DoEngine::BitMap* get_BackGround(std::string strFileName, int _width, int _height); //vector에서 같은 이름을 가진 bmp파일(BackGround)을 찾는다 없다면 새로 만든다
		

		~ResourcesManager(); //소멸자
	};
}