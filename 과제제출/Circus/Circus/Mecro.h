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

#define PI 3.141592f
#define SPEED 300
#define JUMP_POWER 120
#define FB 37
#define JUMP_TIME 0.99f
#define RING_SPEED 2
#define PLAYSPACE 1000
#define GEN_TIME 4.0f
#define GROUNDMAX 8200

//��Ʈ���� ���� - �÷��̾ ���� �����ϰ��ִ��� Ȯ���� �� �ִ�.
enum STATE
{
	IDLE,
	MOVE,
	JUMP,
	LEFT,
	RIGHT
};