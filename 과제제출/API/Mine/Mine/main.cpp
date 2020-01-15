#include <Windows.h>
#include "EngineMain.h"
#include "GameManager.h"
#include "resource.h"

/*

*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	//엔진 객체를 생성하고 타이틀과 윈도우 사이즈를 넣어준다.
	DoEngine::EngineMain engine("Mine_Serch", 870, 512);
	engine.Reigst_Resource(IDR_MENU1);
	
	GameManager::get_Instance()->All_Regist(); //모든 게임씬 초기화

	//엔진 시작
	return engine.StartEngine(hInstance);
}