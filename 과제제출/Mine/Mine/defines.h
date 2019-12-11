#pragma once

#define MAX_WITDH 1024.0f
#define MAX_HEIGHT 768.0f
#define BUTTON_S 0x53 //시작버튼
#define BUTTON_X 0x58 //다시하기버튼
#define MAX_BLOCK 10 //블럭 갯수
#define COR_PT 10 //마우스 클릭 보정치
#define TIME_MAX 60 //시간 MAX
#define BLOCKSTART_X 43 //블럭 시작점(x)
#define BLOCKSTART_Y 46 //블럭 시작점(y)
#define MINE_WIDTH 30 //마인 가로 크기
#define MINE_HEIGHT 16 //마인 세로 크기
#define MAX_MINE 45 //지뢰 갯수
#define FULL_BLOCKWH 26 //풀 블럭 가로 세로 크기
#define STAND_WH 26 //풀 블럭 가로 세로 크기

enum SCENE_INDEX
{
	SCENE_INDEX_TITLE,
	SCENE_INDEX_GAME,
	SCENE_INDEX_END
};

enum BLOCK_KIND
{
	EMPTY_BLOCK,
	ONE_BLOCK,
	TWO_BLOCK,
	THREE_BLOCK,
	FOUR_BLOCK,
	FIVE_BLOCK,
	SIX_BLOCK,
	SEVEN_BLOCK,
	EIGHT_BLOCK,
	FULL_BLOCK,
	MINE_BLOCK,
	FLAG_BLOCK
};

enum GAME_RESULT
{
	GAME_WIN = 1,
	GAME_LOSE
};