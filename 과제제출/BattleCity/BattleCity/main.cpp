#include <Windows.h>
#include "EngineMain.h"
#include "GameManager.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	srand(time(NULL));
	DoEngine::EngineMain engine("BattleCity", 1024, 768);
	
	//게임 초기회
	GameManager::get_Instance()->Init();
	//게임 씬들을 등록해준다
	GameManager::get_Instance()->Regist_Scene();

	//엔진 시작
	return engine.StartEngine(hInstance);
}