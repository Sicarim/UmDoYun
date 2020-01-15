#pragma once

//Key
#define BUTTON_S 0x53 //���۹�ư
#define BUTTON_X 0x58 //�ٽ��ϱ��ư
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

//FeverBar�� ���
enum FEVER_SELECT
{
	FEVER_PUPLE,
	FEVER_RED,
	FEVER_YELLOW
};

//ī�� ���ʽ� ���
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
#define CARD_X 155 //ī�� �ʱ�ȭ ��ġ(y)
#define CARD_Y 295 //ī�� �ʱ�ȭ ��ġ(x)
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

//ī�� ����
enum CARD_STATE
{
	STAND,
	ANSWER,
	FAIL
};


//Fligt
#define FLIGHT_X 175 //ī�� �ʱ�ȭ ��ġ(x)
#define FLIGHT_Y 295 //ī�� �ʱ�ȭ ��ġ(y)
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