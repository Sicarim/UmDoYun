#include "Mecro.h"
#include "GameManager.h"

int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(165);
	GameManager::get_Instence()->Game_Start();
	GameManager::Del_Instence();
	return 0;
}