#pragma once

#define BUTTON_S 0x53 //시작버튼
#define BUTTON_X 0x58 //다시하기버튼
#define WIDTH 33
#define HEIGHT 25
#define MAX_ENEMY 20 //몬스터 갯수
#define ENEMY_KIND 2
#define GENERATE_ENEMY 80
#define UNIT_SPEED 100.0f
#define FIRE_SPEED 400
#define COL_SIZE 1.8f
#define SAVE_TIME 0.5f

enum SCENE_INDEX
{
	SCENE_INDEX_TITLE,
	SCENE_INDEX_GAME,
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
	LOOK_DOWN
};
