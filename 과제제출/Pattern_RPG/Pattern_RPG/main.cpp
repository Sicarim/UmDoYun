#include "Mecro.h"
#include "Game_Manager.h"

int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(165);
	Game_Manager::get_Instence()->Game_Start();
	Game_Manager::Del_Instence();
	return 0;
}