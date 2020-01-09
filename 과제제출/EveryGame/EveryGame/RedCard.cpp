#include "RedCard.h"
#include "GameManager.h"

RedCard::RedCard()
{

}

//초기화(시작 위치 초기화 가능)(override)
void RedCard::Init(int _x, int _y)
{
	//빨간 카드
	m_RedCard = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\ColoredPaperRed.bmp");
	pos_x = _x;
	pos_y = _y;
	size_x = m_RedCard->get_Width();
	size_y = m_RedCard->get_Height();
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;

	isBonus = false;
	m_Bonus = NULL;
}

//키입력(override)
bool RedCard::Input(int _state)
{
	if (!isBefore)
	{
		isBefore = true;
		if (_state == RIGHT)
		{
			isAnswer = ANSWER;
		}
		else
		{
			isAnswer = FAIL;
		}
	}

	return false;
}

//Update함수(override)
void RedCard::Update(float _fETime)
{
	if (!isBonus)
	{
		m_Bonus = GameManager::get_Instance()->Bonus_Card();
		isBonus = true;
	}

	if (isAnswer == ANSWER)
	{
		curTime += _fETime;
		if (pos_x + size_x < LIMIT_RED)
		{
			pos_x += curTime * CARD_SPEED;
		}
		else
		{
			GameManager::get_Instance()->add_CardCount();
			GameManager::get_Instance()->add_FeverCount();
			GameManager::get_Instance()->set_Score(CARD_SCORE);
			if (m_Bonus != NULL)
			{
				GameManager::get_Instance()->add_BonusScore();
			}
			isAnswer = STAND;
		}
	}

	else if (isAnswer == FAIL)
	{
		vibe++;
		curTime += _fETime;

		if (curTime < 0.15f)
		{
			if (vibe % 2 == 0)
			{
				pos_x += 10;
			}
			else if (vibe % 2 == 1)
			{
				pos_x -= 10;
			}
		}
		else
		{
			pos_x = CARD_X;
			pos_y = CARD_Y;
			isAnswer = STAND;
			isBefore = false;
			curTime = 0.0f;
			vibe = 0;
			GameManager::get_Instance()->Down_FeverBar();
		}
	}
}

//Draw 함수(overloding)(override)
void RedCard::Draw()
{
	m_RedCard->Draw(pos_x, pos_y);
	if (m_Bonus != NULL)
	{
		m_Bonus->Draw(pos_x + 20, pos_y + 20);
	}
}

//Draw 함수(override)
void RedCard::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void RedCard::Release()
{
	size_x = 0;
	size_y = 0;
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;
}

RedCard::~RedCard()
{

}