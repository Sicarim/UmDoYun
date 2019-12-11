#include <Windows.h>
#include "EngineMain.h"
#include "GameManager.h"
#include "resource.h"

/*

*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	//���� ��ü�� �����ϰ� Ÿ��Ʋ�� ������ ����� �־��ش�.
	DoEngine::EngineMain engine("Mine_Serch", 870, 512);
	engine.Reigst_Resource(IDR_MENU1);
	
	GameManager::get_Instance()->All_Regist(); //��� ���Ӿ� �ʱ�ȭ

	//���� ����
	return engine.StartEngine(hInstance);
}