#pragma once
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <vector>
#include <list>
#include <string>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <crtdbg.h>
#include <sstream>
#include <iterator>
#include <cstring>

using namespace std;

#define START_X 0
#define START_Y 0
#define WIDTH 50
#define HEIGH 30

enum VIEW_SELECT
{
	VIEW_SELECT_START = 1,
	VIEW_SELECT_MENU,
	VIEW_SELECT_WEAPON,
	VIEW_SELECT_MONSTER,
	VIEW_SELECT_END,
};

enum MENU_SELECT
{
	MENU_SELECT_START = 1,
	MENU_SELECT_MONSTER,
	MENU_SELECT_WEAPON,
	MENU_SELECT_END,
};