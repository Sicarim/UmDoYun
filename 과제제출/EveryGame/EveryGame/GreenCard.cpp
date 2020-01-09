#include "GreenCard.h"
#include "GameManager.h"

GreenCard::GreenCard()
{

}

//초기화(시작 위치 초기화 가능)(override)
void GreenCard::Init(int _x, int _y)
{
	//초록 카드
	m_GreenCard = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\ColoredPaperGreen.bmp");
	pos_x = _x;
	pos_y = _y;
	size_x = m_GreenCard->get_Width();
	size_y = m_GreenCard->get_Height();
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;

	isBonus = false;
	m_Bonus = NULL;
}

//키입력(override)
bool GreenCard::Input(int _state)
{
	if (!isBefore)
	{
		isBefore = true;
		if (_state == UP)
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
void GreenCard::Update(float _fETime)
{
	if (!isBonus)
	{
		m_Bonus = GameManager::get_Instance()->Bonus_Card();
		isBonus = true;
	}

	if (isAnswer == ANSWER)
	{
		curTime += _fETime;
		if (pos_y > LIMIT_GREEN)
		{
			pos_y -= curTime * CARD_SPEED;
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
void GreenCard::Draw()
{
	m_GreenCard->Draw(pos_x, pos_y);

	if (m_Bonus != NULL)
	{
		m_Bonus->Draw(pos_x + 20, pos_y + 20);
	}
}

//Draw 함수(override)
void GreenCard::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void GreenCard::Release()
{
	size_x = 0;
	size_y = 0;
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;
}

GreenCard::~GreenCard()
{

}