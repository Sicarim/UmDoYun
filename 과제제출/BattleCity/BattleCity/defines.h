#pragma once

//Button
#define BUTTON_S 0x53 //시작버튼
#define BUTTON_X 0x58 //다시하기버튼

//Map Info
#define W_COUNT 13
#define H_COUNT 15
#define W_SPACE 100
#define H_SPACE 20
#define OBJECT_COL 1.99f

//Block Info
#define BLOCK_COUNT 5
#define BLOCK_HEALTH 2
enum SELECT_WALL
{
	NO_WALL,
	BROKEN_WALL,
	STILL_WALL,
	WATER_WALL,
	BUSH_WALL,
	EGLE_WALL,
	PLAG_WALL,
};

#define MAX_ENEMY 20 //몬스터 갯수
#define ENEMY_KIND 2
#define GENERATE_ENEMY 80
//#define UNIT_SPEED 50.0f
#define UNIT_SPEED 130.0f
#define FIRE_SPEED 380
#define COL_SIZE 1.7f
#define SAVE_TIME 0.5f

enum SCENE_INDEX
{
	SCENE_INDEX_TITLE,
	SCENE_INDEX_GAME,
	SCENE_INDEX_END
};

enum ENEMY_SELET
{
	PANZER,
	UP_PANZER,
	TANK,
	UP_TANK
};

enum PLAYER_LOOK
{
	LOOK_UP,
	LOOK_LEFT,
	LOOK_RIGHT,
	LOOK_DOWN,
	LOOK_ATTACK
};