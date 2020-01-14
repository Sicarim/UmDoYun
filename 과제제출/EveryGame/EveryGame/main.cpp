#include <Windows.h>
#include "EngineMain.h"
#include "GameManager.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	srand(time(NULL));
	//게임 화면 크기와 제목을 지정
	DoEngine::EngineMain engine("Every Game", 414, 650);

	//게임에 사용될키를 등록
	GameManager::get_Instance()->Key_Init();
	//게임 씬들을 등록해준다
	GameManager::get_Instance()->Regist_Scene();

	//엔진 시작
	return engine.StartEngine(hInstance);
}