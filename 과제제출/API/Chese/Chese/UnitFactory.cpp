#include "UnitFactory.h"

UnitFactory::UnitFactory()
{
	Class_Name = "";
	tmp_BitRECT = { 0 };

	Unit_posX = 0;
	Unit_posY = 0;
	Unit_DrawX = 0;
	Unit_DrawY = 0;
	Current_State = 0;
	tmp_GoCount = 0;
}

UnitFactory::~UnitFactory()
{

}