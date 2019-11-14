#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstdlib>
#include <math.h>

using namespace std;

#define CORRECTION 0.7
#define CARDW 145
#define CARDH 235

#define SPEED 5
#define JUMPMAX 83
#define JUMPPOWER 3
#define JUMPSPEED 10

enum CHAR_DIR
{
	DIR_FRONT,
	DIR_BACK,
	DIR_LEFT,
	DIR_RIGHT
};