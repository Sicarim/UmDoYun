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
#include <map>
#include <assert.h>
#include <functional>
#include <list>

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

using namespace std;

#define SAFE_DELETE( p ) { if( p ) { delete ( p ); ( p ) = NULL; } }
#define SAFE_DELETE_ARRAY( p ) { if( p ) { delete[] ( p ); ( p ) = NULL; } }
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }

//동작 상태를 가르킨다
enum CURRENT_STATE
{
	STOP,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	ATTACK
};
