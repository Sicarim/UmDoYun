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



///////Game/////////
#define MAX_WITHE 9999
#define MIN_WITHE 0
#define FB 37
#define JUMP_TIME 0.99f
#define GROUNDMAX 8200
#define MAX_SCORE 10000

///////FristeView/////////
#define STAND 430	
#define LOGO_X 250
#define LOGO_Y 150
#define RESET_X 0.0f;
#define RESET_Y 0.0f;

///////character/////////
#define PI 3.141592f
#define SPEED 250
#define JUMP_POWER 120

///////Enemy/////////
#define RING_SPEED 2
#define PLAYSPACE 1000
#define GEN_TIME 4.0f

///////Key/////////
#define INPUT_S 0x53

////BonusBIt//////
#define BONUS_X 10
#define BONUS_Y 365
#define GENPROB 40
#define BONUSSPACE 1020

#define SAVE_POINT 1024

//컨트롤의 상태 - 플레이어가 현재 무얼하고있는지 확인할 수 있다.
enum STATE
{
	IDLE,
	MOVE,
	JUMP,
	LEFT,
	RIGHT
};