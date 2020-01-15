#include "Mecro.h"
#include "Std_Manager.h"

int main()
{
	Std_Manager::get_Instence()->Display();
	Std_Manager::get_Instence()->Del_Instence();
	return 0;
}