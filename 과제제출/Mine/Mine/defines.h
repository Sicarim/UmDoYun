#pragma once

#define MAX_WITDH 1024.0f
#define MAX_HEIGHT 768.0f
#define BUTTON_S 0x53 //���۹�ư
#define BUTTON_X 0x58 //�ٽ��ϱ��ư
#define MAX_BLOCK 10 //�� ����
#define COR_PT 10 //���콺 Ŭ�� ����ġ
#define TIME_MAX 60 //�ð� MAX
#define BLOCKSTART_X 43 //�� ������(x)
#define BLOCKSTART_Y 46 //�� ������(y)
#define MINE_WIDTH 30 //���� ���� ũ��
#define MINE_HEIGHT 16 //���� ���� ũ��
#define MAX_MINE 45 //���� ����
#define FULL_BLOCKWH 26 //Ǯ �� ���� ���� ũ��
#define STAND_WH 26 //Ǯ �� ���� ���� ũ��

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