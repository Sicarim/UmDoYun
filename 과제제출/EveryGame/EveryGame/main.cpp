#include <Windows.h>
#include "EngineMain.h"
#include "GameManager.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	srand(time(NULL));
	DoEngine::EngineMain engine("Every Game", 414, 650);

	//���� �ʱ�ȸ
	GameManager::get_Instance()->Key_Init();
	//���� ������ ������ش�
	GameManager::get_Instance()->Regist_Scene();

	//���� ����
	return engine.StartEngine(hInstance);
}