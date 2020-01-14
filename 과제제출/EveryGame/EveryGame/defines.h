#pragma once

//Key
#define BUTTON_S 0x53 //시작버튼
#define BUTTON_X 0x58 //다시하기버튼
//Game
#define MAX_FEVER 0.99f
#define FEVER_X 20
#define FEVER_Y 55
#define TIMEBAR_X 20
#define TIMEBAR_Y 620

#define BIRTH_UP 90
#define BIRTH_DOWN 590
#define BIRTH_LEFT 0
#define BIRTH_RIGHT 410

//FeverBar색 등록
enum FEVER_SELECT
{
	FEVER_PUPLE,
	FEVER_RED,
	FEVER_YELLOW
};

//카드 보너스 등록
enum BONUS_SCORE
{
	BONUS_YELLOW,
	BONUS_GREEN,
	BONUS_BLUE
};

//Scene
enum SCENE_INDEX
{
	SCENE_INDEX_TITLE,
	SCENE_INDEX_SELECT,
	SCENE_INDEX_FLIGHT,
	SCENE_INDEX_CARD
};

//Card
#define MAX_CARD 100
#define CARD_X 155 //카드 초기화 위치(y)
#define CARD_Y 295 //카드 초기화 위치(x)
#define CARD_SPEED 350
#define LIMIT_BLUE 20
#define LIMIT_RED 400
#define LIMIT_GREEN 150
#define LIMIT_YELLOW 548
#define CARD_SCORE 90

enum CARD_NUMBER
{
	BLUE,
	RED,
	GREEN,
	YELLOW
};

//카드 상태
enum CARD_STATE
{
	STAND,
	ANSWER,
	FAIL
};


//Fligt
#define FLIGHT_X 175 //카드 초기화 위치(x)
#define FLIGHT_Y 295 //카드 초기화 위치(y)
#define FLIGHT_SPEED 400;
#define BULLET_SPEED 60;
#define STAR_SPEED 80;
#define FSTAR_SPEED 60;
#define BLUE_SCORE 1400
#define GREEN_SCORE 1400
#define YELLOW_SCORE 100

//click_key
enum STATE
{
	STATE_UP,
	STATE_LEFT,
	STATE_RIGHT,
	STATE_DOWN
};

enum WINANDLOSE
{
	START,
	WIN,
	LOSE
};