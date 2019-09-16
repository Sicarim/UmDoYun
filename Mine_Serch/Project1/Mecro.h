#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <math.h>

using namespace std;

#define START_X 0
#define START_Y 0
#define WIDTH 20
#define HEIGHT 20
#define HALF_X 10
#define HALF_Y 10

//Áö·ÚÆÇ Å©±â
#define MINE_WIDTH 20
#define MINE_HEIGHT 20

//Áö·Ú °¹¼ö
#define MINE_COUNT 30

//Áö·ÚÆÇ Á¦ÇÑ
#define LIMIT_UP 0
#define LIMIT_DOWN 19
#define LIMIT_LEFT 0
#define LIMIT_RIGHT 18

//Ä¿¼­ Á¶ÀÛ
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define CLICK 120
#define PLAG 99

//Å¬¸¯, Áö·Ú, ±ê¹ß
enum OBJECT_CHECK
{
	OBJECT_CHECK_NULL,
	OBJECT_CHECK_START,
	OBJECT_CHECK_CLICK,
	OBJECT_CHECK_MINE,
	OBJECT_CHECK_PLAG,
	OBJECT_CHECK_COUNT,
	OBJECT_CHECK_ANSWER,
	OBJECT_CHECK_END
};