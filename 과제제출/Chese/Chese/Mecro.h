#pragma once
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <vector>

using namespace std;

#define POSROW 8
#define POSCOL 8

enum UNIT_CLASS
{
	CLASS_START,
	CLASS_PAWN = 0,
	CLASS_KNIGHT,
	CLASS_BISHOP,
	CLASS_ROOK,
	CLASS_KING,
	CLASS_QUEEN,
	CLASS_END = 7,
	CLASS_DIE
};

enum PLAYER_NUM
{
	PLAYER_START,
	PLAYER_ONE,
	PLAYER_TWO,
	PLAYER_END
};

#define SELECT 2
#define BITW 101
#define BITH 101
#define CORRENTCION 0.8