#include "YellowCard.h"
#include "GameManager.h"

YellowCard::YellowCard()
{

}

//초기화(시작 위치 초기화 가능)(override)
void YellowCard::Init(int _x, int _y)
{
	//노랑 카드
	m_YellowCard = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\ColoredPaperYellow.bmp");
	pos_x = _x;
	pos_y = _y;
	size_x = m_YellowCard->get_Width();
	size_y = m_YellowCard->get_Height();
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;

	m_Bonus = NULL;
	isBonus = false;
}

//키입력(override)
bool YellowCard::Input(int _state)
{
	if (!isBefore)
	{
		isBefore = true;
		if (_state == DOWN)
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
void YellowCard::Update(float _fETime)
{
	if (!isBonus)
	{
		m_Bonus = GameManager::get_Instance()->Bonus_Card();
		isBonus = true;
	}

	if (isAnswer == ANSWER)
	{
		curTime += _fETime;
		if (pos_y + size_y < LIMIT_YELLOW)
		{
			pos_y += curTime * CARD_SPEED;
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
void YellowCard::Draw()
{
	m_YellowCard->Draw(pos_x, pos_y);

	if (m_Bonus != NULL)
	{
		m_Bonus->Draw(pos_x + 20, pos_y + 20);
	}
}

//Draw 함수(override)
void YellowCard::Draw(int _x, int _y)
{

}

//Release() 함수(override)
void YellowCard::Release()
{
	size_x = 0;
	size_y = 0;
	curTime = 0.0f;
	vibe = 0;
	isAnswer = STAND;
	isBefore = false;
}

YellowCard::~YellowCard()
{

}