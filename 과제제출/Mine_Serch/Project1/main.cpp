#include "Mecro.h"
#include "GameManager.h"
#include "MapManager.h"
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	//_crtBreakAlloc = 249;
	srand(time(NULL)); //·£´ý ³­¼ö
	GameManager::get_Instence()->Game_Start();
	GameManager::del_Instence();
	MapManager::del_Instence();
	return 0;
}
