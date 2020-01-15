#pragma once
#include "GlobalDefine.h"

/**
* @Made By Doyun
* 나도 할 수 있다! 엔진 제작!
*/

/**
* @namespace JEngine
* @brief JEngine 네임 스페이스
* @details 이름 충돌을 피하기 위하여 만든 DoyunEngine의 namespace입니다.
*/
namespace DoEngine
{
	/**
	* @brief 엔진의 Main이 존재하는 클래스
	* @details 엔진의 Main문을 관리하는 클래스 윈도우 사이즈 타이틀변경등을 담당한다.
	* @date 2019-11-10
	* @version 0.0.2
	*/

	class EngineMain
	{
	private:
		string m_strTitle; //게임 타이틀
		int m_winSizeX; //윈도우 사이즈 x
		int m_winSizeY; //윈도우 사이즈 y
		int Menu;

	public:
		EngineMain(); //default
		EngineMain(string _title, int _cx, int _cy);//생성자 
		void Reigst_Resource(int _menu); //윈도우 리소드 등록

		int StartEngine(HINSTANCE hInstance); //엔진 시작
		static bool get_MineTrigger();
		static void set_MineTrigger(bool _trg);
		static int get_NumTrigger();
		static void set_NumTrigger(int _num);
		//소멸자
		~EngineMain();
	};
}

